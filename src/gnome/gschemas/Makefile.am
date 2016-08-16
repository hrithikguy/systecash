@INTLTOOL_XML_NOMERGE_RULE@

gschema_in_files = \
  org.systecash.dialogs.gschema.xml.in \
  org.systecash.dialogs.commodities.gschema.xml.in \
  org.systecash.dialogs.checkprinting.gschema.xml.in \
  org.systecash.dialogs.reconcile.gschema.xml.in \
  org.systecash.dialogs.sxs.gschema.xml.in \
  org.systecash.dialogs.totd.gschema.xml.in \
  org.systecash.gschema.xml.in \
  org.systecash.window.pages.account.tree.gschema.xml.in \
  org.systecash.window.pages.gschema.xml.in

gsettings_SCHEMAS = $(gschema_in_files:.gschema.xml.in=.gschema.xml)

@GSETTINGS_RULES@

CLEANFILES = $(gsettings_SCHEMAS)
