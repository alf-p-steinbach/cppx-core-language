#include <cppx-core-language/all.hpp>
#include <iomanip>          // std::setw
#include <iostream>

auto main()
    -> int
{
    $use_std( cout, endl, left, setw );
    $use_cppx( zero_to, hex_digit );
    $alias_cppx_ns( ascii );
    
    const auto field = setw( 4 );

    // Column headers.
    cout << field << "";
    $repeat_times( 16 ) { cout << field << hex_digit( _i ); }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( const int y: zero_to( 8 ) ) {
        cout << field << hex_digit( y );
        for( const int x: zero_to( 16 ) ) {
            const int code = 16*y + x;
            const auto ch = char( ascii::is_noncontrol( code )? code: ascii::del );
            cout << field << ch;
        }
        cout << endl;
    }
}
