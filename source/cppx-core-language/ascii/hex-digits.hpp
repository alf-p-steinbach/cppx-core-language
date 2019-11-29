#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>          // CPPX_USE_STD
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::(is_in, Sequence)
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::div_up
#include <cppx-core-language/system/Byte.hpp>               // cppx::bits_per_byte

namespace cppx {

    constexpr int hex_digits_per_byte = div_up( bits_per_byte, 4 );

    constexpr auto&     hex_digits_uppercase    = "0123456789ABCDEF";
    constexpr auto&     hex_digits_lowercase    = "0123456789abcdef";

    constexpr auto&     hex_digits = hex_digits_uppercase;

    inline auto hex_digit( const int i )
        -> char
    { return hex_digits[i]; }

    inline auto lowercase_hex_digit( const int i )
        -> char
    { return hex_digits_lowercase[i]; }

    inline auto number_from_hex_digit( const char ch )
        -> int
    {
        return (0?0
            : is_in( Sequence( 'A', 'F' ), ch )?        10 + (ch - 'A')
            : is_in( Sequence( 'a', 'f' ), ch )?        10 + (ch - 'a')
            : is_in( Sequence( '0', '9' ), ch )?        ch - '0'
            :                                           -1
            );
    }

    inline auto is_hex_digit( const char ch )
        -> bool
    { return number_from_hex_digit( ch ) != -1; }

    namespace ascii {
        CPPX_USE_CPPX(
            hex_digits_per_byte,
            hex_digits_uppercase, hex_digits_lowercase, hex_digits,
            hex_digit, lowercase_hex_digit,
            number_from_hex_digit, is_hex_digit
            );
    }  // namespace ascii
}  // namespace cppx
