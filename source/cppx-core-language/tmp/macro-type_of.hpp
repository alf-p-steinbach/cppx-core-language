#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

/// \file
/// \brief `$type_of` Essentially `std::remove_reference_t<decltype(arg)>`.

#include <type_traits>      // std::remove_reference

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $type_of     CPPX_TYPE_OF        ///< \dollarname{type_of}
#endif

/// \brief `$type_of` Essentially `std::remove_reference_t<decltype(arg)>`.
#define CPPX_TYPE_OF( arg ) \
    ::std::remove_reference_t<decltype(arg)>
