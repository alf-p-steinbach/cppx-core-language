#include <iomanip>          // std::setw
#include <iostream>
#include <cppx-core-language/all.hpp>

auto main() -> int
{
    // Instead of `using std::cout, std::endl, std::left, std::setw;`, just:
    $use_std( cout, endl, left, setw );

    $use_cppx( zero_to, hex_digit );    // Use identifiers cppx::zero_to, cppx::hex_digit.
    $use_cppx_nsname( ascii );          // Use namespace name cppx::ascii.
    
    const auto field = setw( 4 );
    cout << left;
    
    // Column headers.
    cout << field << "";
    for( const int x: zero_to( 16 ) ) { cout << field << hex_digit( x ); }
    cout << endl;
    cout << endl;   // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( const int y: zero_to( 8 ) ) {
        cout << field << hex_digit( y );
        for( const int x: zero_to( 16 ) ) {
            const char code = 16*y + x;
            const auto ch = char( ascii::is_noncontrol_char( code )? code: ascii::del );
            cout << field << ch;
        }
        cout << endl;
    }
}
