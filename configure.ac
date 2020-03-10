#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(typeforge, 1.0.1, vanderbrugge1@llnl.gov)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR([config])

CONFIGURE_ROSE_COMPILER # Must occur before LT_INIT to prevent premature call to AC_PROG_CXX

AC_SUBST(TYPEFORGE_CXXFLAGS, "-Wall -Wno-misleading-indentation -Wunused-variable") # -g -Wall -O3 -march=native -ftree-vectorize -rdynamic

AM_INIT_AUTOMAKE
LT_INIT
AC_CONFIG_SRCDIR([src/typeforge.cpp])

AC_OUTPUT(Makefile include/Typeforge/Makefile include/Typeforge/OpNet/Makefile include/nlohmann/Makefile lib/Makefile lib/OpNet/Makefile src/Makefile tests/Makefile docs/Makefile)
