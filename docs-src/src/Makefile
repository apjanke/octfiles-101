
.PHONY: compile
	
SRCFILES = $(wildcard *.cc)

compile: $(SRCFILES)
	for file in $(SRCFILES); do \
	  mkoctfile $$file; \
	done
