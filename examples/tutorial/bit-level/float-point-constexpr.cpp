#include <cppx-core-language/calc/floating-point-operations.hpp>    // cppx::(intpow, squared, cubed)

#include <c/math.hpp>
#include <iostream>
#include <iomanip>
$use_std( cout, endl, fixed, setprecision );

auto main()
    -> int
{
    $use_cppx( intpow, squared, cubed );

    cout << fixed << setprecision( 16 );

    constexpr double base = 1.001;
    constexpr double x2 = squared( base );
    cout << base << " ^ 2 ~= " << x2 << "." << endl;

    constexpr double x3 = cubed( base );
    cout << base << " ^ 3 ~= " << x3 << "." << endl;

    cout << endl;
    for( int i = 0; i <= 12; ++i ) {
        cout << intpow( base, i ) << " versus " << pow( base, i ) << endl;
    }
    
}
