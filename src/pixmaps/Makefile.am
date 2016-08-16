gncpixmapdir = ${GNC_PIXMAP_DIR}

gncpixmap_DATA = \
  gnc-account-16.png \
  gnc-account-delete-16.png \
  gnc-account-delete.png \
  gnc-account-edit-16.png \
  gnc-account-edit.png \
  gnc-account-new-16.png \
  gnc-account-new.png \
  gnc-account-open-16.png \
  gnc-account-open.png \
  gnc-account.png \
  gnc-gnome-pdf-16.png \
  gnc-gnome-pdf-24.png \
  gnc-invoice-16.png \
  gnc-invoice-duplicate-16.png \
  gnc-invoice-duplicate.png \
  gnc-invoice-edit-16.png \
  gnc-invoice-edit.png \
  gnc-invoice-new-16.png \
  gnc-invoice-new.png \
  gnc-invoice-pay-16.png \
  gnc-invoice-pay.png \
  gnc-invoice-post-16.png \
  gnc-invoice-post.png \
  gnc-invoice-unpost-16.png \
  gnc-invoice-unpost.png \
  gnc-invoice.png \
  gnc-jumpto-16.png \
  gnc-jumpto.png \
  gnc-split-trans-16.png \
  gnc-split-trans.png \
  gnc-sx-new-16.png \
  gnc-sx-new.png \
  gnc-transfer-16.png \
  gnc-transfer.png \
  systecash-icon.ico \
  systecash-icon-16x16.png \
  systecash-icon-32x32.png \
  systecash-icon-48x48.bmp \
  systecash-icon-48x48.png \
  systecash-icon-64x64.png \
  systecash-icon-96x96.png \
  systecash-icon-128x128.png \
  systecash-icon-256x256.png \
  systecash_splash.png \
  stock_split_title.png \
  stock_split_watermark.png

gnchuge256icondir = ${datadir}/icons/hicolor/256x256/apps
gnchuge256icon_DATA = 256x256/systecash-icon.png

gnchuge128icondir = ${datadir}/icons/hicolor/128x128/apps
gnchuge128icon_DATA = 128x128/systecash-icon.png

gnclarge96icondir = ${datadir}/icons/hicolor/96x96/apps
gnclarge96icon_DATA = 96x96/systecash-icon.png

gnclarge64icondir = ${datadir}/icons/hicolor/64x64/apps
gnclarge64icon_DATA = 64x64/systecash-icon.png

gnclarge48icondir = ${datadir}/icons/hicolor/48x48/apps
gnclarge48icon_DATA = 48x48/systecash-icon.png

gncmediumicondir = ${datadir}/icons/hicolor/32x32/apps
gncmediumicon_DATA = 32x32/systecash-icon.png

gncsmalltwfouricondir = ${datadir}/icons/hicolor/24x24/apps
gncsmalltwfouricon_DATA = 24x24/systecash-icon.png

gncsmalltwtwoicondir = ${datadir}/icons/hicolor/22x22/apps
gncsmalltwtwoicon_DATA = 22x22/systecash-icon.png

gncextrasmallicondir = ${datadir}/icons/hicolor/16x16/apps
gncextrasmallicon_DATA = 16x16/systecash-icon.png

gncscalableicondir = ${datadir}/icons/hicolor/scalable/apps
gncscalableicon_DATA = scalable/systecash-icon.svg

if BUILDING_FROM_VCS
256x256/systecash-icon.png: systecash-icon-256x256.png
	-mkdir -p 256x256
	cp ${srcdir}/systecash-icon-256x256.png 256x256/systecash-icon.png

128x128/systecash-icon.png: systecash-icon-128x128.png
	-mkdir -p 128x128
	cp ${srcdir}/systecash-icon-128x128.png 128x128/systecash-icon.png

96x96/systecash-icon.png: systecash-icon-96x96.png
	-mkdir -p 96x96
	cp ${srcdir}/systecash-icon-96x96.png 96x96/systecash-icon.png

64x64/systecash-icon.png: systecash-icon-64x64.png
	-mkdir -p 64x64
	cp ${srcdir}/systecash-icon-64x64.png 64x64/systecash-icon.png

48x48/systecash-icon.png: systecash-icon-48x48.png
	-mkdir -p 48x48
	cp ${srcdir}/systecash-icon-48x48.png 48x48/systecash-icon.png

32x32/systecash-icon.png: ${top_srcdir}/art/tango/32x32/systecash.png
	-mkdir -p 32x32
	cp ${top_srcdir}/art/tango/32x32/systecash.png 32x32/systecash-icon.png

24x24/systecash-icon.png: ${top_srcdir}/art/tango/22x22/systecash-24x24.png
	-mkdir -p 24x24
	cp ${top_srcdir}/art/tango/22x22/systecash-24x24.png 24x24/systecash-icon.png

22x22/systecash-icon.png: ${top_srcdir}/art/tango/22x22/systecash-22x22.png
	-mkdir -p 22x22
	cp ${top_srcdir}/art/tango/22x22/systecash-22x22.png 22x22/systecash-icon.png

16x16/systecash-icon.png: ${top_srcdir}/art/tango/16x16/systecash.png
	-mkdir -p 16x16
	cp ${top_srcdir}/art/tango/16x16/systecash.png 16x16/systecash-icon.png

scalable/systecash-icon.svg: ${top_srcdir}/art/tango/scalable/systecash.svg
	-mkdir -p scalable
	cp ${top_srcdir}/art/tango/scalable/systecash.svg scalable/systecash-icon.svg

systecash-icon-16x16.png:
	cp ${top_srcdir}/art/tango/16x16/systecash.png systecash-icon-16x16.png

systecash-icon-32x32.png:
	cp ${top_srcdir}/art/tango/32x32/systecash.png systecash-icon-32x32.png
endif

# As suggested by <http://live.gnome.org/GnomeGoals/AppIcon>
if !OS_WIN32
gtk_update_icon_cache = gtk-update-icon-cache -f -t $(datadir)/icons/hicolor
install-data-hook: update-icon-cache
uninstall-hook: update-icon-cache
update-icon-cache:
	@-if test -z "$(DESTDIR)"; then \
		echo "Updating Gtk icon cache."; \
		$(gtk_update_icon_cache); \
	else \
		echo "*** Icon cache not updated.  After (un)install, run this:"; \
		echo "***   $(gtk_update_icon_cache)"; \
	fi
endif

ico_files_hr = \
  ${gnchuge256icon_DATA} \
  ${gnchuge128icon_DATA} \
  ${gnclarge96icon_DATA} \
  ${gnclarge64icon_DATA} \
  ${gnclarge48icon_DATA}

ico_files_lr = \
  ${gncmediumicon_DATA} \
  ${gncsmalltwfouricon_DATA} \
  ${gncsmalltwtwoicon_DATA} \
  ${gncextrasmallicon_DATA}

EXTRA_DIST = \
  ${gncpixmap_DATA} \
  ${ico_files_hr} \
  ${ico_files_lr} \
  ${gncscalableicon_DATA}

# Only clean up if we're building from svn/svk/git/bzr
if BUILDING_FROM_VCS
clean-local:
	-rm -rf 256x256 128x128 96x96 64x64 48x48 32x32 24x24 22x22 16x16 scalable
endif

# Create systecash-icon.ico
.PHONY: ico
ico: ${ico_files_hr} ${ico_files_lr}
	convert ${ico_files_lr} ${ico_files_hr} tmp.ico; \
	mv tmp.ico systecash-icon.ico
