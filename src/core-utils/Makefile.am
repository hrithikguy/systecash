SUBDIRS = . test

lib_LTLIBRARIES = libgnc-core-utils.la

libgnc_core_utils_la_SOURCES = \
  binreloc.c \
  gnc-prefs.c \
  gnc-environment.c \
  gnc-features.c \
  gnc-filepath-utils.c \
  gnc-gdate-utils.c \
  gnc-gkeyfile-utils.c \
  gnc-glib-utils.c \
  gnc-guile-utils.c \
  gnc-jalali.c \
  gnc-locale-utils.c \
  gnc-path.c \
  gnc-uri-utils.c \
  swig-core-utils-guile.c

libgnc_core_utils_la_LIBADD = \
  ${GUILE_LIBS} \
  ${GLIB_LIBS} \
  ${BINRELOC_LIBS} \
  ${GTK_MAC_LIBS} \
  ${QOF_LIBS}


noinst_HEADERS = \
  binreloc.h \
  gnc-prefs.h \
  gnc-prefs-p.h \
  gnc-environment.h \
  gnc-features.h \
  gnc-filepath-utils.h \
  gnc-gdate-utils.h \
  gnc-gkeyfile-utils.h \
  gnc-glib-utils.h \
  gnc-guile-utils.h \
  gnc-jalali.h \
  gnc-locale-utils.h \
  gnc-path.h \
  gnc-uri-utils.h

if BUILDING_FROM_VCS
swig-core-utils-guile.c: core-utils.i ${top_srcdir}/src/base-typemaps.i
	$(SWIG) -guile $(SWIG_ARGS) -Linkage module \
	-I${top_srcdir}/src -o $@ $<
if ! OS_WIN32
if ! SWIG_DIST_FAIL
	if ! `grep "define scm_from_utf8_string" $@ > /dev/null 2>&1`; then \
	  patch $@ $(top_srcdir)/src/swig-utf8.patch; \
	fi
endif
endif
swig-core-utils-python.c: core-utils.i ${top_srcdir}/src/base-typemaps.i
	$(SWIG) -python -Wall -Werror $(SWIG_ARGS) \
	-I${top_srcdir}/src -o $@ $<
endif

AM_CPPFLAGS = \
  ${GUILE_CFLAGS} \
  ${GLIB_CFLAGS} \
  ${GTK_MAC_CFLAGS} \
  ${QOF_CFLAGS} \
  -I${top_srcdir}/src/libqof/qof \
  -I${top_builddir}/src \
  -I${top_srcdir}/src

gncscmmoddir = ${GNC_SCM_INSTALL_DIR}/systecash
gncscmmod_DATA = core-utils.scm

if GNUCASH_SEPARATE_BUILDDIR
#Only needed when srcdir and builddir are different
#for running
SCM_FILE_LINKS = ${gncscmmod_DATA}
endif

if WITH_PYTHON

lib_LTLIBRARIES += libgnc-core-utils-python.la

libgnc_core_utils_python_la_SOURCES = \
	swig-core-utils-python.c

libgnc_core_utils_python_la_LIBADD = \
	${PYTHON_LIBS} \
	libgnc-core-utils.la

libgnc_core_utils_python_la_CPPFLAGS = \
  ${GLIB_CFLAGS} \
  ${GTK_MAC_CFLAGS} \
  ${QOF_CFLAGS} \
  ${PYTHON_CPPFLAGS} \
  -I${top_srcdir}/src/libqof/qof \
  -I${top_builddir}/src \
  -I${top_srcdir}/src

endif

.scm-links: 
	$(RM) -rf systecash
	mkdir -p  systecash
if GNUCASH_SEPARATE_BUILDDIR
	for X in ${SCM_FILE_LINKS} ; do \
	  $(LN_S) -f ${srcdir}/$$X . ; \
	done
endif
	( cd systecash; for A in $(gncscmmod_DATA) ; do $(LN_S) -f ../$$A . ; done )
if ! OS_WIN32
# Windows knows no "ln -s" but uses "cp": must copy every time (see bug #566567).
	touch .scm-links
endif

if GNC_HAVE_GUILE_2
GUILE_COMPILE_ENV = \
  --library-dir    ${top_builddir}/src/core-utils \
  --library-dir    ${top_builddir}/src/libqof/qof

%.go : %.scm .scm-links $(lib_LTLIBRARIES)
	GNC_UNINSTALLED=yes \
	GNC_BUILDDIR=${top_builddir} \
	$(shell ${abs_top_srcdir}/src/gnc-test-env.pl --noexports ${GUILE_COMPILE_ENV})  \
	$(GUILD) compile -o $@ $<

gncscmmodcachedir = ${pkglibdir}/scm/ccache/@GUILE_EFFECTIVE_VERSION@/systecash
gncscmmodcache_DATA = $(gncscmmod_DATA:.scm=.go)
endif

noinst_DATA = .scm-links
BUILT_SOURCES = gncla-dir.h gnc-version.h
EXTRA_DIST = $(gncscmmod_DATA) core-utils.i gncla-dir.h.in gnc-vcs-info.h
clean-local:
	rm -rf systecash

CLEANFILES = $(BUILT_SOURCES) .scm-links ${gncscmmodcache_DATA}

MAINTAINERCLEANFILES = swig-core-utils-guile.c swig-core-utils-python.c

AM_CPPFLAGS += -DG_LOG_DOMAIN=\"gnc.core-utils\" -DGNC_SCM_INSTALL_DIR="\"${GNC_SCM_INSTALL_DIR}\""

gncla-dir.h: gncla-dir.h.in ${top_builddir}/config.status Makefile
	rm -f $@.tmp
	sed < $< > $@.tmp \
		-e 's#@-DATADIRNAME-@#${DATADIRNAME}#g' \
		-e 's#@-libdir-@#${libdir}#g' \
		-e 's#@-bindir-@#${bindir}#g' \
		-e 's#@-sysconfdir-@#${sysconfdir}#g' \
		-e 's#@-datadir-@#${datadir}#g' \
		-e 's#@-prefix-@#${prefix}#g'
	mv $@.tmp $@

## We borrow guile's convention and use @-...-@ as the substitution
## brackets here, instead of the usual @...@.  This prevents autoconf
## from substituting the values directly into the left-hand sides of
## the sed substitutions.
gnc-version.h: _gnc-version.h
	-if [ ! -f gnc-version.h ]; then cp _gnc-version.h gnc-version.h; fi
	-cmp -s _gnc-version.h gnc-version.h || cp _gnc-version.h gnc-version.h
	-rm -f _gnc-version.h

_gnc-version.h: gnc-vcs-info.h Makefile
	@echo "/* Autogenerated. Do not change. */"   > _gnc-version.h
	@echo "#ifndef GNC_VERSION_H"                >> _gnc-version.h
	@echo "#define GNC_VERSION_H"                >> _gnc-version.h
	@echo ""                                     >> _gnc-version.h
	@scm_info=`${top_srcdir}/util/gnc-vcs-info -t ${top_srcdir}` ; \
	if [ $$? = 0 ] ; then \
		echo "#define GNUCASH_SCM \"$$scm_info\"" >> _gnc-version.h ; \
	fi
	@echo "#define GNUCASH_BUILD_DATE \"`date +%Y-%m-%d`\"" >> _gnc-version.h
	@echo "#include \"gnc-vcs-info.h\""          >> _gnc-version.h
	@echo "#endif"                               >> _gnc-version.h

gnc-vcs-info.h: _gnc-vcs-info.h
	-if [ ! -f gnc-vcs-info.h ]; then cp _gnc-vcs-info.h gnc-vcs-info.h; fi
	-cmp -s _gnc-vcs-info.h gnc-vcs-info.h || cp _gnc-vcs-info.h gnc-vcs-info.h
	-rm -f _gnc-vcs-info.h

_gnc-vcs-info.h: Makefile
	@scm_info=`${top_srcdir}/util/gnc-vcs-info -r ${top_srcdir}` ; \
	if [ $$? = 0 ] ; then \
		if [ -z "$$scm_info" ] ; then \
			echo "gnc-vcs-info failed.  figure out why." ; \
			echo "can't determine svn/svk/git/bzr revision from ${top_srcdir}." ; \
			exit 1 ; \
		fi ; \
		echo "/* Autogenerated. Do not change. */"    > _gnc-vcs-info.h ; \
		echo "#define GNUCASH_SCM_REV \"$$scm_info\"" >> _gnc-vcs-info.h ; \
	else \
		if [ -r $(srcdir)/gnc-vcs-info.h ] ; then \
			cp $(srcdir)/gnc-vcs-info.h _gnc-vcs-info.h ; \
		else \
			echo "You're building from svn/svk/git/bzr...  But your build system is broken" ; \
			echo "Don't do that.   Complain to your build-system creator." ; \
			exit 1 ; \
		fi ; \
	fi
