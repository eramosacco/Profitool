#!/usr/bin/perl
package Profitool::WebEngine::ReportView;

use strict;

################################################################
### JMW Rewritten 20090823 to use "@media screen" and "@media print"
### to enable view/print modes, rather than loading two copies of
### the report as previously done.

=pod

=head1 NAME

Profitool::WebEngine::Lookups - Request handler for field lookup requests

=head1 SYNOPSIS

	(called as a PerlHandler from Apache/mod_perl)

=head1 DESCRIPTION

	C<Profitool::WebEngine::Lookups> handles requests for field lookups
	from Web Edition.  It takes changed fields and trigger names as input,
	queries Profitool, and returns a window full of lookup data.  It also
	mediates lookup data string searches and multiple sets of lookup data.

=head1 SEE ALSO

C<Profitool::WebEngine>
C<Profitool::AutoLookups>
C<Profitool::Interactive>

=head1 COPYRIGHT

	Copyright (c) 2003 Profitool, Inc.

=head1 CHANGELOG

=over 4

=item * 20041107 - bts -

	Elimination of Apache::compat for Apache2.0
		- use CGI ':cgi-lib';
		- Remove calls to $request->content() method
		- Apache::Util::ht_time replaced by HTTP::Date::time2str()
		- change $request->get_remote_host to either
			$request->connection->get_remote_host OR
			$connection->get_remote_host

		- add content type, nothing is assumed in apache2
			$request->content_type('text/html');

		- removed calls to $request->send_http_header
			no longer needed in Apache2.0, header out on first write

=item * 20020801 - bts -

Initial Version

=back 4

=cut

################################################################
# Apache parts and references

my ($ApacheVer,$Apache2,$ApacheOK,$ApacheFORBIDDEN);
use Module::Load::Conditional qw(can_load check_install requires);

if (can_load(modules => {'mod_perl2' => undef})) {
# mod_perl2 final here...
	eval('$ApacheVer = $mod_perl2::VERSION;');
	$Apache2 = 1;
	can_load(modules => {	'Apache2' => undef,
				'Apache2::Const' => undef,
				'APR::Const' => undef,
				'ModPerl::Const' => undef});
	eval('$ApacheOK = Apache2::OK();');
	eval('$ApacheFORBIDDEN = Apache2::FORBIDDEN();');
	can_load(modules => {	'Apache2::Log' => undef,
				'Apache2::Connection' => undef,
				'Apache2::Reload' => undef});
}
elsif (can_load(modules => {'mod_perl' => undef})) {
# mod_perl1 or mod_perl2pre here...
	eval('$ApacheVer = $mod_perl::VERSION;');
	$Apache2 = $ApacheVer >= 1.99;
	if ($Apache2) {
		can_load(modules => {	'Apache2' => undef,
					'Apache::Const' => undef,
					'APR::Const' => undef,
					'ModPerl::Const' => undef});
		eval('$ApacheOK = Apache::OK();');
		eval('$ApacheFORBIDDEN = Apache::FORBIDDEN();');
	} else {
		can_load(modules => {	'Apache' => undef,
					'Apache::Constants' => undef});
		eval('Apache::Constants->import(qw(:response :remotehost));');
		eval('$ApacheOK = Apache::Constants::OK();');
		eval('$ApacheFORBIDDEN = Apache::Constants::FORBIDDEN();');
	}
	can_load(modules => {	'Apache::Log' => undef,
				'Apache::Connection' => undef,
				'Apache::Reload' => undef});
}
else {
#  Cannot run - no valid Apache mod_perl found!
	exit -1;
}

use Apache::Session::File ();
use Apache::Session::Store::File ();
use Apache::Session::Lock::File ();

use HTTP::Date ();

# Profitool::WebEngine global configuration parameters
use Profitool::WebEngine::Conf ();
use Profitool::WebEngine::Labels ();

# Profitool::WebEngine Libraries
use Profitool::WebEngine::WebEd::LibImport ();


## JMW 20090824 - COMMENTED OUT, AS SUBROUTINES ARE INCLUDED HEREIN
# Profitool::SplitReport module for splitting large reports
use Profitool::WebEngine::SplitReport qw(newReport parseReport parseLine finishReport searchReport closeReport);

use JSON::XS;

# round sub for rounding numbers
sub round {
	my($number) = shift;
	return int($number + .5 * ($number <=> 0));
}


####################################################################################################
## TOP INSERT SplitReport FUNCTIONS ################################################################
####################################################################################################

# handler sub, as defined by mod_perl
sub handler {
	my $request = shift;
	my $log = $request->log;
	my $mycolor = "CFCFFF"; ## JMW - This was set so that top rows always started with the same color
	
	WebEd::logAttach($request);

	my $cfg = undef();
	$cfg = Profitool::WebEngine::Conf::getConfig($cfg);

	my $mymodule = "ReportView";
	my $bugs = $cfg->{globals}->{debuglevel};

	my $requestor_ip = WebEd::connection_ip($request);
	my $requestor_name = WebEd::connection_lookup($request);
	my $host = $requestor_name;

	my $date = (HTTP::Date::time2str(time()));
	my $rawtime = time();

	my $revlookup_ok = 1;

	$log->debug(": $mymodule.pm invoked from $requestor_ip ");

	# Verify on reverse lookup
	if ( $cfg->{sessions}->{enforce_reverse_lookup} )  {
		$requestor_name = WebEd::connection_revlookup($request);

		if ( $bugs > 500 ) { }
		if ( $requestor_ip eq $requestor_name ) {
			# host name did not resolve...
			$revlookup_ok = 0;
			if ( $bugs > 500 ) { }
			# insert 403 forbidden code here ....
			return $ApacheFORBIDDEN;
		}
	}

	$host = $requestor_name;

	# Extract the session info from the URI...
	my $browserid = $request->path_info;
	my $action = $browserid;
	if ( $bugs > 300 ) { }

	$browserid =~ s/\/$mymodule\/(\w*)\/\w*/$1/;
	$action =~ s/\/$mymodule\/$browserid\/(\w*)/$1/;

	my %session;
	my $base;
	eval {
		# connect to the previous session...
		$base = $cfg->{persistence}->{base_dir} . "/";
		tie %session, 
			'Apache::Session::File', 
			$browserid, 
			{
				Directory => $base . $cfg->{persistence}->{session_dir},
				LockDirectory => $base . $cfg->{persistence}->{lock_dir},
				Transaction => $cfg->{persistence}->{safe_locks}
			};
	};

	$session{accesses}++;

	# Cache control... this is volatile...
	$request->no_cache(1);
	$request->content_type('text/html');

	my $message = "";
	if ( $session{debug} ) {
		$message .= "Session data connected.\n";
		$message .= "Session id       : <b>$session{_session_id}</b>\n";
		$message .= "Source IP stored : <b>$session{ip}</b>\n";
		$message .= "Start time stamp : <b>$session{starttime}</b>\n";
		$message .= "Expires          : <b>$session{expires}</b>\n";
		$message .= "Accesses         : <b>$session{accesses}</b>\n";
		$message .= "Debug flag       : <b>$session{debug}</b>\n";
		$message .= "Username         : <b>$session{username}</b>\n";
		$message .= "Gateway          : <b>$session{gwhost}:$session{gwport}</b>";
#		$request->print("<!--\n$message\n-->\n\n");
	}

#	$message = "";
	$session{expires} = (time() + $cfg->{sessions}->{timeout} );
	my $stylepref = $session{stylepref};
	my $elapsed = ( time() - $session{starttime} );

	# connect to appropriate socket
	# Connect to Profitool PTClient service...
	my %reportParams = CGI::Vars();
	my $rowLink = $reportParams{'Row'};
	my $fileNmbrRaw = $reportParams{'File'};
	my $curPage = $reportParams{'CurPage'};
	my $toPage = $reportParams{'ToPage'};
	my $searchString = $reportParams{'SrchStr'};
	## Not being sent at present
	#my $showLines = $reportParams{'Length'}; 
	#$log->debug(" --> showLines == \"$showLines\"");

	my $fileNmbrPad = sprintf("%03d",$fileNmbrRaw);
	my $fileName = sprintf("OUT%03d",$fileNmbrRaw);
	$log->debug(" --> fileName == \"$fileName\"");
	my $lfdName = $reportParams{'Lfd'};
       $lfdName =~ s/[^a-zA-Z0-9 ]//gs;
	$log->debug(" --> lfdName == \"$lfdName\"");
	my $pagedir = $base . $cfg->{persistence}->{xfer_dir} . "/XFER_$browserid/" . $fileName;
	$log->debug(" --> page cache directory == \"$pagedir\"");
	my $secPages = $cfg->{userconfig_text}->{reportPagesPerView};
	my $totalPages=0;

	my ($ret, $omsg);
	if ($action =~ /^Reports/) { ## Initial screen creation
		hdrDisplay($request, \%session, $browserid, $cfg, $stylepref, $fileNmbrRaw, $fileName, $lfdName, $pagedir, $rowLink, $message);
	} elsif ($action =~ /^init/) { ## Initial report load after screen is created
		my $pgReport = Profitool::WebEngine::SplitReport::newReport('filename'=>"$fileName", 'pagedir'=>"$pagedir");
		my $pgStatus = {};
		$pgStatus->{status} = "started";
		$pgStatus->{pagecount} = 0;
		my $wmsg = "View {\n  File(\"$fileName\")\n  Lfd(\"$lfdName\")\n}\n"; ##  Length(\"$showLines\")
		($ret, $omsg) = WebEd::onlineMsg(\%session, $browserid, $cfg, $wmsg, \&lineHandler, $pgReport, $pgStatus);
		$totalPages = $pgReport->finishReport();
		$session{"report_$fileName"} = $pgReport;
		$session{"report_pagecount_$fileName"} = $totalPages;
		
		my $sectCnt = $totalPages/$secPages; 
		if($sectCnt > int($sectCnt)) { int($sectCnt +=.5); }
		$session{"report_sectcount_$fileName"} = $sectCnt;
		
		updateDisplay($request, $cfg, $stylepref, $pagedir, 1,{totPages=>"$totalPages"}); ## OK
	} else {

		## Beginning of code for navigation within currently displayed section
		if ($action =~ /^prevPg/) { ## Previous page of current section
			$toPage = $curPage - $secPages;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if ($toPage < 1 && $curPage != 1) {
				updateDisplay($request, $cfg, $stylepref, $pagedir, 1);
			} elsif ($toPage < 1 && $curPage == 1) {
				## my $msg = "You are already at the first group of pages";
				my $msg = "Already displaying first page of current section";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>"$msg"});
			} else {
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage);
			}
		} elsif ($action =~ /^nextPg/) { ## Next page of current section
			$toPage = $curPage + $secPages;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			my $fname = sprintf "%06d",$toPage;
			if (!-e "$pagedir/$fname") {
				## my $msg = "You are already at the last group of pages";
				my $msg = "Starting over with first page of current section";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>"$msg"});
			} else {
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage);
			}
			
			## Beginning of code for navigation within entire document
		} elsif ($action =~ /^firstSeg/) { ## OK
			$toPage = 1;
			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if ($curPage == 1) {
				my $msg = "Already displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>$msg});
			} else {
				my $msg = "Displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, 1, {message=>$msg});
			}
	
		} elsif ($action =~ /^lastSeg/) { ## Last page of current section ## OK
			$toPage = $session{"report_pagecount_$fileName"} - $secPages + 1;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if ($toPage < 1) {
				my $msg = "Already displaying last section of entire report";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>$msg, action=>'last'}); ## OK, I think
			} else {
				my $msg = "Displaying section $sectCnt of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {message=>$msg, action=>'last'}); ## OK, I think
			}
	
		} elsif ($action =~ /^prevSeg/) { ## Previous page of current section
			$toPage = $curPage - $secPages;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if ($toPage < 1 && $curPage != 1) {
				updateDisplay($request, $cfg, $stylepref, $pagedir, 1);
			} elsif ($toPage < 1 && $curPage == 1) {
				#my $msg = "Already displaying first section of this report";
				my $msg = "Already displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>"$msg"});
			} else {
				#my $msg = "Displaying first page of previous section";
				my $msg = "Displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {message=>"$msg"});
			}
	
		} elsif ($action =~ /^prevSegBtm/) { ## Previous page of current section
			$toPage = $curPage - 1;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			my $msg = "Displaying last page of previous section";
			updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {message=>"$msg"});
	
		} elsif ($action =~ /^nextSeg/) { ## Next page of current section
			$toPage = $curPage + $secPages;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			my $fname = sprintf "%06d",$toPage;
			if (!-e "$pagedir/$fname") {
				#my $msg = "Already displaying last section of this report";
				$curSect--;
				my $msg = "Already displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>"$msg"});
			} else {
				my $msg = "Displaying section $curSect of this report &nbsp;(of $sectCnt sections)";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {message=>"$msg"});
			}
		
		## Beginning of code for search and page-jump navigation
		} elsif ($action =~ /^page/) { ## Jump to page# entered in pageNmbr input box
			my $fname = sprintf "%06d",$toPage;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if (!-e "$pagedir/$fname") {
				my $msg = "That page does not exist!";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>$msg});
			} else {
				my $lastPage = $toPage + $secPages; 
				if ($lastPage > $totalPages) { $lastPage = $totalPages; }
				my $msg = "Beginning at page $toPage of this report";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {message=>$msg});
			}
		} elsif ($action =~ /^searchnext/) { ## Search for string entered in srchStr input box
			$toPage = $curPage + $secPages;

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			my $fname = sprintf "%06d",$toPage;
			if (!-e "$pagedir/$fname") {
				## my $msg = "You are already at the last group of pages";
				my $msg = "All matches have been displayed";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>$msg});
			} else {
				$toPage = findNext($pagedir, $toPage, $searchString);
				if ($toPage == -1) {
				my $msg = "No match found for search!";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {search=>$searchString, message=>$msg});
				} else {
					updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {search=>$searchString});
				}
			}
		} elsif ($action =~ /^search/) {
			$toPage = findNext($pagedir, $curPage, $searchString);

			my $totalPages=$session{"report_pagecount_$fileName"};
			my $sectCnt = $session{"report_sectcount_$fileName"};
			my $curSect = int($toPage / $secPages) + (int($toPage/$secPages) != ($toPage/$secPages));

			if ($toPage == -1) {
				my $msg = "No match found for search!";
				updateDisplay($request, $cfg, $stylepref, $pagedir, $curPage, {message=>$msg});
			} else {
				my $msg = "";
				if ($searchString) { 
					$msg = "Displaying matches for &quot;$searchString&quot;";
				}
				updateDisplay($request, $cfg, $stylepref, $pagedir, $toPage, {search=>$searchString, message=>$msg});
			}
		} elsif ($action =~ /^print/) {
		} elsif ($action =~ /^close/) {
			$session{"report_$fileName"}->closeReport();
			delete $session{"report_$fileName"};
			delete $session{"report_pagecount_$fileName"};
		}
	}
	untie %session;
	return($ApacheOK);
}

sub hdrDisplay {
	my ($request, $session, $browserid, $cfg, $stylepref, $fileNmbrRaw, $fileName, $lfdName, $pagedir, $rowLink, $message) = @_;
	my $secPages = $cfg->{userconfig_text}->{reportPagesPerView};

	my $myopener = $browserid . "main";
	my $reportPath = $cfg->{interface}->{module_path} . "/ReportView/$browserid/Reports";

	## Added routine to get filesize. Only works if the file is indeed stored in /home/LFD
	my $filePath = "/home/".$lfdName."/".$fileName;
	my $fileSize = 0;
	if (-e $filePath) {
		$fileSize = (-s $filePath)*0.0009765625*10;
		$fileSize = round($fileSize)/10;
	} else {
		$filePath = "N/A";
	}
	
	my $out = <<___END;
<html>
<head>
<title>ReportView: Report #$fileNmbrRaw</title>
<!--\n reportPath = $reportPath\n lfdName = '$lfdName'\n fileName = '$fileName'\n filePath = $filePath\n fileSize = $fileSize kb\n-->
<link rel='stylesheet' type='text/css' href='$cfg->{interface}->{theme_path}/$stylepref/reportView.css'>

<script type='text/javascript' src='/include/json2min.js'></script>
<script type='text/javascript' src='/include/ajaxclient.js'></script>
<script type='text/javascript' src='$cfg->{interface}->{module_path}/FileFilter/$browserid/include/reportView.js'></script>
</head>
<!-- 
<body onLoad='jumpTo("init");' onunload='var httpreq=newHttpRequest(); httpreq.open("GET","$cfg->{interface}->{module_path}/ReportView/$browserid/close?File=$fileNmbrRaw",false); httpreq.send(null); window.close();' style='margin:0px;'> 
-->
<body onload='jumpTo("init");' onunload='doClose(); return true;' style='margin:0px;'>

<!-- $message -->

<a id='TOP' name="TOP" style="position:absolute; top:-10px; left:-10px;"></a>

<div id="btnBar" class="btnBar">
<form name="getPage" style="margin:0;" onsubmit="jumpTo(sact); return false;" method="GET" action="javascript:;">
<table class="btnTbl" cellpadding="0" cellspacing="0" border="0">
<tr>
	<td class="btnSubTd" width="30%">
		<span id='navTitle' class="navTitle"></span>
		<div id='multiSectBtns' style='display:none;'>
			<a class="btnDoc" href="javascript:;" onclick="sact=''; jumpTo('firstSeg'); blur();" title="Jump to first page of entire report.">&nbsp;|<<&nbsp;</a>
			<a class="btnDoc" href="javascript:;" onclick="sact=''; jumpTo('prevSeg'); blur();" title="Jump to previous section of report.">&nbsp;<<&nbsp;</a>
	
			<a class="btnSeg" href="javascript:;" onclick="sact=''; sectTop(); blur();" title="Jump to first page of currently displayed section.">&nbsp;|<&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; pageUp(); blur();" title="Jump to previous page of currently displayed section.">&nbsp;<&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; pageDown(); blur();" title="Jump to next page of currently displayed section.">&nbsp;>&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; sectBtm(); blur();" title="Jump to last page of currently displayed section.">&nbsp;>|&nbsp;</a>
	
			<a class="btnDoc" href="javascript:;" onclick="sact=''; jumpTo('nextSeg'); blur();" title="Jump to next section of entire report.">&nbsp;>>&nbsp;</a>
			<a class="btnDoc" href="javascript:;" onclick="sact=''; jumpTo('lastSeg'); blur();" title="Jump to last page of entire report.">&nbsp;>>|&nbsp;</a>
		</div>
		<div id='singleSectBtns' style='display:none;'>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; sectTop(); blur();" title="Jump to first page of this report.">&nbsp;|<&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; pageUp(); blur();" title="Jump to previous page of this report.">&nbsp;<&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; pageDown(); blur();" title="Jump to next page of this report.">&nbsp;>&nbsp;</a>
			<a class="btnSeg" href="javascript:;" onclick="sact=''; sectBtm(); blur();" title="Jump to last page of this report.">&nbsp;>|&nbsp;</a>
		</div>
	</td>
	<td class="btnSubTd" width="40%">
		<span id="reportMessage" class="msgBox">Profitool Report Viewer (loading report...)</span>
		<br>
		<a class="btnGry" href="javascript:;" onclick="sact=''; top.reportFrame.window.print(); updateMsg('pages','PRINT'); blur();" title="Print currently displayed report section using browser print utility.">&nbsp;Print Window&nbsp;</a>
		<a class="btnRed" href="javascript:;" onclick="sact=''; doClose(); blur();" title="Close ReportView window.">&nbsp;Close Window&nbsp;</a>
		<span id="prevLinkSpan"></span>
		<span id="nextLinkSpan"></span>
	</td>
	<td class="btnSubTd" width="30%">
		<span id='rptInfo' class="rptInfo" style="visibility:hidden">Report #$fileNmbrRaw</span> &nbsp;<span id='rptSize' class="rptInfo" style="visibility:hidden"></span>
		<br>
		Page Jump: <input type="text" name="pageNmbr" maxlength="8" class="pgNmbr" onfocus="sact='page';" value="" style="vertical-align: middle;">
		<a href="javascript:;" onclick="jumpTo('page'); updateMsg('pages','PGJUMP'); blur();" title="Jump to report page # entered in the field to the left." style='position:relative; top:4px;'><img src='$cfg->{interface}->{theme_path}/$stylepref/img/arrow_yel_rgt.png' border='0' width='16' height='16'></a>&nbsp;
		<span style="position: absolute; left: -100; top: -100;"><input type="submit" name="submit" value="submit"></span>

		Search: <input type="text" name="srchStr" maxlength="40" class="srchStr" onfocus="sact='search';" value="">
		<a href="javascript:;" onclick="jumpTo('search'); blur();" title="Search reports for string entered in the field to the left."><img src='$cfg->{interface}->{theme_path}/$stylepref/img/lookup-mag.gif' border='0' width='14' height='14'></a>&nbsp;
	</td>
</tr>
</table>
</form>
</div>
<script type='text/javascript'>
<!--
	// Statically assigned variables...
	var rowLink = "$rowLink";  // Currently selected row from STATUS screen
	var curFile ="$fileName";  // Name of formatted OUT file
	var curFileNmbr ="$fileNmbrRaw";  // Raw report number of OUT file
	var reportPath = "$reportPath";  // Path to report module
	var lfdName = "$lfdName";  // Logical LFD name
	var browserid = "$browserid";  // Session ID
	var secPages = $secPages;  // # Pages in each section (Added jmw)

	// Dynamically updated variables...
	var sact = "";  // Submit action for Search or Page Jump (= "page")
	var curPage = 1;  // First page of current section
	var lastCurPage;  // Last page of current section
	var totPages;  // Total page count for report (Added jmw)
	var pageid;  // Current page tag target for next/prev page jump. Leave unset.
	var searchid = 0;  // Current search tag target (0 if no search active) = 0
	var searchterm = '';  // Current search string (= "")
	var sections;  // Number of sections in this report

	getPrevNextLinks();
// -->
</script>
<iframe name='reportFrame' id='reportFrame' src='$cfg->{interface}->{theme_path}/$stylepref/reportView.html' style='position:absolute; top:70px; left:0px; width:99%; height:87%; overflow:auto; border:none;'></iframe>
___END
	$request->print("$out");
	$request->print("<!-- rowLink: $rowLink -->\n");
	$request->print("<a name='BTM'></a>\n");
	$request->rflush();
}

sub updateDisplay {
	my ($request, $cfg, $stylepref, $pagedir, $curPage, $extras);
	my ($search, $totPages, $message);
	
	if (scalar(@_) == 5) {
		($request, $cfg, $stylepref, $pagedir, $curPage) = @_;
	} elsif (scalar(@_) == 6) {
		($request, $cfg, $stylepref, $pagedir, $curPage, $extras) = @_;
	} else {
		# invalid number of parameters!
	}

	my $outobj = {};
	$outobj->{curPage} = $curPage;
	$outobj->{message} = "";

	if ($extras) {
		if (defined($extras->{'search'})) {
			$search = $extras->{'search'};
		}
		if (defined($extras->{'totPages'})) {
			$totPages = $extras->{'totPages'};
		}
		if (defined($extras->{'message'})) {
			$outobj->{message} = $extras->{'message'};
		}
		if (defined($extras->{'action'})) {
			$outobj->{action} = $extras->{'action'};
		}
	}

	my $secPages = $cfg->{userconfig_text}->{reportPagesPerView};
	my $tmp = "";
	my $t = 0;
	my $pagenum = $curPage;
	my $fname = sprintf "%06d", $pagenum;
	my $onload = "";
	if ($search) {
		$onload .= "window.location.hash='srch_1';";
	}
	if ($totPages) {
		$onload .= "top.resizePage();";
		$onload .= "top.updateRptInfo('$totPages');";
	}
	$onload = " onload=\"$onload\"" if ($onload);
	my $out = <<__END;
<html>
<head>
<title>Report Viewer</title>
<link rel='stylesheet' type='text/css' href='$cfg->{interface}->{theme_path}/$stylepref/reportView.css'>
</head>
<body$onload>
<span id='reportMaster'><center>
<a id='TOP' name='TOP'></a>
__END

	while ( $pagenum < ($curPage + $secPages) && -e "$pagedir/$fname") {
		my $oldterm = $/;
		undef $/;
		open(my $pagefile, "$pagedir/$fname");
		$tmp = <$pagefile>;
		close $pagefile;
		$/ = $oldterm;
		$tmp =~ s/\&/&amp;/gs;
		$tmp =~ s/</&lt;/gs;
		$tmp =~ s/</&gt;/gs;
		$tmp =~ s/[\s\f\r\n]*$//s;
		#$tmp =~ s/ /&nbsp;/gs;
		if ($search) {
			my $re = qr/($search)/i;
			$out .= "<!-- Searching for $search -->\n";
			$tmp =~ s/$re/$t++>=0?sprintf("<a class='bgYel' id='srch_%d' name='srch_%d'>%s<\/a>",$t,$t,$1):'';/igse;
		}

		$out .= "<a id='pg_$pagenum' name='pg_$pagenum'></a>\n";
		$out .= "<table cellpadding='0' cellspacing='0'>\n<tr><td><pre>";
		$out .= "$tmp";
		$out .= "</pre></td></tr>\n</table>\n";
		$pagenum++;
		$fname = sprintf "%06d", $pagenum;
	}
	my $segBtnVis='hidden';
	if($totPages) {
		if($totPages > $secPages) {
			$segBtnVis='visible';
		}
	}
	$out .= <<__END;
<a id='BTM' name='BTM'></a>
</center></span>
<script type='text/javascript'>
<!--
__END
	if (!$outobj->{message} && $totPages) { ## Only update this the first time, when $totPages has a value
		$outobj->{message} = "Displaying pages " . $curPage . " - " . ($pagenum - 1);
	}
	$outobj->{lastCurPage} = $pagenum - 1;
	$outobj->{searchid} = 1 if ($search);
	$outobj->{searchterm} = $search;
	$outobj->{totPages} = $totPages;
	$outobj->{segBtnVis} = $segBtnVis; ## (Added jmw)
	my $json = new JSON::XS;
	my $jsonObj = $json->space_before->space_after->indent->encode($outobj);
	$out .= "var response = $jsonObj;\n";
$out .= <<__END;
top.updateInfo(response);
__END

if($totPages) { ## Only update this the first time, when $totPages has a value
$out .= <<__END;
top.setSegBtnVis('$segBtnVis');
__END
}

$out .= <<__END;
// -->
</script>
</body>
</html>
__END
	$request->print($out);
	delete $outobj->{message};
	delete $outobj->{curPage};
	delete $outobj->{lastCurPage}; ## Added jmw
	delete $outobj->{totPages}; ## Added jmw
	delete $outobj->{searchid};
	delete $outobj->{searchterm};
	delete $outobj->{action}; ## Added jmw
	delete $outobj->{segBtnVis}; ## Added jmw
	delete $outobj->{totPages};
}

sub showError {
	my ($request,$cfg,$message) = @_;
	my $outobj = {};
	$outobj->{message} = $message;
	my $json = new JSON::XS;
	my $jsonObj = $json->space_before->space_after->indent->encode($outobj);
	$request->print($jsonObj);
	delete $outobj->{message};
}

sub findNext {
	my ($pagedir, $curPage, $searchString)= @_;
	my $toPage = $curPage;
	my $fname = sprintf("%06d",$toPage);
	
	## Diff from jmw, but should be OK
	open (my $findf, "cd '$pagedir'; grep -li '$searchString' *|");
	my @sres = <$findf>;
	close $findf;
	chomp @sres;
	@sres = sort @sres;
	my $ind;
	if (scalar(@sres)) {
		for ($ind = 0; $ind < scalar(@sres); $ind++) {
			return int($sres[$ind]) if ($sres[$ind] >= $fname);
		}
	}
	return -1;
	## Diff from jmw, but should be OK
}

sub lineHandler {
	my ($pgReport, $pgStatus, $line) = @_;
	return if ($pgStatus eq "ended"); # already ended
	if ($pgStatus->{status} eq "data") {
		if ($line =~ /^\s*" \) \}\s*$/) {
			$pgStatus->{status}="endPending";
			return;
		} else {
			$pgStatus->{pagecount} = $pgReport->parseLine($line);
			return 0;
		}
	}
	if ($line =~ /^\s*<!---begin-message--->/) {
		$pgStatus->{status}="started";
		return;
	}
	if ($line =~ /^\s*<!---end-message--->/) {
		$pgStatus->{status}="ended";
		return;
	}
	if ($pgStatus->{status} eq "started" && $line =~ /^\s*File\s*\{/) {
		$pgStatus->{status}="file";
		if ($line =~ /\s*Data\s*\(\s*"/) {
			$pgStatus->{status}="data";
		}
		return;
	}
	if ($pgStatus->{status} eq "file" && $line =~ /^\s*Data\s*\(\s*"\s*$/) {
		$pgStatus->{status}="data";
		return;
	}
	return 0;
}

# vim: st=3 ts=3 sw=3 ai

# perl standard module return...
1;

