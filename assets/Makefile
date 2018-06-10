%.svg:%.pdf
	pdf2ps $*.pdf
	inkscape --without-gui --file=$*.ps --export-plain-svg=$*.svg
%.png:%.svg
	convert $*.svg $*.png

copy:
	scp chaudhur@perso-chaudhur.lxc.enst.fr:/home/chaudhur/www/images/hsa_security/

