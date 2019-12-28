#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/types/type-builders.hpp>    // cppx::(Type_)

#include <string_view>          // std::string_view

namespace cppx
{
    CPPX_USE_STD( basic_string_view );

    template< class Char >
    inline auto p_first_of( const basic_string_view<Char>& view ) noexcept
        -> const Char*
    { return view.data(); }

    template< class Char >
    inline auto p_beyond_of( const basic_string_view<Char>& view ) noexcept
        -> const Char*
    { return (view.data() == nullptr? nullptr : view.data() + view.size()); }

}  // namespace cppx
