#include <cppx-core-language/syntax/basic-string-assembly.hpp>      // cppx::*
#include <cppx-core-language/syntax/macro-use.hpp>                  // $use_std
#include <iostream>         // std::(cout, endl)
#include <iomanip>  // REMOVE
#include <string>           // std::to_string
#include <string_view>      // std::string_view

namespace my{
    $use_std( string_view, cout, endl );

    void display( const string_view& s )
    {
        cout << s << endl;
    }
}  // namespace my

auto main()
    -> int
{
    using namespace cppx::basic_string_assembly;
    $use_std( to_string );

    const double    a   = 1.23;
    const double    b   = 4.56;
    
    my::display( ""s
        << "One would expect that " << a << " + " << b << " = " << a + b
        << ", not " << to_string( a + b ) << "!"
        );
    my::display( "However, integer arithmetic is exact; 2 + 2 = "s << 2 + 2 << "." );
}
