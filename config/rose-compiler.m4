AC_DEFUN([CONFIGURE_ROSE_COMPILER], [

  AC_CHECK_PROGS([ROSECFG], [rose-config], [no])
  if test "$ROSECFG" = no; then
     AC_MSG_ERROR([Could not find the rose-config executable.])
  fi

  AC_PROG_CXX([$(rose-config cxx)])
  AC_SUBST(ROSE_CPPFLAGS, "$(rose-config cppflags) -I$(rose-config prefix)/include")
  AC_SUBST(ROSE_CXXFLAGS, $(rose-config cxxflags))
  AC_SUBST(ROSE_LDFLAGS,  $(rose-config ldflags))
  AC_SUBST(ROSE_LIBDIRS,  $(rose-config libdirs))

])
  
