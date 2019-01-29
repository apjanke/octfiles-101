Octfiles 101 TODO
=================

## Project

* Pick a license. Probably GPL or GNU FDL.
  * About the GFDL
    * See <https://www.adamhyde.net/1198-2/>
    * See <https://en.wikipedia.org/wiki/GNU_Free_Documentation_License>
    * See <https://www.debian.org/vote/2006/vote_001>
    * See <https://web.archive.org/web/20060202010406/http://home.twcny.rr.com/nerode/neroden/fdl.html>
    * And for some really harsh criticisim, see <https://rationalwiki.org/wiki/GNU_Free_Documentation_License>
  * Or maybe a CC license?
* Travis CI setup
  * Build and test all examples.
  * Figure out a way to actually include the document examples from the source code, to ensure they're never out of sync, and always tested by compiling.
* Add PDF output
* Add some BISTs to examples?

## Document Content

### Next Steps

* Find examples of Octave Forge packages that use Oct-Files and use them as reference.
* Why does `NDArray * NDArray` fail to compile?

* Check out [this O'Reilly Octave book](https://www.oreilly.com/library/view/gnu-octave/9781849513326/). I should have a Safari subscription through my ACM or IEE Computer memberships.

### Longer Term Stuff

* See if Matlab/Octave syntax highlighting can be enabled in Asciidoc code snippets?
  * The highlight.js page includes Matlab in the [“scientific” section](https://highlightjs.org/static/demo/).
