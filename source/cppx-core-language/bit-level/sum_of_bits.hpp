#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief \make_name_ref{cppx,sum_of_bits}, the number of 1-bits in a `std::bitset` or
/// unsigned value.

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_CPPX, CPPX_USE_STD
#include <cppx-core-language/bit-level/bits_per_.hpp>       // cppx::bits_per_
#include <cppx-core-language/tmp/type-traits.hpp>           // cppx::is_unsigned_

#include <bitset>           // std::bitset

namespace cppx::_{
    CPPX_USE_STD( bitset );

    /// \brief The number of 1-bits in a `std::bitset`.
    template< int n >
    inline auto sum_of_bits( const bitset<n>& bits ) noexcept
        -> int
    { return bits.count(); }

    /// \brief The number of 1-bits in an unsigned value.
    template< class Unsigned >
    inline auto sum_of_bits( const Unsigned x ) noexcept
        -> int
    {
        static_assert( is_unsigned_<Unsigned> );
        return bitset< bits_per_<Unsigned> >( x ).count();
    }

#if 0  // Possible optimizations, probably not needed
#if defined( _MSC_VER )

    inline auto sum_of_bits( const uint16_t x ) noexcept
        -> int
    { return __popcnt16( x ); }

    inline auto sum_of_bits( const uint32_t x ) noexcept
        -> int
    { return __popcnt( x ); }

    inline auto sum_of_bits( const uint64_t x ) noexcept
        -> int
    { return __popcnt64( x ); }

#elif defined( __GNUC__ )

    /// @cond DOXY_SHOW_IMPL_DETAILS
    namespace impl
    {
        template< class Unsigned >
        inline auto gcc_sum_of_bits(  const Unsigned x ) noexcept -> int;

        template<> inline auto gcc_sum_of_bits<unsigned>( const unsigned x ) noexcept
            -> int
        { return  __builtin_popcount( x ); }

        template<> inline auto gcc_sum_of_bits<unsigned long>( const unsigned long x ) noexcept
            -> int
        { return  __builtin_popcountl( x ); }

        template<> inline auto gcc_sum_of_bits<unsigned long long>( const unsigned long long x ) noexcept
            -> int
        { return  __builtin_popcountll( x ); }
    }  // namespace impl
       /// @endcond

    inline auto sum_of_bits( const uint16_t x ) noexcept
        -> int
    { return impl::gcc_sum_of_bits<uint32_t>( x ); }

    inline auto sum_of_bits( const uint32_t x ) noexcept
        -> int
    { return impl::gcc_sum_of_bits( x ); }

    inline auto sum_of_bits( const uint64_t x ) noexcept
        -> int
    { return impl::gcc_sum_of_bits( x ); }
#endif
#endif // 0

}  // namespace cppx::_

// Exporting namespaces.
namespace cppx{
    namespace bitlevel
    {
        CPPX_USE_CPPX( _::sum_of_bits );
    }  // namespace bitlevel

    using namespace bitlevel;
}  // namespace cppx
