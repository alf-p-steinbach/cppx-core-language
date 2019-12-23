#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

namespace cppx::_
{
    [[noreturn]]
    inline void noreturn() { throw 666; }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    using _::noreturn;

    // Convenience, because most common usage:
    namespace x_throwing {
        using _::noreturn;
    }  // namespace x_throwing
}  // namespace cppx
