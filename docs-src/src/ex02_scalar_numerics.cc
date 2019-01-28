#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex02_scalar_numerics, args, nargout,
  "Basic numeric arrays")
{
  NDArray x (42);
  NDArray y (0.0);
  y(0) = NAN;
  NDArray out = x + y;
  return octave_value (out);
}
