#include <cmath>
#include <iostream>
#include <octave/oct.h>

typedef octave_idx_type oct_idx;

DEFUN_DLD (ex05_sizes_and_indexing, args, nargout,
           "Sizes and indexing")
{
  NDArray x = args(0).array_value ();

  dim_vector sz = x.dims ();
  NDArray y (sz);
  for (oct_idx i = 0; i < y.numel (); i++) {
    y(i) = x(i) + i;
  }

  dim_vector sz2 (2, 3, 4, 5);
  NDArray z (sz2);
  octave_stdout << "Array z has " << sz2.ndims() << " dimensions and "
      << sz2.numel() << " elements." << std::endl;
  NDArray z2 (dim_vector (2, 3, 4, 5));

  return ovl (y);
}
