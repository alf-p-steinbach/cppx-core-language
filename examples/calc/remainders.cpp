#include <cppx-core-language/calc/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( div_down, mod );

    for( const int a: {13, -13} ) {
        for( const int b: {5, -5} ) {
            const auto& s =
                "%3d / %3d = %3d,  %% = %3d; %10c div_down(%3d, %3d) = %3d,  mod = %3d\n";
            printf( s,
                a, b, a/b, a%b,
                ' ',
                a, b, div_down( a, b ), mod( a, b )
                );
        }
    }
}
