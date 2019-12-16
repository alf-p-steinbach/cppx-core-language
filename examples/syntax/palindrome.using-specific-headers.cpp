#include <cppx-core-language/syntax/declarations.hpp>               // $alias.., $use_...
#include <cppx-core-language/syntax/macro-reverse_items_of.hpp>     // $reverse_items_of
#include <cppx-core-language/syntax/types.hpp>                      // cppx::span_of
#include <cppx-core-language/text/ascii-character-util.hpp>         // cppx::ascii

#include <algorithm>            // std::copy
#include <iostream>
#include <iterator>             // std::ostream_iterator
#include <string>               // std::string
#include <string_view>          // std::string
#include <vector>               // std::vector
$use_std( string, string_view, vector );
$alias_cppx_namespaces( ascii );

struct Classified
{
    string          letters;
    vector<string>  non_letters;

    Classified( const string_view& s ) {
        for( const char ch: s ) {
            if( ascii::is_letter( ch ) ) {
                letters += ch;
            }
        }

        non_letters.resize( letters.size() + 1 );
        int i = 0;
        for( const char ch: s ) {
            if( ascii::is_letter( ch ) ) {
                ++i;
            } else {
                non_letters[i] += ch;
            }
        }
    }
};

auto main()
    -> int
{
    $use_std( ostream_iterator, cout, endl );
    $use_cppx( span_of );
    
    const auto s = string_view( "$$$ A man, a plan, a canal: panama!" );

    copy( $reverse_items_of( s ), ostream_iterator<char>( cout ) );
    cout << "  (reversed)" << endl;
    
    const auto the = Classified( s );
    int i = 0;
    cout << the.non_letters[0];
    for( const char ch: span_of( $reverse_items_of( the.letters ) ) ) {
        cout << ch;
        ++i;
        cout << the.non_letters[i];
    }
    cout << "  (smart-reversed)" << endl;
    
    cout << s << "  (original)" << endl;
}
