#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

namespace examples {
    $use_cppx( zero_to );

    void c_style()
    {
        for( int i = 0; i < 10; ++i ) {
            printf( "%d ", 100 + i );
        }
        printf( "\n" );
    }

    void cpp_range_based()
    {
        for( const int i: zero_to( 10 ) ) {
            printf( "%d ", 200 + i );
        }
        printf( "\n" );
    }
}

auto main()
    -> int
{
    examples::c_style();
    examples::cpp_range_based();
}
