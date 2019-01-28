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
  //NDArray my_product = x * y;  // Broken: "ambiguous overloaded operator" compiler error
  NDArray my_product (0.0);

  octave_value_list varargout;
  varargout(0) = my_sum;
  varargout(1) = my_difference;
  varargout(2) = my_product;
  return varargout;
}
