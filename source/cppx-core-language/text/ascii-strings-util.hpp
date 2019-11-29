#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/text/ascii-character-util.hpp>     // cppx::ascii::*
#include <cppx-core-language/types/C_str_.hpp>                  // cppx::C_str_

#include <c/string.hpp>         // strlen
#include <c/ctype.hpp>          // isspace
#include <string>               // std::(string, wstring)
#include <string_view>          // std::string_view
#include <functional>           // std::invoke

namespace cppx::ascii
{
    CPPX_USE_STD(
        basic_string, basic_string_view, string, string_view, wstring, wstring_view
        );

    //---------------------------------------- Is-ASCII checking:

    template< class Char >
    inline auto contains_all_of( const basic_string_view<Char>& sv )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        return contains_all_of( CPPX_ITEMS_OF( sv ) );
    }

    template< class Char >
    inline auto contains_all_of( const C_str_<Char> s )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        return contains_all_of( basic_string_view<Char>( s ) );
    }

    template< class Char>
    inline auto contains_all_of( const basic_string<Char>& s )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        return contains_all_of( basic_string_view<Char>( s ) );
    }


    //----------------------------------------  Whitespace checking:

    template< class Char >
    inline auto is_all_whitespace( const basic_string_view<Char>& sv )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        for( const Char ch: sv ) {
            if( not is_whitespace( ch ) ) {
                return false;
            }
        }
        return true;
    }

    template< class Char >
    inline auto is_all_whitespace( const basic_string<Char>& s )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        return is_all_whitespace( basic_string_view<Char>( s ) );
    }

    template< class Char >
    inline auto is_all_whitespace( const C_str_<Char> s )
        -> Truth
    {
        static_assert( is_a_char_type_<Char> );
        return is_all_whitespace( basic_string_view<Char>( s ) );
    }


    //----------------------------------------  Uppercase/lowercase:

    template< class Char >
    inline auto to_lowercase( const basic_string_view<Char>& v )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        basic_string<Char> result;
        result.reserve( v.size() );
        for( const Char ch : v ) {
            result += to_lowercase( ch );
        }
        return result;
    }

    template< class Char >
    inline auto to_uppercase( const basic_string_view<Char>& v )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        basic_string<Char> result;
        result.reserve( v.size() );
        for( const Char ch : v ) {
            result += to_uppercase( ch );
        }
        return result;
    }

    template< class Char >
    inline auto to_lowercase( const C_str_<Char> s )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        return to_lowercase( basic_string_view<Char>( s ) );
    }

    template< class Char >
    inline auto to_uppercase( const C_str_<Char> s )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        return to_uppercase( basic_string_view<Char>( s ) );
    }

    template< class Char >
    inline auto to_lowercase( const basic_string<Char>& s )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        return to_lowercase( basic_string_view<Char>( s ) );
    }

    template< class Char >
    inline auto to_uppercase( const basic_string<Char>& s )
        -> basic_string<Char>
    {
        static_assert( is_a_char_type_<Char> );
        return to_uppercase( basic_string_view<Char>( s ) );
    }


    //---------------------------------------- ascii::to_wide:

    template< class Char >
    inline auto to_wide( const basic_string_view<Char>& v )
        -> wstring
    {
        static_assert( is_a_char_type_<Char> );
        return wstring( v.begin(), v.end() );
    }

    template< class Char >
    inline auto to_wide( const C_str_<Char> s )
        -> wstring
    {
        static_assert( is_a_char_type_<Char> );
        return to_wide( basic_string_view<Char>( s ) );
    }

    template< class Char >
    inline auto to_wide( const basic_string<Char>& s )
        -> wstring
    {
        static_assert( is_a_char_type_<Char> );
        return to_wide( basic_string_view<Char>( s ) );
    }


    //----------------------------------------  Misc:

    inline auto quoted( const string_view& sv )
        -> string
    {
        string s;
        s = "\"";
        s += sv;
        s += "\"";
        return s;
    }

    inline auto quoted( const char ch )
        -> string
    { return quoted( string_view( &ch, 1 ) ); }

}  // namespace cppx::ascii
