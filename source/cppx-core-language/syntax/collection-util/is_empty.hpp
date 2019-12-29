#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_STD
#include <cppx-core-language/syntax/types/type-builders.hpp>    // cppx::Type_
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

#include <iterator>         // std::(begin, end)
#include <type_traits>      // std::(true_type, false_type)
#include <utility>          // std::(declval)

namespace cppx::_
{
    CPPX_USE_STD( begin, end, declval, true_type, false_type );

    template< class Collection >
    class Has_method_empty_
    {
        template< class C, int x = sizeof( declval<C>().empty() == true ) >
        static auto test( const C& ) -> true_type;

        static auto test( ... ) -> false_type;

    public:
        static constexpr Truth value = decltype(
            test( declval<Collection>() )
            )::value;
    };

    template< class Collection >
    constexpr Truth has_method_empty_ = Has_method_empty_<Collection>::value;

    template< class Collection >
    inline auto is_empty( const Collection& c )
        -> Truth
    {
        if constexpr( has_method_empty_<Collection> )
        {
            return c.empty();
        }
        else
        {
            return begin( c ) == end( c );
        }
    }

    inline auto is_empty( const Type_<const char*> s )      -> Truth    { return !*s; }
    inline auto is_empty( const Type_<const wchar_t*> s )   -> Truth    { return !*s; }
    inline auto is_empty( const Type_<const char16_t*> s )  -> Truth    { return !*s; }
    inline auto is_empty( const Type_<const char32_t*> s )  -> Truth    { return !*s; }

}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace syntax {
        CPPX_USE_FROM_NAMESPACE( _,
            has_method_empty_,
            is_empty
            );
    }  // namespace syntax

    using namespace syntax;
}  // namespace cppx

