#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.67])
AC_INIT(FourEx, 0.1, jramsey@openkettle.com)
AM_INIT_AUTOMAKE



AC_CONFIG_SRCDIR([src/include.cpp])
AC_CONFIG_HEADERS([config.h])


# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

#m4_ifdef([FX_CLANLIB], [],
#[AC_FATAL([MISSING script(s) from m4scripts directory.])]
#m4_pattern_forbid([FX_CLANLIB]))

AC_ARG_ENABLE(clanlibdir, AC_HELP_STRING([--with-clanlib], [Location of the clanlib location]),[
        if test $enableval = yes ; then
                AC_MSG_NOTICE([Using ${clanlibdir} for ClanLib])
                LDFLAGS="$LDFLAGS $clanlibdir/lib"
				CPPFLAGS="$CPPFLAGS $clanlibdir/include/ClanLib-2.2/ClanLib"
        else
            AC_MSG_NOTICE([No ClanLib])
        fi
        ],[])






# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
