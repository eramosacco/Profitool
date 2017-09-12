all:comdata
	@echo "All done"

# Define directories / strings to replace (if any)
COMDIR = /pti/pt.profile/pt-shell
CHOWN_USER = cmissa
CHOWN_GROUP = ptuser

# comdata conf file
comdata: $(COMDIR) \
	$(COMDIR)/ftp_comdata.conf
	$(COMDIR)/ftp_comdata
	@echo "** Target $(@F) Done"
$(COMDIR):
	@install -d $(COMDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(COMDIR)
$(COMDIR)/%comdata:  comdata/%comdata
	@cp $? $(COMDIR)
	@chown $(CHOWN_USER):$(CHOWN_GROUP) $(COMDIR)/$(notdir $?)
