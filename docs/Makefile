all: manual.tex
	latex manual.tex
	latex manual.tex # Needs to be done a second time to make sure that the contents table is correct
	dvips -o manual.ps manual.dvi
	dvipdfm manual.dvi

clean:
	rm manual.aux 
	rm manual.dvi 
	rm manual.log 
	rm manual.pdf 
	rm manual.ps 
	rm manual.toc
