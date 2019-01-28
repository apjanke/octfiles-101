
.PHONY: site clean compile .FORCE

site: docs/Index.html

EXAMPLE_SRCFILES := $(wildcard docs-src/src/*.cc)

docs/Index.html: docs docs-src/Index.asciidoc $(EXAMPLE_SRCFILES)
	asciidoctor --safe --section-numbers --backend html5 \
	  docs-src/Index.asciidoc -o docs/Index.html
docs:
	mkdir -p docs

compile: .FORCE
	cd docs-src/src && make compile

clean:
	rm -f docs-src/src/*.o docs-src/src/*.oct
