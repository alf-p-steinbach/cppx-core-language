#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief `$reverse_items_of` provides an iterator pair for the reverse of a sequence.

#include <cppx-core-language-meta-macro/lvalue_ref_to.hpp>  // cppx::lvalue_ref_to

#include <iterator>         // std::(begin, end, make_reverse_iterator)

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define  $reverse_items_of   CPPX_REVERSE_ITEMS_OF   ///< \dollarname{reverse_items_of}
#endif

/// \brief `$reverse_items_of(c)` effectively expands to
/// `std::reverse_iterator(std::begin(c)), std::reverse_iterator(std::end(c))`.
///
/// There is a check that `c` is not an rvalue expression, where the expansion could
/// inadvertently duplicate a costly or impure function call. But still, be careful.
/// Don't call this macro with an lvalue expression that has side effects.

#define CPPX_REVERSE_ITEMS_OF( c ) \
    std::make_reverse_iterator( std::end( cppx::lvalue_ref_to( c ) ) ), \
    std::make_reverse_iterator( std::begin( c ) )
