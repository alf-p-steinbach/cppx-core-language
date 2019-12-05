#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_zero
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::zero_to
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( zero_to, is_zero );

    const int n = 1 << 4;
    for( const int y: zero_to( n ) ) {
        printf( "%*c", n - y, ' ' );
        for( const int x: zero_to( n ) ) {
            printf( " %c", is_zero( x & ~y )? 'o' : ' ' );
        }
        printf( "\n" );
    }
}
