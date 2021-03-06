﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief Integer types templated on exact number of bits:
/// \make_name_ref{cppx,Int_} and
/// \make_name_ref{cppx,Unsigned_int_}.

#include <cppx-core-language/tmp/type-modifiers.hpp>    // cppx::As_unsigned_

#include <c/stdint.hpp>     // ::intN_t

namespace cppx::_ {
    namespace impl {
        template< int n_bits >  struct Int_t_;

        template<> struct Int_t_<8>{   using T = int8_t;   };
        template<> struct Int_t_<16>{  using T = int16_t;  };
        template<> struct Int_t_<32>{  using T = int32_t;  };
        template<> struct Int_t_<64>{  using T = int64_t;  };
        // TODO: conditional definition for 128-bits.
    }  // namespace impl

    // The Doxygen \hideinitializer command doesn't work here, so.
    /// \brief Signed integer types parameterized by exact width in bits.
    /// \param  n_bits      be 8, 16, 32 or 64.
    #ifdef DOXYGEN
        template< int n_bits >  using Int_  = ...;
    #else
        template< int n_bits >  using Int_  = typename impl::Int_t_<n_bits>::T;
    #endif

    /// \brief Unsigned integer types parameterized by exact width in bits.
    template< int n_bits >  using Unsigned_int_ = As_unsigned_<Int_<n_bits>>;

}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace bit_level {
        CPPX_USE_FROM_NAMESPACE( _,
            Int_,
            Unsigned_int_
        );
    }  // namespace bit_level

    using namespace bit_level;
}  // namespace cppx
