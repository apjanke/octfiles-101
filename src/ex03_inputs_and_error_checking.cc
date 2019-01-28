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
  //NDArray my_product = x * y;
  NDArray my_product (0.0);
  octave_value_list varargout;
  varargout(0) = my_diff;
  varargout(1) = my_product;
  return varargout;
}
