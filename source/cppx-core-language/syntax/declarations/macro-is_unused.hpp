#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

/// \file
/// \brief `$with` binds the specified declarator to `auto&& _` in the following braces block.


#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $is_unused   CPPX_IS_UNUSED      ///< \dollarname{is_unused}
#endif

/// \brief Declares and enforces that the specified variable or param is not used from here on.

#define CPPX_IS_UNUSED( name ) \
    (void) name; struct name
