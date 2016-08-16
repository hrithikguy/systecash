
SET(gnome_GSCHEMA
  org.systecash.dialogs.gschema.xml
  org.systecash.dialogs.commodities.gschema.xml
  org.systecash.dialogs.checkprinting.gschema.xml
  org.systecash.dialogs.reconcile.gschema.xml
  org.systecash.dialogs.sxs.gschema.xml
  org.systecash.dialogs.totd.gschema.xml
  org.systecash.gschema.xml
  org.systecash.window.pages.account.tree.gschema.xml
  org.systecash.window.pages.gschema.xml
)

# If you edit one of the above files, you need to rerun cmake.
# When we can use CONFIGURE_FILE() instead of GNC_CONFIGURE()
# this issue will go away.


ADD_GSCHEMA_TARGETS(gnome-gschema "${gnome_GSCHEMA}")
