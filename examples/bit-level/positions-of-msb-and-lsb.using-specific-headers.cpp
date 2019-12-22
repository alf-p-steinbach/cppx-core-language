#include <cppx-core-language/bit-level/intlog2.hpp>         // cppx::(intlog2, intlog2r)
#include <cppx-core-language/syntax/flow-control.hpp>       // $repeat_times
#include <cppx-core-language/types/Int_.hpp>                // cppx::Unsigned_int_
#include <c/stdint.hpp>     // uint32_t
#include <bitset>           // std::bitset
#include <iomanip>          // std::setw
#include <iostream>         // std::(cout, endl)

const int n_bits = 16;

template< class... Args >
void display_row( const Args&... args )
{
    static const int widths[] = {n_bits, 10, 10};
    const int* pw = widths;
    $use_std( cout, endl, setw );
    ((cout << setw( *pw++ ) << args), ...);  cout << endl;
}

auto main()
    -> int
{
    $use_std( bitset );
    $use_cppx( Unsigned_int_, intlog2, intlog2r );

    const unsigned short_pattern = 42 >> 1;
    const int n_left_zeroes = n_bits - (intlog2( short_pattern ) + 1);
    Unsigned_int_<n_bits> bits = 0;
    display_row( "Bits:", "intlog2:", "intlog2r:" );
    $repeat_times( n_left_zeroes + 2 ) {
        switch( _i ) {
            case 0:     { break; }      // Use bitpattern all zeros for first row.
            case 1:     { bits = short_pattern;  break; }
            default:    { bits <<= 1;  break; }
        }
        display_row( bitset<n_bits>( bits ), intlog2( bits ), intlog2r( bits ) );
    }
}
