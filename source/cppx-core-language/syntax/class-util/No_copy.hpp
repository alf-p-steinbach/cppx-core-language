﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

namespace cppx
{
    class No_copy
    {
        auto operator=( const No_copy& ) -> No_copy& = delete;
        No_copy( const No_copy& ) = delete;

    public:
        auto operator=( No_copy&& ) -> No_copy& = default;
        No_copy( No_copy&& ) = default;

        No_copy() {}
    };

}  // namespace cppx
