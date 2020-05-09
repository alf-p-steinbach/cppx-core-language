#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>                   // CPPX_USE_STD
#include <cppx-core-language/types/system-dependent/size-types.hpp>     // cppx::Size
#include <cppx-core-language/types/Truth.hpp>                           // cppx::Truth

#include <c/stddef.hpp>                             // ptrdiff_t
#include <iterator>                                 // std::(begin, end, forward_iterator_tag)

// Example usage:
//
//      class Iterator:
//          public mix_in::Adapt_as_forward_iterator_<Iterator, Integer>
//      {
//          Integer     m_current;
//      
//      public:
//          void advance() { ++m_current; }
//      
//          auto operator*() const
//              -> Integer
//          { return m_current; }
//                  
//          friend auto operator==( const Iterator& a, const Iterator& b )
//              -> Truth
//          { return a.m_current == b.m_current; }
//      
//          explicit Iterator( const Integer value )
//              : m_current{ value }
//          {}
//      };

namespace cppx::_
{
    CPPX_USE_STD( forward_iterator_tag );
    
    template< class Derived, class Value_type_param >
    class Adapt_as_forward_iterator_
    {
        auto self()
            -> Derived&
        { return static_cast<Derived&>( *this ); }

    public:
        // `std::iterator_traits` types:
        using difference_type       = Size;
        using value_type            = Value_type_param;  // decltype( *declval<Derived>() );
        using pointer               = value_type*;
        using reference             = const value_type&;
        using iterator_category     = forward_iterator_tag;

        using Value = Value_type_param;

        auto operator++()
            -> const Derived&
        {
            self().advance();
            return self();
        }
        
        auto operator++( int )
            -> Derived
        {
            Derived original = self();
            self().advance();
            return original;
        }

        friend auto operator!=( const Derived& a, const Derived& b )
            -> Truth
        { return not(a == b); }
    };

}  // namespace cppx::_

// Exporting namespaces
namespace cppx {
    namespace mix_in {
        CPPX_USE_FROM_NAMESPACE( _,
            Adapt_as_forward_iterator_
        );
    }  // namespace with

    using namespace mix_in;
}  // namespace cppx
