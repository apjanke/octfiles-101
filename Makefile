
.PHONY: site clean compile .FORCE

site: doc/Index.html

EXAMPLE_SRCFILES := $(wildcard doc-src/src/*.cc)

doc/Index.html: doc-src/Index.asciidoc $(EXAMPLE_SRCFILES)
	asciidoctor --safe --section-numbers --backend html5 \
	  doc-src/Index.asciidoc -o doc/Index.html
doc:
	mkdir -p doc

compile: .FORCE
	cd doc-src/src && make compile

clean:
	rm -f doc-src/src/*.o doc-src/src/*.oct
