EXTRA_DIST = \
  systecash.spec.in \
  systecash.spec

all-local: systecash.spec

## We borrow guile's convention and use @-...-@ as the substitution
## brackets here, instead of the usual @...@.  This prevents autoconf
## from substituting the values directly into the left-hand sides of
## the sed substitutions.  *sigh*
systecash.spec: systecash.spec.in Makefile ${top_builddir}/config.status
	rm -f $@.tmp
	sed < $< > $@.tmp \
            -e 's:@-VERSION-@:${VERSION}:'
	mv $@.tmp $@

DISTCLEANFILES = systecash.spec
