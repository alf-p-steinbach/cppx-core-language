#include <cppx-core-language/calc/floating-point-operations.hpp>    // cppx::(intpow, squared, cubed)

#include <iostream>     // std::(cout, endl, fixed)
#include <iomanip>      // std::setprecision
$use_std( cout, endl, fixed, setprecision );

auto main()
    -> int
{
    $use_cppx( intpow, squared, cubed );
    constexpr int n = 10'000;
    constexpr double base = 1 + 1.0/n;
    cout << fixed << setprecision( 16 );

    constexpr double x2 = squared( base );
    cout << base << " ^ 2 ~= " << x2 << "." << endl;

    constexpr double x3 = cubed( base );
    cout << base << " ^ 3 ~= " << x3 << "." << endl;

    constexpr double xn = intpow( base, n );
    cout << base << " ^ " << n << " ~= " << xn << "." << endl;
}
