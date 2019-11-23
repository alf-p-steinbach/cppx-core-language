#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/ascii/ascii-character-names.hpp>   // cppx::ascii::/names/
#include <cppx-core-language/syntax/macro-items_of.hpp>         // CPPX_ITEMS_OF
#include <cppx-core-language/syntax/macro-use.hpp>              // CPPX_USE_STD
#include <cppx-core-language/syntax/Sequence_.hpp>              // cppx::(Sequence_, zero_to)
#include <cppx-core-language/system/Byte.hpp>                   // cppx::Byte
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth
#include <cppx-core-language/syntax/Span_.hpp>                  // cppx::span_of
#include <cppx-core-language/tmp/type-traits.hpp>               // cppx::(is_integral_, is_a_char_type_)
#include <cppx-core-language/tmp/type-modifiers.hpp>            // cppx::(Unsigned_)
#include <cppx-core-language/types/C_str_.hpp>                  // cppx::C_str_

#include <c/string.hpp>         // strlen
#include <c/ctype.hpp>          // isspace
#include <string>               // std::(string, wstring)
#include <string_view>          // std::string_view
#include <functional>           // std::invoke

namespace cppx::cstdlib
{
    // Depends on the C level locale via the `setlocale` function.

    template< class Code >
    inline auto is_byte_space( const Code ch )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        if constexpr( sizeof( Code ) > 1 ) {
            if( Unsigned_<Code>( ch ) > max_byte ) {
                return false;
            }
        }
        return !!::isspace( Byte( ch ) );
    }

    template< class Code >
    inline auto is_wide_space( const Code ch )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        if constexpr( sizeof( Code ) > sizeof( wchar_t ) ) {
            if( Unsigned_<Code>( ch ) > wchar_t( -1 ) ) {
                return false;
            }
        }
        return !!::iswspace( wchar_t( ch ) );
    }

}  // namespace cppx::cstdlib

namespace cppx::ascii
{
    CPPX_USE_STD(
        basic_string, basic_string_view, invoke, string, string_view, wstring, wstring_view
        );

    //---------------------------------------- Is-ASCII checking:

    template< class Code >
    inline auto contains( const Code v )
        -> Truth
    { return (Unsigned_<Code>( v ) <= ascii::max_value); }

    template< class It >
    inline auto contains_all_of( const It start, const It beyond )
        -> Truth
    {
        for( const auto code: span_of( start, beyond ) ) {
            if( not contains( code ) ) {
                return false;
            }
        }
        return true;
    }

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

    // Is independent of locale
    template< class Code >
    inline auto is_whitespace( const Code code )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        return ascii::contains( code ) and cstdlib::is_byte_space( code );
    }

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

    inline auto whitespace_characters()
        -> const string&
    {
        static const string the_chars = invoke([]() -> string
        {
            string result;
            for( const int code: Sequence( 0, ascii::max_value ) ) {
                if( is_whitespace( char( code ) ) ) {
                    result += char( code );
                }
            }
            return result;
        } );

        return the_chars;
    }

    //----------------------------------------  Uppercase/lowercase:

    template< class Code >
    inline auto is_lowercase( const Code code )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        return 'a' <= code and code <= 'z';
    }

    template< class Code >
    inline auto is_uppercase( const Code code )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        return 'A' <= code and code <= 'Z';
    }

    template< class Char >
    inline auto to_lowercase( const Char ch )
        -> Char
    {
        static_assert( is_a_char_type_<Char> );
        return (is_uppercase( ch )? Char( ch - 'A' + 'a' ) : ch);
    }

    template< class Char >
    inline auto to_uppercase( const Char ch )
        -> Char
    {
        static_assert( is_a_char_type_<Char> );
        return (is_lowercase( ch )? Char( ch - 'a' + 'A' ) : ch);
    }

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


    //----------------------------------------  Other classification:

    template< class Code >
    inline auto is_control_char( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        static_assert( space == 32 and del == 127 );
        // No need to call ::iscntrl.
        return (is_in( zero_to( 32 ), code ) or code == 127);
    }

    template< class Code >
    inline auto is_noncontrol_char( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        // No need to call ::isprint.
        return ascii::contains( code ) and not is_control_char( code );
    }

    template< class Code >
    inline auto is_letter( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        return is_lowercase( code ) or is_uppercase( code );
    }

    template< class Code >
    inline auto is_digit( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        return is_in( Sequence( '0', '9' ), code );
    }

    template< class Char >
    inline auto is_general_identifier_character( const Char ch )
        -> bool
    {
        static_assert( is_a_char_type_<Char> );
        return is_letter( ch ) or is_digit( ch ) or ch == '_';
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
