#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
//
// Mainly for use with range based `for` loops.

#include <cppx-core-language/mix-in/Adapt_as_iterable_collection_.hpp>  // cppx::mix_in::*
#include <cppx-core-language/syntax/declarations.hpp>                   // CPPX_USE_...
#include <cppx-core-language/syntax/types/type-builders.hpp>            // cppx::Type_
#include <cppx-core-language/system-dependent/size-types.hpp>           // cppx::Size
#include <cppx-core-language/types/Truth.hpp>                           // cppx::Truth

#include <iterator>     // std::(begin, end, distance)

namespace cppx::_
{
    CPPX_USE_STD( begin, end, distance );

    template< class Collection >
    inline auto first_iterator_of( Collection& c )
        -> auto
    { return begin( c ); }

    template< class Collection >
    inline auto beyond_iterator_of( Collection& c )
        -> auto
    { return end( c ); }

    template< class Iterator >
    class Span_
        : public mix_in::Adapt_as_iterable_collection_<Span_<Iterator>>
    {
        Iterator    m_first;
        Iterator    m_beyond;

    public:
        auto first() const      -> Iterator { return m_first; }
        auto beyond() const     -> Iterator { return m_beyond; }
        auto n_items() const    -> Size     { return distance( m_first, m_beyond ); }

        auto front() const      -> auto&    { return *m_first; }
        auto is_empty() const   -> Truth    { return (m_first == m_beyond); }

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
    using Array_span_ = Span_<Type_<Item>*>;

    template< class Iterator >
    inline auto span_of( const Iterator first, const Iterator beyond )
        -> Span_<Iterator>
    { return Span_<Iterator>( first, beyond ); }

    template< class Iterator >
    inline auto n_items_of( const Span_<Iterator>& span )
        -> Size
    { return distance( span.begin(), span.end() ); }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace spans {
        CPPX_USE_FROM_NAMESPACE( _,
            first_iterator_of,
            beyond_iterator_of,
            Span_,
            Array_span_,
            span_of,
            n_items_of
        );
    }
    using namespace spans;
}  // namespace cppx
