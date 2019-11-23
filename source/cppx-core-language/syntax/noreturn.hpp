#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

namespace cppx
{
    [[noreturn]]
    inline void noreturn() { throw 666; }
}  // namespace cppx
