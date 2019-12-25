
bin_PROGRAMS = typeforge

# AM_LDFLAGS = $(ROSE_LIBS) $(LIBS_WITH_RPATH)
# AM_CPPFLAGS = $(ROSE_INCLUDES)

TF_LIB=$(abs_top_builddir)/lib/libTypeforge.la
$(TF_LIB):
	$(MAKE) -C $(abs_top_builddir)/lib libTypeforge.la

TF_TRANSFORM_LIB=$(abs_top_builddir)/lib/libTypeforge-transform.la
$(TF_TRANSFORM_LIB):
	$(MAKE) -C $(abs_top_builddir)/lib libTypeforge-transform.la

TF_CAST_LIB=$(abs_top_builddir)/lib/libTypeforge-cast.la
$(TF_CAST_LIB):
	$(MAKE) -C $(abs_top_builddir)/lib libTypeforge-cast.la

TF_UTILS_LIB=$(abs_top_builddir)/lib/libTypeforge-utils.la
$(TF_UTILS_LIB):
	$(MAKE) -C $(abs_top_builddir)/lib libTypeforge-utils.la

TF_OPNET_LIB=$(abs_top_builddir)/lib/OpNet/libTypeforge-opnet.la
$(TF_OPNET_LIB):
	$(MAKE) -C $(abs_top_builddir)/lib/OpNet libTypeforge-opnet.la

typeforge_SOURCES=typeforge.cpp
typeforge_LDADD= \
  $(TF_LIB) \
  $(TF_OPNET_LIB) \
  $(TF_TRANSFORM_LIB) \
  $(TF_CAST_LIB) \
  $(TF_UTILS_LIB)
typeforge_CXXFLAGS= \
  -I$(abs_top_srcdir)/include \
  -g -Wall -O3 -march=native -ftree-vectorize \
  -rdynamic

tf-version: typeforge
	./typeforge --version

tf-help: typeforge
	./typeforge --help

check-local: tf-version tf-help

