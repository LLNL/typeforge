
SUBDIRS=OpNet

# AM_LDFLAGS = $(ROSE_LIBS) $(LIBS_WITH_RPATH)
# AM_CPPFLAGS = $(ROSE_INCLUDES)
# AM_CXXFLAGS = -I$(top_srcdir)/include -g -Wall -O3 -march=native -ftree-vectorize

config_CXXFLAGS= \
  -I$(abs_top_srcdir)/include \
  -g -Wall -O3 -march=native -ftree-vectorize \
  -rdynamic -Wno-misleading-indentation \
  -Wno-unused-variable -Wno-unused-but-set-variable

lib_LTLIBRARIES= \
  libTypeforge.la \
  libTypeforge-transform.la \
  libTypeforge-cast.la \
  libTypeforge-utils.la

libTypeforge_la_SOURCES= \
  SpecFrontEnd.cpp \
  ToolConfig.cpp \
  CommandList.cpp \
  Analysis.cpp \
  commons.cpp
libTypeforge_la_CXXFLAGS=$(config_CXXFLAGS)

libTypeforge_transform_la_SOURCES= \
  TFTypeTransformer.cpp \
  TFTransformation.cpp
libTypeforge_transform_la_CXXFLAGS=$(config_CXXFLAGS)

libTypeforge_cast_la_SOURCES= \
  CastStats.cpp
libTypeforge_cast_la_CXXFLAGS=$(config_CXXFLAGS)

libTypeforge_utils_la_SOURCES= \
  CppStdUtilities.cpp
libTypeforge_utils_la_CXXFLAGS=$(config_CXXFLAGS)

