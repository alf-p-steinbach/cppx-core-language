#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>      // CPPX_USE_CPPX

namespace cppx::_ {
    /// \brief The square (second power) of the argument.
    template< class Number >
    constexpr inline auto squared( const Number x )
        -> Number
    { return x*x; }

    /// \brief The cube (third power) of the argument.
    template< class Number >
    constexpr inline auto cubed( const Number x )
        -> Number
    { return x*x*x; }
}  // namespace cppx::definions

// Exporting namespaces.
namespace cppx{
    namespace calc {
        CPPX_USE_CPPX( _::squared, _::cubed );
    }  // namespace calc

    using namespace calc;
}  // namespace cppx
