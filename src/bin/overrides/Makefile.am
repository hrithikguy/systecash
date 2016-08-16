gncoverridesdir = ${GNC_LIBEXECDIR}/overrides
# When you add a file here, please modify ../test/Makefile.am's overrides.stamp
gncoverrides_SCRIPTS = \
  systecash-env \
  systecash-make-guids

EXTRA_DIST = \
  systecash-env.in \
  systecash-build-env.in \
  systecash-make-guids \
  guile.in 

noinst_DATA = systecash-build-env guile

PWD := $(shell pwd)

## We borrow guile's convention and use @-...-@ as the substitution
## brackets below, instead of the usual @...@.  This prevents autoconf
## from substituting the values directly into the left-hand sides of
## the sed substitutions.  *sigh*

guile: guile.in ${top_builddir}/config.status Makefile
	rm -f $@.tmp
	sed < $< > $@.tmp \
	    -e 's#@-GUILE-@#${GUILE}#'
	mv $@.tmp $@
	chmod u+x $@
CLEANFILES = guile

systecash-env: systecash-env.in ${top_builddir}/config.status Makefile
	rm -f $@.tmp
	sed < $< > $@.tmp \
	    -e 's#@-GNC_SCM_INSTALL_DIR-@#${GNC_SCM_INSTALL_DIR}#g' \
            -e 's#@-GNC_LIB_INSTALLDIR-@#${libdir}#' \
            -e 's#@-GNC_PKGLIB_INSTALLDIR-@#${pkglibdir}#g' \
            -e 's#@-GNC_SCRIPT_OVERRIDE_DIR-@#${gncoverridedir}#g' \
            -e 's#@-GNC_PYTHON_DIR-@#${pythondir}#g'
	mv $@.tmp $@
	chmod u+x $@
CLEANFILES += systecash-env

systecash-build-env: systecash-build-env.in ${top_builddir}/config.status Makefile
	rm -f $@.tmp
	sed < $< > $@.tmp \
            -e 's#@-GNC_BUILDDIR-@#${abs_top_builddir}#g' \
            -e 's#@-GNC_SRCDIR-@#${abs_top_srcdir}#g'
	mv $@.tmp $@
	chmod u+x $@
CLEANFILES += systecash-build-env
