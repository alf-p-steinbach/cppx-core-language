#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

/// \file
/// \brief `$here` creates a `Source_location` instance for the call's location.

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $here()  CPPX_HERE()         ///< \dollarname{here}
#endif

/// \hideinitializer
/// \brief `$here()` creates a `Source_location` instance for the call's location.
///
/// Unlike C++20 `std::source_location` a `Source_location` is noexcept copyable.

#define CPPX_HERE() \
    ::cppx::Source_location( __func__, __FILE__, __LINE__ )
