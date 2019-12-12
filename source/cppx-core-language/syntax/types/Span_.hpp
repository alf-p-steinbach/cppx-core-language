#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
//
// Mainly for use with range based `for` loops.

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_STD
#include <cppx-core-language/syntax/types/type-builders.hpp>    // cppx::P_
#include <cppx-core-language/system-dependent/size-types.hpp>   // cppx::Size
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth


#include <iterator>     // std::(begin, end)

namespace cppx::spans
{
    CPPX_USE_STD( begin, end );

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
    {
        Iterator    m_first;
        Iterator    m_beyond;

    public:
        auto first() const      -> Iterator { return m_first; }
        auto beyond() const     -> Iterator { return m_beyond; }

        auto front() const      -> auto&    { return *m_first; }
        auto is_empty() const   -> Truth    { return (m_first == m_beyond); }

        // Standard library & core language naming convention adapters.
        auto begin() const      -> Iterator { return m_first; }
        auto end() const        -> Iterator { return m_beyond; }
        auto empty() const      -> Truth    { return (m_first == m_beyond); }

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

    template< class Iterator >
    inline auto span_of( const Iterator first, const Iterator beyond )
        -> Span_<Iterator>
    { return Span_<Iterator>( first, beyond ); }

    template< class Item >
    using Array_span_ = Span_<P_<Item>>;

    template< class Item >
    inline auto n_items_of( const Array_span_<Item>& span )
        -> Size
    { return span.beyond() - span.first(); }

}  // namespace cppx::spans

namespace cppx {
    using namespace spans;
}  // namespace cppx

