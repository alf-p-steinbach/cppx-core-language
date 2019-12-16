#include <cppx-core-language/syntax/macro-items_of.hpp>         // $items_of
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::(spaces, n*s)
#include <iostream>         // std::(cout, endl)
#include <algorithm>        // std::(copy, sort, equal_range)
#include <string_view>      // std::string_view

auto main()
    -> int
{
    $use_std( copy, cout, endl, equal_range, sort, string_view );

    constexpr string_view   pi_digits   = "3141592653589793238462643383279";      // 30 decimals.
    constexpr int           n_digits    = pi_digits.length();
    
    char sorted_digits[n_digits];
    copy( $items_of( pi_digits ), &sorted_digits[0] );
    sort( $items_of( sorted_digits ) );

    cout << pi_digits << endl;
    cout << string_view( sorted_digits, n_digits ) << endl;
    
    const auto range_pair = equal_range( $items_of( sorted_digits ), '6' );
    const int n = range_pair.second - range_pair.first;
    if( n == 0 ) {
        cout << "... No 6-digits, weird." << endl;
    } else {
        using namespace cppx::syntax;
        cout << spaces( range_pair.first - &sorted_digits[0] ) << n*"^"s << endl;
        cout << "The digit 6 occurs " << n << " times." << endl;
    }
}
