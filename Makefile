
.PHONY: site clean compile .FORCE

site: docs/index.html

EXAMPLE_SRCFILES := $(wildcard docs-src/src/*.cc)

docs/index.html: docs docs-src/index.asciidoc $(EXAMPLE_SRCFILES)
	asciidoctor --safe --section-numbers --backend html5 \
	  docs-src/index.asciidoc -o docs/index.html
docs:
	mkdir -p docs

compile: .FORCE
	cd docs-src/src && make compile

clean:
	rm -f docs-src/src/*.o docs-src/src/*.oct scratch/*.o scratch/*.oct
