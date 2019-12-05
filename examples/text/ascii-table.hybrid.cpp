#include <cppx-core-language/ascii/all.hpp>
#include <iomanip>          // std::setw
#include <iostream>

auto main()
    -> int
{
    using std::cout, std::endl, std::left, std::setw;
    using cppx::hex_digit;
    namespace ascii = cppx::ascii;

    const auto field = setw( 4 );
    
    // Column headers.
    cout << field << "";
    for( int i = 0; i < 16; ++i ) { cout << field << hex_digit( i ); }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( int y = 0; y < 8; ++y ) {
        cout << field << hex_digit( y );
        for( int x = 0; x < 16; ++x ) {
            const int code = 16*y + x;
            const auto ch = char( ascii::is_noncontrol( code )? code: ascii::del );
            cout << field << ch;
        }
        cout << endl;
    }
}
