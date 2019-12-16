#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/macro-items_of.hpp>         // CPPX_ITEMS_OF
#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_STD
#include <cppx-core-language/syntax/flow-control.hpp>           // cppx::(Sequence_, zero_to, span_of)
#include <cppx-core-language/system-dependent/Byte.hpp>         // cppx::Byte
#include <cppx-core-language/text/ascii-character-names.hpp>    // cppx::ascii::/names/
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth
#include <cppx-core-language/tmp/type-traits.hpp>               // cppx::(is_integral_, is_a_char_type_)
#include <cppx-core-language/tmp/type-modifiers.hpp>            // cppx::(Unsigned_)
#include <cppx-core-language/types/C_str_.hpp>                  // cppx::C_str_

#include <c/assert.hpp>         // assert
#include <c/ctype.hpp>          // isspace
#include <bitset>               // std::bitset
#include <functional>           // std::invoke
#include <string_view>          // std::string_view
#include <utility>              // std::invoke

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

    // TODO: is_punctuation

}  // namespace cppx::cstdlib

namespace cppx::_::ascii_impl
{
    CPPX_USE_STD( bitset, invoke, string_view );

    //---------------------------------------- Is-ASCII checking:

    template< class Code >
    inline auto is_ascii( const Code v )
        -> Truth
    { return (Unsigned_<Code>( v ) < unsigned( ascii::n_values )); }

    template< class Code >
    inline auto contains( const Code v )
        -> Truth
    { return is_ascii( v ); }


    //----------------------------------------  Whitespace checking:

    // Is independent of locale
    template< class Code >
    inline auto is_whitespace( const Code code )
        -> Truth
    {
        static_assert( is_integral_<Code> );
        return is_ascii( code ) and cstdlib::is_byte_space( code );
    }

    inline auto whitespace_characters()
        -> string_view
    {
        struct Wrapped
        {
            char    m_s[32];
            int     m_n;

            Wrapped():
                m_n( 0 )
            {
                for( const int code: Sequence( 0, ascii::max_value ) ) {
                    if( is_whitespace( code ) ) {
                        m_s[m_n++] = char( code );
                        assert( m_n < int( sizeof( m_s ) ) );
                    }
                }
                m_s[m_n] = '\0';
            }
        };

        static const Wrapped the_chars;
        return string_view( the_chars.m_s, the_chars.m_n );
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


    //----------------------------------------  Other classification:

    template< class Code >
    inline auto is_control( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        static_assert( ascii::space == 32 and ascii::del == 127 );
        // No need to call ::iscntrl.
        return (is_in( zero_to( 32 ), code ) or code == 127);
    }

    template< class Code >
    inline auto is_noncontrol( const Code code )
        -> bool
    {
        static_assert( is_integral_<Code> );
        // No need to call ::isprint.
        return is_ascii( code ) and not is_control( code );
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
    inline auto is_identifier_character( const Char ch )
        -> bool
    {
        static_assert( is_a_char_type_<Char> );
        return is_letter( ch ) or is_digit( ch ) or ch == '_';
    }

    constexpr inline auto punctuation_characters()
        -> string_view
    { return R"_(!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)_"; }

    template< class Char >
    inline auto is_punctuation( const Char ch )
        -> bool
    {
        using Bits = bitset<ascii::n_values>;
        static const Bits chars = invoke( [&]() -> Bits
        {
            Bits result;
            for( const char ch: punctuation_characters() ) {
                if( ch != 0 ) { result.set( ch ); }
            }
            return result;
        } );

        return ascii_contains( ch ) and chars[Byte( ch )];
    }
}  // namespace cppx::_::ascii_impl

// Exporting namespaces
namespace cppx {
    namespace ascii {
        CPPX_USE_FROM_NAMESPACE( _::ascii_impl,
            contains,
            is_control,
            is_digit,
            is_identifier_character,
            is_letter,
            is_lowercase,
            is_noncontrol,
            is_punctuation,
            is_uppercase,
            is_whitespace,
            punctuation_characters,
            to_lowercase,
            to_uppercase,
            whitespace_characters
            );
    }  // namespace ascii

    namespace text {
        namespace ascii = cppx::ascii;
    };

    using namespace text;
}  // namespace cppx
