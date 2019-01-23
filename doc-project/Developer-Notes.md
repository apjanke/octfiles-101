Oct-Files 101 Developer Notes
=============================

# See Also

* The [TODO](TODO.md)

# References

* [The GNU Octave 4.4.1 Manual Oct-Files section](https://octave.org/doc/v4.4.1/Oct_002dFiles.html)
* [Da Coda Al Fine - Pushing Octave‘s Limits](https://octave.sourceforge.io/coda/index.html) - An older 2004 document on oct-files and advanced Octave programming.
* [ScaryOctave in the Wayback Machine](http://web.archive.org/web/20040430174704/http://wiki.octave.org:80/wiki.pl?ScaryOctave)
* Mailing List and Forum Posts
  * [”Tutorial on Oct files” (2003)](http://octave.1599824.n4.nabble.com/Tutorial-on-Oct-files-td1617194.html) - An “Octave - General” post asking about other tutorials and not finding much. Its links are now 404.

# Style Guide

## Prose Style Guide

Use:

* “oct-files”, not “octfiles”.
  * Capitalize as “Oct-Files” in titles and “Oct-files” at sentence beginnings.
* American English.
* Oxford commas.
* [“Curly quotes”](https://chrisbracco.com/curly-quotes/) and apostrophes, not "straight quotes".
* Commas outside quotes unless they are part of the actual quoted text.

* List items:
  * Get full stops if they are complete sentences, or can be read as complete sentences when combined with their parent item or introductory text.
  * Do not get full stops if they are sentence fragments.
  * But parallelism takes precedence over the above. (Like in this item.)

* Hyperlinks should have descriptive text, not just something like “here”.

### Authorial Voice

The “I” in this guide is Andrew.
If additional contributors join in, maybe we’ll need to change that to “we”, or get rid of it entirely.

## Code Style Guide

* Standard [GNU Octave code style](https://wiki.octave.org/Octave_style_guide)

### Markdown Style Guide

Let’s try putting each sentence on a new line (except for really short ones) in the Markdown source.
That should make for nice diffs but not require manual re-flowing of text.

Preview your Markdown as you work!
I like to use the [Atom editor](https://atom.io/) and its included Markdown Preview package.
(Ctrl+Shift+M on macOS Atom to show the preview.)
