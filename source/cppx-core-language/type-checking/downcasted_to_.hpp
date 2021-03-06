﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/type-builders.hpp>          // cppx::P_
#include <cppx-core-language/tmp/Enable_if_.hpp>                // cppx::Enable_if_
#include <cppx-core-language/tmp/type-checkers.hpp>             // cppx::is_base_and_derived_

namespace cppx
{
    /// @cond DOXY_SHOW_IMPL_DETAILS
    namespace impl
    {
        // Common implementation for const and non-const.
        template< class Derived, class Type >
        inline auto downcasted_to_( P_<Type> p )
            -> P_<Derived>
        {
            static_assert( is_base_and_derived_<Type, Derived> );
            const auto p_derived = dynamic_cast<P_<Derived>>( p );

            // Unclear whether the additional checking below is necessary.
            // Can nullptr be returned for a non-null p_derived?
            return static_cast<P_<Type>>( p_derived ) == p? p_derived : nullptr;
        }
    }
    /// @endcond

    template< class Derived, class Type >
    inline auto downcasted_to_( P_<Type> p )
        -> P_<Derived>
    { return impl::downcasted_to_<Derived>( p ); }

    // const
    template< class Derived, class Type >
    inline auto downcasted_to_( P_<const Type> p )
        -> P_<const Derived>
    { return impl::downcasted_to_<const Derived>( p ); }
}  // namespace cppx
