﻿#include <cppx-core-language/all.hpp>
#include <c/math.hpp>       // sin
#include <iostream>         // std::(cout, endl, fixed)
#include <iomanip>          // std::setprecision

auto main()
    -> int
{
    $use_std( cout, endl, fixed, setprecision );
    $use_cppx( squared );
    using namespace cppx::m;    // pi, etc.
    
    cout << "60 degrees ~= " << 60*(pi/180) << " radians." << endl;

    cout << fixed << setprecision( 20 );
    const double atp = 2*atan2( 1, 0 );     // Pi computed using arc tan of 90 degrees.
    cout << "Error when using '3.14'  : " << 4*squared( sin( 3.14/3 ) ) - 3 << "." << endl;
    cout << "Error when using arctan  : " << 4*squared( sin( atp/3 ) ) - 3 << "." << endl;
    cout << "Error when using cppx:pi : " << 4*squared( sin( pi/3 ) ) - 3 << "." << endl;
}
