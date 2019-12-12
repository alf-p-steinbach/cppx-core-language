#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>          // CPPX_USE_STD
#include <cppx-core-language/syntax/noreturn.hpp>           // cppx::noreturn       // Convenience
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

#include <stdexcept>        // std::runtime_error
#include <exception>        // std::throw_with_nested
#include <string>           // std::string
#include <utility>          // std::forward

namespace cppx::x_throwing {
    CPPX_USE_STD(
        forward,
        current_exception, runtime_error, string, throw_with_nested 
        );

    //------------------------------------------ hopefully & fail
    //
    // The default `fail` function's exception can be caught as a `std::runtime_error`.
    // It's the current exception, if any, that's nested. And the nested exception
    // /can/ just be ignored at the exception handling site.
    //
    // The rationale of the nesting is to not discard useful information even though
    // it carries some overhead, because x_throwing should be rare, not the normal case.
    //
    // Typical usage patterns:
    //
    //      1;
    //      getline( cin, s )
    //          or fail( "foo - getline failed" );
    //
    //      2;
    //      const ptrdiff_t n_values = to_wide_from_utf8( &s[0], &wide_s[0] );
    //      hopefully( n_values >= 0 )
    //          or fail( "foo - to_wide_from_utf8 failed" );
    //      wide_s.resize( n_values );
    //
    // In future `fail` may be extended to support error codes by x_throwing a
    // `std::system_error`, which is derived from `std::runtime_error` and carries an
    // error code.

    inline auto hopefully( const Truth condition )
        -> Truth
    { return condition; }

    // Is really [[noreturn]], but declaring it as such can generate sillywarnings.
    template< class X, class... More_args >
    inline auto fail_( const string& message, More_args&&... more_args )
        -> Truth
    {
        // This checking is necessary for MinGW g++ 8.2.0. Not sure if the standard
        // requires it. It would be a design to attract bugs, if it were required.

        const Truth in_exception_handling = (current_exception() != nullptr);
        if( in_exception_handling )
        {
            // std::throw_with_nested is guaranteed [[noreturn]].
            throw_with_nested( X( message, forward<More_args>( more_args )... ) );
        }
        else
        {
            throw X( message, forward<More_args>( more_args )...  );
        }
    }

    // Is really [[noreturn]], but declaring it as such can generate sillywarnings.
    inline auto fail( const string& message )
        -> Truth
    { return fail_<runtime_error>( message ); }

}  // namespace cppx::x_throwing

namespace cppx {
    using x_throwing::hopefully;
    using x_throwing::fail_;
    using x_throwing::fail;
}  // namespace cppx
