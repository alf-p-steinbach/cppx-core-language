#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/types/Truth.hpp>           // cppx::Truth

namespace cppx{

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

    namespace success_checking {
        struct Success{};
        struct Is_zero{};

        // The intent is that client code provides meanings for `expr >> Success`.
        // Others can be expressed in terms of such client code provided meanings.

        template< class Value >
        auto operator>>( const Value& v, Is_zero )
            -> Truth
        { return v == 0; }
    }  // namespace success_checking

    using success_checking::Success;
    using success_checking::Is_zero;
    using success_checking::operator>>;


    //--------------------------------------------- Inverted condition:

    namespace failure_checking {
        struct Failure{};

        template< class Value >
        auto operator>>( const Value& v, Failure )
            -> Truth
        { return not (v >> Success()); }
    }  // namespace failure_checking

    using failure_checking::Failure;
    using failure_checking::operator>>;

}  // namespace cppx
