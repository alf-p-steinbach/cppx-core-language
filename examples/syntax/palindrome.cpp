#include <cppx-core-language/all.hpp>
#include <iostream>
#include <string_view>

auto main()
    -> int
{
    $use_std( string_view, cout, endl );
    $use_cppx( span_of );
    
    constexpr auto& s = "A man, a plan, a canal: panama!";
    for( const char ch: span_of( $reverse_items_of( s ) ) ) {
        cout << ch;
    }
    cout << endl;
}
