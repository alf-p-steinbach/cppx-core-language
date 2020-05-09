#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>               // CPPX_USE_STD
#include <cppx-core-language/types/Truth.hpp>                       // cppx::Truth
#include <cppx-core-language/introspection/Source_location.hpp>     // cppx::Source_location

#include <stdexcept>        // std::runtime_error etc.
#include <exception>        // std::throw_with_nested
#include <string>           // std::string
#include <utility>          // std::forward

// The default `fail` function's exception can be caught as a `std::runtime_error`.
// It's the current exception, if any, that's nested. And the nested exception
// /can/ just be ignored at the exception handling site.
//
// The rationale of the nesting is to not discard useful information even though
// it carries some overhead, because x_throwing should be rare, not the normal case.
//
// Typical usage pattern:
//
//      getline( cin, s )
//          or fail( "foo - getline failed" );
//
// `fail` never returns, but declaring it as [[noreturn]] can generate sillywarnings.
//
// In future `fail` may be extended to support error codes by x_throwing a
// `std::system_error`, which is derived from `std::runtime_error` and carries an
// error code.

namespace cppx::definitions_ {
    CPPX_USE_STD(
        forward,
        current_exception, runtime_error, string, throw_with_nested 
    );

    template< class X, class... More_args >
    inline auto fail_( const string& message, More_args&&... more_args )
        -> Truth
    {
        // This checking is necessary for MinGW g++ 8.2.0. Not sure if the standard
        // requires it. It would be a design to attract bugs, if it were required.
        const Truth in_exception_handling = (current_exception() != nullptr);
        if( in_exception_handling ) {
            // std::throw_with_nested is guaranteed [[noreturn]].
            throw_with_nested( X( message, forward<More_args>( more_args )... ) );
        } else {
            throw X( message, forward<More_args>( more_args )...  );
        }
    }

    inline auto fail( const string& message )
        -> Truth
    { return fail_<runtime_error>( message ); }

    inline auto fail( const Source_location& srcloc, const string& message )
        -> Truth
    { 
        return fail_<runtime_error>( string()
            + string( srcloc.funcname().value_or( "<unknown func>" ) )
            + " - " + message
            + "\n" + string( 4, ' ' ) + text_location_of( srcloc )
            );
    }

    namespace x_throwing_exports {
        CPPX_USE_FROM_NAMESPACE( definitions_,
            fail_,
            fail
        );
    }  // namespace x_throwing_exports
}  // namespace cppx::definitions_

namespace cppx::x_throwing  { using namespace definitions_::x_throwing_exports; }
namespace cppx::syntax      { using namespace definitions_::x_throwing_exports; }
namespace cppx              { using namespace definitions_::x_throwing_exports; }
