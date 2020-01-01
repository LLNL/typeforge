

TYPEFORGE=../src/typeforge

../src/typeforge:
	make -C ../src typeforge

# Output the TypeChain in GraphViz format
chktf-typechain: $(TYPEFORGE) $(srcdir)/sample-000.cxx
	$(TYPEFORGE) --typechain-graphviz $(srcdir)/sample-000.cxx
	dot -Tsvg typechain.dot -o typechain.svg
	dot -Tsvg typechain_double.dot -o typechain_double.svg

# ADAPT test
#  * this test uses all of typeforge actions
#  * incomplete as generated file cannot be compiled without installing Adapt...
chktf-adapt: $(TYPEFORGE) $(srcdir)/adapt.json $(srcdir)/adapt-000.cxx
	$(TYPEFORGE) --plugin=$(srcdir)/adapt.json $(srcdir)/adapt-000.cxx

# Test the Operand Network
chktf-opnet: $(TYPEFORGE) $(srcdir)/sample-000.cxx
	$(TYPEFORGE) --opnet $(srcdir)/sample-000.cxx

check-local: chktf-typechain chktf-adapt chktf-opnet

