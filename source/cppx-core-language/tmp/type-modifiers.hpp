#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief
/// \make_name_ref{cppx,As_pointee_},
/// \make_name_ref{cppx,As_referent_},
/// \make_name_ref{cppx,As_signed_},
/// \make_name_ref{cppx,As_unsigned_},
/// \make_name_ref{cppx,As_const_} and
/// \make_name_ref{cppx,As_unconst_}.

/// The template aliases defined in this file generally do not support template argument
/// deduction. In contrast, the basic type assemblers like
/// \make_name_ref{cppx,P_} and
/// \make_name_ref{cppx,R_}, do. Those basic type assemblers are also offered by this
/// header, via a convenience include of
/// `<cppx-core-language/syntax/type-builders.hpp> `.

#include <cppx-core-language/syntax/type-builders.hpp>          // Convenience include.

#include <type_traits>      // std::(add_*, make_*, remove_*)

namespace cppx
{
    //-------------------------------------------------------------- Deprecated:

    /// \brief Reduces a type `T*` to just `T`.
    template< class Some_pointer_type >
    using Unptr_ [[deprecated( "New name As_pointee_" )]] = std::remove_pointer_t<Some_pointer_type>;

    /// \brief Reduces a type `T&` or `T&&` to just `T`.
    template< class Some_reference_type >
    using Unref_ [[deprecated( "New name As_referent_" )]] = std::remove_reference_t<Some_reference_type>;

    /// \brief For an integer type, produces the corresponding signed type.
    template< class Integer >
    using Signed_ [[deprecated( "New name As_signed_" )]] = std::make_signed_t< Integer >;

    /// \brief For an integer type, produces the corresponding unsigned type.
    template< class Integer >
    using Unsigned_ [[deprecated( "New name As_unsigned_" )]] = std::make_unsigned_t< Integer >;

    /// \brief For a type `T` produces `const T`.
    template< class Some_type >
    using Const_ [[deprecated( "New name As_const_" )]] = std::add_const_t< Some_type >;

    /// \brief For a type `const T` produces plain `T`.
    template< class Some_type >
    using Unconst_ [[deprecated( "New name As_unconst_" )]] = std::remove_const_t< Some_type >;

    //-------------------------------------------------------------- New names:

    /// \brief Reduces a type `T*` to just `T`.
    template< class Some_pointer_type >
    using As_pointee_   = std::remove_pointer_t<Some_pointer_type>;

    /// \brief Reduces a type `T&` or `T&&` to just `T`.
    template< class Some_reference_type >
    using As_referent_  = std::remove_reference_t<Some_reference_type>;

    /// \brief For an integer type, produces the corresponding signed type.
    template< class Integer >
    using As_signed_    = std::make_signed_t< Integer >;

    /// \brief For an integer type, produces the corresponding unsigned type.
    template< class Integer >
    using As_unsigned_  = std::make_unsigned_t< Integer >;

    /// \brief For a type `T` produces `const T`.
    template< class Some_type >
    using As_const_     = std::add_const_t< Some_type >;

    /// \brief For a type `const T` produces plain `T`.
    template< class Some_type >
    using As_unconst_   = std::remove_const_t< Some_type >;

    namespace type_modifiers
    {
        CPPX_USE_CPPX(
            As_pointee_, As_referent_, As_signed_, As_unsigned_, As_const_, As_unconst_,
            As_pointee_, As_referent_, As_signed_, As_unsigned_, As_const_, As_unconst_
        );
    }  // namespace type_modifiers
}  // namespace cppx
