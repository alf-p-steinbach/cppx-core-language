#include <ctype.h>          // ::isprint
#include <iomanip>          // std::setw
#include <iostream>
#include <limits.h>         // CHAR_MIN, UCHAR_MAX    

using Byte = unsigned char;

auto is_noncontrol_ascii( const int code )
    -> bool
{ return code >= CHAR_MIN and code <= UCHAR_MAX and ::isprint( Byte( code ) ); }

auto main()
    -> int
{
    using std::cout, std::endl, std::left, std::setw;
    constexpr auto& hex_digits = "0123456789abcdef";
    
    const auto field = setw( 4 );
    const auto ascii_del = char( 127 );
    cout << left;
    
    // Column headers.
    cout << field << "";
    for( int i = 0; i < 16; ++i ) { cout << field << hex_digits[i]; }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( int y = 0; y < 8; ++y ) {
        cout << field << hex_digits[y];
        for( int x = 0; x < 16; ++x ) {
            const int code = 16*y + x;
            const auto ch = char( is_noncontrol_ascii( code )? code: ascii_del );
            cout << field << ch;
        }
        cout << endl;
    }
}
