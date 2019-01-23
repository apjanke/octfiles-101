Octfiles 101 TODO
=================

## Project

* Pick a license.
* Create a Makefile, to:
  * Build all examples.
* Figure out a way to actually include the document examples from the source code, to ensure they're never out of sync, and always tested by compiling.
* Travis CI setup
  * Build all examples. Maybe run them, too?
* Find examples of Octave Forge packages that use Oct-Files and use them as reference.

## Document

### Next Steps

* Variadic `error(fmt, ...)` - why not compiling?
* Why does `NDArray * NDArray` fail to compile?
* Find out how to do `warning()` from an oct-file and include in Input Checking section.

### Longer Term Stuff

* See if Matlab/Octave syntax highlighting can be enabled in Markdown code snippets?
  * The highlight.js page includes Matlab in the [“scientific” section](https://highlightjs.org/static/demo/).
