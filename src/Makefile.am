
bin_PROGRAMS = typeforge

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

typeforge_SOURCES=typeforge.cpp CommandLineOptions.cpp
typeforge_LDADD=$(TF_LIB) $(TF_OPNET_LIB) $(TF_TRANSFORM_LIB) $(TF_CAST_LIB) $(TF_UTILS_LIB)
typeforge_LDFLAGS=$(ROSE_LDFLAGS) -Wl,-rpath,$(prefix)/lib
typeforge_CPPFLAGS=$(ROSE_CPPFLAGS) -I$(abs_top_srcdir)/include
typeforge_CXXFLAGS=$(ROSE_CXXFLAGS) $(TYPEFORGE_CXXFLAGS)

chktf-version: typeforge
	./typeforge --version

chktf-help: typeforge
	./typeforge --help > /dev/null

check-local: chktf-version chktf-help

