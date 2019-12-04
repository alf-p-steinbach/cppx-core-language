#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( zero_to );

    const int n = 1 << 4;
    for( const int y: zero_to( n ) ) {
        printf( "%*c", n - y, ' ' );
        for( const int x: zero_to( n ) ) {
            printf( " %c", (x & ~y)? ' ' : 'o' );
        }
        printf( "\n" );
    }
}
