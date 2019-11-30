#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief Essentially the same functionality as C++20 `std::endian`, namely
/// \make_name_ref{cppx,Endian},
/// \make_name_ref{cppx::system,is_little_endian},
/// \make_name_ref{cppx::system,is_big_endian} and
/// \make_name_ref{cppx::system,as_mixed_endian}.

#include <cppx-core-language/syntax/macro-use.hpp>          // CPPX_USE_STD

namespace cppx {
    // Documented in the <all.hpp> header.
    struct Endian
    {
        enum Enum
        {
        #ifdef _WIN32
            little  = 0,
            big     = 1,
            native  = little
        #else
            little  = __ORDER_LITTLE_ENDIAN__,
            big     = __ORDER_BIG_ENDIAN__,
            native  = __BYTE_ORDER__
        #endif
        };
    };
}  // namespace cppx

namespace cppx::system {
    constexpr bool is_little_endian     = (Endian::native == Endian::little);
    constexpr bool is_big_endian        = (Endian::native == Endian::big);
    constexpr bool is_mixed_endian      = not(is_little_endian or is_big_endian);
}  // namespace cppx::system
