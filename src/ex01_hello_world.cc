#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (ex01_hello_world, args, nargout,
  "'Hello, world!' as an oct-file")
{
  octave_stdout << "Hello, world!" << std::endl;

  return octave_value_list ();
}
