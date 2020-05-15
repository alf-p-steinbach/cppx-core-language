#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
//
// Mainly for use with range based `for` loops.

#include <cppx-core-language/mix-in/Adapt_as_iterable_collection_.hpp>  // cppx::mix_in::*
#include <cppx-core-language/syntax/declarations.hpp>                   // CPPX_USE_...
#include <cppx-core-language/syntax/type-builders.hpp>                  // cppx::Type_
#include <cppx-core-language/types/system-dependent/size-types.hpp>     // cppx::Size
#include <cppx-core-language/tmp/type-traits.hpp>                       // cppx::is_a_
#include <cppx-core-language/types/Truth.hpp>                           // cppx::Truth

#include <iterator>     // std::(distance, iterator_traits, random_access_iterator_tag)

namespace cppx::_ {
    CPPX_USE_STD(
        distance, iterator_traits, random_access_iterator_tag
        );

    template< class Iterator >
    class Span_
        : public mix_in::Adapt_as_iterable_collection_<Span_<Iterator>>
    {
        Iterator    m_first;
        Iterator    m_beyond;

    public:
        auto first() const      -> Iterator { return m_first; }
        auto beyond() const     -> Iterator { return m_beyond; }

        auto n_items() const
            -> Size
        {
            static_assert( is_a_<
                random_access_iterator_tag,
                typename iterator_traits<Iterator>::iterator_category
                > );
            return distance( m_first, m_beyond );
        }

        auto front() const      -> auto&    { return *m_first; }
        auto is_empty() const   -> Truth    { return (m_first == m_beyond); }

        Span_():
            m_first(),
            m_beyond()
        {}

        Span_( const Iterator first, const Iterator beyond ):
            m_first( first ),
            m_beyond( beyond )
        {}

        template< class Collection >
        Span_( Collection&& c ):
            m_first( first_iterator_of( c ) ),
            m_beyond( beyond_iterator_of( c ) )
        {}
    };

    template< class Item >
    using Array_span_ = Span_<Item*>;

    template< class Iterator >
    inline auto span_of( const Iterator first, const Iterator beyond )
        -> Span_<Iterator>
    { return Span_<Iterator>( first, beyond ); }

    template< class Iterator >
    inline auto span_of( const Iterator first, const Size size )
        -> Span_<Iterator>
    { return Span_<Iterator>( first, first + size ); }

    template< class Iterator >
    inline auto is_empty( const Span_<Iterator>& span )
        -> Truth
    { return span.is_empty(); }

    template< class Iterator >
    inline auto n_items_of( const Span_<Iterator>& span )
        -> Size
    { return span.n_items(); }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace syntax {
        CPPX_USE_FROM_NAMESPACE( _,
            Span_,
            Array_span_,
            span_of,
            n_items_of
        );
    }  // namespace syntax

    using namespace syntax;
}  // namespace cppx
