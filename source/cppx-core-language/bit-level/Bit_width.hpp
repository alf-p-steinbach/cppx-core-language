#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/bit-level/bits_per_.hpp>       // cppx::bits_per_

namespace cppx::_ {
    struct Bit_width{ enum Enum {
        _8 = 8, _16 = 16, _32 = 32, _64 = 64, _128 = 128, system = bits_per_<void*>
    }; };

    static_assert(
        Bit_width::system == 16 or
        Bit_width::system == 32 or
        Bit_width::system == 64 or
        Bit_width::system == 128
        );
}  // namespace cppx::_

   // Exporting namespaces:
namespace cppx {
    namespace bit_level {
        using _::Bit_width;
    }  // namespace bit_level

    using namespace bit_level;
}  // namespace cppx
