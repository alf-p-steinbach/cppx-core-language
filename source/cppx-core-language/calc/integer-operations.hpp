#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief Common integer operations:
/// \make_name_ref{cppx,is_even},
/// \make_name_ref{cppx,is_odd},
/// \make_name_ref{cppx,is_zero},
/// \make_name_ref{cppx,div_down},
/// \make_name_ref{cppx,div_up} and
/// \make_name_ref{cppx,mod}.

#include <cppx-core-language/calc/general-operations.hpp>       // cppx::(squared, cubed)
#include <cppx-core-language/syntax/macro-use.hpp>              // CPPX_USE_CPPX
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

#include <c/limits.hpp>     // INT_MAX
#include <c/stdint.hpp>     // ::(uintXX_t)
#include <algorithm>        // std::max
#include <type_traits>      // std::(common_type_t, is_integral_v, is_unsigned_v)

namespace cppx
{
    template< class Int >
    constexpr inline auto is_even( const Int x )
        -> Truth
    { return x % 2 == 0; }

    template< class Int >
    constexpr inline auto is_odd( const Int x )
        -> Truth
    { return x % 2 == 1; }

    template< class Int >
    constexpr inline auto is_zero( const Int x )
        -> Truth
    { return x == 0; }

    template< class Int >
    constexpr inline auto div_down( const Int a, const Int b ) noexcept
        -> Int
    {
        const Int q = a/b;
        return (q < 0 and a % b != 0? q - 1 : q);
    }

    template< class Int >
    constexpr inline auto div_up( const Int a, const Int b ) noexcept
        -> Int
    {
        const Int q = a/b;
        return (q >= 0 and a % b != 0? q + 1 : q);
    }

    constexpr inline auto mod( const int a, const int b ) noexcept
        -> int
    { return a - b*div_down( a, b ); }

    //template< class... Ints >
    //constexpr inline auto intmin( const Ints... args )
    //    -> std::common_type_t<Ints...>
    //{ 
    //    static_assert( (... and std::is_integral_v<Ints> ) );
    //    return std::min( {std::common_type_t<Ints...>( args )...} );
    //}

    //template< class... Ints >
    //constexpr inline auto intmax( const Ints... args )
    //    -> std::common_type_t<Ints...>
    //{ 
    //    static_assert( (... and std::is_integral_v<Ints> ) );
    //    return std::max( {std::common_type_t<Ints...>( args )...} );
    //}

    // Is documented in the `all.hpp` header.
    namespace calc
    {
        CPPX_USE_CPPX(
            is_even, is_odd, is_zero, div_down, div_up, mod
        );
    }  // namespace calc
}  // namespace cppx
