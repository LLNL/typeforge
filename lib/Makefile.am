
SUBDIRS=OpNet

lib_LTLIBRARIES= \
  libTypeforge.la \
  libTypeforge-transform.la \
  libTypeforge-cast.la \
  libTypeforge-utils.la

libTypeforge_la_SOURCES=SpecFrontEnd.cpp ToolConfig.cpp CommandList.cpp Analysis.cpp commons.cpp
libTypeforge_la_CPPFLAGS=-I$(abs_top_srcdir)/include $(ROSE_CPPFLAGS)
libTypeforge_la_CXXFLAGS=$(ROSE_CXXFLAGS) $(TYPEFORGE_CXXFLAGS)

libTypeforge_transform_la_SOURCES=TFTypeTransformer.cpp TFTransformation.cpp
libTypeforge_transform_la_CPPFLAGS=-I$(abs_top_srcdir)/include $(ROSE_CPPFLAGS)
libTypeforge_transform_la_CXXFLAGS=$(ROSE_CXXFLAGS) $(TYPEFORGE_CXXFLAGS)

libTypeforge_cast_la_SOURCES=CastStats.cpp
libTypeforge_cast_la_CPPFLAGS=-I$(abs_top_srcdir)/include $(ROSE_CPPFLAGS)
libTypeforge_cast_la_CXXFLAGS=$(ROSE_CXXFLAGS) $(TYPEFORGE_CXXFLAGS)

libTypeforge_utils_la_SOURCES=CppStdUtilities.cpp
libTypeforge_utils_la_CPPFLAGS=-I$(abs_top_srcdir)/include $(ROSE_CPPFLAGS)
libTypeforge_utils_la_CXXFLAGS=$(ROSE_CXXFLAGS) $(TYPEFORGE_CXXFLAGS)
