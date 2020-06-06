#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>                       // CPPX_USE_STD
#include <cppx-core-language/types/system-dependent/Endian.hpp>             // cppx::
#include <cppx-core-language/types/system-dependent/Value_bytes_.hpp>       // cppx::(big_endian_bytes_of, Value_bytes_)
#include <cppx-core-language/text/remove_leading_zeroes_in.hpp>             // cppx::remove_leading_zeroes_in
#include <cppx-core-language/text/to-hex-in-buffer.hpp>                     // cppx::byte_span_to_hex_in
#include <cppx-core-language/tmp/Enable_if_.hpp>                            // cppx::Enable_if_
#include <cppx-core-language/tmp/type-checkers.hpp>                         // cppx::(is_xxx_)

#include <c/assert.hpp>     // assert
#include <string>           // std::string

namespace cppx::hex_stuff {
    CPPX_USE_STD( string );

    template<
        int n_bytes, Endian::Enum e
        >
    inline auto to_hex(
        const Value_bytes_< n_bytes, e >&   bytes,
        const P_<const char>                hex_digits  = hex_digits_uppercase
        ) -> string
    {
        using Bufferptr = Bufferptr_for_byte_to_hex;
        const Size n_digits = Bufferptr::size_for( bytes.size() );
        auto buffer = string( n_digits, '\0' );

        const Size [[may_be_unused]] n_generated = byte_span_to_hex_in(
            Bufferptr( buffer.data() ), CPPX_ITEMS_OF( bytes ), hex_digits
            );
        assert( n_generated == n_digits );
        return buffer;
    }

    template< class Type >
    inline auto to_hex(
        const Type&                 value,
        const P_<const char>        hex_digits  = hex_digits_uppercase
        ) -> string
    {
        static_assert( is_basic_value_<Type> );
        return to_hex( big_endian_bytes_of( value ), hex_digits );
    }

    template< class Type >
    inline auto to_hex_numeral(
        const Type&                 value,
        const P_<const char>        hex_digits  = hex_digits_uppercase
        ) -> string
    {
        string result = to_hex( value, hex_digits );
        remove_leading_zeroes_in( result );
        return result;
    }

}  // namespace cppx::hex_stuff

namespace cppx {
    using namespace hex_stuff;
}  // namespace cppx
