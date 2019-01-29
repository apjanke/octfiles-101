#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex04_basic_arithmetic, args, nargout,
  "Basic arithmetic")
{
  NDArray x = args(0).array_value ();
  NDArray y = args(1).array_value ();

  NDArray my_sum = x + y;
  NDArray my_difference = x - y;
  // Must use product(), not x * y, for NDArrays
  NDArray my_product = product (x, y);

  return ovl (my_sum, my_difference, my_product);
}
