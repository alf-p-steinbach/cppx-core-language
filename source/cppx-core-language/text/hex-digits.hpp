﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>               // CPPX_USE_STD
#include <cppx-core-language/syntax/collection-util/Sequence_.hpp>  // cppx::(is_in, Sequence)
#include <cppx-core-language/calc/integer-operations.hpp>           // cppx::div_up
#include <cppx-core-language/types/system-dependent/Byte.hpp>       // cppx::bits_per_byte

namespace cppx::hex_stuff {
    constexpr int hex_digits_per_byte   = div_up( bits_per_byte, 4 );
    constexpr int hex_base              = 1 << 4;

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
}  // namespace cppx::hex_stuff

namespace cppx {
    using namespace hex_stuff;
}  // namespace cppx
