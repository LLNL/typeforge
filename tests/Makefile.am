

TYPEFORGE=../src/typeforge

../src/typeforge:
	make -C ../src typeforge

# Output the TypeChain in GraphViz format
chktf-typechain: $(TYPEFORGE) $(srcdir)/sample-000.cxx
	$(TYPEFORGE) --typechain-detailed-dot typechain.dot $(srcdir)/sample-000.cxx
	if which dot &> /dev/null; then \
	  dot -Tsvg typechain.dot -o typechain.svg ; \
	fi

# ADAPT test
#  * this test uses all of typeforge actions
#  * incomplete as generated file cannot be compiled without installing Adapt...
chktf-adapt: $(TYPEFORGE) $(srcdir)/adapt.json $(srcdir)/adapt-000.cxx
	$(TYPEFORGE) --plugin=$(srcdir)/adapt.json $(srcdir)/adapt-000.cxx

# Test the Operand Network
chktf-opnet: $(TYPEFORGE) $(srcdir)/sample-000.cxx
	$(TYPEFORGE) --opnet $(srcdir)/sample-000.cxx

check-local: chktf-typechain chktf-adapt chktf-opnet

