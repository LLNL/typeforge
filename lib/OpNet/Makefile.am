
# AM_LDFLAGS = $(ROSE_LIBS) $(LIBS_WITH_RPATH)
# AM_CPPFLAGS = $(ROSE_INCLUDES)
# AM_CXXFLAGS= -I$(top_srcdir)/include -g -Wall -O3 -march=native -ftree-vectorize

lib_LTLIBRARIES= \
  libTypeforge-opnet.la

libTypeforge_opnet_la_SOURCES= \
  OperandNetwork.cpp \
  OperandData.cpp \
  TypeChain.cpp \
  CollapseRules.cpp \
  commons.cpp

libTypeforge_opnet_la_CXXFLAGS= \
  -I$(abs_top_srcdir)/include \
  -g -Wall -O3 -march=native -ftree-vectorize \
  -rdynamic

