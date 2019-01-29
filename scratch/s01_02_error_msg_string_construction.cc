
#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (s01_02_error_msg_string_construction, args, nargout,
           "Error message construction using argument type")
{
  octave_value x = args(0);

  builtin_type_t x_type = x.builtin_type ();
  std::string msg = std::string ("Type of arg 1 is: ") + x_type;
  error (msg);

  return octave_value_list ();
}
