#include <cmath>
#include <iostream>
#include <octave/oct.h>

DEFUN_DLD (s01_01_arithmetic, args, nargout,
           "Basic arithmetic")
{
    NDArray x = args(0).array_value ();
    NDArray y = args(1).array_value ();

    NDArray my_sum = x + y;
    NDArray my_difference = x - y;
    NDArray my_product = x * y;  // Broken: "ambiguous overloaded operator" compiler error

    octave_value_list varargout;
    varargout(0) = my_sum;
    varargout(1) = my_difference;
    varargout(2) = my_product;
    return varargout;
}
