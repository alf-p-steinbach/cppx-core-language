#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_even
#include <cppx-core-language/bit-level/bits_per_.hpp>       // cppx::bits_per_
#include <cppx-core-language/bit-level/intlog2.hpp>         // cppx::intlog2
#include <cppx-core-language/bit-level/sum_of_bits.hpp>     // cppx::sum_of_bits
#include <cppx-core-language/syntax/types/Sequence_.hpp>    // cppx::Sequence

#include <c/stdint.hpp>         // uint8_t
#include <bitset>               // std::bitset
#include <iostream>             // std::(cout, endl)
#include <iomanip>              // std::setw
$use_std( bitset, cout, endl, setw );

template< class... Args >
void display_row( const Args&... args )
{
    ((cout << setw( 16 ) << args), ...) << endl;
}

auto main()
    -> int
{
    $use_cppx( bits_per_, Sequence, is_even, intlog2, sum_of_bits );
    
    using U = uint8_t;
    const int n_bits = bits_per_<U>;
    const int max_bit_pos = n_bits - 1;
    using Bits = bitset<n_bits>;

    display_row( "Value:", "Bits:", "MSB pos:", "Sum of bits:" );
    cout << endl;

    U u = 0;
    for( const int i: Sequence( -1, max_bit_pos ) ) {
        u <<= 1;
        if( is_even( i ) ) { u |= 1; }
        display_row( +u, Bits( u ), intlog2( u ), sum_of_bits( u ) );
    }
}
