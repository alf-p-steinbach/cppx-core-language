#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/collection-util/Sequence_.hpp>              // cppx::zero_to
#include <cppx-core-language/syntax/declarations/macro-define_tag.hpp>          // CPPX_DEFINE_TAG
#include <cppx-core-language/syntax/declarations/macro-use_from_namespace.hpp>  // CPPX_USE...
#include <cppx-core-language/syntax/flow-control/x-throwing.hpp>                // cppx::hopefully
#include <cppx-core-language/bit-level/bits_per_.hpp>                           // cppx::bits_per_
#include <cppx-core-language/bit-level/Int_.hpp>                                // cppx::Unsigned_int_
#include <cppx-core-language/tmp/Enable_if_.hpp>                                // cppx::Enable_if_
#include <cppx-core-language/tmp/type-checkers.hpp>                             // cppx::is_enum_

#include <bitset>                   // std::bitset
#include <initializer_list>         // std::initializer_list
#include <stdexcept>                // std::out_of_range
#include <type_traits>              // std::underlying_type_t

CPPX_DEFINE_TAG( Compile_time );

namespace cppx::definitions_ {
    CPPX_USE_CPPX(
        bits_per_, Enable_if_, is_enum_, Truth, Unsigned_int_,
        hopefully,
        zero_to
        );
    CPPX_USE_STD(
        bitset, initializer_list, out_of_range, underlying_type_t
        );

    template<
        class Enum, int n_bits = bits_per_<void*>,
        class = Enable_if_<is_enum_<Enum>>
        >
    class Bitset_
    {
        using Integer = std::underlying_type_t<Enum>;
        using Ull = unsigned long long;

        bitset<n_bits>  m_bits;

        template< class... Args >
        constexpr static auto bits_for( const Enum arg_1, const Args... more_args )
            -> Ull
        {
            const Enum values_array[] = {arg_1, more_args...};
            Ull result = 0;
            for( const Enum v: values_array ) {
                const auto i = static_cast<long long>( v );
                hopefully( 0 < i and i < n_bits )
                    or (throw out_of_range( "Enum value outside range of bitset" ), 0);
                hopefully( i < bits_per_<Ull> )
                    or( throw out_of_range( "Enum value outside bit index range of long long" ), 0 );
                result |= Ull(1) << i;
            }
            return result;
        }

    public:
        template< class... Args >       // Every Args type should be Enum.
        constexpr Bitset_( tag::Compile_time, const Enum arg1, const Args... more_args ):
            m_bits( bits_for( arg1, more_args... ) )
        {}

        template< class... Args >       // Every Args type should be Enum.
        Bitset_( const Enum arg_1, const Args... more_args ):
            m_bits()
        {
            const Enum values_array[] = {arg_1, more_args...};
            for( const Enum v: values_array ) {
                const auto i = static_cast<Integer>( v );
                hopefully( 0 < i and i < n_bits )
                    or (throw out_of_range( "Enum value outside range of bitset" ), 0);
                m_bits.set( i );
            }
        }

        constexpr Bitset_():
            m_bits()
        {}

        constexpr auto capacity() const
            -> int
        { return n_bits; }

        constexpr auto size() const
            -> int
        { return m_bits.count(); }

        constexpr auto operator[] ( const int i ) const
            -> Truth
        { return m_bits.test( i ); }

        template< class Func >
        void for_each( const Func& f ) const
        {
            for( const int i: zero_to( n_bits ) ) {
                if( m_bits.test( i ) ) {
                    f( static_cast<Enum>( i ) );
                }
            }
        }
    };
}  // namespace cppx::definitions_
