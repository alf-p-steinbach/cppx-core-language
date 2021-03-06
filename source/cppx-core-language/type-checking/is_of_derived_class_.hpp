﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/type-builders.hpp>          // cppx::P_
#include <cppx-core-language/tmp/Enable_if_.hpp>                // cppx::Enable_if_
#include <cppx-core-language/tmp/type-checkers.hpp>             // cppx::is_base_and_derived_
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

namespace cppx
{
    // `true` if a pure downcast via `dynamic_cast` succeeds.
    // `false` if the `dynamic cast` fails or gives a cross cast.
    //
    // Essentially whether a `static_cast<Derived*>( &o )` would do the Right Thing™.

    template<
        class Derived, class Type,
        class = Enable_if_<is_base_and_derived_<Type, Derived>>
        >
    inline auto is_of_derived_class_( const Type& o )
        -> Truth
    {
        const auto p_derived = dynamic_cast<P_<const Derived>>( &o );
        return static_cast<P_<const Type>>( p_derived ) == &o;
    }
}  // namespace cppx
