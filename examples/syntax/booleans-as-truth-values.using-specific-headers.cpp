#include <cppx-core-language/syntax/declarations.hpp>           // $use_std
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::*
#include <c/stdlib.hpp>     // printf
#include <string>           // std::string
$use_std( string );
using namespace cppx::syntax;

void say( const string& s ) { printf( "%s\n", s.c_str() ); }

auto main()
    -> int
{
    say( "Most people say that 2 + 2 = 4 is "s << (2 + 2 == 4) << "." );
    say( "However, some people maintain that 2 + 2 = 4 is "s << +(2 + 2 == 4) << "..." );
}
