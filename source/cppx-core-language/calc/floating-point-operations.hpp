﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief Useful common “calculator” operations:
/// \make_name_ref{cppx,intpow},
/// \make_name_ref{cppx,squared} and
/// \make_name_ref{cppx,cubed}.

#include <cppx-core-language/calc/general-operations.hpp>       // cppx::(squared, cubed)
#include <cppx-core-language/calc/integer-operations.hpp>       // cppx::is_odd
#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_CPPX

namespace cppx::_ {
    /// @cond DOXY_SHOW_IMPL_DETAILS
    namespace impl
    {
        constexpr inline auto intpow( const double base, const int exponent )
            -> double
        {
            double result = 1;
            double weight = base;
            for( int n = exponent; n != 0; weight *= weight ) {
                if( is_odd( n ) ) {
                    result *= weight;
                }
                n /= 2;
            }
            return result;
        }
    }  // namespace impl
    /// @endcond

    /// \brief Efficient *x* to the *n*'th power, when *n* is an integer.
    ///
    /// \param  base        The *x* in “*x* to the *n*'th”.
    /// \param  exponent    The *n* in “*x* to the *n*'th”.
    ///
    /// Essentially this is Horner's rule adapted to calculating a power, so that the
    /// number of floating point multiplications is at worst O(log2(n)).
    constexpr inline auto intpow( const double base, const int exponent )
        -> double
    {
        return (0?0
            : exponent == 0?        1.0
            : exponent < 0?         1.0/impl::intpow( base, -exponent )
            :                       impl::intpow( base, exponent )
            );
    }
}  // namespace cppx::_

// Exporting namespaces.
namespace cppx {
    namespace calc {
        CPPX_USE_CPPX( _::intpow );
    }  // namespace math

    using namespace calc;
}  // namespace cppx
