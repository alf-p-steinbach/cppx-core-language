#pragma once    // Source encoding: UTF-8 with BOM (π is a firstcase Greek "pi").
#include <cppx-core/iterators/Forward_iterator_impl_.hpp>       // cppx::Forward_iterator_impl_
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth
#include <cppx-core-language/tmp/Enable_if_.hpp>                // cppx::Enable_if_
#include <cppx-core-language/tmp/type-traits.hpp>               // cppx::is_integral_
#include <cppx-core-language/tmp/type-modifiers.hpp>            // cppx::Unsigned_

#include <c/assert.hpp>

namespace cppx{
    
    template<
        class Integer,
        class = Enable_if_< is_integral_<Integer> >
        >
    class Sequence_
    {
        using Unsigned = Unsigned_<Integer>;

        Unsigned    m_first;
        Unsigned    m_last;

        class Iterator:
            public Forward_iterator_impl_<Iterator, Integer>
        {
            Unsigned    m_current;

        public:
            void advance() { ++m_current; }

            auto operator*() const noexcept
                -> Integer
            { return static_cast<Integer>( m_current ); }
            
            friend auto operator==( const Iterator& a, const Iterator& b ) noexcept
                -> Truth
            { return a.m_current == b.m_current; }

            explicit Iterator( const Integer value ) noexcept
                : m_current( static_cast<Unsigned>( value ) )
            {}
        };

    public:
        constexpr auto first() const noexcept
            -> Integer
        { return static_cast<Integer>( m_first ); }

        constexpr auto last() const noexcept
            -> Integer
        { return static_cast<Integer>( m_last ); }

        constexpr auto n_values() const noexcept
            -> Integer
        { return static_cast<Integer>( 1 + m_last - m_first ); }

        constexpr auto contains( const Integer x ) const noexcept
            -> Truth
        { return m_first <= x and x <= m_last; }

        auto begin() const noexcept  -> Iterator     { return Iterator( m_first ); }
        auto end() const noexcept    -> Iterator     { return Iterator( m_last + 1 ); }

        constexpr Sequence_( const Integer first, const Integer last ) noexcept
            : m_first( first )
            , m_last( last )
        {
            assert(
                first <= last or
                static_cast<Unsigned>( first ) == static_cast<Unsigned>( last ) + 1
                );
        }
    };

    using Sequence = Sequence_<int>;

    template< class Integer >
    inline constexpr auto zero_to( const Integer n ) noexcept
        -> Sequence_<Integer>
    { return Sequence_<Integer>( 0, n - 1 ); }

    template< class Integer >
    inline constexpr auto one_through( const Integer n ) noexcept
        -> Sequence_<Integer>
    { return Sequence_<Integer>( 1, n ); }

    template< class Integer >
    auto is_in( const Sequence_<Integer>& seq, const Integer v ) noexcept
        -> Truth
    { return seq.contains( v ); }

}  // namespace cppx
