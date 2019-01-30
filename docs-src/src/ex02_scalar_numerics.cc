#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex02_scalar_numerics, args, nargout,
  "Basic numeric arrays")
{
  Matrix x (1, 1, 42.0);
  Matrix y (1, 1, NAN);
  return octave_value (x + y);
}
