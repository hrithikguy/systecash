SUBDIRS = . test

pkglib_LTLIBRARIES = libgncmod-register-gnome.la

libgncmod_register_gnome_la_LDFLAGS = -avoid-version

libgncmod_register_gnome_la_LIBADD = \
  ${top_builddir}/src/register/register-core/libgncmod-register-core.la \
  ${top_builddir}/src/core-utils/libgnc-core-utils.la \
  ${top_builddir}/src/gnc-module/libgnc-module.la \
  ${top_builddir}/src/engine/libgncmod-engine.la \
  ${top_builddir}/src/app-utils/libgncmod-app-utils.la \
  ${top_builddir}/src/gnome-utils/libgncmod-gnome-utils.la \
  ${top_builddir}/src/libqof/qof/libgnc-qof.la \
  ${GLIB_LIBS} \
  ${GNOMECANVAS_LIBS}

libgncmod_register_gnome_la_SOURCES = \
  gncmod-register-gnome.c \
  combocell-gnome.c \
  datecell-gnome.c \
  formulacell-gnome.c \
  systecash-color.c \
  systecash-cursor.c \
  systecash-date-picker.c \
  systecash-grid.c \
  systecash-header.c \
  systecash-item-edit.c \
  systecash-item-list.c \
  systecash-scrolled-window.c \
  systecash-sheet.c \
  systecash-style.c \
  pricecell-gnome.c \
  quickfillcell-gnome.c \
  table-gnome.c 

noinst_HEADERS = \
  formulacell-gnome.h \
  systecash-color.h \
  systecash-cursor.h \
  systecash-date-picker.h \
  systecash-grid.h \
  systecash-header.h \
  systecash-item-edit.h \
  systecash-item-list.h \
  systecash-scrolled-window.h \
  systecash-sheet.h \
  systecash-sheetP.h \
  systecash-style.h \
  pricecell-gnome.h \
  quickfillcell-gnome.h \
  table-gnome.h

AM_CPPFLAGS = \
  -I${top_srcdir}/src \
  -I${top_srcdir}/src/core-utils \
  -I${top_srcdir}/src/engine \
  -I${top_srcdir}/src/gnc-module \
  -I${top_srcdir}/src/app-utils \
  -I${top_srcdir}/src/gnome-utils \
  -I${top_srcdir}/src/register/ledger-core \
  -I${top_srcdir}/src/register/register-core \
  -I${top_srcdir}/src/libqof/qof \
  ${GLIB_CFLAGS} \
  ${GTK_XIM_FLAGS} \
  ${GNOMECANVAS_CFLAGS}

AM_CPPFLAGS += -DG_LOG_DOMAIN=\"gnc.register.gnome\"
