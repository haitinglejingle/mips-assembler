## This is the Makefile for the template paper. All you need to do is 
## edit "TARGETS" below to the name of the main .tex file for your paper.

TARGETS = report

TEXFILES = $(wildcard *.tex)
PDFS = $(addsuffix .pdf,$(TARGETS))

all: $(PDFS)

%.pdf: %.tex $(TEXFILES)
	pdflatex $*.tex

clean:
	/bin/rm -f $(PDFS) *.dvi *.aux *.ps *~ *.log *.lot *.lof *.toc *.blg *.bbl url.sty

FORCE:

