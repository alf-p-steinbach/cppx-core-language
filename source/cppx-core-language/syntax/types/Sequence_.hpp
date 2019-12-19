#pragma once    // Source encoding: UTF-8 with BOM (π is a firstcase Greek "pi").
#include <cppx-core-language/mix-in/Adapt_as_forward_iterator_.hpp> // cppx::mix_in::Adapt_as_forward_iterator_
#include <cppx-core-language/types/Truth.hpp>                       // cppx::Truth
#include <cppx-core-language/tmp/Enable_if_.hpp>                    // cppx::Enable_if_
#include <cppx-core-language/tmp/type-traits.hpp>                   // cppx::is_integral_
#include <cppx-core-language/tmp/type-modifiers.hpp>                // cppx::Unsigned_
#include <cppx-core-language/calc/number-type-properties.hpp>       // cppx::(min_, max_)

#include <c/assert.hpp>

namespace cppx::sequences{
    
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
            public mix_in::Adapt_as_forward_iterator_<Iterator, Integer>
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

        template< class Value_integer >
        constexpr auto contains( const Value_integer x ) const noexcept
            -> Truth
        {
            if constexpr( max_<Value_integer> > max_<Integer> ) {
                if( x > max_<Integer> ) {
                    return false;
                }
            }
            if constexpr( min_<Value_integer> < min_<Integer> ) {
                // Here Value_integer is necessarily a signed type.
                if constexpr( is_signed_<Integer> ) {
                    if( x < min_<Integer> ) {
                        return false;
                    }
                } else {
                    if( x < 0 ) {       // Comparing to Integer(0) could wrap.
                        return false;
                    }
                }
            }
            return m_first <= Unsigned( x ) and Unsigned( x ) <= m_last;
        }

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

    template< class Integer, class Value_integer >
    inline constexpr auto is_in( const Sequence_<Integer>& seq, const Value_integer v ) noexcept
        -> Truth
    { return seq.contains( v ); }

}  // namespace cppx::sequences

namespace cppx {
    using namespace cppx::sequences;
}  // namespace cppx
