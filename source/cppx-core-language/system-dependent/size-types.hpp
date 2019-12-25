#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief Signed
/// \make_name_ref{cppx,Size} and
/// \make_name_ref{cppx,Index}, plus unsigned equivalents
/// \make_name_ref{cppx,As_unsigned_size} and
/// \make_name_ref{cppx,As_unsigned_index}.
///
/// For historical reasons the standard library often (but not always) uses the unsigned
/// size type `size_t`. In expressions that mix signed and unsigned types this can cause
/// inadvertent conversion to unsigned type of a negative value, then creating an
/// unintended very large value. E.g. `"Hello"s.length() < -2` is *guaranteed* true,
/// which is very silly – until you encounter the effect as an inexplicable bug.
///
/// For this reason C++20 will finally add `std::ssize()` as a signed result size
/// function. It returns `ptrdiff_t`. The signed types defined here are in practice
/// equivalent except on a 16-bit system where `ptrdiff_t` in practice will be 32
/// bits, which on such system can incur some inefficiency, while the `Size` defined
/// here will be 16 bits on a 16-bit system (but I have no 16-bit system to test on).

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_CPPX
#include <cppx-core-language/tmp/type-modifiers.hpp>        // cppx::As_signed_

#include <c/stddef.hpp>     // size_t

namespace cppx
{
    /// \brief A \make_name_ref{cppx,As_signed_} equivalent of `size_t`.
    using Size                  = As_signed_< size_t >;     // ~ptrdiff_t

    /// \brief Same as \make_name_ref{cppx,Size} but with name signifying use as index.
    using Index                 = Size;

    using As_unsigned_size         = size_t;
    using As_unsigned_index        = As_unsigned_size;

    // Documented in the <all.hpp> header.
    namespace system
    {
        CPPX_USE_CPPX( Size, Index, As_unsigned_size, As_unsigned_index );
    }

}  // namespace cppx
