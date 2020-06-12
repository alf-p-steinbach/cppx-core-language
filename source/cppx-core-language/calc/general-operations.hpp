#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_FROM_NAMESPACE
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

namespace cppx::definitions_ {
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

    template< class Value >
    constexpr inline auto is_zero( const Value x )
        -> Truth
    { return x == 0; }

    namespace general_operation_exports {
        CPPX_USE_FROM_NAMESPACE( definitions_,
            squared,
            cubed,
            is_zero
            );
    }  // namespace general_operation_exports

}  // namespace cppx::definitions_

namespace cppx::calc    { using namespace cppx::definitions_::general_operation_exports; }
namespace cppx          { using namespace cppx::definitions_::general_operation_exports; }
