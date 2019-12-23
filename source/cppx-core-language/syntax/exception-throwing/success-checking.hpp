#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/types/Truth.hpp>           // cppx::Truth

namespace cppx::_ {

    //------------------------------------------ Success, Failure & `>>`
    //
    // A unified notation that provides separation of failure /checking/ and
    // /throwing/ of exception with possibly costly to construct arguments.
    //
    // Since the `or` is the built-in `or` the arguments to `fail` are only evaluated
    // in the case of failure, which means the `fail` argument expressions are not even
    // evaluated for the normal case of success.
    //
    // Typical usage pattern, here using a Windows' function that returns `HRESULT`:
    //
    //      CoInitialize( nullptr, COINIT_MULTITHREADED ) >> Success()
    //          or fail( "CoInitialize failed" );
    //
    // ... where one has defined e.g.
    //
    //      auto operator>>( const HRESULT hr, Success )
    //          -> Truth
    //      { return SUCCEEDED( hr ); }
    //
    // The intent is that client code provides meanings for `expr >> Success`.
    // Others can be expressed in terms of such client code provided meanings.

    struct Success{};
    struct Is_zero{};
    struct Failure{};

    //auto operator>>( const Value& v, Success );     // Must be provided by client code.
        
    template< class Value >
    auto operator>>( const Value& v, Is_zero )
        -> Truth
    { return v == 0; }

    template< class Value >
    auto operator>>( const Value& v, Failure )
        -> Truth
    { return not (v >> Success()); }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace x_throwing {
        using _::Success;
        using _::Is_zero;
        using _::Failure;
        using _::operator>>;
    }  // namespace x_throwing

    namespace syntax {
        using namespace x_throwing;
    }  // namespace syntax

    using namespace x_throwing;
}  // namespace cppx
