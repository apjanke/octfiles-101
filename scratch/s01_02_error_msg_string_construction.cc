#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (s01_02_error_msg_string_construction, args, nargout,
           "Error message construction using argument type")
{
  octave_value x = args(0);

  std::string x_type_name = x.type_name ();
  std::string msg = std::string ("Type of arg 1 is: ") + x_type_name;
  error (msg.c_str ());

  builtin_type_t x_type = x.builtin_type ();
  std::string msg2 = std::string ("Builtin type id of arg 1 is: ") + x_type;
  error (msg2.c_str ());

  octave_idx_type n_elems = x.numel ();
  std::string msg3 = std::string ("Numel in arg 1: ") + n_elems;
  error (msg3.c_str ());
}
