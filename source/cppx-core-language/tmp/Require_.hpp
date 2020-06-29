#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief \make_name_ref{cppx,Reqyure_} Like `enable_if_t` but produces hard error instead of SFINAE.

#include <utility>

namespace cppx
{
    template< bool condition, class Result = void >
    struct Require_t_
    {
        static_assert( condition, "A template parameters requirement failed" );
        using T = Result;
    };

    /// \brief Like `enable_if_t` but produces hard error instead of SFINAE.
    template< bool condition, class Result = void >     // "bool" until C++20
    using Require_ = typename Require_t_<condition, Result>::T;

}  // namespace cppx
