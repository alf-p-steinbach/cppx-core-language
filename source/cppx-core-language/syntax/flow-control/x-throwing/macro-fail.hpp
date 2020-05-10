#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/introspection/macro-here.hpp>                  // CPPX_HERE
#include <cppx-core-language/syntax/flow-control/x-throwing/fail.hpp>       // cppx::fail

/// \file
/// \brief `$fail` invokes `cppx::fail` with the source location and a specified message.

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $fail    CPPX_FAIL           ///< \dollarname{fail}
#   define $fail_   CPPX_FAIL_          ///< \dollarname{fail_}
#endif

/// \brief `$fail` invokes `cppx::fail` with the source location and a specified message.

#define CPPX_FAIL( s ) ::cppx::fail( CPPX_HERE(), s )

/// \brief `$fail_` invokes `cppx::fail_` with specified exception type, the source location,
/// and a specified message.
#define CPPX_FAIL_( X, s ) ::cppx::fail_<X>( CPPX_HERE(), s )
