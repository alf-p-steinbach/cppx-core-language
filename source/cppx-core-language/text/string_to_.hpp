#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>                       // CPPX_USE...
#include <cppx-core-language/syntax/flow-control/exception-throwing.hpp>    // cppx::(hopefully, fail)

#include <charconv>         // std::from_chars
#include <string_view>      // std::string_view

namespace cppx::_ {
    CPPX_USE_STD( string_view, from_chars, from_chars_result, errc );

    template< class Number >
    auto string_to_( const string_view& spec )
        -> Number
    {
        Number result;
        const from_chars_result r =
            from_chars( spec.data(), spec.data() + spec.size(), result );

        hopefully( r.ec == errc() )
            or fail( "cppx::string_to_ - std::from_chars failed" );
        return result;
    }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace text {
        using _::string_to_;
    }  // namespace text

    using namespace text;
}  // namespace cppx
