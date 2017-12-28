AC_INIT([librdt], [1.0.1], [daviddoyaguez@gmail.com])
AM_INIT_AUTOMAKE([subdir-objects foreign -Wall -Werror])
AC_PROG_CC
AM_PROG_AR
AC_PROG_RANLIB
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile src/Makefile test/bintree/Makefile test/list/Makefile test/namednode/Makefile test/node/Makefile])

AC_CHECK_PROGS([DOXYGEN], [doxygen])
if test -z "$DOXYGEN"; then
  AC_MSG_WARN([Doxygen not found - continuing without Doxygen])
else
  AC_CHECK_PROGS([DOT], [dot])
  if test -z "$DOT"; then
    AC_MSG_ERROR[Doxygen needs dot, please install graphviz package]
  fi
  AC_CHECK_PROGS([PDFLATEX], [pdflatex])
  if test -z "$PDFLATEX"; then
    AC_MSG_ERROR([Doxygen needs pdflatex, please install texlive package])
  fi
fi


AC_OUTPUT
