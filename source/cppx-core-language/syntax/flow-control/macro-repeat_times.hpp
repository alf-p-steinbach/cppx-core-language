#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/types/Sequence_.hpp>            // cppx::zero_to
#include <cppx-core-language/system-dependent/size-types.hpp>       // cppx::Index

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $repeat_times    CPPX_REPEAT_TIMES   ///< \dollarname{repeat_times}
#endif

// Using a range based loop allows the loop index variable to be `const`.
//
#define CPPX_REPEAT_TIMES( n ) \
    if( const cppx::Index _n [[maybe_unused]] = n; false ) {} else \
        for( const cppx::Index _i [[maybe_unused]]: cppx::zero_to( _n ) )
