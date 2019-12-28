﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::spaces
#include <cppx-core-language/text/ascii-character-names.hpp>    // cppx::ascii::*
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


    //----------------------------------------  Adjustment (mostly for console output):

    inline auto at_left_in( const int width, const string_view& s )
        -> string
    { return string( s ) + spaces( width - int( s.length() ) ); }

    inline auto at_left_in( const int width, const char ch )
        -> string
    { return ch + spaces( width - 1 ); }

    inline auto at_right_in( const int width, const string_view& s )
        -> string
    { return spaces( width - int( s.length() ) ) + string( s ); }

    inline auto at_right_in( const int width, const char ch )
        -> string
    { return spaces( width - 1 ) + ch; }


    //----------------------------------------  Misc:

    // The intent is to yield the same result as produced by `std::quoted`, but in a string.
    inline auto quoted(
        const string_view&      sv,
        const char              quote_char  = '"',
        const char              escape_char = '\\'
        ) -> string
    {
        string s;
        const int fudge_factor = 7;
        s.reserve( sv.length() + fudge_factor );
        s = quote_char;
        for( const char ch: sv ) {
            if( ch == quote_char or ch == escape_char ) {
                s += escape_char;
            }
            s += ch;
        }
        s += "\"";
        return s;
    }

    inline auto quoted(
        const char              ch,
        const char              quote_char  = '"',
        const char              escape_char = '\\'
        )  -> string
    { return quoted( string_view( &ch, 1 ), quote_char, escape_char ); }
}  // namespace cppx::ascii
