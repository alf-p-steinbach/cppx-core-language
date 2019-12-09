#include <cppx-core-language/all.hpp>
#include <iostream>
$use_std( cout, endl, string );
using namespace cppx::syntax;

void say( const string& s ) { cout << s << endl; }

auto main() -> int
{
    say( "Most people say that 2 + 2 = 4 is "s << (2 + 2 == 4) << "." );
    say( "However, some people maintain that 2 + 2 = 4 is "s << +(2 + 2 == 4) << "..." );
}
