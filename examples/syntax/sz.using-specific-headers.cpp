#include <cppx-core-language/calc/named-numbers.hpp>                // cppx::m::pi
#include <cppx-core-language/syntax/basic-string-assembly.hpp>      // "<<"
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( m::pi );
    using namespace cppx::syntax;       // s, "<<" and "^".

    printf( "Pi is roughly "s << pi << ", or thereabouts.\n" ^sz );
}
