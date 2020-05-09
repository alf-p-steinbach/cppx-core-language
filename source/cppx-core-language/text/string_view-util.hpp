#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_...
#include <cppx-core-language/syntax/type-builders.hpp>          // cppx::(Type_)

#include <string_view>          // std::string_view

namespace cppx::_
{
    CPPX_USE_STD( basic_string_view );

    template< class Char >
    inline auto ptr_to_first_in( const basic_string_view<Char>& view ) noexcept
        -> const Char*
    { return view.data(); }

    template< class Char >
    inline auto ptr_to_beyond( const basic_string_view<Char>& view ) noexcept
        -> const Char*
    { return (view.data() == nullptr? nullptr : view.data() + view.size()); }
}  // namespace cppx::_

// Exporting namespaces
namespace cppx {
    namespace text {
        CPPX_USE_FROM_NAMESPACE( _,
            ptr_to_first_in,
            ptr_to_beyond
            );
    }  // namespace text

    using namespace text;
}  // namespace cppx
