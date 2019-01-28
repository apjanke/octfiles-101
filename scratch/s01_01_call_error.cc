#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (s01_01_call_error, args, nargout,
  "Call error() variadically")
{
  error ("A single C string message");

  int n = 42;
  error ("Message: n=%d", n);

  std::string str = "foobar";
  error ("Message: str=%s", str.c_str ());

  error ("Message: x=%f", 42.0);

  return octave_value_list ();
}