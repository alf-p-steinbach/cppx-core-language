#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief
/// \make_name_ref{cppx,bits_per_},
/// \make_name_ref{cppx,value_bits_per_} and
/// \make_name_ref{cppx,magnitude_bits_per_}.


#include <cppx-core-language/syntax/declarations.hpp>               // CPPX_USE_CPPX
#include <cppx-core-language/types/system-dependent/Byte.hpp>       // cppx::bits_per_byte

#include <limits>           // std::numeric_limits 

namespace cppx::_ {
    CPPX_USE_STD( numeric_limits );

    /// \brief The number of bits per object/value of the specified type.
    template< class Type >
    constexpr int bits_per_             = sizeof( Type )*bits_per_byte;

    /// \brief The number of bits that determine the magnitude, i.e. the number of value
    /// representation bits minus a sign bit, if any.
    ///
    /// On 2019 computers this is generally `bits_per_<Type> - std::is_signed_v<Type>`.
    ///
    template< class Type >
    constexpr int magnitude_bits_per_   = numeric_limits<Type>::digits;

    /// \brief The number of bits that determine the value, i.e. the number of value
    /// representation bits. Formally, for types larger than `char` this the number
    /// of value representation bits can be less than the number of bits per value.
    /// I.e. formally there can be padding bits even in a basic value.
    ///
    /// However, on 2019 computers this is generally just `bits_per_<Type>`.
    ///
    template< class Type >
    constexpr int value_bits_per_       = magnitude_bits_per_<Type> + (Type(-1) < 0);
}  // namespace cppx::_

// Exporting namespaces.
namespace cppx {
    namespace bit_level
    {
        CPPX_USE_CPPX(
            _::bits_per_,
            _::magnitude_bits_per_,
            _::value_bits_per_
            );
    }  // namespace bit_level

    using namespace bit_level;
}  // namespace cppx
