#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::(div_down, intmod)
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( div_down, intmod );

    for( const int a: {13, -13} ) {
        for( const int b: {5, -5} ) {
            const auto& s =
                "%3d / %3d = %3d,  %% = %3d; %10c div_down(%3d, %3d) = %3d,  intmod = %3d\n";
            printf( s,
                a, b, a/b, a%b,
                ' ',
                a, b, div_down( a, b ), intmod( a, b )
                );
        }
    }
}
