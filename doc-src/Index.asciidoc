Oct-Files 101
=============

# Introduction

This guide is a gentle introduction to writing oct-files for GNU Octave.
It assumes you know Octave M-code and have a passing familiarity with C++.
No prior oct-file experience is assumed.

Oct-files are Octave extensions written in C++ that make use of the same Octave internal API that Octave itself is written in.
(I'm not sure what that API is called.)
That API is in C++ and makes use of a lot of templates and inheritance, so it can be difficult to muddle through.

I wrote this guide because I needed to write a few oct-files and couldn't find a good introductory tutorial, and I wanted others to have an easier time of it than I did.
The Octave manual's [Oct-Files appendix](https://octave.org/doc/v4.4.1/Oct_002dFiles.html) covers the oct-file interface and aspects of coding unique to it, but seems to presume a familiarity with the internal Octave API.
I lacked that familiarity.
This guide intends to step in for the beginner who also doesn't know the internal Octave API, but wants to get a quick start being productive with oct-files.

Please note: I am myself an oct-file novice.
I'm writing this document as I learn.
Please forgive any mistakes.
Or better yet, file an [Issue](https://github.com/apjanke/octfiles-101/issues) and let me know what I did wrong.
You can also contact me at <floss@apjanke.net>.

This guide was written and tested with Octave 4.4, primarily on macOS, but it should apply to other versions and OSes as well.

## Terminology

This document uses the following terms, which may or may not be offical Octave-speak:

<dl>
  <dt>M function</dt>
  <dd>An Octave function defined in M-code. These are the regular Octave functions you're used to writing.</dd>

  <dt>oct function</dt>
  <dd>An Octave function defined by an oct-file.
</dl>

# Writing Oct-Files

## The Very Basics

### Hello, World

Here's the coding classic “Hello, World” written as an oct-file:

```C++
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex01_hello_world, args, nargout,
  "My 'Hello, world!' function")
{
  octave_stdout << "Hello, world!" << std::endl;

  return octave_value_list ();
}
```

This is the equivalent of the following M function:

```
function ex01_hello_world ()
  % My 'Hello, world!' function
  fprintf ("Hello, world!\n");
endfunction
```

Let's break this down.

```c++
#include <iostream>
#include <octave/oct.h>
```

These `#includes` are C preprocessor statements that pull in "header" files, giving you access to the definitions of C/C++ functions and types.
`#include <iostream>` pulls in the standard C++ I/O routines.
`#include <octave/oct.h>` pulls in Octave's oct-file API, which also includes the Octave internal API.
Just put these in every oct-file.

```c++
DEFUN_DLD (ex01_hello_world, args, nargout,
  "'Hello, world!' as an oct-file")
```

The `DEFUN_DLD (...)` macro defines the entry point to your oct-file.
This introduces the C++ function that will be presented as the Octave function for this oct-file.

The first argument (`ex01_hello_world`) is the name of the Octave function you're defining.
It should be the same name as the file, minus its `.cc` extension.

The next two arguments, `args` and `nargout`, give your function access to how it was called from Octave M-code.
Leave them exactly as is.

The fourth argument, is the helptext string for your function.
You can extend it across multiple lines by putting multiple double-quoted strings in a row on subsequent lines, with no commas between them, before the closing “`)`”.
(C++ concatenates mulstiple strings like this into a single string.)
Put a `\n` newline at the end of each string in a multi-line help string.

For example:

```c++
DEFUN_DLD (ex01_hello_world, args, nargout,
  "'Hello, world!' as an oct-file\n"
  "\n"
  "This is another line of helptext.\n"
  "And another.")
```

The code between the `{...}` braces is the body of your main oct-file function.

```c++
  octave_stdout << "Hello, world!" << std::endl;
```

This displays output to the Octave command window.
In oct-files, you use `octave_stdout` instead of `std::out`.
The `std::endl` adds a newline and flushes the output.

```c++
  return octave_value_list ();
```

Your C++ oct-file main function always has to return something, even if at the Octave level the function has no argouts.
Return values from an oct-file are encapsulated in an `octave_value_list` object, which is the C++ equivalent of a comma-separated list in M-code.
`octave_value_list ()` with no arguments constructs an empty list, which is equivalent to an M-code function that returns zero argouts.

### Creating Some Arrays

Let's create some array values.

Octave arrays are represented by a [whole slew of C++ types](https://octave.org/doc/v4.0.1/Matrices-and-Arrays-in-Oct_002dFiles.html) in the Octave API.
In M-code, these are all just held in variables, but in C++, different kinds of arrays are differentiated by static types.
Here are the basic ones:

| C++ Type | Meaning | M-code Equivalent |
|----------|---------|----------|
| `octave_value` | A single Octave array | Any variable |
| `octave_value_list` | A list of Octave arrays | A comma-separated list |
| `Array` | An N-dimensional array of any type | Any variable |
| `Matrix` | A 2-dimensional `double` array | `double` |
| `NDArray` | An N-dimensional `double` array | `double` (non-complex) |
| `charMatrix` | A 2-dimensional character array | `char` |

_(TODO: Find out which, if any, of these are `abstract` types and note that.)_

_(TODO: Find out the difference between an `Array` and an `octave__value`.)_

Consider this M function:

```
function out = ex02_some_values
  x = 42;
  y = NaN;
  out = x + y;
endfunction
```

Here's the oct-file equivalent:

```c++
#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex02_scalar_numerics, args, nargout,
  "Basic numeric arrays")
{
  NDArray x (42.0);
  NDArray y (0.0);
  y(0) = NAN;
  NDArray out = x + y;
  return octave_value_list (octave_value (out));
}
```

Let's break down the new stuff:

`#include <cmath>` pulls in the C math header.
You need this to get access to the `NAN` constant.

```c++
  NDArray x (42.0);
```

An `NDArray` is an n-dimensional Octave `double` array. `NDArray <name> (<x>)`, where <x> is a C++ `double` value, creates a scalar (1-by-1) Octave `double` array and initializes it with the value you pass in.

In Octave, every numeric literal is a `double`, whether you write it as `42` or `42.0`.
In C++, they're distinct types: `42` is an `int`, and `42.0` is a `double`.
But because you're making an `NDArray`, whatever you pass in gets converted to a double.
(Usually. You can't say `NDArray y(0);`. I don't know why.)
`NDArray` knows its element data type, and that type is always `double`. I think.

```c++
NDArray y (0.0);
y(0) = NAN;
```

Once you create an `NDArray`, you can assign values to its elements using `()`-indexing, like you can in M-code.
But, in C/C++, arrays are [zero-indexed](https://en.wikipedia.org/wiki/Zero-based_numbering) instead of 1-indexed like in M-code.
And you index into an `NDArray` C-style.

You can't just say `NDArray y (NAN)` directly.
That gives you a `0` instead of `NaN`.
I don't know why.
Instead, you have to create a new array, and then assign over its element's value.

```c++
NDArray out = x + y;
```

You can do math with C++ Octave array types using `+`, `-`, `*`, and other arithmetic operators, similar to how you can in M-code.
(_TODO: Find out whether `*` is `times` or `mtimes`._)

```c++
return octave_value (out);
```

You can't return an `NDArray` directly from your oct function.
That will give you a C++ compilation error.
You need to convert it to an `octave_value`.
(I don't know why.)
But you can omit the `octave_value_list (...)` around your `octave_value (...)` – there is an automatic conversion from `octave_value` to an `octave_value_list`.

### Inputs and Error Checking

To do useful work, we need to accept input arguments from our caller.

```c++
#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex03_inputs_and_error_checking, args, nargout,
  "Inputs and error checking")
{
  int nargin = args.length ();
  if (nargin != 2) {
  	error ("Need exactly 2 argins, got %d", nargin);
  }
  NDArray x = args(0).array_value ();
  NDArray y = args(1).array_value ();

  NDArray my_diff = x - y;
  // This "x * y" results in a compilation error. I wonder why?
  // NDArray my_product (x * y);
  NDArray my_product (0.0);
  octave_value_list varargout;
  varargout(0) = my_diff;
  varargout(1) = my_product;
  return varargout;
}
```

This is basically the equivalent of the M function:

```
function [my_diff, my_product] = ex03_inputs_and_error_checking (x, y)
  narginchk (2, 2);
  my_diff = x - y;
  my_product = x .* y;
endfunction
```

Let's break it down:

```c++
  error ("Need exactly 2 argins, got %d", nargin);
```

Calling `error()` in an oct-file behaves the same as calling `error()` in M-code: it aborts execution of the function, returning control to the interactive prompt, or an enclosing M-code `try`/`catch` block. You can pass multiple arguments to `error()`, in which case the first argument is a `printf`-style format string, and the remaining arguments are values to substitue into the format string's placeholders. This is a good thing to make use of, because it lets you include information about the actual data values that caused a problem, making it easier to debug.

Note that if you pass strings in to `error()`, they must be C-style strings (`char *`s) and not C++ `std::string` objects. Any `std::string` needs to be converted to a `char *` by calling `c_str()` on it.

Also, the values passed in to `error()` need to be basic C++ types like `char *`, `int`, or `double`, not Octave API objects like `NDArray` or `Matrix`.

```c++
octave_value_list varargout;
varargout(0) = my_diff;
varargout(1) = my_product;
return varargout;
```

You can assign into an `octave_value_list` using `()`-indexing, like you can with an `Array`, but the right-hand-side values must themselves be `octave_value`s or compatible.

You can't just say `return octave_value_list (my_diff, my_product)`.
I don't know why.

And here's where I'm stuck.
I don't know why `x * y` fails to compile.

_Next step: look at some oct-files in Octave Forge packages to find examples._

See [Input Parameter Checking in Oct-Files](https://octave.org/doc/v4.0.1/Input-Parameter-Checking-in-Oct_002dFiles.html) for more details.

# Other Resources

[The GNU Octave 4.4.1 Manual Oct-Files section](https://octave.org/doc/v4.4.1/Oct_002dFiles.html) – This is the official reference on oct-files.

[Da Coda Al Fine - Pushing Octave‘s Limits](https://octave.sourceforge.io/coda/index.html) – An older 2004 document on advanced Octave programming.
Contains a section on oct-files.

The `#octave` channel on [freenode IRC](https://freenode.net/) is often populated with Octave hackers, including Octave's core developers.
You can ask oct-file questions there.

The Octave source code is the real low-level reference on the Octave internal API used by oct-files.
The relevant definitions are in the `*.h` header files in `liboctave/` and `libinterp/`.

[StackOverflow](https://stackoverflow.com) is the web's premiere Q&A site for programmers.
Tag your question with the [“octave” tag](https://stackoverflow.com/questions/tagged/octave).
