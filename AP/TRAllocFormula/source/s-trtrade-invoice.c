#define LPROTOTYPE
#define PRIMELIB
#include "fortran.h"
#include "cmis_com.h"
#include "p_post_com_batch.h"
#include "billing_com.h"
#include "apar_hold_com.h"
#include "apar_tracking_com.h"
#include "sc_com1.h"
#include "sc_com2.h"
#include "shared_com.h"
#include "black_board_insert.h"
#include "parm_k.h"
/*
----------------------------------------------------------------------C
     S/TRTRADE-INVOICES

     PURCHASE INPUT PROCESSOR

*/

#include "libutil.h"
#include "libpost.h"
#include "libSQLclient.h"
#include "libfio.h"
#include "libscr.h"
#include "libbb.h"
double combjp();
double rndoff();
void dout();
void tr6805(void)
{
static short T1;
static short D3;
static short D6;
static double T9;
static double T10;
static short D14;
static short D16;
static short D19;
static short D21;
static short D23;
static short D25;
static short D27;
static short K22 = 22;
static short K1 = 1;
static short K24 = 24;
static short K18 = 18;
static short K11 = 11;
static short K17 = 17;
static short K0 = 0;
static short K10 = 10;
static short K14 = 14;
static short K33 = 33;
static short K12 = 12;
static short K26 = 26;
static short K16 = 16;
static short K4 = 4;
static short K9 = 9;
static short K5 = 5;
static short K15 = 15;
static short K13 = 13;
static short K8 = 8;
static short K3 = 3;
static short K2 = 2;
static short K6 = 6;
static short K30 = 30;
static short K7 = 7;
static short K27 = 27;
static short K76 = 76;
static short K23 = 23;
static double R4 = 1.e0;
static short K9999 = 9999;
static short K20 = 20;
static double R7 = 0.30e0;
static double R8 = 0.1e0;
static short N1 = -1;
static short K40 = 40;
static short K21 = 21;
static double R11 = 0.e0;
static double R12 = .01e0;
static short K36 = 36;
static short K50 = 50;
static short K19 = 19;
static short K52 = 52;
static short K60 = 60;
static short K25 = 25;
static double R17 = 0.01e0;
static short K160 = 160;
static short K78 = 78;
static short K53 = 53;
static short K62 = 62;
static double pSldep;
static short bSeqfn[5];
static short duplxS;                         /* DUPLEX PRIMOS FUNCTION */
static short cpShlp[8];                      /* NAME USED FOR HELP REQUESTS IN SCFM */
static short filelS;

static double fldnam[12];
static double quanty[375];
static double amnts[375];
static double dracct[375];
static double drjacc[375];
static double cracct[375];
static double rjobs[375];
static double invli[375];
static double invdli[375];
static double poli[375];
static double discli[375];
static double clntli[375];
static double csh[375];
static double dsc[375];
static double taxamt[375];
static double taxcod[375];
static double adisc[375];
static double apict[375];
static double arict[375];
static double apadj[375];
static double aradj[375];
static double datuse[375];
static double accteq[375];
static double hrsbil[375];
static double adjhrs[375];
static double amntl[375];
static double adjams[375];
static double eqjobs[375];
static double eqphss[375];
static double eqordj[375];
static double eqordl[375];
static double invoic;
static double accts[20];
static double vatamt[375];
static double data[10];
static double ppsout[1];
static double tmemo[2];
static double vatact[2][3][2][3];
static double code[1];
static double entity[10][6];

static short litem[375];
static short fordom;
static short accpay;
static short ifgs;
static short vivo;
static short vatype;
static short vatdsc[36][20];
static short despnt[2][3][2][3];
static short activ[5];
static short memo[8];
static short ifldna[16];
static short loctax[20];

static short dscact[5];
static short iactxt[5];
static short jobtxt[5];
static short keygi[20];
static short activs[375][5];
static short rmemo[375][8];
static short inobil[375];
static short neactv[375][5];
static short nefunc[375][5];
static short idchg[375][2];
static short idadj[375][2];
static short itax[5];
static short lactxt[5];
static short ljbtxt[5];
static short icaltx[375];
static short jrnkey[10];
static short keyact[11];
static short ivname[15];
static short lastyp[4];
static short itemp[2];
static short nresp[12];
static short irescd[375][8];
static short namres[8];
static short namqty[3];
static short inhld[38];
static short marray[14];
static short jcoid[2];
static short keycSm[60];
static short keysav[10];
static short keysv[22];
static short nexpn[375];
static short nclos[375];
static short icert[6];
static short keyalc[22];

static short invdat[5];
static short iact[5];
static short imem[8];
static short memotx[8];

static short keyeor[52];
static short nunit[5];
static short neqact[5];
static short neqfnc[5];
static short noract[5];
static short memadj[8];
static short idin[39];

static unsigned short nqtyrc;
static unsigned short invref;
static unsigned short dupdue;
static unsigned short image;
static unsigned short linitm;
static unsigned short backed;

static short ndup;
static double typlst;
static short iflag;
static double olddsc;
static double craold;
static short idumb;
static short irc;
static short ipbya;
static double sdatdu;
static short idsmod;
static short idum;
static short invchk;
static short invdup;
static short i;
static short nview;
static double batch;
static double effbat;
static double effout;
static short nswvb;
static double effdat;
static double datout;
static double vatrt;
static short iswpps;
static double pps1;
static double pps2;
static short nfunc;
static double trtype;
static short nsweor;
static double dum;
static short ircb;
static double refno;
static short ircf;
static double vcno;
static short nm1;
static short nd1;
static short ny1;
static double datinv;
static short ircidt;
static double perbgl;
static double perenl;
static double disbgl;
static double disenl;
static short idsflg;
static double vbjob;
static short nbank;
static double apgl;
static double dscern;
static double vatcr;
static double vatdr;
static short iforgn;
static double client;
static short nonbil;
static short ircnon;
static double po;
static short nm2;
static short nd2;
static short ny2;
static double datdue;
static short ircddt;
static double cramnt;
static double disc;
static short ifc;
static short ilc;
static double dscfac;
static double ddisc;
static double vatpct;
static short iexvat;
static double vattot;
static short ircvat;
static double divisr;
static double divsor;
static double stxtot;
static short irctax;
static double taxemt;
static double codtax;
static short iopt;
static double taxrat;
static double saltax;
static double usetax;
static short noe;
static double rmisc;
static double ttaxbl;
static double sbtotx;
static short ircsub;
static double sbrtio;
static short nswcls;
static short nswcxp;
static double crjacc;
static double alloc;
static short j;
static double ramnt;
static short mflag;
static short icnt;
static double perc;
static double rj;
static double rp;
static double ac;
static double stcode;
static double rjp;
static double amt;
static short inirnt;
static double eqdccj;
static double eqdccp;
static short nercdl;
static short neorrc;
static double eqorad;
static double ordjsv;
static double autadj;
static double atadhr;
static double perbeg;
static double perend;
static double disbeg;
static double disend;
static short nrefsh;
static short nswall;
static double hrsacc;
static double rntacc;
static double hrsbld;
static double rntbld;
static short nswend;
static double hrsacf;
static double rntacf;
static double hrsblf;
static double rntblf;
static double eqdate;
static double eqjob;
static double eqphs;
static double eqcrac;
static double eqdato;
static double hrsunb;
static double rntunb;
static double eqjbph;
static short ldummy;
static double thrunb;
static double thours;
static double tauadj;
static short noeor;
static short npif;
static double hrsuna;
static double rntuna;
static double hours;
static double amount;
static double adjhr;
static double adjamt;
static double datusd;
static double rental;
static double rentor;
static double adjrnt;
static double equcjp;
static double eqccjb;
static double eqccph;
static double eqccjp;
static short len;
static double eqdrac;
static double tdist;
static double tdistl;
static double thrs;
static double tadjhr;
static double tadamt;
static double tadisc;
static double tvat;
static double tstax;
static double taxabl;
static short lsttax;
static short lstadj;
static short lstadh;
static short lstvat;
static short ilast;
static short nswdup;
static short ircbak;
static short ircamt;
static double adjlin;
static double erate;
static double adamnt;
static short ircSd;
static short lstdsc;
static short ircacc;
static double bjob;
static short k;
static double rjob;
static double phase;
static short ircact;
static short irca;
static short ircv;
static double subjct;
static double exempt;
static short irc1;
static short irc2;
static short nerr;
static double accnt;
static double rjobph;
static double rvat;
static double penny;
static short ic;
static short jfunc;
static double diff;
static double vatro;
static short icg;
static double dscadj;
static double staxro;
static double check;
static short month;
static short iday;
static short iyear;
static double chkdat;
static double cash;
static short ib;
static short ircdin;
static short ivcmod;
static short ircS;
static short ircSS;
static short ircx;
static double tsaltx;
static double crjtax;
static double crltax;
static double taxtyp;
static double taxent;
static double ratio;
static double actvat;
static double cract;
static double cractl;
static double pstamt;
static short iacpay;
static double dract;
static double dractl;
static short kk;
static short iclr;
static double tamnt;
static double clsamt;
static short ierrs;
static double chkjob;
static double chkphs;
static short idupls;
static short n;
static double epps;
static double x;
static double odate;
static double hldref;
static short nread;
static int FIRST = 1;
static int ftnsiz[] = {1,1,12,1,1,5,1,1,4,1,1,5};
static namelist DATAVAR[] = {
"fldnam",fldnam,2,ftnsiz,"dscact",dscact,1,ftnsiz+3,"lastyp",lastyp,1,ftnsiz+6,"invdat",invdat,1,ftnsiz+9,
    "ndup",&ndup,1,NULL
};
static char *DATAVAL[] = {
"$DATAVAR",
"fldnam='AMOUNT','DRACCT','JOBPH','ACTIV','MEMO','EXPN','CLOS','VAT','INV','DISC','PO','CLNT',dscact=",
"'DI','SC','OU','NT','',lastyp='  ','  ','  ','',invdat='DA','TE',' I','NV','',ndup='N',",
"$END"
};

static char* F3064[] = {
    "('HOLD ALL INVOICES: ',a8)"
};
static char* F3067[] = {
    "('HOLD ALL TRADE INVOICES: ',a8)"
};
static char* F3645[] = {
    "(b'Z#.##')"
};
static char* F3725[] = {
    "(f8.0)"
};
static char* F3825[] = {
    "(b'$$$,$$#.##')"
};
static char* F3831[] = {
    "(b'ZZ#.##','%     ')"
};
static char* F4010[] = {
    "(2a2,'TRAL',a8,4x,24x)"
};
static char* F4225[] = {
    "(f10.0)"
};
static char* F4320[] = {
    "(2a2,5a2,b'########',78(' '))"
};
static char* F4445[] = {
    "(14x,f8.0,f6.0,f2.0,5a2,5a2,f10.2)"
};
static char* F4495[] = {
    "(b'ZZZZZ#')"
};
static char* F4505[] = {
    "(f7.2)"
};
static char* F4515[] = {
    "(f8.2)"
};
static char* F4885[] = {
    "(b'---,--#.##')"
};
static char* F5315[] = {
    "(f9.2)"
};
static char* F5785[] = {
    "(b'-,---,--#.##')"
};
static char* F6155[] = {
    "(b'ZZZZZ#',b'Z#',5a2,4x)"
};
static char* F6355[] = {
    "(a1,' TAX ',a8,'  ')"
};
static char* F6494[] = {
    "(a1,' TAX ',a8,'  ')"
};
static char* F6565[] = {
    "('P V',a1,4x)"
};
static char* F6595[] = {
    "(f12.2,4x)"
};
static char* F6765[] = {
    "('CDV',a1,4x)"
};
static char* F7040[] = {
    "(2a2,'PO',b'ZZZZZZ',b'ZZZZZZ',b'ZZ',5a2,a8,82x)"
};
static char* F7320[] = {
    "('**Warning:  PPS expires on ',a8,44x)"
};
static char* F7375[] = {
    "(b'Z#.##')"
};

    if(FIRST) {
        FIRST=0;
        fiointu((char*)DATAVAL,0,2);
        fiornl(DATAVAR,5,NULL);
    }

    typlst = *(double*)fifstrgv("~~~~~~~~",8);
    iflag = 0;                               /* TELL ME TWICE FLAG */
    olddsc = 0.e0;                           /* PREVIOUS DISCOUNT RATE */
    craold = 0.e0;                           /* PREVIOUS INVOICE AMOUNT */

    linitm = FALSE;
    invref = FALSE;
    gnliSc("READ","INVOICE FROM REFERENCE",&K22,&idumb,&K1,&irc);
    if(irc == 0) invref = TRUE;

    /*
     ---- Set IPBYA which indicates whether Payables
     ---- are to be recorded by activity (AP/AR$MASTER)

    */
    ibyaSc("P ",&ipbya);

    image = FALSE;
    if(xc_cSenvr != 1) goto S550;            /* NO CAPTURE IF NOT IN ONLINE */
    gnliSc("READ","TRTRADE PURCHASE CAPTURE",&K24,&idumb,&K1,&irc);
    if(irc == 0) image = TRUE;
    T1 = CPTURS;
    flagSc("U ","G ",&T1,&irc);
    if(irc == 1) image = FALSE;              /* CAPTURE WAS ALREADY ON */

S550:
    dupdue = FALSE;
    gnliSc("READ","DUPLICATE DUE DATE",&K18,&idumb,&K1,&irc);
    if(irc == 0) dupdue = TRUE;

    sdatdu = 0.e0;                           /* SAVE DATE DUE FOR LATER USE   1/6/89 SL */

    /*
    -------------------CHECK FOR % DISCOUNTS

    */
    idsmod = 0;                              /* DISCOUNT NOT IN % */

    gnliSc("READ","% DISCOUNTS",&K11,&idum,&K1,&irc);
    if(irc == 7) goto S1000;

    idsmod = 1;                              /* DISCOUNT IS A % */

S1000:

    /*
     --- OPEN COMMITMENT$MASTER

    */
    ioSf("OPEN","COMMITMENT$MASTER",&K17,"    ",&K0,&K0,&K0,&K0,&irc);

    if(irc != 0) ferrSc(&K10,&irc,"COULD NOT OPEN COMMITMENT$MASTER  SUBR: TR6805~",&K0);

    /*
     ---- Check configuration params to see if duplicate invoice checking
          is required.  If so, also check if user must confirm acceptance
          of duplicate invoice situations, or just a return will suffice.

    */
    invchk = 0;                              /* NOT NECESSARY TO CHECK */
    invdup = 0;                              /* NO CONFIRM DUP INV */

    gnliSc("READ","CHECK INVOICES",&K14,&idum,&K1,&irc);
    if(irc != 0) goto S1080;

    /*
     ---- Yes, check for duplicates.  Now determine if its at the
          invoice or job level.

    */
    fileSc("READ",&K33,"AP/AR$MASTER",&K12,&K1,&irc,0);
    if(irc != 0) ferrSc(&K10,&irc,"AP/AR$MASTER~",&K0);

    invchk = 1;                              /* CHECK AT INVOICE LEVEL */
    if(icompr("J ",&idum,&K1) == 0) invchk = 2;/* CHECK AT JOB/PHASE LEVEL */

    /*
     ---- Finally, see if user must enter confirmation (i.e. "OK")
          when Duplicate Invoice situation found.

    */
    gnliSc("READ","CONFIRM DUPLICATE INVOICES",&K26,&idum,&K1,&irc);
    if(irc == 0) invdup = 1;

S1080:

    /*
     ----  OPEN INPUT BATCH

    */
    for(i=1; i==1 || i<=10; i++)
    {
        jrnkey[i-1] = 0;
    }

    jrnkey[0] = 1;                           /* SET FLAG FOR PURCHASE JOURNAL */
    nview = 0;                               /* RESET VIEWING ONLY FLAG */
    iSopnS(jrnkey,&batch,&effbat,&effout,&irc);
    if(irc > 1) goto S9000;
    if(irc == 1) nview = 1;                  /* SET VIEWING ONLY FLAG */

    /*
     ----- Test for Verify Batch

    */
    nswvb = 0;
    if(icompr(&batch,"/ ",&K1) == 0) nswvb = 1;

    loadSs(xsc1_scSsel,&K16,&irc);           /* LOAD INPUT SCREEN */
    if(irc != 0) goto S9000;

    if(xbb_nsetSb > 375) xbb_nsetSb = 375;   /* limit to size of data arrays */
    if(idsmod == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsmod == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    backed = FALSE;

    /*
     ----- SEE IF QUANTITIES AND RESOURCE CODES ARE ON THE SCREEN

    */
S1105:

    readSs(&K10,&irc);

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S1120;

    for(i=1,D3=(D3=(7-i+1))>0?D3:1; D3>0; D3--,i+=1)
    {
        if(jrnkey[i-1] == 0) goto S1110;
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S1110;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S1105;
S1110:;
    }

    goto S1125;

S1120:

    effdat = effbat;

S1125:

    xbilcom_bSdate = effdat;

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    mvwrd("RESOURCE CODE   ",namres,&K8);
    mvwrd("QTY   ",namqty,&K3);

    nqtyrc = TRUE;                           /*  ASSUME THEY ARE THERE */
    dataSs(namres,&K16,&idum,&K1,&irc);
    if(irc == 1) nqtyrc = FALSE;             /*  NO, THEY ARE NOT */

    iswpps = 1;
    dataSs("PPS APPLICABLE",&K14,&idum,&K2,&irc);
    if(irc != 4) iswpps = 0;
    pps1 = -1.e0;
    pps2 = -1.e0;
    ppsout[0] = *(double*)fifstrgv("N       ",8);

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    /*
     ----- INITIALIZE TIME & EXPENSE VARIABLES

    */
    initSb(&irc);

    xbilcom_bSbtch = batch;
    xbilcom_bSdate = effdat;

    /*
         OUTPUT BATCH NUMBER AND EFFECTIVE DATE

    */
    soutSs("P ",&K1,&batch,&K8,&irc);
    soutSs("P ",&K2,&effout,&K8,&irc);

    nfunc = *(short*)fifstrgv("A ",2);       /* SET DEFAULT FUNCTION */
    if(nview == 1) nfunc = *(short*)fifstrgv("L ",2);/* SET DEFAULT FUNCTION FOR A CLOSED BATCH */
    fill(&trtype,&K4,"  ");                  /* INITIALIZE TRANSACTION TYPE */
    ndup = *(short*)fifstrgv("N ",2);        /* SET DEFAULT DUPLICATION SWITCH */

S1800:

    backed = FALSE;
    nsweor = 0;                              /* set flag to read data from "Outside Rental", if appropriate */
    protSs(&K0,&K0,&K2,&K0,&irc);            /* UNPROTECT ALL FIELDS */
    initSs(&K2,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);      /* LOAD FUNCTION */
    doutSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    doutSs("DUP ",&K3,&ndup,&K1,&irc);       /* LOAD AUTO DUP SWITCH */
    if(idsmod == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsmod == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsmod == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    /*
         PUT DUE DATE BACK ON SCREEN...BUT NOT FIRST TIME THRU SL 1/6/89

    */
    if(dupdue && sdatdu != 0.e0) qmdySc(&K2,&K0,&K0,&K0,&sdatdu,&irc);

    if(dupdue && sdatdu != 0.e0) mdySc("P ","DUE ",&K3,&sdatdu,&dum,&irc);

    posSs("REFNO ",&K5,&irc);

    if(icompr(&trtype,"        ",&K8) == 0 && nview == 0) posSs("TRANSACTION TYPE",&K16,&irc);
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2050;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2050;

    soutSs("B ",&K3,"RETURN after Reference#~",&K0,&irc);
    soutSs("C ",&K6,&K0,&K0,&irc);
    namdSs("C ","V/C$INFO",&K8,"    ",&irc);

S2000:
    iflag = 0;                               /* TELL ME TWICE FLAG FOR DISCOUNT RATE 0 = FIRST TIME */

    rdpaSs("REFNO ",&K5,&K1,&irc);           /* READ SCREEN THRU REFERENCE# */
    soutSs("C ",&K3,&K0,&K0,&ircb);          /* CLEAR VENDOR NAME */
    namdSs("C ","V/C$INFO",&K8,"    ",&ircb);
    if(irc == 0) goto S2200;
    if(irc == 4) goto S2100;
    if(irc == 8) goto S1800;
    goto S9000;

S2050:

    /*
         AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    soutSs("C ",&K6,&K0,&K0,&irc);
    soutSs("C ",&K3,&K0,&K0,&ircb);          /* CLEAR VENDOR NAME */
    namdSs("C ","V/C$INFO",&K8,"    ",&ircb);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    rdpaSs("REFNO ",&K5,&K11,&irc);
    goto S2200;

S2100:
    errSs("Screen cannot be SAVED until data has been entered~",&K0,&irc);
    goto S2000;

S2200:
    dataSs("FUNC",&K4,&nfunc,&K1,&ircf);

    /*
     ----- If Verify Batch test for invalid function

    */
    if(nswvb == 0) goto S2210;
    if(nfunc == *(short*)fifstrgv("R ",2) || nfunc == *(short*)fifstrgv("L ",2) || nfunc == *(short*)fifstrgv("N ",2) ||
      nfunc == *(short*)fifstrgv("S ",2)) goto S2210;
    errSs("Verify Batch - only 'R', 'L', 'N' and 'S' are valid~",&K0,&irc);
    posSs("FUNC",&K4,&irc);
    goto S2000;

S2210:
    if(nfunc == *(short*)fifstrgv("L ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2250;
    if(nview == 1) goto S2230;               /* VIEWING ONLY */

    if(nfunc == *(short*)fifstrgv("A ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("C ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("D ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2250;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2250;
    errSs("Enter 'A', 'C', 'L', 'N', 'S', or 'D'~",&K0,&irc);
    goto S2240;

S2230:

    /*
         VIEWING ONLY ALLOWED (LIST OR NEXT) ON A CLOSED BATCH

    */
    errSs("Batch is CLOSED.  Viewing only.  Enter 'L' or 'N'~",&K0,&irc);
    goto S2240;

S2240:
    if(ircf == 0) blnkSs("FUNC",&K4,&irc);
    if(ircf != 0) starSs("FUNC",&K4,&irc);
    goto S2000;
S2250:

    /*
         GET REFERENCE NUMBER

    */
    dataSs("REFNO ",&K5,&refno,&K8,&irc);
    if(irc == 0) goto S2320;
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2950;/* START A 'NEXT' SERIES */
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2950;/* START A 'NEXT SAVED' SERIES */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;/* START A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;/* START A 'RE-ENTER' SERIES */
    iSgref(&batch,&K0,&refno,&irc);
    if(irc != 0) goto S2310;
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    goto S2320;
S2310:
    errSs("Enter Source Document Reference#~",&K0,&irc);
    starSs("REFNO ",&K5,&irc);
    goto S2000;

S2320:

    /*
     ----- Check for Invalid Reference Number

    */
    if(icompr(&refno,"/ ",&K1) != 0) goto S2330;
    errSs("Invalid Reference Number~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;
S2330:

    /*
         If 'NEXT'ing thru screens, or saved screens, go to NEXT function

    */
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("S ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2950;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2950;

    /*
         SEE IF THIS SOURCE DOCUMENT (REFERENCE#) HAS ALREADY BEEN ENTERED

    */
    iSvref(&batch,&refno,&K0,&irc);
    if(irc == 9) goto S9000;

    if(nfunc != *(short*)fifstrgv("A ",2)) goto S2350;

    /*
         IF AN ITEM IS TO BE ADDED, IT SHOULD NOT BE ON FILE ALREADY

    */
    if(irc == 0) goto S2380;                 /* IT IS NOT ON FILE */
    errSs("This Reference# is already on file~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2350:

    /*
         IF AN ITEM IS TO BE CHANGED, DELETED, OR LISTED, IT SHOULD ALREADY  BE
            ON FILE

    */
    if(irc == 1 || irc == 2) goto S2370;     /* IT IS ON FILE */
    errSs("This Reference# is not on file in this Batch~",&K0,&irc);
    blnkSs("REFNO ",&K5,&irc);
    goto S2000;

S2370:

    /*
         DISPLAY PREVIOUSLY ENTERED SOURCE DOCUMENT

    */
    iSdisp(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    if(irc == 2) goto S2000;                 /* WRONG INPUT SCREEN FOR THIS DOCUMENT */
    /*
    /* DOCUMENT

         PUT CURRENT FUNCTION BACK ON SCREEN

    */
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

S2380:
    if(nfunc == *(short*)fifstrgv("A ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("C ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("D ",2)) goto S2900;

    /*
         'LIST' - LET THEM LOOK AT IT, THEN GO AGAIN...

    */
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);
    if(irc == 0) errSs("For viewing only.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2900:

    /*
         'DELETE' - CONFIRM THAT THIS ITEM IS TO BE DELETED

    */
    errSs("RETURN to DELETE this item.  Otherwise, enter ^~",&K0,&irc);
    bangSs(&irc);
    if(irc == 9) goto S9000;
    if(irc == 8) goto S1800;

    /*
         DELETE THE REFERENCED ITEM FROM THIS BATCH

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S1800;

S2950:

    /*
         Get and Display the 'NEXT' screen image

    */
    iSnext(&batch,&refno,&irc);
    if(irc <= 1) goto S2955;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S9000;/* END OF A 'RE-ENTER' SERIES */
    initSs(&K1,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    errSs("There are no more entries in this Batch.~",&K0,&irc);
    goto S2000;

S2955:
    if(nfunc == *(short*)fifstrgv("N ",2)) goto S2960;
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S2960;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S2960;
    if(irc != 1) goto S2950;                 /* NOT A SAVED SCREEN */
    goto S2960;

S2960:
    iSdisp(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    if(irc == 2) goto S2970;                 /* WRONG SCREEN UP TO DISPLAY THIS ITEM */
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);

    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

    /*
         IF A 'RE-ENTER' SERIES IS IN PROCESS, GO TO PROCESS THIS SCREEN

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3000;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3000;

    errSs("For VIEWING only.  RETURN for next screen~",&K0,&irc);
    goto S2000;

S2970:
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    goto S2000;

S3000:

    /*
         'ADD' or 'CHANGE' - PROCESS INPUT SCREEN

         Initialize variables that might have a value from a previous use of
            this program to process an "equipment rental invoice".

    */
    for(i=1; i==1 || i<=375; i++)
    {

        eqjobs[i-1] = 0.e0;
        eqphss[i-1] = 0.e0;
        accteq[i-1] = 0.e0;
        hrsbil[i-1] = 0.e0;
        adjhrs[i-1] = 0.e0;
        amntl[i-1] = 0.e0;
        adjams[i-1] = 0.e0;
        datuse[i-1] = 0.e0;
        fill(&neactv[i-1][0],&K5,"  ");
        fill(&nefunc[i-1][0],&K5,"  ");

    }

    /*
     ----------------------------------------------------------------------

      -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - -  -

         If 'CHANGE' (not 'ADD'), set flag to avoid re-reading from
         Outside Rental file unless required by other circumstances,
         such as the input dates being revised or the specific request
         to "refresh" the data read from Outside Rental.

    */
    if(nfunc != *(short*)fifstrgv("A ",2)) nsweor = 1;

    /*
         If this input screen includes the fields that allow applying an
            an invoice against previously accrued Outside Equipment Rental
            reserves, special consideration must be given to a "Change".
            When we call up a previously entered reference, we need to know
            the following dates as they were entered when the screen was
            last processed.  If all of the dates remain unchanged after
            this screen is read, then the outside rental file is NOT
            re-read.  This will preserve any editting of the data that
            had been performed up to the last time this reference was
            processed.

         Read Invoice Date as last processed

    */
    gmdySc(&K1,&nm1,&nd1,&ny1,&datinv,&ircidt);

    /*
         If MONTH1, DAY1, YEAR1 is not on screen get MONTH INVOICE, etc

    */
    if(ircidt == 1) mdySc("G ","INVOICE ",&K7,&datinv,&dum,&irc);

    if(datinv == 0.e0) datinv = effdat;

    /*
         Get range of dates to which this invoice generally applies
            as last entered.

    */
    mdySc("G ","PERIOD BEGIN",&K12,&perbgl,&K0,&irc);
    if(irc != 0) perbgl = 0.e0;
    mdySc("G ","PERIOD END",&K10,&perenl,&K0,&irc);
    if(irc != 0) perenl = datinv;

    /*
         Get range of dates for which this unit's rental data is to be displayed
            as last entered.

    */
    mdySc("G ","DISPLAY BEGIN",&K13,&disbgl,&K0,&irc);
    if(irc != 0) disbgl = perbgl;
    mdySc("G ","DISPLAY END",&K11,&disenl,&K0,&irc);
    if(irc != 0) disenl = perenl;

    /*
         Get the amount for each line of distribution as last entered.

    */
    if(xbb_nsetSb == 0) goto S3020;
    for(i=1; i==1 || i<=xbb_nsetSb; i++)
    {
        xbb_jsetSb = i;
        dataSs("AMOUNT",&K6,&amntl[i-1],&K0,&irc);
    }
S3020:

    /*
      -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  - -  -

    */
    backed = FALSE;
    protSs("FUNC",&K4,&K1,&K0,&irc);
    protSs("REFNO ",&K5,&K1,&K0,&irc);
    doutSs("FUNC",&K4,&nfunc,&K1,&irc);
    doutSs("REFNO ",&K5,&refno,&K8,&irc);
    idsflg = idsmod;

    /*
         AUTO READ SCREEN IF A 'RE-ENTER' IS IN PROCESS

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3060;
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S3060;

    errSs("Enter Purchase data.~",&K0,&irc);
    posSs("VCNO",&K4,&irc);
    idsflg = idsmod;

S3050:
    if(!backed) goto S3055;

    /*
    ------Make sure any 'D' records from the previous attempt are removed

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S8200;

S3055:
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* SAVE THIS SCREEN IF RE-ENTERING */
    readSs(&K2,&irc);
    if(irc == 0) goto S3100;
    if(irc == 4) goto S8050;
    if(irc == 8) goto S1800;
    goto S9000;

S3060:

    /*
     ----- Verify Batch Processing

    */
    if(nswvb == 0) goto S3080;               /* This is not a Verify Batch */

    /*
         Output vendor name

    */
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    if(irc != 0) goto S3061;

    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);
    if(irc != 0) goto S3061;

    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

S3061:

    /*
     ----- Output the Verify Batch Message

    */
    posSs("PARK",&K4,&irc);
    errSs("Verify...  RETURN if correct, or '^' to revise~",&K0,&irc);
    bangSs(&irc);
    if(irc == 0) goto S3062;                 /* verified */
    if(irc == 8) goto S3075;                 /* to be revised */
    goto S9000;

S3062:

    /*
     ----- Verify ok - Delete entry

     ----- Get the information from the screen for releasing the 'Hold' on
             the invoice

    */
    readSs(&K11,&irc);
    if(irc != 0) goto S3074;

    dataSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    dataSs("INVOICE ",&K7,&invoic,&K8,&irc);

    if(icompr(&trtype,&typlst,&K8) == 0) goto S3070;
    typlst = trtype;

    /*
     ----- Look for Genl Info Switch for Holding all Invoices

    */
    fill(xhold_hScode,&K4,"  ");

    WRITE(INTERNAL,keygi,27,FMT,F3064,1,REAL8,trtype,0);
    gnliSc("READ",keygi,&K27,inhld,&K76,&irc);
    if(irc != 0) gnliSc("READ","HOLD ALL INVOICES",&K17,inhld,&K76,&irc);
    if(irc != 0) goto S3065;

    /*
     ----- Get the Hold Code from the data buffer if not blank

    */
    getrsn(inhld,xhold_hScode,xhold_hSresn,&irc);
    if(irc > 6) mvbyt("ALL     ",xhold_hScode,&K8);

S3065:
    WRITE(INTERNAL,keygi,33,FMT,F3067,1,REAL8,trtype,0);
    gnliSc("READ",keygi,&K33,inhld,&K76,&irc);
    if(irc != 0) gnliSc("READ","HOLD ALL TRADE INVOICES",&K23,inhld,&K76,&irc);
    if(irc != 0) goto S3070;

    /*
     ----- Get the Hold Code from the data buffer in not blank

    */
    getrsn(inhld,xhold_hScode,xhold_hSresn,&irc);
    if(irc > 6) mvbyt("TRADE   ",xhold_hScode,&K8);

S3070:
    xhold_hSfunc = *(short*)fifstrgv("R ",2);
    mvbyt(xc_cScoid,xhold_hScoid,&K4);
    mvbyt(&trtype,xhold_hStype,&K8);
    xhold_hSvcno = vcno;
    mvbyt(&invoic,xhold_hSinvc,&K8);

    for(i=1; i==1 || i<=xbb_lsetSb; i++)
    {
        xbb_jsetSb = i;
        dataSs(&fldnam[2],&K8,&vbjob,&K0,&irc);
        if(irc != 0) goto S3074;
        if(vbjob == fifdint(vbjob)) vbjob = combjp(&vbjob,&R4);
        spltjp(&vbjob,&xhold_hSjob,&xhold_hSphs,&irc);
        invhld(&irc);
    }

S3074:
    iSdlet(&batch,&refno,&irc);
    goto S1800;

S3075:
    errSs("Revise as necessary.  Then, RETURN to enter.~",&K0,&irc);

    /*
     ----- Read revised version of reference from screen

    */
    readSs(&K2,&irc);
    if(irc == 0) goto S3100;
    if(irc == 8) goto S1800;
    goto S9000;

S3080:

    /*
     ----- Read the information from the screen

    */
    readSs(&K11,&irc);
    if(irc == 4) goto S8000;
    goto S3100;

S3100:

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S3120;

    for(i=1,D6=(D6=(7-i+1))>0?D6:1; D6>0; D6--,i+=1)
    {
        if(jrnkey[i-1] == 0) goto S3110;
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S3110;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S3055;
S3110:;
    }

    goto S3125;

S3120:

    effdat = effbat;

S3125:

    xbilcom_bSdate = effdat;

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    /*
         GET DUP SWITCH (YES or NO)

    */
    dataSs("DUP ",&K3,&ndup,&K1,&irc);
    if(ndup == *(short*)fifstrgv("N ",2) || ndup == *(short*)fifstrgv("Y ",2)) goto S3127;
    errSs("Must be 'Y' or 'N'~",&K0,&irc);
    starSs("DUP ",&K3,&irc);
    goto S3050;
S3127:

    /*
         GET TRANSACTION TYPE

    */
    dataSs("TRANSACTION TYPE",&K16,&trtype,&K8,&irc);
    if(irc != 4) goto S3130;                 /* EMPTY FIELD */
    errSs("Enter Transaction Type~",&K0,&irc);
    starSs("TRANSACTION TYPE",&K16,&irc);
    goto S3050;

S3130:

    /*
     --- VALIDATE TRANSACTION TYPE

    */
    if(icompr(&trtype,lastyp,&K8) == 0) goto S3150;
    ttypSc(&trtype,&nbank,&irc);
    if(irc == 0) goto S3140;
    errSs("Invalid Transaction Type~",&K0,&irc);
    blnkSs("TRANSACTION TYPE",&K16,&irc);
    goto S3050;

S3140:
    mvwrd(&trtype,lastyp,&K4);
    protSs("TRANSACTION TYPE",&K16,&K1,&K0,&irc);

S3150:

    /*
     --- GET ACCOUNT NUMBERS

    */
    tracSc(&trtype,accts,&irc);
    if(irc != 0) goto S3175;

    apgl = accts[0];
    dscern = accts[6];
    vatcr = accts[8];
    vatdr = accts[9];

    if(apgl < 0.001e0) goto S3175;
    if(dscern < 0.001e0) goto S3175;

    if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vatcr < 0.001e0) goto
      S3175;

    if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vatdr < 0.001e0) goto
      S3175;

    goto S3210;

S3175:
    ferrSc(&K9999,&K10,"Use TR ACCOUNT to establish ledger accounts for A/P~",&K0);

S3210:

    /*
         Get any overide account numbers from this screen

    */
    ovracc("TRADE PAY ACCOUNT     ",&K22,&apgl,&irc);
    if(irc > 4) goto S3050;

    ovracc("DISCOUNT EARN ACCOUNT ",&K22,&dscern,&irc);
    if(irc > 4) goto S3050;

    ovracc("VAT INPUT ACCOUNT     ",&K22,&vatcr,&irc);
    if(irc > 4) goto S3050;

    ovracc("VAT OUTPUT ACCOUNT    ",&K22,&vatdr,&irc);
    if(irc > 4) goto S3050;

    /*
     --- GET VENDOR NUMBER

    */
    dataSs("VCNO",&K4,&vcno,&K0,&irc);
    if(irc == 0) goto S3220;
    errSs("Enter vendor number~",&K0,&irc);
    starSs("VCNO",&K4,&irc);
    goto S3050;

S3220:

    /*
     ---- CHECK FOR VENDOR IN V/C ROSTER

    */
    vinfSc(&vcno,"    ","NAME",&K4,ivname,&K30,&K0,&K0,&irc);

    if(irc == 0) goto S3230;
    if(irc == 7) goto S3225;
    errSc(&K20,&irc,"FILE: V/C$INFO   PROGRAM: TR PURCHASE~",&K0,&irc);
    bangSs(&irc);
    goto S9000;
S3225:
    errSs("Vendor not in Vendor/Client roster.~",&K0,&irc);
    blnkSs("VCNO",&K4,&irc);
    goto S3050;
S3230:
    vinfSc(&vcno,"    ","FOREIGN ",&K7,&iforgn,&K2,&K0,&K0,&irc);
    fordom = 1;                              /* Domestic Vendor */
    if(iforgn == *(short*)fifstrgv("X ",2)) fordom = 2;/* Foriegn Vendor */

    soutSs("P ",&K3,ivname,&K30,&irc);
    namdSs("P ","V/C$INFO",&K8,"    ",&irc);

    /*
     --- GET CLIENT NUMBER (optional, for automatic billing)

    */
    dataSs("CLIENT",&K6,&client,&K0,&irc);
    if(irc != 0) goto S3270;

    /*
     ---- CHECK FOR CLIENT IN V/C ROSTER

    */
    vinfSc(&client,"    ","NAME",&K4,ivname,&K1,&K0,&K0,&irc);
    if(irc == 0) goto S3270;
    if(irc == 7) goto S3265;
    errSc(&K20,&irc,"Looking for CLIENT in V/C$INFO~",&K0,&irc);
    bangSs(&irc);
    goto S9000;

S3265:
    errSs("Client not in Vendor/Client roster.~",&K0,&irc);
    blnkSs("CLIENT",&K6,&irc);
    goto S3050;

S3270:

    /*
    ------Get the NON-BILLABLE field from the screen if it is there

    */
    dataSs("NON-BILLABLE",&K12,&nonbil,&K2,&ircnon);

    /*
     ----- Get the Invoice Number.  If it is blank and the Configuration
           Parameter 'INVOICE FROM REFERENCE' is in place then default
           Invoice to Reference.

    */
    dataSs("INVOICE ",&K7,&invoic,&K8,&irc);
    if(irc == 0) goto S3320;
    if(irc == 1) goto S3330;
    if(!invref) goto S3310;
    mvwrd(&refno,&invoic,&K4);
    doutSs("INVOICE ",&K7,&invoic,&K8,&irc);
    goto S3320;

S3310:
    errSs("Enter invoice number~",&K0,&irc);
    starSs("INVOICE ",&K7,&irc);
    goto S3050;
S3320:

    /*
         Get invoice information from 'Invoice Tracking File', if possible
         1st parameter is the commitment type (P, S or C)

    */
    linvSc("P ",&vcno,&invoic,&irc);
    if(irc == 7) goto S3050;                 /* not found, but required for this vendor */
S3330:

    /*
         Read Commitment ID

    */
    dataSs("PO",&K2,&po,&K8,&irc);
    if(irc == 0 || irc == 1) goto S3420;
    errSs("Enter Purchase Order Number~",&K0,&irc);
    starSs("PO",&K2,&irc);
    goto S3050;
S3420:

    /*
     --- GET INVOICE DATE -  INVOICE DATE = EFFECTIVE DATE IF NOT ENTERED

    */
    gmdySc(&K1,&nm1,&nd1,&ny1,&datinv,&ircidt);

    /*
         If MONTH1, DAY1, YEAR1 is not on screen get MONTH INVOICE, etc

    */
    if(ircidt == 1) mdySc("G ","INVOICE ",&K7,&datinv,&dum,&irc);

    if(datinv > 0.e0 && irc == 0) goto S3500;
    if(datinv > 0.e0 && irc != 0) goto S3490;
    if(datinv == 0.e0) datinv = effdat;
    goto S3500;

S3490:
    errSs("Invalid Invoice Date~",&K0,&irc);

    blnkSs("YEAR1 ",&K5,&irc);
    blnkSs("DAY1",&K4,&irc);
    blnkSs("MONTH1",&K6,&irc);
    blnkSs("YEAR INVOICE",&K12,&irc);
    blnkSs("DAY INVOICE",&K11,&irc);
    blnkSs("MONTH INVOICE",&K13,&irc);
    goto S3050;

S3500:

    /*
     --- GET DUE DATE

    */
    gmdySc(&K2,&nm2,&nd2,&ny2,&datdue,&ircddt);

    /*
         If MONTH2, DAY2, YEAR2 is not on screen get MONTH DUE, etc

    */
    if(ircddt == 1) mdySc("G ","DUE ",&K3,&datdue,&dum,&irc);

    sdatdu = datdue;                         /* SAVE DATE DUE FOR NEXT SCREEN SL 1/6/89 */

    if(datdue > 0.e0 && irc == 0) goto S3640;
    if(datdue > 0.e0 && irc != 0) goto S3530;

    dueSc(&vcno,&datinv,&datdue,&irc);
    if(irc == 0) goto S3640;
    if(irc == 1) goto S9100;

S3530:
    if(datdue == 0.e0) errSs("Enter Due Date~",&K0,&irc);
    if(datdue > 0.e0) errSs("Invalid Due Date~",&K0,&irc);
    blnkSs("YEAR2 ",&K5,&irc);
    blnkSs("DAY2",&K4,&irc);
    blnkSs("MONTH2",&K6,&irc);
    blnkSs("YEAR DUE",&K8,&irc);
    blnkSs("DAY DUE ",&K7,&irc);
    blnkSs("MONTH DUE",&K9,&irc);
    goto S3050;

S3640:

    /*
     ----- Check Due Date vs Open Thru Date for the Purchase Journal

    */
    ckdue(&datdue,&irc);
    if(irc != 0) goto S3050;

    /*
     --- GET PPS APPLICABLE FLAG

    */
    if(iswpps == 0) goto S3650;              /*  NO PPS FOR THIS SCREEN */
    ppstax(&vcno,&effdat,&pps1,icert,&irc);
    if(irc != 0) pps1 = -1.e0;

    pps2 = pps1;                             /* INIT INPUT RATE TO STORED RATE */

    if(nfunc == *(short*)fifstrgv("A ",2)) goto S3642;

    /*
     --- IF CHANGE SHOW RATE FROM V/C$INFO UNLESS IT HAS BEEN OVERRIDEN
          TO "N"OT APPLICABLE

    */
    dataSs("PPS APPLICABLE",&K14,&ppsout[0],&K4,&irc);
    if(irc != 0 || ppsout[0] == *(double*)fifstrgv("N       ",8)) pps2 = -1.e0;

S3642:

    /*
     --- OUTPUT PPS RATE (OR "N"OT APPLICABLE) TO SCREEN

    */
    if(pps2 < 0.e0) ppsout[0] = *(double*)fifstrgv("N       ",8);
    if(pps2 >= 0.e0) WRITE(INTERNAL,ppsout,5,FMT,F3645,1,REAL8,pps2,0);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K5,&irc);

S3650:

    /*
     --- GET INVOICE TOTAL

    */
    dataSs("TOTAL INVOICE",&K13,&cramnt,&K0,&irc);
    if(irc == 0) goto S3720;
    errSs("Enter invoice amount.~",&K0,&irc);
    blnkSs("TOTAL INVOICE",&K13,&irc);
    goto S3050;
S3720:

    /*
         IDSFLG = IDSMOD

    */
    dataSs("DISCOUNT",&K8,adisc,&K8,&irc);
    disc = 0.e0;
    if(irc == 0) goto S3722;
    vinfSc(&vcno,"    ","DISCOUNT",&K8,&disc,&K0,&K0,&K0,&irc);
    if(disc == 0.e0) goto S3722;
    doutSs("DISCOUNT",&K8,&disc,&K0,&irc);
    idsflg = 1;
S3722:
    lstrSa("$ ",1,adisc,8,&ifc,&ilc);
    if(ifc == 0) goto S3730;
    idsflg = 0;
    msubSa("  ",1,1,1,adisc,8,ifc,ifc);
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3725,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3730:
    lstrSa("% ",1,adisc,8,&ifc,&ilc);
    if(ifc == 0) goto S3780;
    idsflg = 1;
    msubSa("  ",1,1,1,adisc,8,ifc,ilc);
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3725,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3780:
    if(adisc[0] == *(double*)fifstrgv("        ",8)) goto S3800;
    if(READ(INTERNAL,adisc,8,IOSTAT,NULL,1,FMT,F3725,1,REAL8,&disc,0)) goto S3790;
    goto S3800;

S3790:
    errSs("Re-enter discount as numeric only.~",&K0,&irc);
    goto S3050;

S3800:
    if(idsflg == 0) soutSs("P ",&K4,"Discount$",&K9,&irc);
    if(idsflg == 0) soutSs("P ",&K5,"Discount%",&K9,&irc);
    if(idsflg == 1) soutSs("P ",&K4,"Discount%",&K9,&irc);
    if(idsflg == 1) soutSs("P ",&K5,"Discount$",&K9,&irc);

    /*
         DETERMINE PRO-RATA DISCOUNT ALLOCATION RATIO

    */
    dscfac = 0.e0;

    /*
         IF ( NFUNC .EQ. 'C ' ) IDSFLG = 0       DISC IS ALREADY $$$$
    */
    if(idsflg == 0) goto S3826;              /* IF DISCOUNT NOT %%%% */
    /*
                               IF DISCOUNT A %, CONVERT TO AN AMOUNT
    */
    dscfac = disc*0.01e0;
    disc = dscfac*cramnt;
    /*
         DDISC = DSCFAC * 100D0
    */
    WRITE(INTERNAL,xc_cSmess,12,FMT,F3825,1,REAL8,disc,0);
    /*
    3825  FORMAT ( B'ZZ#.##', '% Disc' )
    */
    soutSs("P ",&K6,xc_cSmess,&K10,&irc);
    goto S3833;

S3826:

    /*
     ---- Display $ discount from % discount

     ----- CODE MODIFIED HERE PER WORK ORDER KGC-0020
           DISCOUNT RATE LIMIT RAISED TO 30% ***DEI***

    */
    if(cramnt != 0) dscfac = disc/cramnt;    /* RATIO FOR DISTRIBUTING DISCOUNT */
    ddisc = dscfac*100.e0;
    WRITE(INTERNAL,xc_cSmess,12,FMT,F3831,1,REAL8,ddisc,0);
    soutSs("P ",&K6,xc_cSmess,&K12,&irc);

S3833:
    if(iameq(&dscfac,&R7) < 1) goto S3835;

    errSs("Discount Rate cannot be greater than 30%~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;

S3835:

    /*
     ----- CODE ADDED HERE IN RESPONSE TO WORK ORDER KGC-0020
           TEST IF DISCOUNT IS LESS THAN 10 %, AND IF >= 10 %
           PROCESS AS A 'TELL ME TWICE' CONFIRM TO FINALIZE.

     ----- IF THE DISCOUNT IS < 10 % - DISREGARD AND PROCESS AS BEFORE.

    */
    if(iameq(&dscfac,&R8) < 1) goto S3845;

    /*
     ----- DISCOUNT IS >=10% AND <=30% - TEST TO SEE IF THIS IS
           THE CONFIRMING (SECOND) PASS THROUGH - IF SO - CHECK THE
           DATA (DISCOUNTS AND INVOICE AMOUNTS) FOR A MATCH.

     ----- TEST THE FUNCTION INDICATOR - IF R - DO NOT
           TEST FOR THE 10% SOLUTION...

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S3845;
    if(iflag == 1) goto S3840;               /* SECOND PASS THROUGH */

    /*
     ----- FIRST TIME THROUGH - SET PROCESSING INFORMATION

    */
    iflag = 1;
    olddsc = dscfac;
    craold = cramnt;
    errSs("Discount is greater than 10% - RETURN to confirm~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;                              /* RETURN TO READ$S TO RE-READ SCREEN INPUTS */

S3840:

    /*
     ----- SECOND TIME THROUGH FOR DISCOUNT >= 10%
           TEST 'SAMENESS' OF DISCOUNTS AND INVOICE AMOUNTS
           IF SAME - PROCESS AS BEFORE - OTHERWISE RESET THE
           'OLD' TEMPORARY VARIABLES AND RE-REQUEST CONFIRMATION.

    */
    if(iameq(&olddsc,&dscfac) == 0 && iameq(&craold,&cramnt) == 0) goto S3845;

    /*
     ----- RESET THE TEMPORARY STORE VARIABLES AND REREAD SCREEN

    */
    iflag = 1;                               /* KEEP FLAG SET TO REQUEST CONFIRMATION OF DATA */
    olddsc = dscfac;
    craold = cramnt;
    errSs("Discount is greater than 10% - RETURN to confirm~",&K0,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    goto S3050;                              /* RETURN TO READ$S TO RE-READ SCREEN INPUTS */

S3845:

    /*
     --- GET TOTAL VAT AMOUNT AND PRO-RATA VAT RATIO

    */
    vatpct = 0.e0;
    iexvat = 0;
    vinfSc(&vcno,"    ","VAT EXEMPTED",&K12,&idum,&K1,&K0,&K0,&irc);
    if(irc == 0 && idum == *(short*)fifstrgv("Y ",2)) iexvat = 1;

    vatpct = vatrt/100.e0;
    dataSs("TOTAL VAT",&K9,&vattot,&K0,&irc);
    if(irc != 0) goto S3850;

    dataSs("VAT TYPE",&K8,&vatype,&K2,&ircvat);
    if(ircvat != 0) goto S3847;
    if(vatype == *(short*)fifstrgv("F ",2) || vatype == *(short*)fifstrgv("G ",2) || vatype == *(short*)fifstrgv("S ",2)
      ) goto S3847;
    blnkSs("VAT TYPE",&K8,&irc);
    errSs("Invalid Vat Type, Enter F or G or S ~",&K0,&irc);
    goto S3050;

S3847:
    if(ircvat == 0) vatSac(&trtype,vatact,vatdsc,despnt,&irc);
    accpay = 2;                              /* Payable */
    if(vatype == *(short*)fifstrgv("F ",2)) ifgs = 1;/* Fixed Assets */
    if(vatype == *(short*)fifstrgv("G ",2)) ifgs = 2;/* Goods */
    if(vatype == *(short*)fifstrgv("S ",2)) ifgs = 3;/* Services */
    if(vatype == *(short*)fifstrgv("S ",2)) accpay = 1;/* Accrued */

    divisr = cramnt-vattot;
    if(divisr != 0.e0) vatpct = vattot/divisr;/* DO NOT DIVIDE BY ZERO */

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S3860;
    if(cramnt != 0.e0) vatpct = vattot/cramnt;
    goto S3860;

S3850:
    if(iexvat == 1) goto S3860;
    vattot = 0.e0;
    if(vatpct != -1.e0) vattot = cramnt-cramnt/(1.e0+vatpct);/* DO NOT DIVIDE BY ZERO */
    vattot = rndoff(&vattot,&K2);
    doutSs("TOTAL VAT",&K9,&vattot,&N1,&irc);

S3860:
    if(idsflg == 0) goto S3865;
    disc = (cramnt-vattot)*dscfac;
    /*
         CALL DOUT$S ( 'DISCOUNT', 8, DISC, -1, IRC )

    */
S3865:
    divsor = cramnt-vattot;
    if(idsflg == 0 && divsor != 0.0e0) dscfac = disc/divsor;

    /*
         IDSFLG = 0

     --- IF NATION CODE IS "NZ" or "AU" THEN RE-CALCULATE DISCOUNT FACTOR
         USING THE VALUE ADDED TAX AMOUNT

    */
    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S3870;

    dscfac = 0.e0;
    divisr = cramnt-disc-vattot;
    if(divisr != 0.e0) dscfac = disc/divisr; /* DO NOT DIVIDE BY ZERO */

S3870:
    dataSs("TOTAL SALES TAX",&K15,&stxtot,&K0,&irctax);
    for(i=1; i==1 || i<=xbb_lsetSb; i++)
    {
        icaltx[i-1] = -1;
    }
    taxemt = 0.e0;

    dataSs("TAX CODE",&K8,&codtax,&K8,&irc);
    if(irc == 0) goto S3890;
    codtax = *(double*)fifstrgv("        ",8);
    goto S3900;

S3890:
    iopt = 2;
    staxSc(&iopt,&codtax,&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

    if(irc == 0) goto S3895;
    blnkSs("TAX CODE",&K8,&irc);
    errSs("Invalid Sales Tax Code~",&K0,&irc);
    goto S3050;

S3895:
    doutSs("SALES TAX LOCATION",&K18,loctax,&K40,&irc);
    doutSs("SALES TAX RATE",&K14,&taxrat,&N1,&irc);

S3900:

    dataSs("MISC",&K4,&rmisc,&K0,&irc);
    if(irc == 0) goto S3910;
    rmisc = 0;

S3910:
    ttaxbl = 0.0e0;
    for(i=1; i==1 || i<=xbb_lsetSb; i++)
    {
        xbb_jsetSb = i;
        dataSs("AMOUNT",&K6,&amnts[i-1],&K0,&irc);
        dataSs("TAXCOD",&K6,&taxcod[i-1],&K8,&irc);
        if(irc != 0) mvwrd(&codtax,&taxcod[i-1],&K4);
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S3925;
        ttaxbl = ttaxbl+amnts[i-1];
S3925:;
    }

    dataSs("AMOUNT SUBJECT TO TAX",&K21,&sbtotx,&K0,&ircsub);
    if(ircsub != 0) sbtotx = ttaxbl;
    if(sbtotx >= 0.0e0 && ttaxbl >= 0.0e0) goto S3930;
    if(sbtotx <= 0.0e0 && ttaxbl <= 0.0e0) goto S3930;
    errSs("Total Taxable and Amount Subject to Tax must have same sign~",&K0,&irc);
    starSs("AMOUNT SUBJECT TO TAX",&K21,&irc);
    goto S3050;

S3930:
    if(iameq((T9= fabs(sbtotx),&T9),(T10= fabs(ttaxbl),&T10)) <= 0) goto S3940;
    errSs("Amount Subject to Tax may be more than Total Taxable~",&K0,&irc);
    starSs("AMOUNT SUBJECT TO TAX",&K21,&irc);
    goto S3050;

S3940:
    sbrtio = 1.0e0;
    if(ttaxbl != 0.0e0) sbrtio = sbtotx/ttaxbl;

    /*
     --- GET CLOSE COMMITMENT FLAG

    */
    nswcls = 0;
    dataSs("FINAL COMMITMENT PAYMENT",&K24,&idum,&K2,&irc);
    if(irc == 0) nswcls = 1;

    /*
     --- CHECK FOR COMMIT AS EXPENDED FIELD

    */
    nswcxp = 0;
    dataSs("COMMIT AS EXPENDED",&K18,&idum,&K2,&irc);
    if(irc == 0) nswcxp = 1;

    /*
     --- CHECK TO INVALID COMBINATION OF ENTRIES

    */
    if(icompr(&po,"-       ",&K8) == 0 && nswcls+nswcxp > 0) goto S3950;
    if(nswcls+nswcxp > 1) goto S3975;
    goto S4000;

S3950:

    /*
     ---   PO = '-       '

    */
    blnkSs("FINAL COMMITMENT PAYMENT",&K24,&irc);
    blnkSs("COMMIT AS EXPENDED",&K18,&irc);
    errSs("Do not mark Final Payment or Commit as Expended;PO# indicates uncommited item~",&K0,&irc);
    goto S3050;

S3975:

    /*
     --- CAN NOT ENTER BOTH FINAL PAYMENT AND COMMIT AS EXPENDED

    */
    blnkSs("FINAL COMMITMENT PAYMENT",&K24,&irc);
    blnkSs("COMMIT AS EXPENDED",&K18,&irc);
    errSs("Do not mark both Final Payment and Commit as Expended ~",&K0,&irc);
    goto S3050;

S4000:
    crjacc = apgl;                           /* LOAD DEFAULT PAYABLES ACCOUNT */

    /*
    ------See if an ALLOCATION FORMULA has been entered for use
          in automaticaly distributing this invoice.

    */
    dataSs("ALLOCATION FORMULA",&K18,&alloc,&K8,&irc);
    if(irc != 0) goto S4050;

    /*
    -------See if data is already on the screen, if so do not output distribution

    */
    for(j=1; j==1 || j<=xbb_nsetSb; j++)
    {

        xbb_jsetSb = j;

        /*
             Get amount to be applied to invoice from this distribution line.
                If there is an amount, skip past looking up allocation formula.

        */
        dataSs(&fldnam[0],&K8,&ramnt,&K0,&irc);
        if(irc == 0) goto S4050;

    }

    /*
         There a no amounts entered in the lines of distribution.  Look up
            allocation formula information necessary to distribute invoice
            amount over appropriate jobs, phases, activities, and accounts.

    */
    mflag = FLSNXT+FLSUKY;
    ramnt = cramnt;
    icnt = 0;

    WRITE(INTERNAL,keyalc,44,FMT,F4010,1,DO,2,INT2,xc_cScoid,REAL8,alloc,0);

    mvwrd(keyalc,keysv,&K22);

S4020:

    ioSf("FIND","MISC$INFO",&K9,"TRAL",keyalc,&K0,&mflag,&K0,&irc);

    if(irc == 7) goto S4030;

    if(icompr(keyalc,keysv,&K16) != 0) goto S4030;

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","PERCENT ",&K7,&perc,&K0,&K0,&K0,&irc);

    if(iameq(&perc,&R11) == 0) goto S4020;

    icnt = icnt+1;
    xbb_jsetSb = icnt;

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","JOB ",&K3,&rj,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","PHASE ",&K5,&rp,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","ACTIVITY",&K8,iact,&K10,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","ACCOUNT ",&K7,&ac,&K0,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","SALES TAX CODE",&K14,&stcode,&K8,&K0,&K0,&irc);

    gdatSf("GET ","MISC$INFO",&K9,"TRAL","MEMO",&K4,imem,&K16,&K0,&K0,&irc);

    rjp = combjp(&rj,&rp);
    doutSs(&fldnam[2],&K7,&rjp,&N1,&irc);

    doutSs(&fldnam[3],&K7,iact,&K10,&irc);

    doutSs(&fldnam[1],&K8,&ac,&N1,&irc);

    doutSs("TAXCOD",&K6,&stcode,&K8,&irc);

    doutSs(&fldnam[4],&K6,imem,&K16,&irc);

    amt = (cramnt-stxtot)*perc/100.e0;
    roffSc(&amt,&R12,&irc);
    doutSs(&fldnam[0],&K8,&amt,&N1,&irc);

    ramnt = ramnt-amt;

    goto S4020;

S4030:
    if(icnt > 0) goto S4035;
    errSs("Invalid Allocation Formula.~",&K0,&irc);
    blnkSs("ALLOCATION FORMULA",&K18,&irc);
    goto S3050;

S4035:
    if(iameq(&ramnt,&R11) == 0) goto S4040;

    dataSs(&fldnam[0],&K8,&amt,&K0,&irc);

    amt = amt+ramnt;
    doutSs(&fldnam[0],&K8,&amt,&N1,&irc);

S4040:

    goto S4900;

S4050:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
         Determine whether to load input screen with equipment rental data

         See if an outside rental equipment unit number has been input
            to which this invoice is to be applied

    */
    dataSs("EQ UNIT ",&K7,nunit,&K10,&irc);
    if(irc != 0) goto S4900;                 /* no unit number on input screen */

    /*
     -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -
         INITIALIZE RENTAL INVOICE PARAMETERS

    */
    if(inirnt == 1) goto S4260;

    /*
         Get DEFAULT equipment cost center job and phase number

    */
    eqccSc(&eqdccj,&eqdccp,&irc);
    if(irc == 0) goto S4115;
    errSs("Default Equipment Cost Center must be configured~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4115:

    /*
         Determine Equipment Repair Code Delimiter

    */
    gnliSc("READ","REPAIR CODE DELIMITER",&K21,&nercdl,&K2,&irc);
    if(irc == 0) goto S4130;
    errSs("Repair Code Delimiter must be set up~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4130:

    /*
         Determine Equipment Repair Code for 'OUTSIDE RENTAL' expense

    */
    gnliSc("READ","OUTSIDE RENTAL REPAIR CODE",&K26,&neorrc,&K2,&irc);
    if(irc == 0) goto S4145;
    errSs("OUTSIDE RENTAL REPAIR CODE must be set up~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4145:

    /*
         Determine OUTSIDE RENTAL DEBIT ADDER

    */
    gnliSc("READ","OUTSIDE RENTAL DEBIT ADDER",&K26,xc_cSmess,&K10,&irc);
    if(irc == 0) goto S4160;
    errSs("OUTSIDE RENTAL DEBIT ADDER must be set up~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4160:
    if(READ(INTERNAL,xc_cSmess,10,IOSTAT,NULL,1,FMT,F4225,1,REAL8,&eqorad,0)) goto S4175;
    goto S4190;
S4175:
    errSs("Invalid OUTSIDE RENTAL DEBIT ADDER (see SA GENL INFO)~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4190:

    /*
         Determine OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT

    */
    gnliSc("READ","OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT",&K36,xc_cSmess,&K10,&irc);
    if(irc == 0) goto S4215;
    errSs("OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT must be set up~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4215:
    if(READ(INTERNAL,xc_cSmess,10,IOSTAT,NULL,1,FMT,F4225,1,REAL8,&ordjsv,0)) goto S4230;
    goto S4245;
S4230:
    errSs("Invalid OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4245:

    inirnt = 1;                              /* initialization of rental parameters complete */

S4260:

    /*
     -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -   -

         Get and display description of this unit from EQ$MASTER

    */
    uinfSc(nunit,"    ","DESCRIPTION",&K11,xc_cSmess,&K50,&K0,&K0,&irc);
    if(irc == 0) goto S4275;
    errSs("Equipment Unit not found in EQ UNIT INFO~",&K0,&irc);
    blnkSs("EQ UNIT ",&K7,&irc);
    goto S3050;
S4275:
    doutSs("EQ UNIT DESCRIPTION",&K19,xc_cSmess,&K50,&irc);

    /*
         See if there is an "Outside Rental Adjustment" amount that is
            to be allocated pro-rata over distribution of invoice.
            If yes, this amount will be distributed pro-rata based on
            the equipment hours this invoice is determined to be paying.
            The allocated adjustment amount will be added to any adjustment
            amount entered directly on a line of distribution ADJAMS(I).

    */
    dataSs("AUTO ALLOCATE ADJUSTMENT",&K24,&autadj,&K0,&irc);
    dataSs("AUTO ALLOCATE ADJUSTMENT HR",&K27,&atadhr,&K0,&irc);

    /*
         Get range of dates to which this invoice generally applies

    */
    mdySc("G ","PERIOD BEGIN",&K12,&perbeg,&K0,&irc);
    if(irc != 0) perbeg = 0.e0;
    mdySc("G ","PERIOD END",&K10,&perend,&K0,&irc);
    if(irc != 0) perend = datinv;

    /*
         Get range of dates for which this unit's rental data is to be displayed

    */
    mdySc("G ","DISPLAY BEGIN",&K13,&disbeg,&K0,&irc);
    if(irc != 0) disbeg = perbeg;
    mdySc("G ","DISPLAY END",&K11,&disend,&K0,&irc);
    if(irc != 0) disend = perend;

    /*
         If any of the dates used to select "outside rental" data have
            been changed, refresh the display

    */
    if(perbeg != perbgl) goto S4300;
    if(perend != perenl) goto S4300;
    if(disbeg != disbgl) goto S4300;
    if(disend != disenl) goto S4300;

    /*
         See if there has been an explicit directive to refresh the display

    */
    dataSs("REFRESH DISPLAY",&K15,&nrefsh,&K1,&irc);
    doutSs("REFRESH DISPLAY",&K15,"  ",&K1,&irc);/* always erase  */
    /*
    /*  box
    */
    if(icompr(&nrefsh,"  ",&K1) != 0) goto S4300;/* refresh is non-blank */
    if(nsweor == 1) goto S4550;              /* outside rental already read for this */
    /*
    /* for this
                                             reference
    */
S4300:
    nsweor = 1;                              /* set flag = outside rental information has been read */
    /*
    /* read

         Save the dates used to select "outside rental" data

    */
    perbgl = perbeg;
    perenl = perend;
    disbgl = disbeg;
    disenl = disend;

    /*
         See if "ALL" accruals are to be displayed.  This would display
            accruals that fall within the display date range but would
            normally not be displayed because they have been fully paid

    */
    dataSs("DISPLAY ALL",&K11,&nswall,&K1,&irc);

    /*
         Erase the entire scrolling input area

    */
    ersSs("PIF ",&K3,&irc);                  /* erase to end of board */

    xbb_jsetSb = 0;                          /* initialize set pointer */

    /*
         Find and display rental data for this unit where the date of reported
            usage falls within the display range of dates.  Since the supplier
            might have billed for this usage on more than one invoice, it is
            necessary to look for multiple records for the same unit, day,
            job, phase, activity, function, and accrual account and to
            accumulate the data from such multiple records together to be
            displayed as one set of information.

    */
    fill(keyeor,&K52,"  ");
    hrsacc = 0.e0;                           /* hours accrued */
    rntacc = 0.e0;                           /* rental accrued */
    hrsbld = 0.e0;                           /* hours billed */
    rntbld = 0.e0;                           /* rental billed */

    nswend = 0;                              /* not end of file */

    WRITE(INTERNAL,xpScom1_keynxt,100,FMT,F4320,1,DO,2,INT2,xc_cScoid,DO,5,INT2,nunit,REAL8,disbeg,0);

    mflag = FLSNXT+FLSRET+FLSUKY;

S4345:
    ioSf("FIND","EQ$OUTSIDE$RENTAL",&K17,"    ",xpScom1_keynxt,&K0,&mflag,&K0,&irc);
    if(irc == 0) goto S4385;
    if(irc == 7) goto S4360;                 /* end of file */
    ferrSc(&K30,&irc,"Trying to get records from EQ$OUTSIDE$RENTAL~",&K0);

S4360:
    nswend = 1;                              /* end of file */
    if(icompr(&keyeor[0],"  ",&K1) == 0) goto S4550;/* no data in  */
    /*
    /*  file
    */
    goto S4420;                              /* process like next record is different from current record */
S4385:

    /*
         Determine whether "next" record is for same set

    */
    if(icompr(keyeor,"  ",&K1) == 0) goto S4405;/* first record */
    if(icompr(keyeor,xpScom1_keynxt,&K60) != 0) goto S4420;
S4405:

    /*
         Get accrued and billed information from this record

    */
    gdatSf("GET ","EQ$OUTSIDE$RENTAL",&K17,"    ","HOURS ACCRUED",&K13,&hrsacf,&K0,&K0,&K0,&irc);
    gdatSf("GET ","EQ$OUTSIDE$RENTAL",&K17,"    ","RENTAL ACCRUED",&K14,&rntacf,&K0,&K0,&K0,&irc);
    gdatSf("GET ","EQ$OUTSIDE$RENTAL",&K17,"    ","HOURS BILLED",&K12,&hrsblf,&K0,&K0,&K0,&irc);
    gdatSf("GET ","EQ$OUTSIDE$RENTAL",&K17,"    ","RENTAL BILLED",&K13,&rntblf,&K0,&K0,&K0,&irc);

    /*
         Accumulate information from this record into totals for the set

    */
    hrsacc = hrsacc+hrsacf;                  /* hours accrued */
    rntacc = rntacc+rntacf;                  /* rental accrued */
    hrsbld = hrsbld+hrsblf;                  /* hours billed */
    rntbld = rntbld+rntblf;                  /* rental billed */

    /*
         Update current key buffer

    */
    mvwrd(xpScom1_keynxt,keyeor,&K52);

    goto S4345;                              /* go back and get next record */

S4420:
    if(icompr(&keyeor[0],xc_cScoid,&K4) != 0) goto S4550;/* end of company */
    if(icompr(&keyeor[2],nunit,&K10) != 0) goto S4550;/* end of unit */
    READ(INTERNAL,keyeor,60,FMT,F4445,1,REAL8,&eqdate,REAL8,&eqjob,REAL8,&eqphs,DO,5,INT2,neqact,DO,5,INT2,neqfnc,REAL8,
      &eqcrac,0);

    if(eqdate < disbeg) goto S4525;          /* skip data prior to display range */
    if(eqdate > disend) goto S4550;          /* past end of display range */

    /*
         ...Found a set to display...

         Calculate data to be displayed

    */
    outdat(&eqdate,&eqdato,NULL);
    hrsunb = hrsacc-hrsbld;                  /* unbilled hours */
    rntunb = rntacc-rntbld;                  /* unbilled rental */
    eqjbph = combjp(&eqjob,&eqphs);

    /*
         Skip display of a set if it has been fully billed (no unbilled balances)
            unless "Display All" has been checked

    */
    if(iameq(&hrsunb,&R11) != 0) goto S4465;
    if(iameq(&rntunb,&R11) != 0) goto S4465;
    if(icompr(&nswall,"  ",&K1) != 0) goto S4465;
    goto S4525;                              /* skip this set */

S4465:

    /*
         Increment set pointer

    */
    xbb_jsetSb = xbb_jsetSb+1;
    if(xbb_jsetSb <= xbb_nsetSb) goto S4480;

    xbb_jsetSb = xbb_jsetSb-1;

    errSs("Too much \"Equipment Outside Rental\" data to process in one reference.~",&K0,&irc);
    bangSs(&irc);

    errSs("You can: 1) Narrow the \"Display Period\" to include less data, or  ~",&K0,&irc);
    bangSs(&irc);

    errSs("You can: 2) Process the portion of the data that can be displayed.~",&K0,&irc);
    bangSs(&irc);

    goto S4550;

S4480:

    /*
         Display rental information

    */
    doutSs("LITERAL DATE USED",&K17,&eqdato,&K8,&irc);
    if(irc == 1) ferrSc(&K0,&irc,"Field LITERAL DATE USED required with Equipment Number~",&K0);

    WRITE(INTERNAL,xc_cSmess,6,FMT,F4495,1,REAL8,eqjob,0);
    doutSs("EQ JOB",&K6,xc_cSmess,&K6,&irc);

    doutSs("EQ PHASE",&K8,&eqphs,&N1,&irc);
    doutSs("EQ ACTIVITY",&K11,neqact,&K10,&irc);
    doutSs("EQ FUNCTION",&K11,neqfnc,&K10,&irc);

    WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hrsunb,0);
    dout("UNBILLED HOURS",&K14,xc_cSmess,&K7,&hrsunb,&irc);
    dout("UNBILLED HOURS UNADJUSTED",&K25,xc_cSmess,&K7,&hrsunb,&irc);

    WRITE(INTERNAL,xc_cSmess,8,FMT,F4515,1,REAL8,rntunb,0);
    dout("UNBILLED RENTAL",&K15,xc_cSmess,&K8,&rntunb,&irc);
    /*
             /*
    */
    dout("UNBILLED RENTAL UNADJUSTED",&K26,xc_cSmess,&K8,&rntunb,&irc);

    /*
         The following fields are displayed at the right edge of the board
            where they will be "out of the way".  They are not needed as
            information to be displayed, but are needed as data to be
            available to pack a valid set of input batch data

    */
    doutSs("EQ ACCOUNT",&K10,&eqcrac,&N1,&irc);
    mdySc("P ","USED",&K4,&eqdate,&K0,&irc);

    /*
         If the date of this equipment usage falls within the
            invoice period, load "Paid in Full" with an "X".
            Also, load the Unbilled Rental in the Amount field
            and load the account, job/phase and activity field.

    */
    if(eqdate < perbeg || eqdate > perend) goto S4525;

    doutSs("PIF ",&K3,"F ",&K1,&irc);

    WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hrsunb,0);
    rmvbSc(xc_cSmess,&K7,&K0,&ldummy,&irc);
    dout("HOURS ",&K5,xc_cSmess,&K7,&hrsunb,&irc);

    WRITE(INTERNAL,xc_cSmess,8,FMT,F4515,1,REAL8,rntunb,0);
    rmvbSc(xc_cSmess,&K8,&K0,&ldummy,&irc);
    dout("AMOUNT",&K6,xc_cSmess,&K8,&rntunb,&irc);

    doutSs("DRACCT",&K6,&eqcrac,&N1,&irc);
    doutSs("JOBPH ",&K5,&eqjbph,&N1,&irc);
    doutSs("ACTIV ",&K5,neqact,&K10,&irc);

S4525:

    if(nswend == 1) goto S4550;              /* end of file */

    /*
         Set up key and data to go back and process "next" record
            that has already been read

    */
    mvwrd(xpScom1_keynxt,keyeor,&K52);

    hrsacc = 0.e0;
    rntacc = 0.e0;
    hrsbld = 0.e0;
    rntbld = 0.e0;

    goto S4385;

S4550:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

         Force re-read input screen to recognize rental data output to display

    */
    readSs(&K11,&irc);

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S4585;

    for(i=1,D14=(D14=(7-i+1))>0?D14:1; D14>0; D14--,i+=1)
    {
        if(jrnkey[i-1] == 0) goto S4575;
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S4575;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S4550;
S4575:;
    }

    goto S4610;

S4585:

    effdat = effbat;

S4610:

    xbilcom_bSdate = effdat;

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    thrunb = 0.e0;
    thours = 0.e0;
    tauadj = 0.e0;

    /*
         Process each set to determine the amount to be applied to the invoice

    */
    for(i=1; i==1 || i<=xbb_lsetSb; i++)
    {

        xbb_jsetSb = i;

        /*
             Reset array elements that would be associated with this input set
                of data.

        */
        eqjobs[i-1] = 0.e0;
        eqphss[i-1] = 0.e0;
        fill(&neactv[i-1][0],&K5,"  ");
        fill(&nefunc[i-1][0],&K5,"  ");
        accteq[i-1] = 0.e0;
        hrsbil[i-1] = 0.e0;
        adjhrs[i-1] = 0.e0;
        adjams[i-1] = 0.e0;
        datuse[i-1] = 0.e0;

        fill(&idadj[i-1][0],&K2,"  ");
        apadj[i-1] = 0.e0;
        aradj[i-1] = 0.e0;

        /*
             If Literal Date Used is not blank, set is from "Outside Rental" file

        */
        dataSs("LITERAL DATE USED",&K17,&eqdato,&K8,&irc);
        if(irc == 4) goto S4780;

        noeor = i;                           /* keep track of the number of "Outside Rental" entries */
        /*
        /* entries

             Read in all information for this set as currently displayed

        */
        dataSs("PIF ",&K3,&npif,&K1,&irc);
        dataSs("EQ JOB",&K6,&eqjob,&K0,&irc);
        dataSs("EQ PHASE",&K8,&eqphs,&K0,&irc);
        eqjbph = combjp(&eqjob,&eqphs);
        dataSs("EQ ACTIVITY",&K11,neqact,&K10,&irc);
        dataSs("EQ FUNCTION",&K11,neqfnc,&K10,&irc);
        dataSs("EQ ACCOUNT",&K10,&eqcrac,&K0,&irc);
        dataSs("UNBILLED HOURS",&K14,&hrsunb,&K0,&irc);
        dataSs("UNBILLED RENTAL",&K15,&rntunb,&K0,&irc);
        dataSs("UNBILLED HOURS UNADJUSTED",&K25,&hrsuna,&K0,&irc);
        dataSs("UNBILLED RENTAL UNADJUSTED",&K26,&rntuna,&K0,&irc);
        dataSs("HOURS ",&K5,&hours,&K0,&irc);
        dataSs("AMOUNT",&K6,&amount,&K0,&irc);
        dataSs("ADJUST HOURS",&K12,&adjhr,&K0,&irc);
        dataSs("ADJUST AMOUNT",&K13,&adjamt,&K0,&irc);
        mdySc("G ","USED",&K4,&datusd,&K0,&irc);

        /*
             Save data values unique to an outside rental entry
                that will later be needed to pack a data set

        */
        eqjobs[i-1] = eqjob;
        eqphss[i-1] = eqphs;
        frmaSc(&eqjob,&eqphs,neqact,&irc);
        mvwrd(neqact,&neactv[i-1][0],&K5);
        mvwrd(neqfnc,&nefunc[i-1][0],&K5);
        accteq[i-1] = eqcrac;
        hrsbil[i-1] = hours;
        adjhrs[i-1] = adjhr;
        adjams[i-1] = adjamt;
        datuse[i-1] = datusd;

        /*
             Determine whether to adjust accrued unbilled outside rental hours

        */
        rental = 0.e0;
        rentor = 0.e0;

        if(adjhr == 0.e0) goto S4625;        /* no adjustment to be calculated */
        xpScom1_noscSp = 0;
        xpScom1_nscdat = 0;

        eqcalc(&nfunc,&backed,&batch,&refno,"C ","HR  ",nunit,&eqjob,&eqphs,neqact,neqfnc,&datusd,memadj,&vcno,&adjhr,&
          R11,&R11,&rental,&rentor,&irc);
        if(irc != 0) goto S3050;

S4625:

        /*
             Is there an Outside Rental Amount Adjustment to be processed...

        */
        if(autadj == 0.e0 && adjamt == 0.e0 && atadhr == 0.e0) goto S4655;

        /*
                Validate the debit account stipulated in configuration parameter
                OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT

        */
        eqordj[i-1] = ordjsv;                /* move account to variable that can be modified */
        vglaS2("OutsideRentalAdjDr  ","I ","E ","D ",&eqjob,&eqphs,neqact,&eqordj[i-1],&eqordl[i-1],&irc);
        if(irc == 0) goto S4640;
        blnkSs("EQ UNIT ",&K7,&irc);
        goto S3050;
S4640:

        /*
             Get Company ID for Job/Phase that Used the Rental Equipment

        */
        jinfSc(&eqjob,&eqphs,"JC  ","COMPANY ID",&K10,&idadj[i-1][0],&K4,&K0,&K0,&irc);
        if(irc != 0) ferrSc(&K0,&irc,"COMPANY ID FOR EQUIPMENT JOB~",&K0);

        if(icompr(&idadj[i-1][0],xc_cScoid,&K4) == 0) goto S4655;/* NO ICT INDICATED */
        /*
        /* INDICATED

         ----- Check Journal Close Dates for ICT

        */
        ckjrn2(&idadj[i-1][0],&K1,&effdat,&refno,&irc);
        if(irc == 0) goto S4650;
        starSs("EQ JOB",&K6,&irc);
        starSs("EQ PHS",&K6,&irc);
        goto S3050;

S4650:

        /*
             Get authorization for intercompany charge and associated accounts

        */
        aictSc(&idadj[i-1][0],&eqordj[i-1],&apadj[i-1],&aradj[i-1],&irc);
        if(irc == 0) goto S4655;
        blnkSs("EQ JOB",&K6,&irc);
        blnkSs("EQ PHS",&K6,&irc);
        errSs("Indicated Intercompany ADJUSTMENT is NOT authorized~",&K0,&irc);
        goto S3050;

S4655:

        adjrnt = rentor;                     /* <<< needs to go back to base??? */

        hrsunb = hrsuna+adjhr;
        WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hrsunb,0);
        dout("UNBILLED HOURS",&K14,xc_cSmess,&K7,&hrsunb,&irc);

        rntunb = rntuna+adjrnt+adjamt;
        WRITE(INTERNAL,xc_cSmess,8,FMT,F4515,1,REAL8,rntunb,0);
        dout("UNBILLED RENTAL",&K15,xc_cSmess,&K8,&rntunb,&irc);

        /*
             Determine amount to be displayed, based on PIF entry

        */
        if(icompr(&npif,"F ",&K1) == 0) goto S4670;/* full payment */
        if(icompr(&npif,"P ",&K1) == 0) goto S4685;/* partial payment */
        if(icompr(&npif,"  ",&K1) == 0) goto S4755;/* no payment */

        blnkSs("PIF ",&K3,&irc);
        errSs("Enter \"F\"ull, \"P\"artial, or \"blank\"~",&K0,&irc);
        goto S3050;

S4670:

        /*
             Load Hours and Amount field with full payment

        */
        WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hrsunb,0);
        rmvbSc(xc_cSmess,&K7,&K0,&ldummy,&irc);
        dout("HOURS ",&K5,xc_cSmess,&K7,&hrsunb,&irc);

        WRITE(INTERNAL,xc_cSmess,8,FMT,F4515,1,REAL8,rntunb,0);
        rmvbSc(xc_cSmess,&K8,&K0,&ldummy,&irc);
        dout("AMOUNT",&K6,xc_cSmess,&K8,&rntunb,&irc);

        hrsbil[i-1] = hrsunb;

        goto S4700;

S4685:

        /*
             If a partial payment is indicated, but only a number of hours
                that are to be paid has been entered, calculate the dollar
                amount of the partial payment.  Assume an average hourly
                rate for the remaining hours by dividing the remaining
                unbilled amount by the remaining unbilled hours.

        */
        if(amntl[i-1] != amount) goto S4700; /* amount has been entered */
        if(hrsunb == 0.e0) goto S4700;

        /*
             Calculation of Amount to be paid on this line:
                RNTUNA: amount of accrued rental remaining unbilled
                ADJRNT: amount of adjustment to rental accrual arising from
                           entry of hours adjustment
                HRSUNB: hours remaining unbilled
                HOURS : hours to be paid for by this transaction
                ADJAMT: amount of adjustment to rental accrual directly entered
                           in $ADJ column

        */
        amount = (rntuna+adjrnt)/hrsunb*hours+adjamt;
        roffSc(&amount,&R12,&irc);

        WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hours,0);
        rmvbSc(xc_cSmess,&K7,&K0,&ldummy,&irc);
        dout("HOURS ",&K5,xc_cSmess,&K7,&hours,&irc);

        WRITE(INTERNAL,xc_cSmess,8,FMT,F4515,1,REAL8,amount,0);
        rmvbSc(xc_cSmess,&K8,&K0,&ldummy,&irc);
        dout("AMOUNT",&K6,xc_cSmess,&K8,&amount,&irc);

S4700:

        /*
             Assemble the values that are going to be output as the account
                job/phase and activity to which the rental invoice distribution
                will be debitted.  The invoice amount will be charged to the
                equipment cost center, to an activity that is comprised of the
                rental unit number and a repair code for "outside rental expense"
                and to an account that is a contra account to the reserve
                account that was credited when the usage of the rented equipment
                was charged to job cost.

             See if this unit is associated with a specific Equipment Department
                in the unit's master record

        */
        uinfSc(nunit,"    ","EQ USAGE CREDIT JOB",&K19,&equcjp,&K0,&K0,&K0,&irc);
        if(equcjp <= 0.e0) irc = 7;
        if(irc != 0) goto S4720;

        /*
             Set the Equipment Cost Center job and phase for this unit from the
                job/phase found in the unit's master record

        */
        spltjp(&equcjp,&eqccjb,&eqccph,&irc);
        if(iameq(&eqccph,&R11) == 0) eqccph = 1.e0;
        goto S4740;

S4720:

        /*
             Use the EQ$OUTSIDE$RENTAL job and phase if they exist

        */
        eqccjb = eqjob;
        eqccph = eqphs;

        if(eqjob > 0.e0) goto S4740;

        /*
             Set the Equipment Cost Center job and phase for this unit to
                the "default" Equipment Cost Center job and phase

        */
        eqccjb = eqdccj;
        eqccph = eqdccp;

S4740:

        /*
             Only if the equipment cost center phase is NOT "1", concatenate
                the equipment cost center job and phase into one value.  This
                will dispense with seeing ".01" as a phase number.

        */
        eqccjp = eqccjb;
        if(eqccph != 1.e0) eqccjp = combjp(&eqccjb,&eqccph);

        /*
             Build the equipment cost center activity comprised of the Unit
                number, the repair code delimiter, and the "outside rental"
                repair code.

        */
        fill(xc_cSmess,&K7,"  ");
        mvbyt(nunit,&xc_cSmess[0],&K10);
        mvbyt(&nercdl,&xc_cSmess[5],&K1);
        mvbyt(&neorrc,&xc_cSmess[6],&K2);

        len = 14;
        rmvblk(xc_cSmess,&len,&K0);          /* remove blanks from combination */

        mvbyt(xc_cSmess,noract,&K10);
        frmaSc(&eqccjb,&eqccph,noract,&irc);

        /*
             Set up the debit account as the account to which the reserve for
                outside rental was credited at the time the usage was charged
                to job cost, plus the "Outside Rental Adder"

        */
        eqdrac = eqcrac+eqorad;

        /*
             Load the account, job/phase and activity fields

        */
        doutSs("DRACCT",&K6,&eqdrac,&N1,&irc);
        doutSs("JOBPH ",&K5,&eqccjp,&N1,&irc);
        doutSs("ACTIV ",&K5,noract,&K10,&irc);

        goto S4765;

S4755:

        /*
             Blank fields that are not to be displayed

        */
        doutSs("HOURS ",&K5,"  ",&K1,&irc);
        doutSs("AMOUNT",&K6,"  ",&K1,&irc);
        doutSs("DRACCT",&K6,"  ",&K1,&irc);
        doutSs("JOBPH ",&K5,"  ",&K1,&irc);
        doutSs("ACTIV ",&K5,"  ",&K1,&irc);

        hrsbil[i-1] = 0.e0;
        amount = 0.e0;

S4765:

        /*
             Get "HOURS" to be added to the Control Total

        */
        dataSs("HOURS ",&K5,&hours,&K0,&irc);

        /*
             Accumulate totals for display

        */
        thrunb = thrunb+hrsunb;              /* unbilled hours */
        thours = thours+hours;               /* hours to be paid with this invoice */

        /*
             CALL ERR$P('@4765, HRSUNB=~',0, HRSUNB,0 )      <<<
             CALL ERR$P('@4765, THRUNB=~',0, THRUNB,0 )      <<<
             CALL ERR$P('@4765, HOURS =~',0, HOURS, 0 )      <<<
             CALL ERR$P('@4765, THOURS=~',0, THOURS,0 )      <<<
             Save the "AMOUNT" and "HOURS" as last displayed.  This will be used
                to determine when the AMOUNT and/or the HOURS entry has been changed.
                This comes into play when the program is trying to decide whether
                to automatically calculate the AMOUNT of a partial payment based
                upon the partial HOURS entry.

        */
        amntl[i-1] = amount;

S4780:;
    }

    /*
         Force re-read input screen to recognize rental data output to display

    */
S4815:
    readSs(&K11,&irc);

    /*
         get override effective date

    */
    mdySc("G ","EFFECTIVE",&K9,&effdat,&datout,&irc);
    if(irc != 0) goto S4845;

    for(i=1,D16=(D16=(7-i+1))>0?D16:1; D16>0; D16--,i+=1)
    {
        if(jrnkey[i-1] == 0) goto S4830;
        clsdSc(&i,&effdat,"W ",&irc);
        if(irc == 0) goto S4830;
        blnkSs("MONTH EFFECTIVE",&K15,&irc);
        blnkSs("DAY EFFECTIVE",&K13,&irc);
        blnkSs("YEAR EFFECTIVE",&K14,&irc);
        goto S4815;
S4830:;
    }

    goto S4860;

S4845:

    effdat = effbat;

S4860:

    xbilcom_bSdate = effdat;

    /*
     --- GET VAT RATE FOR THE EFFECTIVE DATE

    */
    vatrat(&effdat,&vatrt,&irc);

    /*
         Update optional display of total unbilled outside rental hours

    */
    WRITE(INTERNAL,xc_cSmess,10,FMT,F4885,1,REAL8,thrunb,0);
    dout("TOTAL UNBILLED HOURS",&K20,xc_cSmess,&K10,&thrunb,&irc);/* right justified */

    /*
         Update optional display of total outside rental hours to be paid

    */
    WRITE(INTERNAL,xc_cSmess,10,FMT,F4885,1,REAL8,thours,0);
    rmvbSc(xc_cSmess,&K10,&K0,&ldummy,&irc); /* left justified */
    dout("TOTAL HOURS",&K11,xc_cSmess,&K10,&thours,&irc);

S4900:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    */
    tdist = 0.e0;                            /* total distributed incl. auto adjustment */
    tdistl = 0.e0;                           /* total distributed and displayed by line */

    thrs = 0.e0;
    tadjhr = 0.e0;
    tadamt = 0.e0;

    tadisc = 0.e0;
    tvat = 0.e0;
    tstax = 0.e0;
    taxabl = 0.e0;
    taxemt = 0.e0;

    lsttax = 0;
    lstadj = 0;                              /* row of last automatically allocated adjustment */
    lstadh = 0;                              /* row of last automatically allocated adjustment (hours) */
    lstvat = 0;                              /* row of last automatically calculated VAT amount */

    ilast = 0;
    nswdup = 0;

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    */
    for(i=1,D19=(D19=(xbb_lsetSb-i+1))>0?D19:1; D19>0; D19--,i+=1)
    {

        xbb_jsetSb = i;

        litem[i-1] = 0;                      /* RESET FLAG FOR 'LINE ITEM' */
        ircbak = 1;                          /* Set at No Back Charge amount to start with */

        vatamt[i-1] = 0.e0;

        if(itest(xbb_isetSb,&i) == 0) goto S5675;

        /*
             INITIALIZE KEY INTERCOMPANY PARAMETERS

        */
        mvbyt("    ",&idchg[i-1][0],&K4);
        apict[i-1] = 0.e0;
        arict[i-1] = 0.e0;

        /*
             GET AMOUNT

        */
        dataSs(&fldnam[0],&K8,&amnts[i-1],&K0,&ircamt);

        if(ircamt != 1) goto S4955;          /* field was found */

        /*
        -----See if a field named BACKCHARGE13 is on the screen

        */
        if(i != 13) goto S5675;

        dataSs("BACKCHGAMT13",&K12,&amnts[i-1],&K0,&ircbak);
        if(ircbak == 1) goto S5675;
        if(ircbak == 0) amnts[i-1] = -amnts[i-1];/* Reverse Sign */

S4955:

        tdist = tdist+amnts[i-1];            /* total distributed incl. auto adjustment */
        tdistl = tdistl+amnts[i-1];          /* total distributed and displayed by  */
        /*
        /*  line

             Determine amount of 'auto adjustment allocation' to be added
                to this line item

        */
        if(autadj == 0.e0) goto S4970;
        if(hrsbil[i-1] == 0.e0) goto S4970;

        adjlin = 0.e0;
        if(thours != 0.e0) adjlin = autadj/thours*hrsbil[i-1];
        roffSc(&adjlin,&R17,&irc);

        adjams[i-1] = adjams[i-1]+adjlin;
        tauadj = tauadj+adjlin;

        amnts[i-1] = amnts[i-1]+adjlin;
        tdist = tdist+adjlin;                /* total distributed incl. auto adjustment */
        lstadj = i;                          /* remember location of last adjustment for round-off */

S4970:

        /*
             Determine amount of 'auto adjustment allocation hr' to be added
                to this line item

        */
        if(atadhr == 0.e0) goto S4985;
        if(hrsbil[i-1] == 0.e0) goto S4985;

        /*
             determine amount to adjust this line

        */
        adjlin = 0.e0;
        if(thours != 0.e0) adjlin = atadhr/thours*hrsbil[i-1];
        erate = (amnts[i-1]-adjams[i-1])/hrsbil[i-1];
        adamnt = erate*adjlin;
        roffSc(&adamnt,&R17,&irc);

        tadamt = tadamt+adamnt;

        /*
             adjust hours

        */
        adjhrs[i-1] = adjhrs[i-1]+adjlin;
        hrsbil[i-1] = hrsbil[i-1]+adjlin;
        thrs = thrs+hrsbil[i-1];
        tadjhr = tadjhr+adjlin;

        /*
             update hours on screen

        */
        WRITE(INTERNAL,xc_cSmess,7,FMT,F4505,1,REAL8,hrsbil[i-1],0);
        rmvbSc(xc_cSmess,&K7,&K0,&ldummy,&irc);
        dout("HOURS ",&K5,xc_cSmess,&K7,&hrsbil[i-1],&irc);

        /*
             adjust amounts

        */
        amnts[i-1] = amnts[i-1]+adamnt;
        tdist = tdist+adamnt;
        tdistl = tdistl+adamnt;

        lstadh = i;                          /* remember location of last adjustment for round-off */

S4985:

        /*
             Get amount of VAT

        */
        dataSs(&fldnam[7],&K8,&vatamt[i-1],&K0,&ircvat);

        /*
             If both Billed amount and VAT amount have no entry,
                or are not on screen, go process blank line

        */
        if(ircamt != 0 && ircvat != 0) goto S5500;

        /*
         --- GET LINE ITEM INVOICE NUMBER IF IT IS ON THE SCREEN

        */
        dataSs(&fldnam[8],&K5,&invli[i-1],&K8,&irc);
        if(irc != 1) linitm = TRUE;
        if(irc == 1) invli[i-1] = invoic;
        if(irc == 1) goto S5020;
        linvSc("P ",&vcno,&invli[i-1],&irc);
        if(irc == 7) goto S3050;             /* Not found but required for vendor */
S5020:

        /*
         --- GET LINE ITEM INVOICE DATE IF  IT IS ON THE SCREEN

        */
        mvnoSc(&i,invdat,&K9,&irc);
        mdySc("G ",invdat,&K10,&invdli[i-1],&dum,&irc);
        if(irc != 0) invdli[i-1] = datinv;   /* USE THE DEFAULT */

        /*
         --- GET LINE ITEM PO NUMBER IF IT IS ON THE SCREEN

        */
        dataSs(&fldnam[10],&K4,&poli[i-1],&K8,&irc);
        if(irc == 1) poli[i-1] = po;         /* USE THE DEFAULT */

        /*
         --- GET LINE ITEM CLIENT NUMBER (optional field, used for billing)

        */
        dataSs(&fldnam[11],&K6,&clntli[i-1],&K0,&irc);
        if(irc != 0) goto S5050;

        /*
         ---- CHECK FOR CLIENT IN V/C ROSTER

        */
        vinfSc(&clntli[i-1],"    ","NAME",&K4,ivname,&K1,&K0,&K0,&irc);
        if(irc == 0) goto S5065;
        if(irc == 7) goto S5035;
        errSc(&K20,&irc,"Looking for CLIENT (by line item) in V/C$INFO~",&K0,&irc);
        bangSs(&irc);
        goto S9000;

S5035:
        errSs("Client not in Vendor/Client roster.~",&K0,&irc);
        blnkSs(&fldnam[11],&K6,&irc);
        goto S3050;

S5050:
        clntli[i-1] = client;                /* use default CLIENT for this reference */

S5065:

        /*
        ------See if this line has a NON-BILL field

        */
        mvwrd(&nonbil,&inobil[i-1],&K1);
        if(ircnon != 0) dataSs("NON-BILL",&K7,&inobil[i-1],&K2,&irc);

        /*
         --- GET LINE ITEM DISCOUT IF IT IS ON THE SCREEN

        */
        discli[i-1] = 0.e0;
        dataSs(&fldnam[9],&K6,&discli[i-1],&K0,&ircSd);

        litem[i-1] = 1;                      /* SET FLAG FOR 'LINE ITEM */

        /*
             DETERMINE PORTIN OF DISCOUNT TO BE ALLOCATED TO THIS LINE ITEM

        */
        adisc[i-1] = 1.e-2*fifdint(amnts[i-1]*dscfac*1.e2+.5001e0);
        if(linitm && ircSd == 0) adisc[i-1] = discli[i-1];
        tadisc = tadisc+adisc[i-1];          /* TALLY DISCOUNT ALLOCATED */
        if(ircSd == 4) doutSs(&fldnam[9],&K6,&adisc[i-1],&N1,&irc);
        lstdsc = i;                          /* SAVE LOCATION FOR LAST DISCOUNT */

        /*
         --- GET PRO-RATA VAT AMOUNT

        */
        dataSs(&fldnam[7],&K8,&vatamt[i-1],&K0,&irc);
        if(irc == 0) goto S5080;

        vatamt[i-1] = amnts[i-1]*vatpct;
        if((xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) && vattot != 0.e0 &&
          cramnt != vattot) vatamt[i-1] = (amnts[i-1]+adisc[i-1])/(cramnt-vattot)*vattot;
        vatamt[i-1] = rndoff(&vatamt[i-1],&K2);
        doutSs(&fldnam[7],&K8,&vatamt[i-1],&N1,&irc);
        lstvat = i;                          /* save row of last automatically calculated VAT amount */
S5080:
        tvat = tvat+vatamt[i-1];

        /*
             GET ACCOUNT NUMBER

        */
        dataSs(&fldnam[1],&K8,&drjacc[i-1],&K0,&ircacc);

        /*
             GET JOB & PHASE

        */
        dataSs(&fldnam[2],&K8,&rjobs[i-1],&K0,&irc);
        if(irc == 0) goto S5175;
        if(ircbak == 0) goto S5120;
        errSs("Enter job/phase number.~",&K0,&irc);
        starSs(&fldnam[2],&K8,&irc);
        goto S3050;

        /*
        ------Look for a single Job/Phase to use for Back Charges

        */
S5120:
        bjob = 0.e0;
        for(k=0; k==0 || k<xbb_lsetSb; k++)
        {
            if(litem[k] == 0) goto S5145;
            if(rjobs[k] == 0.e0) goto S5145;
            if(bjob == 0.e0) bjob = rjobs[k];
            if(bjob != 0.e0 && bjob == rjobs[k]) goto S5145;
            errSs("Must enter Job/Phs for Back Charge~",&K0,&irc);
            goto S3050;
S5145:;
        }
        if(bjob != 0) goto S5160;
        errSs("Must enter Job/Phs for Back Charge~",&K0,&irc);
        goto S3050;

S5160:
        rjobs[i-1] = bjob;
        goto S5175;

S5175:
        if(rjobs[i-1] == fifdint(rjobs[i-1])) rjobs[i-1] = combjp(&rjobs[i-1],&R4);
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);

        /*
             GET ACTIVITY NUMBER

        */
        dataSs(&fldnam[3],&K8,&activs[i-1][0],&K10,&ircact);

        xc_cSvjob = *(double*)fifstrgv("JOBPH   ",8);
        xc_cSvphs = *(double*)fifstrgv("        ",8);
        xc_cSvact = *(double*)fifstrgv("ACTIV   ",8);

        frmaSc(&rjob,&phase,&activs[i-1][0],&irca);
        if(irca   >  1) goto S3050;
        if(ircact == 0) goto S5180;
        if(ircbak == 0) goto S5180;
        errSs("Enter activity number.~",&K0,&irc);
        starSs(&fldnam[3],&K8,&irc);
        goto S3050;
S5180:
        if(ircact == 0) doutSs(&fldnam[3],&K8,&activs[i-1][0],&K10,&irc);

        /*
        -------Get Account and Activity for Back Charges

        */
        if(ircbak != 0) goto S5210;          /* Not a Back Charge on this line */
        if(ircact == 0) goto S5195;          /* Already have an activity */
        vctlSc("F ",&vcno,&rjob,&phase,"          ",&po,"BACK CHARGE ACTIVITY",&K20,&activs[i-1][0],&K10,&irc);
        frmaSc(&rjob,&phase,&activs[i-1][0],&irca);
        if(irc == 0) goto S5195;
        errSs("Invalid Activity for Back Charge~",&K0,&irc);
        goto S3050;

S5195:
        if(ircacc == 0) goto S5210;
        vctlSc("F ",&vcno,&rjob,&phase,&activs[i-1][0],&po,"BACK CHARGE ACCOUNT",&K19,&drjacc[i-1],&K0,&irc);
        if(irc == 0) goto S5210;
        errSs("Invalid Account for Back Charge~",&K0,&irc);
        goto S3050;

S5210:

        /*
             VALIDATE JOB/PHASE/ACTIVITY#

        */
        valdSc(&K1,&rjob,&phase,&activs[i-1][0],&drjacc[i-1],&ircv);
        if(ircv == 0) goto S5225;
        blnkSs(&fldnam[2],&K8,&irc);
        if(ircv >= 2) blnkSs(&fldnam[3],&K8,&irc);
        if(ircv >= 3) blnkSs(&fldnam[1],&K8,&irc);
        goto S3050;

S5225:

        /*
             VALIDATE DEBIT ACCOUNT

        */
        vglaS2("Debit               ","I ","E ","D ",&rjob,&phase,&activs[i-1][0],&drjacc[i-1],&dracct[i-1],&irc);
        if(irc == 0) goto S5240;
        blnkSs(&fldnam[1],&K8,&irc);
        goto S3050;
S5240:

        /*
             VALIDATE CREDIT ACCOUNT

        */
        vglaS2("Credit              ","A ","E ","C ",&rjob,&phase,&activs[i-1][0],&crjacc,&cracct[i-1],&irc);
        if(irc == 0) goto S5255;
        blnkSs("CRACCT",&K6,&irc);
        goto S3050;
S5255:

        /*
             SET UP ACCOUNT FOR DISCOUNT EARNED FOR EACH LINE ITEM THAT HAS A
                DISCOUNT, IF NATION CODE IS 'NZ' or 'AU' USE DISTRIBUTION JOB
                AND PHASE IF NOT 'NZ' or 'AU' USE DEFAULT ADMINISTRATIVE JOB
                AND PHASE

        */
        if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) vglaSc("A ",&rjob,&phase,&
          dscern,&dsc[i-1],&irc);

        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) vglaSc("A ",&xc_cSdacj,&
          xc_cSdacp,&dscern,&dsc[i-1],&irc);
        if(irc == 0) goto S5270;

        bangSs(&irc);

        errSs("Invalid Ledger Account for 'Discounts Earned' in TR ACCOUNT~",&K0,&irc);
        blnkSs("DISCOUNT",&K8,&irc);
        goto S3050;

S5270:

        /*
             GET MEMO

        */
        dataSs(&fldnam[4],&K8,&rmemo[i-1][0],&K16,&irc);

        /*
        ------Get TAXCODnn if it is on the screen

        */
        dataSs("TAXCOD",&K6,&taxcod[i-1],&K8,&irc);
        if(irc != 0) mvwrd(&codtax,&taxcod[i-1],&K4);
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S5355;

        iopt = 2;
        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc == 0) goto S5285;
        blnkSs("TAXCOD",&K6,&irc);
        errSs("Invalid Sales Tax Code~",&K0,&irc);
        goto S3050;

S5285:
        doutSs("TAXOUT",&K6,"          ",&K10,&irc);
        doutSs("TAXLOC",&K6,loctax,&K40,&irc);

        if(icaltx[i-1] == 0) goto S5310;
        dataSs("TAXAMT",&K6,&taxamt[i-1],&K0,&irc);
        icaltx[i-1] = 1;
        if(irc == 0) icaltx[i-1] = 0;
        if(icaltx[i-1] == 0) goto S5325;
S5310:
        taxamt[i-1] = amnts[i-1]*saltax*sbrtio*.01e0;
        lsttax = i;
        roffSc(&taxamt[i-1],&R17,&irc);
        WRITE(INTERNAL,itax,9,FMT,F5315,1,REAL8,taxamt[i-1],0);
        doutSs("TAXOUT",&K6,itax,&K9,&irc);
S5325:
        if(irctax == 0) goto S5340;
        if(icaltx[i-1] == 1) goto S5340;
        errSs("Must enter the Total Sales Tax control Amount~",&K0,&irc);
        starSs("TOTAL SALES TAX",&K15,&irc);
        goto S3050;
S5340:
        tstax = tstax+taxamt[i-1];
        if(irctax != 0) stxtot = tstax;

        subjct = amnts[i-1]*sbrtio;
        exempt = amnts[i-1]-subjct;
        taxabl = taxabl+subjct;
        taxemt = taxemt+exempt;

S5355:

        /*
         ----- GET RESOURCE CODE AND QUANITY IF THEY ARE ON THE SCREEN

        */
        quanty[i-1] = 0.e0;
        fill(&irescd[i-1][0],&K8,"  ");

        if(!nqtyrc) goto S5395;
        dataSs(namqty,&K5,&quanty[i-1],&K0,&irc1);
        dataSs(namres,&K16,&irescd[i-1][0],&K16,&irc2);
        irc = irc1+irc2;
        if(irc == 0) goto S5370;
        if(irc == 8) goto S5395;
        starSs(namqty,&K5,&irc);
        starSs(namres,&K16,&irc);
        errSs("Enter both a quantity and a resource code~",&K0,&irc);
        goto S3050;

S5370:

        /*
         ----- VALIDATE THE RESOURCE CODE

        */
        vrscSc(xc_cScoid,&irescd[i-1][0],&irc);
        if(irc == 0) goto S5395;
        blnkSs(namres,&K16,&irc);
        errSs("Invalid Resource Code~",&K0,&irc);
        goto S3050;

S5395:

        /*
             CHECK COMPANY ID ASSOCIATED WITH JOB/PHASE TO SEE IF AN INTERCOMPANY
                TRANSACTION IS INDICATED

        */
        jinfSc(&rjob,&phase,"JC  ","COMPANY ID",&K10,&idchg[i-1][0],&K4,&K0,&K0,&irc);
        if(irc != 0) ferrSc(&K0,&irc,"COMPANY ID FOR JOB/PHASE~",&K0);

        if(icompr(&idchg[i-1][0],xc_cScoid,&K4) == 0) goto S5420;/* NO ICT INDICATED */
        /*
        /* INDICATED

         ----- Check Journal Close Dates for ICT

        */
        ckjrn2(&idchg[i-1][0],&K1,&effdat,&refno,&irc);
        if(irc == 0) goto S5415;
        starSs(&fldnam[2],&K8,&irc);
        goto S3050;

S5415:

        /*
             GET AUTHORIZATION FOR INTERCOMPANY CHARGE AND ASSOCIATED PARAMETERS

        */
        aictSc(&idchg[i-1][0],&drjacc[i-1],&apict[i-1],&arict[i-1],&irc);
        if(irc == 0) goto S5420;             /* ICT IS OK */

        /*
             BLINK ACCOUNT# & JOB# AND OUTPUT ERROR MESSAGE

        */
        blnkSs(&fldnam[1],&K8,&irc);
        blnkSs(&fldnam[2],&K8,&irc);
        errSs("Indicated Intercompany charge is NOT authorized~",&K0,&irc);
        goto S3050;

S5420:

        /*
         --- GET CLOSE COMMITMENT FLAG

        */
        nclos[i-1] = 0;
        dataSs(&fldnam[6],&K8,&idum,&K2,&irc);
        if(irc == 0) nclos[i-1] = 1;

        /*
         --- CHECK FOR COMMIT AS EXPENDED FIELD

        */
        nexpn[i-1] = 0;
        dataSs(&fldnam[5],&K8,&idum,&K2,&irc);
        if(irc == 0) nexpn[i-1] = 1;

        /*
         --- CHECK TO INVALID COMBINATION OF ENTRIES

        */
        if(icompr(&po,"-       ",&K8) == 0 && nclos[i-1]+nexpn[i-1] > 0) goto S5445;
        if(nclos[i-1]+nexpn[i-1] > 1) goto S5460;
        goto S5475;

S5445:

        /*
         ---   PO = '-       '

        */
        blnkSs(&fldnam[6],&K8,&irc);
        blnkSs(&fldnam[5],&K8,&irc);
        errSs("Do not mark Final Payment or Commit as Expended;PO# indicates uncommited item~",&K0,&irc);
        goto S3050;

S5460:

        /*
         --- CAN NOT ENTER BOTH FINAL PAYMENT AND COMMIT AS EXPENDED

        */
        blnkSs(&fldnam[6],&K8,&irc);
        blnkSs(&fldnam[5],&K8,&irc);
        errSs("Do not mark both Final Payment and Commit as Expended ~",&K0,&irc);
        goto S3050;

S5475:

        ilast = i;
        litem[i-1] = 1;                      /* SET FLAG TO INDICATE 'LINE ITEM' */
        nswdup = 1;                          /* NOW WE CAN DUPLICATE ON SUCCEEDING LINES */

        goto S5675;

S5500:

        /*
             VERIFY THAT A LINE WITH NO AMOUNT ALSO HAS NO OTHER ENTRIES

        */
        amnts[i-1] = 0.;                     /* RESET AMOUNT WHEN LINE IS UNUSED */

        nerr = 0;
        dataSs(&fldnam[1],&K8,&accnt,&K0,&irc);
        if(irc == 4 || irc == 1) goto S5535;
        blnkSs(&fldnam[1],&K8,&irc);
        nerr = 1;
S5535:

        dataSs(&fldnam[2],&K8,&rjobph,&K0,&irc);
        if(irc == 4 || irc == 1) goto S5550;
        blnkSs(&fldnam[2],&K8,&irc);
        nerr = 1;
S5550:

        dataSs(&fldnam[3],&K8,activ,&K10,&irc);
        if(irc == 4 || irc == 1) goto S5565;
        blnkSs(&fldnam[3],&K8,&irc);
        nerr = 1;
S5565:

        dataSs(&fldnam[4],&K8,memo,&K16,&irc);
        if(irc == 4 || irc == 1) goto S5580;
        blnkSs(&fldnam[4],&K8,&irc);
        nerr = 1;
S5580:

        dataSs(&fldnam[7],&K8,&rvat,&K0,&irc);
        if(irc == 4 || irc == 1) goto S5595;
        blnkSs(&fldnam[7],&K8,&irc);
        nerr = 1;
S5595:

        if(!nqtyrc) goto S5635;
        dataSs(namqty,&K5,&idumb,&K1,&irc);
        if(irc == 4 || irc == 1) goto S5615;
        blnkSs(namqty,&K5,&irc);
        nerr = 1;

S5615:
        dataSs(namres,&K16,&idumb,&K1,&irc);
        if(irc == 4 || irc == 1) goto S5635;
        blnkSs(namres,&K16,&irc);
        nerr = 1;

S5635:
        if(nerr == 0) goto S5650;
        errSs("If no amount is entered, then leave remainder of line blank~",&K0,&irc);
        goto S3050;
S5650:

S5675:;
    }

    if(tadjhr == 0) goto S5685;

    /*
         Update optional display of total outside rental hours to be paid

    */
    thours = thours+tadjhr;
    WRITE(INTERNAL,xc_cSmess,10,FMT,F4885,1,REAL8,thours,0);
    rmvbSc(xc_cSmess,&K10,&K0,&ldummy,&irc); /* left justified */
    dout("TOTAL HOURS",&K11,xc_cSmess,&K10,&thours,&irc);

S5685:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

         If an 'Auto Allocate Adjustment' has been distributed, add additional
            adjustment for 'penny round-off' to last line of distribution to
            which an adjustment was allocated.

    */
    if(lstadj == 0) goto S5725;
    penny = autadj-tauadj;
    adjams[lstadj-1] = adjams[lstadj-1]+penny;
    tauadj = tauadj+penny;

    amnts[lstadj-1] = amnts[lstadj-1]+penny;
    tdist = tdist+penny;

S5725:

    if(lstadh == 0) goto S5750;

    /*
         adjust any penny problems when auto-adjusting hours

    */
    erate = (tdist-tadamt)/(thrs-tadjhr);
    penny = tadjhr*erate-tadamt;
    adjhrs[lstadh-1] = adjhrs[lstadh-1]+penny/erate;

    amnts[lstadh-1] = amnts[lstadh-1]+penny;
    tdist = tdist+penny;
    tdistl = tdistl+penny;

S5750:

    /*
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    */
    elnsSb(&N1,&ic,&jfunc);

    /*
         TRAP SCREEN THAT HAS NO LINE ITEMS

    */
    if(nswdup != 0) goto S5770;
    errSs("Enter distribution of Invoice~",&K0,&irc);
    posSs(&fldnam[0],&K8,&irc);
    goto S3050;
S5770:

    /*
         CHECK DISTRIBUTION OF TOTAL INVOICE AMOUNT

         Update optional display of total amount distributed and displayed by line

    */
    WRITE(INTERNAL,xc_cSmess,12,FMT,F5785,1,REAL8,tdistl,0);
    rmvbSc(xc_cSmess,&K12,&K0,&ldummy,&irc); /* left justify */
    doutSs("TOTAL DISTRIBUTED",&K17,xc_cSmess,&K12,&irc);

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) diff = cramnt-tdist-vattot-
      stxtot;

    if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) diff = cramnt-tdist-disc-
      vattot;

    if(fabs(diff) < .005e0) goto S5790;
    errSs("Distribution of amounts does not match invoice total~",&K0,&irc);
    xbb_jsetSb = 1;
    blnkSs("TOTAL VAT",&K9,&irc);
    blnkSs("DISCOUNT",&K8,&irc);
    blnkSs("TOTAL DISTRIBUTED",&K17,&irc);
    blnkSs("TOTAL INVOICE",&K13,&irc);
    blnkSs("AUTO ALLOCATE ADJUSTMENT",&K24,&irc);
    goto S3050;

S5790:

    /*
         If VAT has been calculated automatically, force balancing of penny
            round-off into last automatically calculated VAT amount.

    */
    if(lstvat == 0) goto S5825;              /* no automatic calculation */

    vatro = vattot-tvat;                     /* determine amount of round-off */
    if(fabs(vatro) < .005e0) goto S5825;     /* no significant round-off */
    if(fabs(vatro) > .08e0) goto S5825;      /* too big to be round-off */
    vatamt[lstvat-1] = vatamt[lstvat-1]+vatro;/* revise last calculated  */
    /*
    /*  VAT
    */
    xbb_jsetSb = lstvat;
    doutSs(&fldnam[7],&K8,&vatamt[lstvat-1],&N1,&irc);/* update screen */
    elnsSb(&N1,&icg,&jfunc);
    tvat = tvat+vatro;                       /* revise total of distributed VAT */

S5825:

    /*
         CHECK DISTRIBUTION OF TOTAL VAT TAX

    */
    if(fabs(vattot-tvat) < .005e0) goto S5850;
    if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) errSs(
      "Distribution of GST does not match GST total~",&K0,&irc);

    if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) errSs(
      "Distribution of VAT does not match VAT total~",&K0,&irc);

    xbb_jsetSb = 1;
    blnkSs(&fldnam[7],&K8,&irc);
    blnkSs("TOTAL VAT",&K9,&irc);
    goto S3050;
S5850:

    /*
     ----------------------------------------------------------------------

         FORCE BALANCE OF DISCOUNT ALLOCATION (FRACTIONAL PENNY ROUND-OFF)

    */
    dscadj = disc-tadisc;
    if(!linitm) goto S5865;
    if(fabs(dscadj) < 0.20e0) goto S5865;
    blnkSs("DISCOUNT",&K8,&irc);
    xbb_jsetSb = 1;
    blnkSs(&fldnam[9],&K6,&irc);
    errSs("Discount distribution does not match total~",&K0,&irc);
    goto S3050;

S5865:
    adisc[lstdsc-1] = adisc[lstdsc-1]+dscadj;

    /*
    ------If Sales Tax was Calculated then check for Roundoff

    */
    staxro = 0.e0;
    if(lsttax == 0) goto S5880;

    staxro = stxtot-tstax;
    if(fabs(staxro) < .005e0) goto S5880;
    if(fabs(staxro) > .080e0) goto S5880;

    tstax = tstax+staxro;

S5880:
    if(fabs(stxtot-tstax) < .005e0) goto S5920;
    errSs("Distribution of Sales Tax does not match Sales Tax Total~",&K0,&irc);
    goto S3050;

S5920:
    /*
     ----------------------------------------------------------------------
         GET CHECK# AND DATE OF CHECK IF INVOICE HAS ALREADY BEEN PAID

    */
    dataSs("CHECK ",&K5,&check,&K8,&irc);
    if(irc == 4) goto S5980;
    gmdySc(&K3,&month,&iday,&iyear,&chkdat,&irc);
    if(irc == 0) goto S5940;
    errSs("Enter check date~",&K0,&irc);
    starSs("YEAR3 ",&K5,&irc);
    starSs("DAY3",&K4,&irc);
    starSs("MONTH3",&K6,&irc);
    goto S3050;

S5940:

    /*
         CHECK IF CASH DISBURSEMENT JOURNAL IS CLOSED THRU CHKDAT

    */
    clerr();

    clsdSc(&K3,&chkdat,"W ",&irc);
    if(irc == 0) goto S5945;
    blnkSs("MONTH3",&K6,&irc);
    blnkSs("DAY3",&K4,&irc);
    blnkSs("YEAR3 ",&K5,&irc);
    posSs("MONTH3",&K6,&irc);
    goto S3050;

S5945:

    /*
         VERIFY THAT THE BANK CASH ACCOUNT HAS BEEN SET UP

    */
    taccSc(&check,accts,&cash,&irc);
    if(irc == 0) goto S5950;
    blnkSs("CHECK ",&K5,&irc);
    errSs("Invalid Check#~",&K0,&irc);
    goto S3050;

S5950:
    doutSs("CHECK ",&K5,&check,&K8,&irc);

    /*
         Get the overide Cash Account if it is present

    */
    ovracc("CASH ACCOUNT",&K12,&cash,&irc);
    if(irc > 4) goto S3050;

    /*
         SET UP CASH ACCOUNT FOR EACH LINE ITEM

    */
    for(i=1; i==1 || i<=xbb_lsetSb; i++)
    {
        if(litem[i-1] == 0) goto S5960;

        spltjp(&rjobs[i-1],&rjob,&phase,&irc);

        vglaS2("Cash Ledger Account ","A ","O ","C ",&rjob,&phase,"          ",&cash,&csh[i-1],&irc);
        if(irc == 0) goto S5960;

        bangSs(&irc);

        errSs("Invalid Cash Ledger Account for indicated Bank Account~",&K0,&irc);
        blnkSs("CHECK ",&K5,&irc);
        goto S3050;

S5960:;
    }

S5980:

    /*
     ----------------------------------------------------------------------

         PACK INTO SCREEN DATA BUFFER

    */
    ib = 0;
    xpScom1_nscdat = 0;
    xpScom1_nentry = 0;

    for(i=1,D21=(D21=(xbb_lsetSb-i+1))>0?D21:1; D21>0; D21--,i+=1)
    {

        if(litem[i-1] == 0) goto S6700;

        xbb_jsetSb = i;

        /*
             Load table with active input field names for reference in other routines

        */
        fill(xc_cSnmaf,&K160,"  ");          /* blank fill names buffer */
        mvbyt("AMOUNT",&xc_cSnmaf[0][0],&K6);/* amount */
        xc_cSnoaf = 1;                       /* number of active fields */

        /*
        ------See if buffer is dangerously full

        */
        if(ib < MAXSCD-1500) goto S6140;

        /*
        ------If we have not yet BACKED up this reference this is the time to do it

        */
        if(backed) goto S6125;

        backed = TRUE;
        if(nfunc == *(short*)fifstrgv("A ",2)) goto S6125;

        iSback("BACK",&batch,&refno,&irc);
        if(irc != 0) goto S9000;

        iSdlet(&batch,&refno,&irc);

S6125:
        xpScom1_nscdat = xpScom1_nscdat+1;
        iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
        iSxinv(&batch,&refno,&vcno,&invoic,&irc);
        if(ircdin == 0) iSxdin(&batch,&refno,idin,&irc);
        ib = 0;

S6140:

        xc_cSrow = i;

        /*
             Get the BILLING REFERENCE if there is one

        */
        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        xpScom1_nentry = xpScom1_nentry+1;   /* count entries */

        ib = ib+1;
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("\\\\      ",8);/* Group Separator */
        xpScom1_pSscdt[ib] = 1.e0;           /* Version */
        xpScom1_pSscdt[ib+1] = i;            /* Group Number */
        xpScom1_pSscdt[ib+2] = xpScom1_nentry;/* Invoice screen entry number */
        xpScom1_pSscdt[ib+3] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+4] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+5] = 0.e0;         /* Reserved for future use */
        xpScom1_pSscdt[ib+6] = 0.e0;         /* Reserved for future use */

        ib = ib+7;

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];

        spltjp(&rjobs[i-1],&rjob,&phase,&irc);

        /*
         --- Look for any expired insurance, if found hold payment

        */
        mvbyt(&activs[i-1][0],activ,&K10);
        holdSc(&vcno,&rjob,&phase,&effdat,&trtype,"B ",activ,&po,&invoic,&ib,&irc);

        /*
         --- CHECK IF "COMMIT AS EXPENDED" FIELD WAS FILLED IN

        */
        if(nswcxp == 1 || nexpn[i-1] == 1) goto S6250;

        /*
         --- CHECK COMMITMENTS FOR OVER-BILLING

         --- CHECK IF WE CAN "COMMIT AS EXPENDED"

        */
        mvbyt(&activs[i-1][0],activ,&K10);

        /*
         --- "V/C$INFO"

        */
        itemp[0] = *(short*)fifstrgv("  ",2);
        vinfSc(&vcno,"    ","COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&K0,&K0,&irc);
        if(irc == 0 && itemp[0] == *(short*)fifstrgv("Y ",2)) goto S6250;

        /*
         --- CHECK VENDOR CONTROL

        */
        vctlSc("F ",&vcno,&rjob,&phase,&activs[i-1][0],&po,"COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&irc);
        if(irc == 0 && itemp[0] == *(short*)fifstrgv("Y ",2)) goto S6250;

        /*
           --- GET COMMIT AS EXPENED FOR JOB/PHASE/ACTIVITY "ACTIVITY$INFO"

        */
        WRITE(INTERNAL,keyact,22,FMT,F6155,1,REAL8,rjob,REAL8,phase,DO,5,INT2,activ,0);

        ioSf("FIND","ACTIVITY$INFO",&K13,"    ",keyact,&K0,&K0,&K0,&irc);
        if(irc != 0) goto S6170;

        dataSf("GET ","ACTIVITY$INFO",&K13,"    ","COMMIT AS EXPENDED",&K18,&itemp[0],&K1,&K0,&K0,&irc);
        if(irc != 0 || itemp[0] != *(short*)fifstrgv("Y ",2)) goto S6170;

        goto S6250;                          /* COMMIT AS EXPENDED */

S6170:

        /*
         --- COMMITMENT VALIDATION ERROR

        */
        ivcmod = *(short*)fifstrgv("B ",2);  /* check for Over "B"illed condition */
        if(check != *(double*)fifstrgv("        ",8)) ivcmod = *(short*)fifstrgv("BW",2);/* Warning Only */
        vcomSc(&ivcmod,&idchg[i-1][0],"PO",&vcno,&rjob,&phase,&activs[i-1][0],&po,&amnts[i-1],&ircS);
        if(ircS == 0) goto S6275;

        for(j=1; j==1 || j<=5; j++)
        {
            blnkSs(&fldnam[j-1],&K8,&irc);
        }

        if(ircS == 7) goto S6225;            /* COMMIT DOES NOT EXISTS REQUIRED */
        if(ircS == 2) goto S3050;            /* COMMIT REQUIRED */

        blnkSs("PO",&K2,&irc);
        posSs("PARK",&K4,&irc);
        bangSs(&irc);
        clrSs(&K24,&K24,&K1,&K78,&ircSS);
        rstSs(&K0,&N1,&ircSS);               /* UN-BLINK ALL FIELDS */
        if(irc == 0) goto S6275;
        if(irc != 8) goto S9000;
        posSs("VCNO",&K4,&irc);
        goto S3050;

S6225:

        /*
           --- PURCHASE$ORDER# NOT FOUND

        */
        blnkSs("PO",&K2,&irc);
        goto S3050;

S6250:

        /*
           --- UNBLINK FIELDS SET BLINKING BY COMMITMENT VALIDATION, IF ANY

        */
        rstSs(&K0,&N1,&irc);

        if(icompr(&po,"-       ",&K8) == 0) goto S6275;

        /*
           --- PACK DATA FOR PURCHASE$ORDER COMMIT AS EXPENDED

        */
        if(amnts[i-1] == 0.e0) goto S6275;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("PO      ",8);/* PURCHASE$ORDER */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);/*  TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);/* DOCUMENT REFERENCE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* PURCHASE$ORDER DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* CASH FLOW DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        mvwrd("CHANGE ORDER    ",&xpScom1_pSscdt[ib+19],&K8);

        ib = ib+21;

S6275:

        /*
             IS THIS AN INTERCOMPANY TRANSACTION

        */
        if(apict[i-1] != 0.e0) goto S6415;   /* INTERCOMPANY TRANSACTION */
        if(amnts[i-1] == 0.e0) goto S6380;

        code[0] = *(double*)fifstrgv("P       ",8);
        if(ircbak == 0 && i == 13) code[0] = *(double*)fifstrgv("P B     ",8);
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
        ------Pack Sales Tax

        */
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S6380;

        iopt = 0;

        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc != 0) goto S6380;
        if(noe == 0) goto S6380;

        tsaltx = taxamt[i-1];

        for(j=1; j==1 || j<=noe; j++)
        {

            crjtax = entity[j-1][4];
            crltax = 0.e0;
            if(crjtax != 0.e0) vglaSc("A ",&rjob,&phase,&crjtax,&crltax,&irc);

            mvwrd("SALES   ",&taxtyp,&K4);   /* Sales Tax */
            if(crjtax != 0.e0) mvwrd("USE     ",&taxtyp,&K4);/* Use Tax */

            if(crltax == 0.e0) crjtax = crjacc;
            if(crltax == 0.e0) crltax = cracct[i-1];

            if(icaltx[i-1] == 0 && icompr(&taxtyp,"SALES ",&K5) == 0) goto S6320;

            /*
            ---------Tax was calculated by the sales tax rate

            */
            taxent = entity[j-1][3]*amnts[i-1]*sbrtio*.01e0;
            goto S6335;

            /*
            ---------Pro-Rate the Sales Tax by entity from tax input by user

            */
S6320:
            ratio = 0.e0;
            if(saltax != 0.e0) ratio = entity[j-1][3]/saltax;
            if(iameq(&ratio,&R11) == 0) ratio = 1.e0;
            taxent = taxamt[i-1]*ratio;

S6335:
            roffSc(&taxent,&R17,&irc);

            if(icompr(&taxtyp,"USE ",&K3) == 0) goto S6350;
            tsaltx = tsaltx-taxent;
S6350:
            /*
            ***     IF ( J .EQ. NOE ) TAXENT = TAXENT + TSALTX
            */
            if(i == lsttax && j == noe) taxent = taxent+staxro;

            WRITE(INTERNAL,memotx,16,FMT,F6355,1,REAL8,taxtyp,REAL8,taxcod[i-1],0);

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("ST      ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = drjacc[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = crjtax;  /* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = dracct[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = crltax;  /* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

        }

S6380:

        /*
         --- PACK DISCOUNT IF NATION = 'NZ' or 'AU'

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6550;

        /*
             check to see whether we have a value to pack

        */
        if(iameq(&adisc[i-1],&R11) == 0) goto S6550;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P       ",8);/* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = adisc[i-1];  /* AMOUNT OF DISCOUNT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        goto S6550;

S6415:

        /*
             PACK THE ORIGINATING COMPANY SIDE OF AN INTERCOMPANY TRANSACTION

        */
        if(amnts[i-1] == 0.e0) goto S6430;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO  */
        /*
        /*  entry

        */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT O ",8);/* PURCHASE - INTERCOMPANY - ORIGINATOR */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = arict[i-1];  /* DEBIT INTERCO A/R ACCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = arict[i-1];  /* DEBIT INTERCO A/R ACCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6430:

        /*
         --- PACK DISCOUNT IF NATION = 'NZ' or 'AU'

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6445;

        /*
             check to see whether we have a value to pack

        */
        if(iameq(&adisc[i-1],&R11) == 0) goto S6445;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT O ",8);/* PURCHASE - INTERCOMPANY - ORIGINATOR */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = adisc[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT DISCOUNT */
        xpScom1_pSscdt[ib+16] = crjacc;      /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT DISCOUNT */
        xpScom1_pSscdt[ib+18] = cracct[i-1]; /* CREDIT ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6445:

        /*
             NOW, PACK CHARGED COMPANY'S SIDE OF INTERCOMPANY TRANSACTION

        */
        if(amnts[i-1] == 0.e0) goto S6550;
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT R ",8);/* PURCHASE - INTERCOMPANY - RECEIVER */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = amnts[i-1];  /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = apict[i-1];  /* CREDIT INTERCO A/P ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = apict[i-1];  /* CREDIT INTERCO A/P ACCOUNT */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;

        ib = ib+22;

        /*
        ------Pack Sales Tax Inter-Company

        */
        if(icompr(&taxcod[i-1],"        ",&K8) == 0) goto S6380;

        iopt = 0;

        staxSc(&iopt,&taxcod[i-1],&effdat,&taxrat,&saltax,&usetax,loctax,entity,&noe,&irc);

        if(irc != 0) goto S6540;
        if(noe == 0) goto S6540;

        tsaltx = taxamt[i-1];

        for(j=1; j==1 || j<=noe; j++)
        {

            crjtax = entity[j-1][4];
            crltax = 0.e0;
            if(crjtax != 0.e0) vglaSc("A ",&rjob,&phase,&crjtax,&crltax,&irc);

            mvwrd("SALES   ",&taxtyp,&K4);   /* Sales Tax */
            if(crjtax != 0.e0) mvwrd("USE     ",&taxtyp,&K4);/* Use Tax */

            if(crltax == 0.e0) crjtax = crjacc;
            if(crltax == 0.e0) crltax = cracct[i-1];

            if(icaltx[i-1] == 0 && icompr(&taxtyp,"SALES ",&K5) == 0) goto S6460;

            /*
            ---------Tax was calculated by the sales tax rate

            */
            taxent = entity[j-1][3]*amnts[i-1]*sbrtio*.01e0;
            goto S6475;

            /*
            ---------Pro-Rate the Sales Tax by entity from tax input by user

            */
S6460:
            ratio = 0.e0;
            if(saltax != 0.e0) ratio = entity[j-1][3]/saltax;
            if(iameq(&ratio,&R11) == 0) ratio = 1.e0;
            taxent = taxamt[i-1]*ratio;

S6475:
            roffSc(&taxent,&R17,&irc);

            if(icompr(&taxtyp,"USE ",&K3) == 0) goto S6490;
            tsaltx = tsaltx-taxent;
S6490:
            if(j == noe) taxent = taxent+tsaltx;
            if(i == lsttax && j == noe) taxent = taxent+staxro;

            WRITE(INTERNAL,memotx,16,FMT,F6494,1,REAL8,taxtyp,REAL8,taxcod[i-1],0);

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("STICT O ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = arict[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = crjtax;  /* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = arict[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = crltax;  /* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

            ib = ib+1;
            xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
            xpScom1_pSscdt[ib] = *(double*)fifstrgv("STICT R ",8);/* SALES TAX */
            xpScom1_pSscdt[ib+1] = 2.e0;     /* VERSION */
            mvwrd(&idchg[i-1][0],&xpScom1_pSscdt[ib+2],&K2);/* COMPANY ID */
            mvwrd(&trtype,&xpScom1_pSscdt[ib+3],&K4);/* TRANSACTION TYPE */
            xpScom1_pSscdt[ib+4] = vcno;     /* VENDOR */
            xpScom1_pSscdt[ib+5] = rjob;     /* JOB */
            xpScom1_pSscdt[ib+6] = phase;    /* PHASE */
            mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+7],&K5);/* ACTIVITY */
            mvwrd(&po,&xpScom1_pSscdt[ib+9],&K4);/* COMMIT ID */
            mvwrd("    ",&xpScom1_pSscdt[ib+10],&K2);/* LINE ITEM */
            mvwrd(&invoic,&xpScom1_pSscdt[ib+11],&K4);/* INVOCIE */
            xpScom1_pSscdt[ib+12] = datinv;  /* INVOICE DATE */
            xpScom1_pSscdt[ib+13] = effdat;  /* EFFECTIVE DATE */
            xpScom1_pSscdt[ib+14] = datdue;  /* DUE DATE */
            xpScom1_pSscdt[ib+15] = amnts[i-1];/* INVOICE AMOUNT */
            mvwrd(&taxcod[i-1],&xpScom1_pSscdt[ib+16],&K4);/* TAX CODE */
            mvwrd(&entity[j-1][0],&xpScom1_pSscdt[ib+17],&K10);/* ENTITY */
            xpScom1_pSscdt[ib+20] = entity[j-1][3];/* TAX RATE */
            xpScom1_pSscdt[ib+21] = taxent;  /* TAX AMOUNT */
            xpScom1_pSscdt[ib+22] = drjacc[i-1];/* DEBIT JOB ACCOUNT */
            xpScom1_pSscdt[ib+23] = apict[i-1];/* CREDIT TAX JOB ACCT */
            xpScom1_pSscdt[ib+24] = dracct[i-1];/* DEBIT LEDGER ACCOUNT */
            xpScom1_pSscdt[ib+25] = apict[i-1];/* CREDIT TAX LEDG ACT */
            mvwrd(memotx,&xpScom1_pSscdt[ib+26],&K8);/* MEMO */
            mvwrd("P       ",&xpScom1_pSscdt[ib+28],&K4);/* PURCHASE JOURNAL */
            mvwrd("B       ",&xpScom1_pSscdt[ib+29],&K4);/* TYPE */
            mvwrd(&taxtyp,&xpScom1_pSscdt[ib+30],&K4);/* SALES OR USE */
            xpScom1_pSscdt[ib+31] = taxemt;  /* Exempt Amount */
            xpScom1_pSscdt[ib+32] = cramnt;  /* Invoice Total */
            xpScom1_pSscdt[ib+33] = taxabl;  /* Invoice Taxable Amnt */
            ib = ib+34;

        }

S6540:

S6550:

        /*
         --- PACK VAT TAX AMOUNT IF APPLICABLE

        */
        actvat = vatdr;
        cract = crjacc;
        cractl = cracct[i-1];
        if(vatamt[i-1] == 0.e0) goto S6640;
        code[0] = *(double*)fifstrgv("P V     ",8);
        if(ircvat != 0) goto S6580;
        WRITE(INTERNAL,code,8,FMT,F6565,1,INT2,vatype,0);

        vivo = 1;                            /* Vat In */
        actvat = vatact[vivo-1][ifgs-1][fordom-1][accpay-1];
        vglaSc("A ",&rjob,&phase,&actvat,&actvat,&irc);
        if(irc == 0) goto S6580;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][accpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6580:

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = vatamt[i-1]; /* AMOUNT OF VAT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = actvat;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = cract;       /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = actvat;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cractl;      /* CREDIT ACCOUNT */
        WRITE(INTERNAL,tmemo,16,FMT,F6595,1,REAL8,amnts[i-1],0);
        mvbyt(tmemo,&xpScom1_pSscdt[ib+19],&K16);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
        ------If this is a Foreign Vendor pack a reversing Vs entry

        */
        if(fordom != 2) goto S6640;
        if(ircvat != 0) goto S6640;
        if(vatype == *(short*)fifstrgv("F ",2)) code[0] = *(double*)fifstrgv("P Vf    ",8);
        if(vatype == *(short*)fifstrgv("G ",2)) code[0] = *(double*)fifstrgv("P Vg    ",8);
        if(vatype == *(short*)fifstrgv("S ",2)) code[0] = *(double*)fifstrgv("P Vs    ",8);
        vivo = 2;                            /* Vat Out */
        actvat = vatact[vivo-1][ifgs-1][fordom-1][accpay-1];
        vglaSc("A ",&rjob,&phase,&actvat,&actvat,&irc);
        if(irc == 0) goto S6620;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][accpay-1]-1][0],&K40,&irc);
        goto S3050;

S6620:

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* PURCHASE */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = -vatamt[i-1];/* AMOUNT OF VAT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = actvat;      /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = cract;       /* CREDIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+17] = actvat;      /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = cractl;      /* CREDIT ACCOUNT */
        WRITE(INTERNAL,tmemo,16,FMT,F6595,1,REAL8,amnts[i-1],0);
        mvbyt(tmemo,&xpScom1_pSscdt[ib+19],&K16);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6640:

        /*
         ----- PACK OUTSIDE EQUIPMENT RENTAL BILLING TRANSACTIONS

        */
        if(datuse[i-1] == 0.e0) goto S6675;  /* no outside rental for this row */
        if(hrsbil[i-1] == 0.e0 && amnts[i-1] == 0) goto S6660;/* no invoice */
        /*
        /* invoice
                                                                 amount for this row

        */
        mvwrd("EQ      ",&xpScom1_pSscdt[ib],&K4);
        mvwrd("OR 1    ",&xpScom1_pSscdt[ib+1],&K4);

        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);
        mvwrd(nunit,&xpScom1_pSscdt[ib+3],&K5);
        xpScom1_pSscdt[ib+5] = datuse[i-1];
        xpScom1_pSscdt[ib+6] = eqjobs[i-1];
        xpScom1_pSscdt[ib+7] = eqphss[i-1];
        mvwrd(&neactv[i-1][0],&xpScom1_pSscdt[ib+8],&K5);
        mvwrd(&nefunc[i-1][0],&xpScom1_pSscdt[ib+10],&K5);
        xpScom1_pSscdt[ib+12] = accteq[i-1];
        xpScom1_pSscdt[ib+13] = effdat;

        xpScom1_pSscdt[ib+14] = 0.e0;
        xpScom1_pSscdt[ib+15] = 0.e0;
        xpScom1_pSscdt[ib+16] = hrsbil[i-1];
        xpScom1_pSscdt[ib+17] = amnts[i-1];

        xpScom1_pSscdt[ib+18] = vcno;

        ib = ib+28;                          /* reserve 9 items for future use */

S6660:

        /*
         ----- PACK AN ADJUSTMENT AMOUNT TO AN OUTSIDE RENTAL ACCRUAL

        */
        if(adjams[i-1] == 0.e0) goto S6675;  /* no adjustment to pack */

        /*
             Prepare memo

        */
        mvwrd("Adjust: ",&memadj[0],&K4);
        outdat(&datuse[i-1],&memadj[4],&K4);

        /*
             Pack the debit side of the entry as a charge to job cost

        */
        ib = ib+1;

        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT R ",8);/* PURCHASE [no ap/ar] */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(&idadj[i-1][0],&xpScom1_pSscdt[ib+1],&K2);/* CHARGED COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = eqjobs[i-1];
        xpScom1_pSscdt[ib+5] = eqphss[i-1];
        mvwrd(&neactv[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = adjams[i-1]; /* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = eqordj[i-1]; /* DEBIT JOB ACCOUNT */
        /*
         *** P$SCDT(IB+17) = CRJACC             CREDIT JOB ACCOUNT
        */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT JOB ACCOUNT */
        if(icompr(&idadj[i-1][0],xc_cScoid,&K4) != 0) xpScom1_pSscdt[ib+16] = apadj[i-1];/* INTERCOMPANY PAYABLE ACCOUNT */
        xpScom1_pSscdt[ib+17] = eqordl[i-1]; /* DEBIT ACCOUNT */
        /*
         *** P$SCDT(IB+19) = CRACCT(I)          CREDIT ACCOUNT
        */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        if(icompr(&idadj[i-1][0],xc_cScoid,&K4) != 0) xpScom1_pSscdt[ib+18] = apadj[i-1];/* INTERCOMPANY PAYABLE ACCOUNT */
        mvwrd(memadj,&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
             Pack the credit side of the entry as an accrual for outside
                rental expense in the equipment cost center

        */
        ib = ib+1;

        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("P ICT R ",8);/* PURCHASE [no ap/ar] */
        xpScom1_pSscdt[ib+1] = 2.e0;         /* VERSION # */
        ib = ib+1;
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = eqccjb;
        xpScom1_pSscdt[ib+5] = eqccph;
        mvwrd(nunit,&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* DUE DATE */
        xpScom1_pSscdt[ib+13] = -adjams[i-1];/* AMOUNT OF PURCHASE */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        /*
         *** P$SCDT(IB+16) = DRJACC(I)          DEBIT JOB ACCOUNT
        */
        xpScom1_pSscdt[ib+15] = accteq[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT JOB ACCOUNT */
        if(icompr(&idadj[i-1][0],xc_cScoid,&K4) != 0) xpScom1_pSscdt[ib+16] = aradj[i-1];/* INTERCOMPANY RECEIVABLE ACCOUNT */
        /*
         *** P$SCDT(IB+18) = DRACCT(I)          DEBIT ACCOUNT
        */
        xpScom1_pSscdt[ib+17] = accteq[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        if(icompr(&idadj[i-1][0],xc_cScoid,&K4) != 0) xpScom1_pSscdt[ib+18] = aradj[i-1];/* INTERCOMPANY RECEIVABLE ACCOUNT */
        mvwrd(memadj,&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        mvwrd("EQ      ",&xpScom1_pSscdt[ib],&K4);
        mvwrd("OR 1    ",&xpScom1_pSscdt[ib+1],&K4);

        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+2],&K2);
        mvwrd(nunit,&xpScom1_pSscdt[ib+3],&K5);
        xpScom1_pSscdt[ib+5] = datuse[i-1];
        xpScom1_pSscdt[ib+6] = eqjobs[i-1];
        xpScom1_pSscdt[ib+7] = eqphss[i-1];
        mvwrd(&neactv[i-1][0],&xpScom1_pSscdt[ib+8],&K5);
        mvwrd(&nefunc[i-1][0],&xpScom1_pSscdt[ib+10],&K5);
        xpScom1_pSscdt[ib+12] = accteq[i-1];
        xpScom1_pSscdt[ib+13] = effdat;

        xpScom1_pSscdt[ib+14] = 0.e0;
        xpScom1_pSscdt[ib+15] = adjams[i-1]; /* adjust accrual */
        xpScom1_pSscdt[ib+16] = 0.e0;
        xpScom1_pSscdt[ib+17] = 0.e0;

        xpScom1_pSscdt[ib+18] = vcno;

        ib = ib+28;                          /* reserve 9 items for future use */

S6675:

        /*
         ----- PACK TIME AND EXPENSE DATA

             INITIALIZE TIME & EXPENSE VARIABLES

        */
        initSb(&irc);

        xbilcom_bSbtch = batch;
        xbilcom_bSdate = effdat;

        mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
        xbilcom_bSvcno = clntli[i-1];        /* CLIENT NUMBER */
        xbilcom_bSvndr = vcno;               /* VENDOR NUMBER */
        mvwrd(&invoic,xbilcom_bSvinv,&K4);   /* VENDOR INVOICE */
        xbilcom_bSvind = datinv;             /* VENDOR INVOICE DATE */
        mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
        xbilcom_bSdrja = drjacc[i-1];        /* VENDOR DR JOB ACCOUNT */
        xbilcom_bSdrgl = dracct[i-1];        /* VENDOR DR GL ACCOUNT */
        xbilcom_bScrja = 0.0e0;              /* VENDOR CR JOB ACCOUNT */
        xbilcom_bScrgl = 0.0e0;              /* VENDOR CR GL ACCOUNT */

        xbilcom_bScjob = rjob;               /*  CHARGE JOB */
        xbilcom_bScphs = phase;              /*  CHARGE PHASE */
        xbilcom_bSjcda = drjacc[i-1];        /*  ACCOUNT CHARGED */
        mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
        mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
        xbilcom_bSqty = quanty[i-1];         /*  QUANTITY */
        xbilcom_bSamnt = amnts[i-1];         /*  $ AMOUNT */
        xbilcom_bSref = refno;               /*  REFERENCE NUMBER */
        xbilcom_bSpo = po;                   /*  COMMITMENT ID */
        mvwrd(&inobil[i-1],&xbilcom_bSnbil,&K1);/*  NON-BILLABLE FLAG */
        xpScom1_noscSp = ib;

        T1 = NBWRNS;                         /* request billing rate */
        flagSc("U ","S ",&T1,&irc);
        autote(&irc);
        if(irc == 7) irc = 0;
        if(irc != 0) goto S3050;             /*  ERROR IN T&E BILLING */

        ib = xpScom1_noscSp;

        if(adjhrs[i-1] == 0.e0) goto S6700;  /* no adjustment to be calculated */
        /*
        /* calculated

             INITIALIZE TIME & EXPENSE VARIABLES - for use by EQCALC

        */
        initSb(&irc);

        xbilcom_bSbtch = batch;
        xbilcom_bSdate = effdat;

        xpScom1_noscSp = ib;

        /*
             Prepare memo for adjustment to equipment usage

        */
        mvwrd("Adjust: ",&memadj[0],&K4);
        outdat(&datuse[i-1],&memadj[4],NULL);

        eqcalc(&nfunc,&backed,&batch,&refno,"P ","HR  ",nunit,&eqjobs[i-1],&eqphss[i-1],&neactv[i-1][0],&nefunc[i-1][0],
          &datuse[i-1],memadj,&vcno,&adjhrs[i-1],&R11,&R11,&rental,&rentor,&irc);
        if(irc != 0) goto S3050;

        ib = xpScom1_noscSp;

S6700:;
    }

    /*
         IF THIS ITEM IS ALREADY PAID, PACK CASH DISBURSEMENT DATA

    */
    if(icompr(&check,"        ",&K8) == 0) goto S6960;

    for(i=1,D23=(D23=(xbb_lsetSb-i+1))>0?D23:1; D23>0; D23--,i+=1)
    {

        if(litem[i-1] == 0) goto S6950;

        /*
        ------See if buffer is dangerously full

        */
        if(ib < MAXSCD-1500) goto S6740;

        /*
        ------If we have not yet BACKED up this reference this is the time to do it

        */
        if(backed) goto S6725;

        backed = TRUE;
        if(nfunc == *(short*)fifstrgv("A ",2)) goto S6725;

        iSback("BACK",&batch,&refno,&irc);
        if(irc != 0) goto S9000;

        iSdlet(&batch,&refno,&irc);

S6725:
        xpScom1_nscdat = xpScom1_nscdat+1;
        iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
        iSxinv(&batch,&refno,&vcno,&invoic,&irc);
        if(ircdin == 0) iSxdin(&batch,&refno,idin,&irc);
        ib = 0;

S6740:

        xc_cSrow = i;

        /*
             Get the BILLING REFERENCE if there is one

        */
        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);
        code[0] = *(double*)fifstrgv("CD      ",8);
        if(i == 13 && ircbak == 0) code[0] = *(double*)fifstrgv("CDB     ",8);
        pstamt = amnts[i-1];
        if(xc_cSntnl == *(short*)fifstrgv("NZ",2) || xc_cSntnl == *(short*)fifstrgv("AU",2)) pstamt = pstamt+adisc[i-1];

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = pstamt;      /* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = adisc[i-1];  /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
         ---- PACK DATA FOR VAT AMOUNT PAID ON THIS CHECK

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2) && fabs(vatamt[i-1]) <
          .001e0) goto S6860;

        code[0] = *(double*)fifstrgv("CDV     ",8);
        if(ircvat == 0) WRITE(INTERNAL,code,8,FMT,F6765,1,INT2,vatype,0);

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT  ( VAT ) */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = vatamt[i-1]; /* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

        /*
         -----If this is a Foreign Vendor and Vat type is Service, pack Vs type

        */
        if(fordom != 2) goto S6780;
        if(ircvat != 0) goto S6780;
        if(vatype == *(short*)fifstrgv("F ",2)) code[0] = *(double*)fifstrgv("CDVf    ",8);
        if(vatype == *(short*)fifstrgv("G ",2)) code[0] = *(double*)fifstrgv("CDVg    ",8);
        if(vatype == *(short*)fifstrgv("S ",2)) code[0] = *(double*)fifstrgv("CDVs    ",8);
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = code[0];        /* CASH DISBURSEMENT  ( VAT ) */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLES BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = invoic;       /* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* INVOICE DATE */
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = effdat;      /* EFFECTIVE DATE OF INVOICE PAID */
        xpScom1_pSscdt[ib+13] = -vatamt[i-1];/* AMOUNT OF PAYMENT */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT TAKEN */
        xpScom1_pSscdt[ib+15] = crjacc;      /* DEBIT JOB ACCOUNT (USE CREDIT ACCOUNT PAYABLE) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = cracct[i-1]; /* DEBIT ACCOUNT (USE CREDIT ACCOUNT PAYABLE */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd(&rmemo[i-1][0],&xpScom1_pSscdt[ib+19],&K8);
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6780:

        /*
         -----Pack entry to reverse accrued Vat and post to Payable Vat

        */
        if(fabs(vatamt[i-1]) < .001e0) goto S6860;/* NO VAT PAID */
        if(vatype != *(short*)fifstrgv("S ",2)) goto S6860;
        vivo = 1;                            /* Vat In */
        iacpay = 2;                          /* Payable */
        dract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&dract,&dractl,&irc);
        if(irc == 0) goto S6795;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][1],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6795:
        vivo = 1;                            /* Vat In */
        iacpay = 1;                          /* Accrued */
        cract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&cract,&cractl,&irc);
        if(irc == 0) goto S6825;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6825:
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("D       ",8);/* Debit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = dract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = dractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("C       ",8);/* Credit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = cract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = cractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        /*
         -----Pack entry to reverse accrued Vat Out and post to Payable Vat Out

        */
        if(fabs(vatamt[i-1]) < .001e0) goto S6860;/* NO VAT PAID */
        if(fordom != 2) goto S6860;
        if(vatype != *(short*)fifstrgv("S ",2)) goto S6860;
        vivo = 2;                            /* Vat Out */
        iacpay = 1;                          /* Accrued */
        dract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&dract,&dractl,&irc);
        if(irc == 0) goto S6840;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][1],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6840:
        if(fordom == 2) vivo = 2;            /* Foreign is Vat Out */
        if(fordom == 2) iacpay = 2;          /* Foreign is Payable */
        cract = vatact[vivo-1][ifgs-1][fordom-1][iacpay-1];
        vglaSc("A ",&rjob,&phase,&cract,&cractl,&irc);
        if(irc == 0) goto S6855;
        errSs(&vatdsc[despnt[vivo-1][ifgs-1][fordom-1][iacpay-1]-1][0],&K40,&irc);
        bangSs(&irc);
        goto S3050;

S6855:
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("D       ",8);/* Debit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = dract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = dractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("GJ      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("C       ",8);/* Credit */
        xpScom1_pSscdt[ib+1] = vatamt[i-1];  /* AMOUNT */
        xpScom1_pSscdt[ib+2] = cract;        /* JOB ACCOUNT */
        xpScom1_pSscdt[ib+3] = cractl;       /* LEDGER ACCOUNT */
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+4],&K2);/* COMPANY ID */
        xpScom1_pSscdt[ib+5] = rjobs[i-1];   /* JOB/PHASE */
        mvwrd("          ",&xpScom1_pSscdt[ib+6],&K5);/* BLANK ACTIVITY */
        if(ipbya == *(short*)fifstrgv("Y ",2)) mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);/* ONLY IF PAYABLE BY ACTIVITY */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* HOURS */
        xpScom1_pSscdt[ib+9] = 0.e0;         /* CLASSIFICATION */
        xpScom1_pSscdt[ib+10] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(1) */
        xpScom1_pSscdt[ib+11] = *(double*)fifstrgv("        ",8);/* LINE ITEM MEMO(2) */
        xpScom1_pSscdt[ib+12] = chkdat;      /* (Check date) of invoice */
        ib = ib+13;

S6860:

        /*
             RECORD DISCOUNT TAKEN, IF ANY

        */
        if(fabs(adisc[i-1]) < .001e0) goto S6950;

        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("CD      ",8);/* CASH DISBURSEMENT */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd(&trtype,&xpScom1_pSscdt[ib+2],&K4);
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = xc_cSdacj;
        xpScom1_pSscdt[ib+5] = xc_cSdacp;
        mvwrd(dscact,&xpScom1_pSscdt[ib+6],&K5);

        /*
             If NZ, or AU use actual job, phase and activity and not defaults

        */
        if(xc_cSntnl != *(short*)fifstrgv("NZ",2) && xc_cSntnl != *(short*)fifstrgv("AU",2)) goto S6940;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);

S6940:
        xpScom1_pSscdt[ib+8] = *(double*)fifstrgv("-       ",8);/* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);
        xpScom1_pSscdt[ib+10] = 0.e0;
        xpScom1_pSscdt[ib+11] = chkdat;      /* DATE OF PAYMENT */
        xpScom1_pSscdt[ib+12] = 0.e0;
        xpScom1_pSscdt[ib+13] = -adisc[i-1]; /* AMOUNT OF DISCOUNT EARNED (NOTE  */
        /*
        /*  CONTRA AMOUNT)
        */
        xpScom1_pSscdt[ib+14] = 0.e0;
        xpScom1_pSscdt[ib+15] = dscern;      /* DEBIT JOB ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+16] = cash;        /* CREDIT JOB ACCOUNT (CASH) */
        xpScom1_pSscdt[ib+17] = dsc[i-1];    /* DEBIT ACCOUNT (DISCOUNTS EARNED) */
        xpScom1_pSscdt[ib+18] = csh[i-1];    /* CREDIT ACCOUNT (CASH) */
        mvwrd("Discnt: ",&xpScom1_pSscdt[ib+19],&K4);/* PUT INVOICE ON WHICH  */
        /*
        /*  DISCOUNT
        */
        mvwrd(&invoic,&xpScom1_pSscdt[ib+20],&K4);/* WAS EARNED IN MEMO */
        xpScom1_pSscdt[ib+21] = check;       /* CHECK NUMBER */

        ib = ib+22;

S6950:;
    }

    /*
    ----------------------------------------------------------------------C

    */
S6960:

    /*
     --- CLOSE COMMITMENTS

     ---  CLOSE THIS COMMITMENT FOR EACH JOB/PHASE/ACTIVITY

    */
    for(i=1,D25=(D25=(xbb_lsetSb-i+1))>0?D25:1; D25>0; D25--,i+=1)
    {

        if(nswcls == 0 && nclos[i-1] == 0) goto S7090;

        if(litem[i-1] == 0) goto S7090;      /* NOT USED */

        xc_cSrow = i;

        /*
             Get the BILLING REFERENCE if there is one

        */
        dataSs("BILLING REFERENCE",&K17,&xbilcom_bSbref,&K0,&irc);

        invoic = invli[i-1];
        po = poli[i-1];
        datinv = invdli[i-1];
        if(i == 1) goto S7030;

        /*
         --- SEE IF JOB/PHASE/ACTIVITY HAS ALREADY BEEN CLOSED

        */
        kk = i-1;
        for(k=0; k==0 || k<kk; k++)
        {
            if(litem[k] == 0) goto S7020;    /* NOT USED */
            if(rjobs[i-1] != rjobs[k] || icompr(&activs[i-1][0],&activs[k][0],&K10) != 0) goto S7020;
            if(nswcls == 0 && nclos[k] == 0) goto S7020;
            goto S7090;
S7020:;
        }

S7030:

        /*
         --- GET THE UNBILLED AMOUNT FOR THE JOB/PHASE/ACTIVITY/PO

        */
        spltjp(&rjobs[i-1],&rjob,&phase,&irc);
        jinfSc(&rjob,&phase,"JC  ","COMPANY ID",&K10,jcoid,&K4,&K0,&K0,&irc);

        mvbyt(&activs[i-1][0],activ,&K10);

        for(iclr=0; iclr==0 || iclr<10; iclr++)
        {                                    /* CLEAR ALL ELEMENTS... */
            data[iclr] = 0.e0;               /* ...OF EXPANDED C$M... */
        }

        /*
         --- ENCODE KEY TO THE COMMITMENT$MASTER

        */
        WRITE(INTERNAL,keycSm,120,FMT,F7040,1,DO,2,INT2,jcoid,REAL8,vcno,REAL8,rjob,REAL8,phase,DO,5,INT2,activ,REAL8,
          po,0);                             /* ...BUFFER */

        ioSf("FIND","COMMITMENT$MASTER",&K17,"    ",keycSm,&K0,&K0,&K0,&irc);
        if(irc == 7) goto S7090;

        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$ORIGINAL",&K9,&data[0],&K0,&K0,&K0,&irc);
        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$CHANGE  ",&K7,&data[1],&K0,&K0,&K0,&irc);
        gdatSf("GET ","COMMITMENT$MASTER",&K17,"    ","$BILLED  ",&K7,&data[2],&K0,&K0,&K0,&irc);

        /*
         --- CHECK IF THERE IS A CURRENT BILLING FOR THIS COMMITMENT

        */
        tamnt = 0.e0;
        for(k=0; k==0 || k<xbb_lsetSb; k++)
        {
            if(litem[k] == 0) goto S7060;    /* NOT USED */
            if(rjobs[i-1] == rjobs[k] && icompr(&activs[i-1][0],&activs[k][0],&K10) == 0) tamnt = tamnt+amnts[k];
S7060:;
        }

        /*
         --- CALCULATE UNBILLED AMOUNT

        */
        clsamt = data[0]+data[1]-(data[2]+tamnt);

        if(clsamt == 0.e0) goto S7090;       /* COMMITMENT IS BILLED IN FULL */

        /*
         --- PACK DATA TO CLOSE A COMMITMENT

        */
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("PO      ",8);/* PURCHASE ORDER */
        xpScom1_pSscdt[ib+1] = *(double*)fifstrgv("        ",8);
        mvwrd(xc_cScoid,&xpScom1_pSscdt[ib+1],&K2);/* COMPANY ID */
        mvwrd("        ",&xpScom1_pSscdt[ib+2],&K4);/* DUMMY TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;
        xpScom1_pSscdt[ib+4] = rjob;
        xpScom1_pSscdt[ib+5] = phase;
        mvwrd(&activs[i-1][0],&xpScom1_pSscdt[ib+6],&K5);
        xpScom1_pSscdt[ib+8] = po;           /* COMMITMENT */
        xpScom1_pSscdt[ib+9] = *(double*)fifstrgv("        ",8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+10] = datinv;      /* PURCHASE ORDER DATE */
        xpScom1_pSscdt[ib+11] = effdat;      /* EFFECTIVE DATE */
        xpScom1_pSscdt[ib+12] = datdue;      /* CASH FLOW DATE */
        xpScom1_pSscdt[ib+13] = -clsamt;     /* AMOUNT OF PURCHASE ORDER */
        xpScom1_pSscdt[ib+14] = 0.e0;        /* DISCOUNT AVAILABLE */
        xpScom1_pSscdt[ib+15] = drjacc[i-1]; /* DEBIT JOB ACCOUNT */
        xpScom1_pSscdt[ib+16] = 0.e0;        /* CREDIT ACCOUNT */
        xpScom1_pSscdt[ib+17] = dracct[i-1]; /* DEBIT ACCOUNT */
        xpScom1_pSscdt[ib+18] = 0.e0;        /* CREDIT ACCOUNT */
        mvwrd("CHANGE ORDER    ",&xpScom1_pSscdt[ib+19],&K8);

        ib = ib+21;

        /*
         ----- Pack T&E for Closed Commitment

             INITIALIZE TIME & EXPENSE VARIABLES

        */
        initSb(&irc);

        xbilcom_bSbtch = batch;
        xbilcom_bSdate = effdat;

        mvwrd(&idchg[i-1][0],xbilcom_bScoid,&K2);/* CHARGED COMPANY ID */
        xbilcom_bSvcno = clntli[i-1];        /* CLIENT NUMBER */
        xbilcom_bSvndr = vcno;               /* VENDOR NUMBER */
        mvwrd(&invoic,xbilcom_bSvinv,&K4);   /* VENDOR INVOICE */
        xbilcom_bSvind = datinv;             /* VENDOR INVOICE DATE */
        mvwrd(&rmemo[i-1][0],xbilcom_bSvmem,&K8);/* VENDOR INVOICE MEMO */
        xbilcom_bSdrja = drjacc[i-1];        /* VENDOR DR JOB ACCOUNT */
        xbilcom_bSdrgl = dracct[i-1];        /* VENDOR DR GL ACCOUNT */
        xbilcom_bScrja = 0.0e0;              /* VENDOR CR JOB ACCOUNT */
        xbilcom_bScrgl = 0.0e0;              /* VENDOR CR GL ACCOUNT */

        xbilcom_bScjob = rjob;               /*  CHARGE JOB */
        xbilcom_bScphs = phase;              /*  CHARGE PHASE */
        xbilcom_bSjcda = drjacc[i-1];        /*  ACCOUNT CHARGED */
        mvwrd(&activs[i-1][0],xbilcom_bSactv,&K5);/*  ACTIVITY */
        mvwrd(&irescd[i-1][0],xbilcom_bSresc,&K8);/*  RESOURCE CODE */
        xbilcom_bSqty = quanty[i-1];         /*  QUANTITY */
        xbilcom_bSamnt = -clsamt;            /*  $ AMOUNT */
        xbilcom_bSref = refno;               /*  REFERENCE NUMBER */
        xbilcom_bSpo = po;                   /*  COMMITMENT ID */
        xbilcom_bScom = 1.0e0;               /*  COMMITMENT FLAG */
        xpScom1_noscSp = ib;

        autote(&irc);
        xbilcom_bScom = 0.0e0;               /*  ACCRUAL FLAG */
        if(irc == 7) irc = 0;
        if(irc != 0) goto S3050;             /*  ERROR IN T&E BILLING */

        ib = xpScom1_noscSp;

S7090:;
    }

    /*
    ----------------------------------------------------------------------C

         check if DIN exists, if so, then check it

    */
    dataSs("DIN ",&K3,idin,&K78,&ircdin);
    if(ircdin != 0) goto S7100;

    chkdin(&batch,&refno,idin,&irc);
    if(irc == 0) goto S7100;

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* DON'T STOP IF ON 'RE-ENTER' */

    if(xsc1_scSsmd != 21) goto S7095;

    /*
         Handle confirmation when in Web Edition

    */
    confrm("Duplicate DIN~",&K0,&irc);
    if(irc == 0) goto S7100;

    goto S7140;

S7095:

    inatSb(&K24,&K1,"Duplicate DIN - enter OK to continue, or ^ to change",&K53,nresp,&K24,&irc);

    if(irc == 9) goto S9000;                 /* BANG */
    if(irc == 8) goto S7140;                 /* ROOFTOP */
    if(irc == 0 && icompr(nresp,"OK",&K2) == 0) goto S7100;/* OK */
    goto S7140;

S7100:
    ierrs = 0;
    if(invchk == 0 && ierrs == 0) goto S7150;
    if(invchk == 0 && ierrs > 0) goto S7500;

    chkjob = 0.e0;
    chkphs = 0.e0;
    idupls = 0;

    if(invchk == 1) n = 1;                   /* CHECK AT INVOICE LEVEL */
    if(invchk == 2) n = xbb_lsetSb;          /* CHECK AT JOB/PHASE LEVEL */
    if(linitm) n = xbb_lsetSb;               /* INVOICE # ON LINE ITEM */
    for(i=1; i==1 || i<=n; i++)
    {                                        /* POSSIBLE LINE ITEM INVOICE# */
        if(litem[i-1] == 0) goto S7125;
        invoic = invli[i-1];
        if(invchk == 1) goto S7110;
        spltjp(&rjobs[i-1],&chkjob,&chkphs,&irc);
S7110:

        chkiSc(&K33,"P ",&vcno,"B ",&invoic,&chkjob,&chkphs,&irc);
        if(irc != 7) goto S7120;

        chkinv(&batch,&refno,&vcno,&invoic,&irc);
        if(irc == 0) goto S7125;

S7120:

        blnkSs("VCNO",&K4,&irc);
        blnkSs("INVOICE ",&K7,&irc);
        if(invchk == 2) blnkSs(&fldnam[2],&K7,&irc);
        idupls = 1;
S7125:;
    }

    if(ierrs == 0 && idupls == 0) goto S7150;
    if(ierrs > 0 && idupls == 0) goto S7500;
    if(nswvb == 1) goto S7150;

    /*
     ---- Duplicate invoice.  Warn user, and either make them
          input something to show they know, or just accept a
          return.

    */
    if(invdup > 0) goto S7130;
    errSs("Invoice already on file... Return to continue, or ^ to change~",&K0,&irc);

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* DON'T STOP IF ON 'RE-ENTER' */

    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7150;
    if(irc == 8) goto S7140;                 /* ROOFTOP */
    goto S9000;                              /* USER WANTS OUT */

S7130:

    /*
     ---- Make the user acknowledge the duplicate situation with
          an "OK"

    */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8000;/* DON'T STOP IF ON 'RE-ENTER' */

    if(xsc1_scSsmd != 21) goto S7132;

    /*
         Handle confirmation when in Web Edition

    */
    confrm("Invoice already on file~",&K0,&irc);
    if(irc == 0) goto S7150;

    goto S7140;

S7132:

    inatSb(&K24,&K1,"Invoice already on file...enter OK to continue, or ^ to change",&K62,nresp,&K24,&irc);

S7135:
    if(irc == 9) goto S9000;                 /* BANG */
    if(irc == 8) goto S7140;                 /* ROOFTOP */
    if(irc == 0 && icompr(nresp,"OK",&K2) == 0) goto S7150;/* OK */

    clrSs(&K24,&K24,&K1,&K78,&irc);
    inatSb(&K24,&K1,"Valid responses are 'OK', ^, or !",&K33,nresp,&K24,&irc);
    goto S7135;                              /* INVALID ANSWER...RE-ASK */

S7140:

    /*
     ---- Rooftop handler.  If rooftop is the response, unblink the
          blinking fields and position cursor for screen work.

    */
    clrSs(&K24,&K24,&K1,&K78,&irc);
    rstSs(&K0,&N1,&irc);                     /* UN-BLINK ALL FIELDS */
    posSs("INVOICE ",&K7,&irc);
    goto S3050;

S7150:

    /*
     ----------------------------------------------------------------------

         If the amount of this invoice is greater than the amount logged for
            this invoice, pack a HOLD.

    */
    n = 1;
    if(linitm) n = xbb_lsetSb;

    for(i=1,D27=(D27=(n-i+1))>0?D27:1; D27>0; D27--,i+=1)
    {

        if(litem[i-1] == 0) goto S7180;

        invoic = invli[i-1];
        linvSc("P ",&vcno,&invoic,&irc);     /* GET LOGGED AMOUNT */
        if(xtrkcom_amtlog == 0.e0) goto S7180;/* invoice not logged */
        if(!linitm) goto S7160;
        if(amnts[i-1] <= xtrkcom_amtlog) goto S7180;

S7160:
        if(cramnt <= xtrkcom_amtlog) goto S7180;/* not greater than logged amount */
        ib = ib+1;

        packjm(&i,xpScom1_pSscdt,&ib,&ircx); /* Potentially Pack JOURNALS$MEMO entry */
        xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
        xpScom1_pSscdt[ib] = *(double*)fifstrgv("H       ",8);/* HOLD INVOICE */
        ib = ib+1;
        xpScom1_pSscdt[ib] = 2.e0;           /* VERSION */
        mvbyt(xc_cScoid,&xpScom1_pSscdt[ib+1],&K4);/* COMPANY ID */
        mvbyt(&trtype,&xpScom1_pSscdt[ib+2],&K8);/* TRANSACTION TYPE */
        xpScom1_pSscdt[ib+3] = vcno;         /* V/C NUMBER */
        xpScom1_pSscdt[ib+4] = 0.e0;
        xpScom1_pSscdt[ib+5] = 0.e0;
        xpScom1_pSscdt[ib+6] = 0.e0;         /* HELD AMOUNT */
        mvbyt(&invoic,&xpScom1_pSscdt[ib+7],&K8);/* INVOICE NUMBER */
        xpScom1_pSscdt[ib+8] = 0.e0;         /* EXPIRED DATE */
        xpScom1_pSscdt[ib+9] = effdat;       /* EFFECTIVE DATE */
        mvbyt("LOG ERR ",&xpScom1_pSscdt[ib+10],&K8);/* HOLD CODE */
        mvbyt("AMOUNT EXCEEDS LOG      ",&xpScom1_pSscdt[ib+11],&K24);/* HOLD  */
        /*
        /*  DESCP
        */
        mvwrd(&po,&xpScom1_pSscdt[ib+14],&K4);/* COMMIT ID */
        ib = ib+15;

S7180:;
    }

    /*
     ----------------------------------------------------------------------

         GET CONFIRMATION BEFORE POSTING ITEM

    */
    if(nfunc == *(short*)fifstrgv("R ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */
    if(nfunc == *(short*)fifstrgv("X ",2)) goto S7920;/* DON'T STOP ON 'RE-ENTER' */

    /*
     --- TEST TO SEE IF PPS CAN BE CHANGED

    */
    if(pps1 < 0.e0) goto S7500;

    vinfSc(&vcno,"    ","DATE PPS EXPIRY",&K15,&epps,&K0,&K0,&K0,&irc);

    x = 0.0e0;
    if(x == x) goto S7325;                   /* EXPIRY DATE NOT USED */

    if(datdue <= epps) goto S7325;

    outdat(&epps,&odate,NULL);
    WRITE(INTERNAL,xc_cSmess,78,FMT,F7320,1,REAL8,odate,0);
    errSs(xc_cSmess,&K78,&irc);
    bangSs(&irc);

S7325:
    errSs("Good entry.  RETURN to continue, \"*\" to change PPS, or \"^\"~",&K0,&irc);
    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7400;
    if(irc == 4) goto S8000;
    if(irc == 8) goto S1800;
    if(irc != 2) goto S9000;

    /*
     --- TOGGLE PPS

    */
    if(pps2 < 0.e0) goto S7350;              /* 'N     ' WAS DISPLAYED */
    pps2 = -1.e0;
    ppsout[0] = *(double*)fifstrgv("N       ",8);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K4,&irc);
    goto S7325;

S7350:
    pps2 = pps1;
    WRITE(INTERNAL,ppsout,5,FMT,F7375,1,REAL8,pps2,0);
    doutSs("PPS APPLICABLE",&K14,&ppsout[0],&K5,&irc);
    goto S7325;

S7400:
    if(pps1 == pps2) goto S7600;

    /*
     --- PACK PPS HOLD WHEN OVERRIDDEN

    */
    ib = ib+1;

    packjm(&i,xpScom1_pSscdt,&ib,&ircx);     /* Potentially Pack JOURNALS$MEMO entry */
    xpScom1_pSscdt[ib-1] = *(double*)fifstrgv("TR      ",8);/* TRANSACTIONS */
    xpScom1_pSscdt[ib] = *(double*)fifstrgv("H       ",8);/* HOLD PURCHASE ORDER */
    ib = ib+1;
    xpScom1_pSscdt[ib] = 2.e0;               /* VERSION */
    mvbyt(xc_cScoid,&xpScom1_pSscdt[ib+1],&K4);/* COMPANY ID */
    mvbyt(&trtype,&xpScom1_pSscdt[ib+2],&K8);/* TRANSACTION TYPE */
    xpScom1_pSscdt[ib+3] = vcno;             /* V/C NUMBER */
    xpScom1_pSscdt[ib+4] = 0.e0;
    xpScom1_pSscdt[ib+5] = 0.e0;
    xpScom1_pSscdt[ib+6] = 0.e0;             /* HELD AMOUNT */
    mvbyt(&invoic,&xpScom1_pSscdt[ib+7],&K8);/* INVOICE NUMBER */
    xpScom1_pSscdt[ib+8] = 0.e0;             /* EXPIRED DATE */
    xpScom1_pSscdt[ib+9] = effdat;           /* EFFECTIVE DATE */
    mvbyt("*PPS    ",&xpScom1_pSscdt[ib+10],&K8);/* HOLD CODE */
    mvbyt("PPS WAS OVERRIDDEN  ",&xpScom1_pSscdt[ib+11],&K20);/* HOLD DESCP */
    mvwrd(&po,&xpScom1_pSscdt[ib+14],&K4);   /* COMMIT ID */
    ib = ib+15;
    goto S7600;

S7500:

    /*
     --- GOOD ENTRY

    */
    errSs("Good entry. RETURN to continue. Otherwise, enter ^~",&K0,&irc);
    posSs("PARK",&K4,&irc);
    bangSs(&irc);
    if(irc == 0) goto S7600;
    if(irc == 4) goto S8000;
    goto S8200;

S7600:

    /*
         IF THIS IS A CHANGE, DELETE PRIOR VERSION OF THIS ITEM

    */
    rstSs(&K0,&N1,&irc);                     /* UN-BLINK ALL FIELDS */
    if(nfunc != *(short*)fifstrgv("C ",2)) goto S7950;
S7920:
    if(xpScom1_nscdat > 0) goto S7950;
    if(nswvb == 1) goto S7940;
    iSdlet(&batch,&refno,&irc);
    if(irc == 9) goto S9000;
    goto S7950;

S7940:

    /*
     ----- Change the Reference # for the revised version of Verify Batch

    */
    mvbyt(&refno,&hldref,&K8);
    jstrSa(1,&refno,8);
    mvbyt("/ ",&refno,&K1);
    rmvbSc(&refno,&K8,&K0,&len,&irc);

    /*
         DELETE REVISED VERSION OF REFERENCE, IF IT ALREADY EXISTS

    */
    if(xpScom1_nscdat > 0) goto S7945;

    iSdlet(&batch,&refno,&irc);

S7945:
    /*
         SAVE IMAGE OF INPUT SCREEN

    */
S7950:
    if(image) prntSs(&K1,&irc);
    iSsave(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    /*
         SAVE DATA FROM SCREEN

    */
    xpScom1_nscdat = xpScom1_nscdat+1;
    iSdatm(&batch,&refno,&xpScom1_nscdat,xpScom1_pSscdt,&ib,&irc);
    ib = 0;
    if(irc != 0) goto S9000;

    iSxinv(&batch,&refno,&vcno,&invoic,&irc);
    if(ircdin == 0) iSxdin(&batch,&refno,idin,&irc);

    if(backed) iSback("DLET",&batch,&refno,&irc);

    if(nswvb == 1) mvbyt(&hldref,&refno,&K8);

    goto S1800;

S8000:

    /*
         SAVE screen image of a BAD entry screen

    */
    nread = 1;                               /* set flag to read current screen image */
    goto S8100;

S8050:
    nread = 0;                               /* reset flag - don't read  screen image */
    goto S8100;

S8100:

    /*
         delete all previous references to this Batch#/Reference#

    */
    iSdlet(&batch,&refno,&irc);
    if(irc == 7) irc = 0;
    if(irc != 0) goto S9000;

    /*
         SAVE image of BAD screen in INPUT$BATCHES

    */
    iSbad(&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    if(backed) iSback("DLET",&batch,&refno,&irc);

    if(nfunc == *(short*)fifstrgv("X ",2)) goto S8120;/* DON'T STOP ON RE-ENTER */
    errSs("Screen SAVED for later use.  RETURN to continue~",&K0,&irc);
    bangSs(&irc);
S8120:
    if(irc == 0) goto S1800;
    goto S9000;

S8200:
    if(!backed) goto S1800;

    /*
    ------Restore Backed Up copy of this reference

    */
    iSback("REST",&batch,&refno,&irc);
    if(irc != 0) goto S9000;

    goto S1800;

S9000:
    if(nswvb != 1) goto S9100;

    /*
     ----- Check to see if any more records in the Verify Batch

    */
    fill(xc_cSmess,&K4,"  ");
    iSnext(&batch,xc_cSmess,&irc);
    if(irc <= 1) goto S9100;

    /*
     ----- No more records, Delete the Verify Batch

    */
    iSdlet(&batch,&K0,&irc);

S9100:
    if(backed) iSback("REST",&batch,&refno,&irc);
    fileSc("CLO ",&K33,&K0,&K0,&K0,&irc,0);

    return;

}
/*
-----------------------------------------------------------------------
     RDS 09/16/04

     This routine does a DOUT$S using the supplied buffer or the double
     precision value when the supplied buffer begins with a "*"

     This allows overflow values to be formatted in a way that allows
     them to fit as long as the input field is big enough

*/

void dout(short *ifld,short *lfld,short *ibuf,short *lbuf,double *dpnum,short *ierr)
{
static short K1 = 1;
static short N1 = -1;


    if(icompr(ibuf,"* ",&K1) == 0) goto S2000;

    /*
         Make the normal call since the data has NOT overflowed

    */
    doutSs(ifld,lfld,ibuf,lbuf,ierr);

    goto S9000;

S2000:

    /*
         Make a call to best handle the overflowed value in the input
         field space provided

    */
    doutSs(ifld,lfld,dpnum,&N1,ierr);

S9000:

    return;
}
/*

-----------------------------------------------------------------------

     GMT January 25, 1991 09:53:32    LMI-0013

     Add code to avoid validating (and departmentalizing) general
     ledger account for discounts earned, unless the nation code
     is 'NZ'.  If the nation code is not 'NZ', the discounts earned
     account will not be used in any transaction posted by the closing
     of this input batch.

-----------------------------------------------------------------------

     RDS February 27, 1991 20:57:08    EDL-0062

     Allow screens driven by this selection to contain a screen field for any
     of the 4 TR ACCOUNT account numbers and CASH account, that if present
     and a valid account number is entered, will overide the normal account.
     The new routine OVRACC is called to get and validate each of these
     possible inputs.  Also the CALL to  VCTL$C has been modified.
     The arguments to VCTL$C have been changed in the following ways.

        1) The order is V/C NUMBER,JOB,PHASE,ACTIVITY,CONTRACT ID not
                        V/C NUMBER,JOB,PHASE,CONTRACT ID,ACTIVITY

        2) CALLs to VCTL$C provide suitable values for encoding into
           the key buffer for VENDOR$CONTROL.  In the past 0D0 was sometimes
            passed when '          ' or '        ' should have been.

-----------------------------------------------------------------------

     DLP May 1, 1991 15:00:52    EDL-0069

     Added code to support extended VAT accounting.

           1)  Added input field named VAT TYPE
           2)  Added call to VINF$C for "FORIEGN" vendor type
           3)  Added call to VAT$AC to get Vat Accounts
           4)  Added new sections to Pack accountting entries for new
               Vat posting.

-----------------------------------------------------------------------

     GEL May 13, 1991 14:06:16    CAL-0023

     Added ability to optionally verify the Due Date to the Purchase
     Journal open thru date.

-----------------------------------------------------------------------

     GEL May 20, 1991 12:01:52    FRU-0110

     Added check for a return code of 4 after READ$S which is executed
     by express reenter and the BATCH REENTER report.  This is code
     signifies an SCFM validation error and thus saves the screen image.

-----------------------------------------------------------------------

     RDS May 21, 1991 11:14:20    EDL-0101

     Fix the spelling of FOREIGN.

-----------------------------------------------------------------------

     DLP May 28, 1991 14:54:40    ACC-0071

     Modified call to VGLA$C for Discount Earned Account.
     If C$NTNL is "NZ" use distribution Job and Phase in call.
     If C$NTNL is not "NZ" use the default administrative Job and Phase.

-----------------------------------------------------------------------

     GEL June 13, 1991 13:47:12    FRU-0105

     Moved initialization of B$PRIC, B$PO, and B$POLI to INIT$B which is
     where it should have been in the first place.

-----------------------------------------------------------------------

     GEL June 17, 1991 17:08:44    FRU-0105

     Enhanced so that commitments would be subject to T&E markup.

-----------------------------------------------------------------------

     GEL October 29, 1991 12:00:00   PRO-0136

     Assigned values to account numbers referenced in BILLING$COM.
     This was an oversight when the work for LEH-0058 was done.

-----------------------------------------------------------------------

     GEL October 31, 1991 16:15:00   FRU-0139

     Apply T&E markup when closing out a commitment.  This is a
     continuation of Work Order FRU-0105.

-----------------------------------------------------------------------

     GEL January 21, 1991 16:00:00   FRU-0143

     Set B$COM to 1.0 indicating a commitment when closing out a
     commitment and immediately set it back to 0.0 indicating an
     accrual.

-----------------------------------------------------------------------

      DLP January 27, 1992 20:00:00   HBZ-0046

      Added calls to NAMD$S for V/C$INFO

----------------------------------------------------------------------

     DLP February 5, 1992 15:00:00   HBZ-0041

     Changed the DATA$S call for DISCOUNT to return an ASCII string.
     The Discount field can now be entered using a $ or % signs to
     indicate what type of discount to use.

-----------------------------------------------------------------------

     DLP February 10, 1992 09:35:48    EDL-0099

     Added code to support BACK CHARGEing expenses from an Invoice.

-----------------------------------------------------------------------

     DLP February 12, 1992 20:11:28    PRO

     Changed Discount processing to allow a blank entry to be the
     same as a 0 entry.

-----------------------------------------------------------------------

     DLP February 13, 1992 20:40:40    PRO

     Re-display the proper Discount displays afer each reference.

-----------------------------------------------------------------------

     RDS February 26, 1992 19:45:20    HBZ-0060

     Put the INTEGER row number in the second word of each set of
     data in the INPUT$BATCHS 'D' record. (This supports POSTUD)

-----------------------------------------------------------------------

     DLP June 29, 1992 15:16:52    PRO-0000

     Modified tests for a distribution line that is totaly blank to
     test the IRC from DATA$S calls to allow for IRC = 4 for blank fields
     and for IRC = 1 for non-existant fields

-----------------------------------------------------------------------

     DLP July 24, 1992 10:07:00    JEN

     Modified call to VCOM$C to include a new argument, IMODE.
     IMODE can equal 'B ' or 'P '
     B = test for billed amount exceeds commitment
     P = test for Paid amount exceeds commitment

-----------------------------------------------------------------------

     DLP August 27, 1992 13:49:56    HBZ-0142

     When calling VCOM$C to validate the Commitment, and a manual check
     number has been entered, indicationg this invoice has been paid,
     use a MODE of "BW" to override COMMIT REQUIRD to be only a warning.
     This will allow the user to enter this invoice and payment.

-----------------------------------------------------------------------

     DLP August 31, 1992 14:08:00    HBZ-0142

     Pass the Check number to BATC CLOSE in the packed setes of data for
     the Invoice.  This Check number is then used in POSTTR to tell
     CCOM$C if this Invoice was paid with a Manual Check.
     This fixes the problem of placing Invoices on hold, because their
     Commitment was exceeded, when the invoice has been already paid
     with a manual check.

-----------------------------------------------------------------------

     DLP September 25, 1992 16:49:20    HBZ-0000

     Display the VENDOR NAME when nexting through references.

-----------------------------------------------------------------------

     GBT November 11, 1992 08:16:36    HBZ-0161

     On duplicate invoices, added ability to force the user to enter a confirmation
     instead of just a carriage return.  This confirmation only occurs when the
     configuration parameter "CONFIRM DUPLICATE INVOICES" is set.

-----------------------------------------------------------------------

     GBT December 7, 1992 12:31:00    GBT

     Corrected the test for Invoice Checking at the JOB-Level.  It was testing
     incorrectly such that Job-Level would be the method chosen when it  was
     NOT so indicated in the configuration parameter.
     (called-in by DLP during client-site testing)

-----------------------------------------------------------------------

     DLP December 14, 1992 16:52:40    HBZ-0163

     Changed calls to READ$S to not do validation when only reading the
     FUNC and TRANSACTION TYPE

-----------------------------------------------------------------------

     DLP January 25, 1993 20:06:36    PRO

     Restored call to READ$S to use a mode of 1 to cause SCFM validation.

-----------------------------------------------------------------------

     DLP March 9, 1993 08:26:12    JEN

     Display PPS rate with 2 decimal digits.  PPS EXPIRY date is now
     not used.

-----------------------------------------------------------------------

     GMT January 2, 1994 16:05:12    HBZ

     Enhance invoice entry program to allow direct entry of the client
     number that is to be billed by automatic T&E billing.  A client number
     can be entered on each line of distribution of an invoice.  A client
     number can also be entered for the entire invoice, unless overridden on
     a particular line of distribution.

-----------------------------------------------------------------------

     GMT January 2, 1994 22:59:44    PHI-0115

     Revise arguments to "Vendor Control" (VCTL$C) to include a
     parameter that stipulates whether to get the "F"irst vendor
     control record that fits, or to look thru all applicable
     vendor control records and use the record that has the "B"est
     fit.

     Also, add new arguments to HOLD$C to indicate whether the
     invoice being processed is charged to a purchase order or
     to a subcontract.  With this information, hold codes can be
     configured to be applied only to invoices charged to purchase
     orders or only to invoices charged to subcontracts.

-----------------------------------------------------------------------

     GEL January 4, 1994 16:04:28    HBZ-0299

     Corrections to satisfy DEC ALPHA compiler.

-----------------------------------------------------------------------

     RDS February 4, 1994 14:43:40    HBZ-0309

     Change the way JOURNALS$MEMO is posted to accomodate JOURNALS$MEMO
     posting from an IMPORT BATCH.  JOURNALS$MEMO data is now packed in
     the INPUT$BATCHES "D" record with a code of "JM".  When this set is
     encountered, it is DATA$Fed to JOURNALS$MEMO.  If the subsequent "D"
     record set results in call(s) to Post to "JOURNALS" (PST$J2) then a
     JOURNALS$MEMO record will be added with each JOURNALS record that is
     added.

-----------------------------------------------------------------------

     GEL February 16, 1994 13:23:00    DFZ-0001

     Eliminate FORTRAN Writes to the user terminal.

-----------------------------------------------------------------------

     DLP July 22, 1994 14:05:04    HBZ-0330

     Changed calls to FACT$C to calls to FRMA$C

-----------------------------------------------------------------------

     DLP September 7, 1994 13:38:20    HBZ

     Modified to save the reference when in "X" mode and a
     Duplicate Invoice was found for CONFIRM DUPLICATE INVOICE

-----------------------------------------------------------------------

     GMT March 19, 1995 09:03:52    SMI-0007

     Remove code that packs a "Q" (quantity) data set in input batches
     buffer.  Since the file RESOURCE$DATA has been obsoleted, POSTTR
     no longer recognizes a "Q" data set.

-----------------------------------------------------------------------

     GEL April 4, 1995 14:27:32    MAI

     Check number was not being properly validated allowing bogus numbers
     to be posted.

-----------------------------------------------------------------------

     GMT May 9, 1995 18:01:16    FRU-0183

     Add initialization of new BILLING$COM variable B$COID to support
     inter-company automatic t&e billing.

-----------------------------------------------------------------------

     GMT May 18, 1995 14:12:52    SMI-0009

     Add common variable for VENDOR INVOICE DATE.


-----------------------------------------------------------------------

     DLP October 26, 1995 15:53:12    MCI-0051

     Modified to use HOLD$C and to always build a version 2
     of the Hold buffer

-----------------------------------------------------------------------

     GMT November 9, 1995 09:04:52    SMITH

     When a transaction is charged to a 'T&E' type job (per JC JOB INFO,
     field JOB TYPE), but there are no billing rates that will produce
     a billing for the transaction, a warning will be issued to the
     user.  When possible, the input field on the entry screen that is
     initiating the transaction will blink.
     This warning can be suppressed company-wide and on all batch input
     screens by installing a configuration parameter as follows:

           key:  AUTO T&E BILLING RATE WARNING
           data: NO

-----------------------------------------------------------------------

     DLP November 22, 1995 09:49:00    GSMEMO

     Added code to pack a Group Separator between each transaction

-----------------------------------------------------------------------

     DLP January 15, 1996 14:57:44    HBZ-0364

     Set C$ROW to the current row of distribution.

-----------------------------------------------------------------------

     DLP March 26, 1996 10:40:08    MOS-0032

     Added code to calculate and/or accept SALES TAX by line item
     and to pack the SALES TAX into "ST" sets for posting to
     SALES$TAX$DATA

-----------------------------------------------------------------------

     DLP March 26, 1996 14:05:04    MCI-0068

     Added code to get an ALLOCATION FORMULA from the screen and if it
     is defined to display the distribution on the screen.

-----------------------------------------------------------------------

     RDS April 24, 1996 15:17:52    SMI-0079

     Fixes indicated by testing on Smith's machine having to do with
     the capture and posting of Billing Memos and custom billing fields
     on various new TR, PR, and EQ Batch Input screens.

-----------------------------------------------------------------------

     RDS July 3, 1996 11:07:16    PRO

     Fix several problems, some harmless and some not so harmless, having to
     do with the changes that were made to this program to allow scrolling.

-----------------------------------------------------------------------

     GMT February 13, 1997 15:18:35    DGC

     Enhanced to utilize account validation routine VGLA$2 that
     calls for new arguments:

          - Income, Expense, or Other transaction type

          - Debit or Credit side of transaction

          - Activity associated with transaction

     Also enhanced to allow entry operator to omit entry in the account
     input field.  If look ups or custom validation routines find and
     use a valid account, the blank entry will be accepted.  Otherwise,
     the user will be presented with the customary validation error
     message.

-----------------------------------------------------------------------

     GMT March 11, 1997 12:52:43    DES-0025

     Add equipment rental invoice processing capability.

     When equipment usage and/or rental are recorded, if a unit is identified
     in its EQ UNIT INFO record as a rented piece of equipment, and if
     posting to the "outside rental" table has been configured by the presence
     of the configuration parameter EQ OUTSIDE RENTAL, then information  will
     be posted to the EQ$OUTSIDE$RENTAL table.  Only the rental rates set up
     for rate components whose descriptions begins with an "*" will be posted
     to the "outside rental" accrual table.

     If an input field "EQ UNIT" exists on an input screen that is processed
     by the "tr trade invoice" program, and if an equipment unit number  is
     entered in that field, then this feature is engaged.

     Additional optional fields can be added to the input screen that accept
     the following information:

       DATE PERIOD BEGIN - beginning of invoice period
                               (default=beginning of time)
       DATE PERIOD END   - end of invoice period
                               (default=effective date of batch)

       DATE DISPLAY BEGIN - beginning of display period
                               (default=beginning of time)
       DATE DISPLAY END   - end of display period
                               (default=effective date of batch)

       DISPLAY ALL        - display all equipment rental accruals, if
                               an "X" is entered in this field.
                               (default=display only "unbilled" accruals)

       REFRESH DISPLAY    - re-read accrual data from outside rental
                               file (manual overrides you may have typed
                               will have to be re-typed), if an "X"
                               is entered in this field.

     Where:

       The "invoice PERIOD" is the range of dates to which an invoice
       is to generally apply - the period in which you expect to find
       all of the accrual records to which the current invoice is to be
       applied.

       The "DISPLAY period" is the range of dates for which you want to
       be shown all of the unbilled accruals.

     When an invoice is entered, if an equipment unit number is referenced, then
     it is assumed that the scrolling blackboard portion of the input screen has
     fields that will accomodate a display of information looked up in the
     "EQ$OUTSIDE$RENTAL" table.  (See Profitool's standard screen
     TR RENTAL INVOICE as an example.)  The following fields are expected to be
     on the scrolling distribution lines for display of the accrual information:

       PIF
       EQ JOB
       EQ PHASE
       EQ ACTIVITY
       UNBILLED HOURS
       UNBILLED RENTAL
       ADJUST HOURS

     For the stipulated unit, all unbilled accruals
     that fall within the "display period" will be shown on the distribution
     lines in the blackboard.  If the accrual also falls within the "invoice
     period", then the PIF field will be automatically loaded with an "F" on
     the assumption that, more often than not, this accrual is to be applied
     to the invoice being entered.  If the accrual is displayed, but does not
     fall within the invoice period, then the PIF field will be left blank.

     The user can then scroll thru the displayed lines of distribution and
     verify that the selected amounts are to be covered by the current invoice.
     When necessary, the value in the PIF field can be changed to "F" to fully
     apply an accrual, a "P" to allow stipulating a partial payment, or  "blank"
     to skip an accrual.

     Each time the screen is validated, the total amount distributed will be
     displayed in a field TOTAL DISTRIBUTED, if that field is present on the
     screen.  This total distributed can then be compared to the invoice
     amount to determine the amount of distribution error.

     Since this is still the TR TRADE INVOICE processing program, if the
     scrolling portion of the screen has been laid out to accomodate such,
     direct distributions of all or part of the invoice amount can be
     entered just as if you were entering them on a trade invoice entry
     screen.

     When an input batch is posted that has included application of invoice
     amounts to amounts previously accrued for outside equipment rental, then
     the EQ$OUTSIDE$RENTAL table will be posted to reflect the amount of such
     invoices and will reduce the unbilled balance of such accruals.

-----------------------------------------------------------------------

     GMT March 23, 1997 20:42:06    DES-0025

     Revise coding of debit side of the invoice as follows:

          job&phase    - equipment cost center
          activity     - unit number; repair code delimiter; and
                            outside rental repair code
          account      - reserve account to which outside rental was
                            credited when usage was recorded; plus
                            Outside Rental Debit Adder

     Enhance processing of partial hours and amounts so that the
     partial amount will be calculated based upon an average hourly
     rate.  The amount will be proposed as the hours entered multiplied
     by the remaining unbilled rental amount divided by the unbilled
     hours.

-----------------------------------------------------------------------

     GMT April 17, 1997 10:52:57    DES-0025

     Implement additional enhancements to the processing of an
     invoice that is charged against an Outside Equipemtn Rental
     accrual:

          1. Add feature that allows for an adjustment to the original
             accrual to be entered at the time of recording an invoice.
             The distribution of such an adjustment to the amount will
             be debitted to the same job/phase/activity as the original
             accrual, but will the debitted to the account stipulated
             with the configuration parameter:

                  OUTSIDE RENTAL ADJUSTMENT DEBIT ACCT

             The credit side of the adjustment will be applied to the
             same job/phase/activity/account as the original credit.
             The job/phase will be the equipment department.  The activity
             will be the unit number with the repair code for outside
             rental appended.  The account will be the same account
             originally creditted with the accrual.

          2. Add feature that allos for an adjustment to the originally
             reported equipment usage.  This adjustment of reported usage
             is recorded in the same manner as if the additional hours
             ( + or - ) were entered into an EQ USAGE or EQ TIME input
             batch.

     The effective date of both types of adjustments will be the date of the
     original accrual unless that date is no longer open in the journal  that
     is to be used to record the adjustment.  In the case of an adjustment
     to the dollar accrual, the purchase journal will control.  In the case
     of an adjustment to the reported equipment usage, the equipment journal
     will control.

     When either type of adjustment (or both) are applied to an outside
     rental accrual, the on screen display of the remaining unbilled hours
     and unbilled amounts will be modified to reflect the impact of the
     adjustment, although that adjustment will not really be posted until
     the current batch is closed and posted.

     On screen control totals are available that will display the total
     unbilled hours and amounts for all selected distributions as well as
     the total hours and amount you have indicated are to be paid by the
     invoice being entered.  Each time you push the return key, the program
     will recalculate all indicated hours and amounts to be paid based upon
     your selection of records to be displayed, and you modifying those
     records with the "Full", "Partial", or "no pay" flags and the entry
     of partial hours and/or amounts and the entry of hours and/or amount
     adjustments.
     line

-----------------------------------------------------------------------

     GEL May 02, 1997 11:52:56    ADM-1250

     Eliminate free formatted DECODEs.  Such a DECODE on a blank buffer
     could produce undesirable results.

-----------------------------------------------------------------------

     GMT June 03, 1997 14:17:02    DES

     Upgrade call to VGLA$C to call new VGLA$2.

-----------------------------------------------------------------------

     RDS June 05, 1997 10:40:29    DES-0025

     This change fixes the problem that arose when EQCALC tried to
     create an INPUT$BATCHES "D" record at DES.  The code that was to do
     this was depending on having local access to "BATCH" and "REFNO".
     Also, EQCALC is now aware of the need to backup a scrolling reference
     at the time of adding the first "D" record when performing the
     "C", "R", or "X" funtion.

-----------------------------------------------------------------------

     GMT July 10, 1997 17:33:27    DES-0025

     Add necessary initialization of arrays that hold
     outside equipment rental data.

-----------------------------------------------------------------------

     GMT August 14, 1997 12:13:19    DGC

     Install adjustments to Equipment Outside Rental invoice
     processing as indicated by experience at DGC.

-----------------------------------------------------------------------

     GMT August 18, 1997 19:16:01    DGC

     Correct errors in handling key buffers for Equipment
     Outside Rental file.

-----------------------------------------------------------------------

     GMT August 20, 1997 13:01:08    DGC

     Reverse modifications made in error...

-----------------------------------------------------------------------

     GMT September 11, 1997 18:19:31    DGC

     Add code necessary to address the situation where the is
     too much Equipment Outside Rental data to be displayed on
     the available lines of the scrolling blackboard.  When this
     happens, issue a series of messages that direct the user
     to either:

        1) Narrow the "Display Period" to include less data, or
        2) Go ahead and process the amount that can be displayed.

     This implicitly results in "splitting" an invoice into multiple
     parts to eventually apply the entire invoice to all of the
     distributions it is billing.

-----------------------------------------------------------------------

     GMT October 30, 1997 08:14:32    DGC

     Make corrections to equipment rental billing processing.
     Values from one reference were carried over to the next reference
     due to the incorrect use of NSET$B rather than LSET$B.

-----------------------------------------------------------------------

     GMT November 24, 1997 13:58:04    dgc

     Add an additional READ of input screen to recognize information
     loaded into scrolling rows by the program output.

-----------------------------------------------------------------------

     SCB February 26, 1998 13:13:27    DEV

     Added capability to read either the new 58 byte key or old 52 byte  key
     COMMITMENT$MASTER file. If applicable, changed the date format in the C$M
     key to handle an 8 char date field.

-----------------------------------------------------------------------

     GMT May 11, 1998 19:56:05    DES

     Add initialization of equipment rental arrays to be executed on
     entry into program.  As it was, the initialization was effective
     on repeated entries into this program to process equipment
     rental invoices, BUT, if you used this program to enter equipment
     rental invoices and then came back into this program to enter
     a simple trade invoice, the equipment rental variables carried
     residual values.

-----------------------------------------------------------------------

     GMT December 22, 1998 13:46:05    DES

     Recent changes in Outside Equipment Rental processing resulted
     in the following error.  Even when there is no amount to be paid
     on a specific line of distrubution, and IF there is no "VAT" input
     field for that line of distribution, then the program still wanted
     to see a job/phase input.

     This correction changed the test for a blank line to essentially
     say "if there is no number input in the amount field and there
     is no number input in the VAT field, then process this line as
     a blank line".

     Also...

     Correct coding of invoice entries used to record an outside
     equipment rental adjustment so that the "dummy" invoice entries
     are not posted to AP/AR$MASTER (note use of 'P ICT R ' code).

-----------------------------------------------------------------------

     CJO February 19, 1999 15:59:10    PRO

     General source file cleanup; assumes this version is
     now Y2K compliant and has no need to consider 2 vs 4
     digit years.  The edits include :
       Delete/modify code assuming NEWLAB, NEWC$M and NEWL$D
       are all true.
       Delete LOGICAL Y2K and associated tests and date
       conversions.
       Delete comments having /VAX/PRIME/POSIX notes

-----------------------------------------------------------------------

     GMT June 17, 1999 16:11:49    DES

     Correct error in handling of debit account for Outside Rental
     Adjustments.

-----------------------------------------------------------------------

     SCB June 21, 1999 11:05:18    MAI-0070

     Added capability to post zero GST values for MAI for tax reporting  purposes.

-----------------------------------------------------------------------

     GMT August 30, 1999 15:35:37    DES

     Add "Auto Adjustment Allocation" feature.  The "Rental Invoice" input
     screen has been reorganized and a new field (Allocate) has been added.
     If a dollar amount is entered in this field, it is intended to be
     allocated pro-rata over the distribution of the invoice to the
     Outside Rental acrual line items.  The result is the same as if the
     user had manually typed an adjustment amount on each individual line,
     but is much simpler for the user.

     When the distribution of the invoice over selected rental accrual lines
     has been completed, then the sum of the amounts to be paid on each  line
     added to the "Allocate" amount must balance to the invoice total.  It
     is permissable to BOTH enter an adjustment on a specific line AND apply
     an automatic adjustment allocation at the same reference.

     Correct calculation of amount to be paid on a line when the line
     is a partial payment of the total unbilled hours and when there is
     a adjustment to the $amount accrued for outside rental.

     Reorganize source code and add memos.

-----------------------------------------------------------------------

     GMT October 10, 1999 21:56:26    DES-0079

     Enhance posting to EQ$OUTSIDE$RENTAL file to include the
     vendor and invoice number.  Equipment usage posted via
     an equipment usage input batch will be posted with
     vendor "0" and a blank invoice number.  All billing
     applied to an outside rental accrual, as well as adjustments
     to usage and accrual amounts posted via an invoice entry
     input batch will be recorded with the vendor and invoice
     number reference.

-----------------------------------------------------------------------

     GMT October 10, 1999 22:13:00    DBS

     Add declaration of memo buffer used in "allocation" processing.

     (per DBS - 10/08/1999)

-----------------------------------------------------------------------

     GMT December 17, 1999 11:24:28    DES-0079

     Enhance to support recording additional information in
     EQ Outside Rental file and to post to new Invoice Payable
     file with respect to Outside Rental billings.

-----------------------------------------------------------------------

     SCB March 02, 2000 09:53:03    BEC-0017

     Added AZ to the GST zero value calculation.

-----------------------------------------------------------------------

     SCB March 02, 2000 10:03:14    BEC-0017

     Misspelled nation code AU in previous comment.  Actually added Australia
     to the zero calculation GST by adding the AU nation code to every
     comparison that tests for the NZ nation code.

-----------------------------------------------------------------------

     SCB March 02, 2000 11:55:14    BEC-0017

     Changed JOURNALS$MEMO output number format in TMEMO from a formatted
     number to an F12.2 format because the commas weren't being processed
     by Report Writer reports properly.

-----------------------------------------------------------------------

     RDS April 06, 2000 16:43:08    DES

     Check for whether it is time to create a new "D" record sooner.
     This avoids the problem that occurs on a "C"hange when PACKC wants
     to write the first "D" record.  PACKC does not know how to backup
     and delete the reference being changed which caused the fatal
     error 12  group 20.

-----------------------------------------------------------------------

     RDS June 21, 2000 09:55:35    TIC-0146

     Changes to support the addition of "ACCOUNT" (debit job account)
     to the COMMITMENT$MASTER file.

-----------------------------------------------------------------------

     GMT July 21, 2000 16:10:24    DES

     Put Outside Rental Adjustment Debit Job Account in a local
     variable that won't be modified by calls to VGLA$2.

-----------------------------------------------------------------------

     RDS October 28, 2000 10:33:59    TIC

     Change two READ$S calls to have a mode of 2 so that fields defined
     as required by SCFM will be enforced.

-----------------------------------------------------------------------

     CJO October 28, 2000 15:03:57    TRU/PRO

     Add code to read the auto dup field and enable field duplications
     in the detail entry portion of the screen.

-----------------------------------------------------------------------

     DBS December 05, 2000 09:33:02    DES0083

     Added support for cross checking invoices in open batches

-----------------------------------------------------------------------

     DBS February 02, 2001 16:14:46    TIC0158

     Added support for checking for duplicate DIN in input batches.

-----------------------------------------------------------------------

     DBS March 07, 2001 14:44:27    DES0094

     Added support for AUTO ALLOCATE ADJUSTMENT HR screen field,
     which automatically adjusts hours similar to the previously
     existing AUTO ALLOCATE ADJUSTMENT feature does to amounts.

-----------------------------------------------------------------------

     RDS May 22, 2002 13:19:05    DEV-0004

     Implement the new "confirm" popup box for duplicate invoice/DIN
     confirmation.

-----------------------------------------------------------------------

     GMT June 14, 2002 10:54:14    FRU

     When this program is executing the "rental invoice" functionality,
     it will look to see if the unit's equipment master record includes
     a job/phase in a field EQ USAGE CREDIT JOB.  If found, then this
     job/phase will be used as the equipment cost center for the unit.
     Else, the configured default equipment cost center will be used for
     the unit.

-----------------------------------------------------------------------

     GMT October 21, 2002 13:52:39    DES

     Modify as required to allow the debit job account to which repair
     expense is charged to be variable for each line of distribution.
     The debit job account can vary by the equipment repair code that is
     appended to the unit number (equipment department activity).

-----------------------------------------------------------------------

     GMT December 17, 2002 12:18:01    DES

     Correct problem where EQ Outside Rental adjustments were mistakenly
     carried forward from one reference to another and duplicated. This
     situation arose when a reference was entered that did not reference
     an equipment unit number and therefore did not process any outside
     rental data.  If the previous reference had an outside rental adjustment
     then the adjustment was duplicated.

-----------------------------------------------------------------------

     GMT January 16, 2003 13:01:14    DES (HD #13180)

     Withdraw modification checked in on December 17, 2002 12:18:01
     as it was proven to be faulty.

     Moved loop that initializes the arrays of screen input associated
     with entry of outside equipment rental data to the area where the
     addition or change of a reference is first processed.  Previously,
     this initialization was done on entry into the program to clear
     out data captured in an earlier use of the program in the same
     session.  Now, the same initialization is done at the beginning of
     processing of each new or changed reference so that data will neither
     carry over from a previous use of the program nor from a previously
     entered reference in the same use of the program.

     NDR - gmt

-----------------------------------------------------------------------

     DBS July 07, 2004 10:25:32    TRU0120

     Added support for override batch effective date, use the following
     input screens fields to override.

     MONTH EFFECTIVE
     DAY EFFECTIVE
     YEAR EFFECTIVE

-----------------------------------------------------------------------

     RDS November 02, 2004 09:11:58    FRU (14340)

     Change how formatted amount fields are handled in order to prevent
     overflow conditions.  Some amount fields can exceed the format that
     is currently used when doing DOUT$S calls.  This program now calls  a
     simple and local routine whos purpose is to head off "******" output.
     When such a value is about to be output DOUT$S will instead be called
     with the original double precision value and the length of -1. This
     will cause the program to format the amount in such a way as to make
     it fit as long as there is enough room to output the complete amount.

     The screen field "JOBPH" is now determined in the following way:

     "EQ USAGE CREDIT JOB" from EQ$MASTER if available.

     else

     Taken from EQ$OUTSIDE$RENTAL if available

     else

     default equipment cost center job ("EQUIPMENT COST CENTER" in GENL$INFO)

-----------------------------------------------------------------------

     GEL October 25, 2005 12:21:01    PT6-0006

     Recode all calls to POUT$S so that "row" and "column" position
     references are eliminated.

-----------------------------------------------------------------------

     GEL May 10, 2007 10:13:16    ACC14687

     Added ability to hold invoices by Type with the Config Parameters

     HOLD ALL INVOICES: {type}
     HOLD ALL SUBCONTRACT INVOICES: {type}
     HOLD ALL TRADE INVOICES: {type}

     The program first looks for the Paramater for the specific Type.
     If it is not found it then looks for the corresponding Parameter
     with no Type.

-----------------------------------------------------------------------

     GEL July 05, 2007 18:55:16    TRU14710

     Enhance to validate effective dates verses journal close dates when
     doing an ICT.  This change will cause a hard error at data entry.

-----------------------------------------------------------------------

     RDS August 13, 2010 14:39:59    ZHI-0042

     Comment out the line of code directly after 6350 CONTINUE.
     This line of code was clobbering the tax amount for the last
     entity.

-----------------------------------------------------------------------

     GEL September 23, 2010 17:32:32    ZHI-0044

     When packing the Hold Reason in the INPUT$BATCHES data record
     for AMOUNT EXCEEDS LOG pack 24 chars rather than 20.  The
     uninitialized 4 chars were causing the data base server to barf.

-----------------------------------------------------------------------

     GEL September 27, 2010 12:23:47    ZHI-0044

     Undo previous change.  It is superseded by a change to
     post.posttr.ftn which unpacks 20 instead of 24 chars.

-----------------------------------------------------------------------

     GEL March 09, 2011 16:19:19    KIR-0032

     Look for a new field AMOUNT SUBJECT TO TAX.  There are times
     when only a portion of the invoice is subject to tax.  This is
     the mechanism to stipulate that override amount.  If the field
     doesn't exist (or exists and is blank) then tax will be computed
     on the entirety of the invoice.

     Enhance the memo for tax accruals written to the JOURNALS file.
     It will include "S TAX" for Sales Tax (or "U TAX" for Use tax)
     and the Tax Code.

*/
