﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/text/hex-digits.hpp>               // cppx::(hex_digits*, hex_base)
#include <cppx-core-language/types/C_buffer_param_.hpp>         // cppx::C_buffer_param_
#include <cppx-core-language/syntax/flow-control.hpp>           // CPPX_ITEMS_OF, CPPX_REPEAT_TIMES
#include <cppx-core-language/syntax/collection-util/Span_.hpp>  // cppx::span_of
#include <cppx-core-language/syntax/type-builders.hpp>          // cppx::Type_
#include <cppx-core-language/text/C_str_.hpp>                   // cppx::C_str

namespace cppx::hex_stuff {
    using Bufferptr_for_byte_to_hex     = C_buffer_param_<char, hex_digits_per_byte>;

    inline auto byte_to_hex_in(
        const Bufferptr_for_byte_to_hex     buffer,
        const Byte                          value,
        const C_str                         digits  = hex_digits_uppercase
        ) -> Size
    {
        char* p_end = buffer.ptr() + hex_digits_per_byte;
        Byte remaining_part = value;
        CPPX_REPEAT_TIMES( hex_digits_per_byte ) {
            *--p_end = digits[remaining_part % hex_base];
            remaining_part /= Byte( hex_base );      // Cast suppresses an MSVC sillywarning.
            }
        return hex_digits_per_byte;
    }

    inline auto byte_span_to_hex_in(
        const Bufferptr_for_byte_to_hex     buffer,
        const Type_<const Byte*>            p_first,
        const Type_<const Byte*>            p_beyond,
        const C_str                         digits  = hex_digits_uppercase
        ) -> Size
    {
        char* p = buffer.ptr();
        for( const Byte value: span_of( p_first, p_beyond ) ) {
            byte_to_hex_in( Bufferptr_for_byte_to_hex( p ), value, digits );
            p += Bufferptr_for_byte_to_hex::size_for_1();
        }
        return p - buffer;
    }
}  // namespace cppx::hex_stuff

namespace cppx {
    using namespace hex_stuff;
}  // namespace cppx
