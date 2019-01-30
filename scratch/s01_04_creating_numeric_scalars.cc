
#include <cmath>
#include <iostream>
#include <octave/oct.h>


DEFUN_DLD (s01_04_creating_numeric_scalars, args, nargout,
           "Constructing scalars")
{
  NDArray nd1 (42);  // WRONG
  NDArray nd2 (42.3);  // WRONG
  NDArray nd3 (9999999999.0); // WRONG
  NDArray nd4 (NAN);  // WRONG
  NDArray nd5 ({1, 1}, 42);
  NDArray nd6 ({1, 1}, 999999999.999);
  NDArray nd7 ({2, 3}, 123.456);
  NDArray nd8 ({1, 2, 3}, 999.999);
  Matrix m1 (1, 1, 42);
  Matrix m2 (1, 1, 42.3);
  Matrix m3 (1, 1, 99999.9999);
  MArray<double> ma1 ({1, 1}, 42);
  MArray<double> ma2 ({1, 1}, 42.3);
  MArray<double> ma3 ({1, 1}, 99999.99999);
  Matrix nan1 (1, 1, NAN);

  return ovl (nd1, nd2, nd3, nd4, nd5, nd6, nd7, nd8, m1, m2, m3, ma1, ma2, ma3, nan1);
}


