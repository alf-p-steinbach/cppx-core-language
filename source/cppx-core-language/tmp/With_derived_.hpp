#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief For designating the role of the derived class template parameter in CRTP.
/// \make_name_ref{cppx,With_derived_}

namespace cppx {
    template< class T > struct With_derived_ { using Derived = T; };
}  // namespace cppx
