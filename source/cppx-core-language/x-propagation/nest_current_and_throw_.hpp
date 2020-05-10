#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>               // CPPX_USE_STD
#include <cppx-core-language/types/Truth.hpp>                       // cppx::Truth

#include <exception>        // std::(current_exception, throw_with_nested)
#include <string>           // std::string
#include <utility>          // std::forward

namespace cppx::definitions_ {
    CPPX_USE_STD(
        forward,
        current_exception, string, throw_with_nested 
    );

    template< class X, class... More_args >
    inline auto nest_current_and_throw_( const string& message, More_args&&... more_args )
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

}  // namespace cppx::definitions_

namespace cppx::x_propagation   { using definitions_::nest_current_and_throw_; }
namespace cppx::x_throwing      { using definitions_::nest_current_and_throw_; }
namespace cppx                  { using definitions_::nest_current_and_throw_; }
