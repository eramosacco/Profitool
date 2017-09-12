# This program requires third-party software:
#     $PT_SITE_PATH/shell/ptfilter.pl

all: perl
	@echo "All done"

# Note: PTDIR is dependent on the current PT revision
PERLDIR     = /pti/pt.site.6.1.18/shell
CHOWN_USER  = cmissa
CHOWN_GROUP = ptuser

# perl dir 
perl: $(PERLDIR) \
    $(PERLDIR)/ptfilter.pl
	@echo "** Target $(@F) Done"

$(PERLDIR):
	@install -d $(PERLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(PERLDIR)

$(PERLDIR)/%.pl: perl/%.pl
	@cp $? $(PERLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(PERLDIR)/$(notdir $?)
