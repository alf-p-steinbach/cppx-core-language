#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( m::pi );
    using namespace cppx::syntax;       // s, "<<" and "^".

    printf( "Pi is roughly "s << pi << ", or thereabouts.\n" ^sz );
}
