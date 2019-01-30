#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex03_inputs_and_error_checking, args, nargout,
  "Inputs and error checking")
{
  octave_idx_type nargin = args.length ();
  if (nargin != 2) {
  	error ("Need exactly 2 argins, got %ld", (long) nargin);
  }
  NDArray x = args(0).array_value ();
  NDArray y = args(1).array_value ();
  if (x.any_element_is_nan ()) {
    warning ("NaNs present in input");
  }

  return ovl (y, x);
}
