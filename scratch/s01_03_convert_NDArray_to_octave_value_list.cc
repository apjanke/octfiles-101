
#include <cmath>
#include <iostream>
#include <octave/oct.h>

octave_value_list
f1() {
  NDArray x (1.0);
  NDArray y (2.0);

  return octave_value_list (x, y);
}

DEFUN_DLD (s01_02_error_msg_string_construction, args, nargout,
           "Try converting NDArray to octave_value_list")
{
  NDArray x (42.0);

  return octave_value_list (x);
}


