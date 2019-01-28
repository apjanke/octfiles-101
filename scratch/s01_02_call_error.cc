#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (s01_02_call_error, args, nargout,
  "Call error() variadically")
{
  std::string str = "foobar";
  int n = 4;
  double x = 42.0;
  long ln = 5;

  error ("Message: str=%s n=%d x=%f ln=%ld",
  	str.c_str (), n, x, ln);

  return octave_value_list ();
}