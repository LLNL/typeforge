
all: typeforge.pdf

typeforge.pdf: typeforge.tex typeforge.bib
	@if which pdflatex &> /dev/null; then \
	  pdflatex typeforge.tex ; \
	  bibtex typeforge ; \
	  pdflatex typeforge.tex ; \
	  pdflatex typeforge.tex ; \
	else \
	  echo "### Requires pdflatex to build the documentation!" ; \
	fi

clean:
	rm -f typeforge.aux typeforge.bbl typeforge.blg typeforge.log typeforge.toc typeforge.pdf

