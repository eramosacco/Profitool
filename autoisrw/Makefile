
all: perl shell
	@echo "All done"

# Note: PERLDIR is dependent on the current PT revision
PERLDIR     = /pti/pt.site.6.1.18/auto
SHELLDIR    = /pti/pt.profile/pt-shell
CHOWN_USER  = cmissa
CHOWN_GROUP = ptuser

# Perl dir and Perl files 
perl: $(PERLDIR) \
    $(PERLDIR)/is_odd_week.pl
	@echo "** Target $(@F) Done"

$(PERLDIR):
	@install -d $(PERLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(PERLDIR)

$(PERLDIR)/%.pl: %.pl
	@cp $? $(PERLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(PERLDIR)/$(notdir $?)

# Shell script
shell: $(SHELLDIR) \
    $(SHELLDIR)/ptautoisrw
	@echo "** Target $(@F) Done"

$(SHELLDIR):
	@install -d $(SHELLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(SHELLDIR)

$(SHELLDIR)/ptautoisrw: ptautoisrw
	@cp ptautoisrw $(SHELLDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(SHELLDIR)/ptautoisrw
