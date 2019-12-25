#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief
/// \make_name_ref{cppx,Byte},
/// \make_name_ref{cppx,As_signed_byte},
/// \make_name_ref{cppx,bytes_per_},
/// \make_name_ref{cppx,as_byte_pointer},
/// \make_name_ref{cppx,as_signedbyte_pointer},
/// \make_name_ref{cppx,as_char_pointer} and
/// \make_name_ref{cppx,bits_per_byte}, + `std::byte` support definitions
/// \make_name_ref{cppx,as_number} and
/// \make_name_ref{cppx,as_std_byte}.
///
/// \sa Related: the <cppx-core-language/\make_ref{bits_per_.hpp}> header 
/// defines the general bit size function template `bits_per_byte`.

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_STD
#include <cppx-core-language/system-dependent/size-types.hpp>   // cppx::Size
#include <cppx-core-language/syntax/types/type-builders.hpp>    // cppx::P_

#include <c/limits.hpp>     // CHAR_BIT
#include <c/stddef.hpp>     // std::byte

namespace cppx
{
    /// \brief Default choice of byte type.
    using Byte              = unsigned char;
    using As_signed_byte       = signed char;

    constexpr auto max_byte = static_cast<Byte>( -1 );

    /// \brief The number of bytes per instance of a type.
    template< class Type > constexpr Size bytes_per_ = sizeof( Type );

    inline auto as_byte_pointer( const P_<As_signed_byte> p )          -> P_<Byte>;
    inline auto as_byte_pointer( const P_<const As_signed_byte> p )    -> P_<const Byte>;
    inline auto as_byte_pointer( const P_<char> p )                 -> P_<Byte>;
    inline auto as_byte_pointer( const P_<const char> p )           -> P_<const Byte>;
    inline auto as_signedbyte_pointer( const P_<Byte> p )           -> P_<As_signed_byte>;
    inline auto as_signedbyte_pointer( const P_<const Byte> p )     -> P_<const As_signed_byte>;
    inline auto as_signedbyte_pointer( const P_<char> p )           -> P_<As_signed_byte>;
    inline auto as_signedbyte_pointer( const P_<const char> p )     -> P_<const As_signed_byte>;
    inline auto as_char_pointer( const P_<Byte> p )                 -> P_<char>;
    inline auto as_char_pointer( const P_<const Byte> p )           -> P_<const char>;
    inline auto as_char_pointer( const P_<As_signed_byte> p )          -> P_<char>;
    inline auto as_char_pointer( const P_<const As_signed_byte> p )    -> P_<const char>;

    /// \brief Usually 8, but e.g. 16 on some DSPs.
    constexpr int bits_per_byte = CHAR_BIT;

    // Conversions to/from C++17 `std::byte`:
    inline auto as_number( const std::byte value ) -> Byte;
    inline auto as_std_byte( const Byte value ) -> std::byte;

    // Documented in the <all.hpp> header.
    namespace system
    {
        CPPX_USE_CPPX(
            Byte, As_signed_byte,
            as_byte_pointer, as_signedbyte_pointer, bits_per_byte, as_number, as_std_byte
            );
    }

    //------------------------------------------------------- impl

    inline auto as_byte_pointer( const P_<As_signed_byte> p )
        -> P_<Byte>
    { return reinterpret_cast<P_<Byte>>( p ); }

    inline auto as_byte_pointer( const P_<const As_signed_byte> p )
        -> P_<const Byte>
    { return reinterpret_cast<P_<const Byte>>( p ); }

    inline auto as_byte_pointer( const P_<char> p )
        -> P_<Byte>
    { return reinterpret_cast<P_<Byte>>( p ); }

    inline auto as_byte_pointer( const P_<const char> p )
        -> P_<const Byte>
    { return reinterpret_cast<P_<const Byte>>( p ); }

    inline auto as_signedbyte_pointer( const P_<Byte> p )
        -> P_<As_signed_byte>
    { return reinterpret_cast<P_<As_signed_byte>>( p ); }

    inline auto as_signedbyte_pointer( const P_<const Byte> p )
        -> P_<const As_signed_byte>
    { return reinterpret_cast<P_<const As_signed_byte>>( p ); }

    inline auto as_signedbyte_pointer( const P_<char> p )
        -> P_<As_signed_byte>
    { return reinterpret_cast<P_<As_signed_byte>>( p ); }

    inline auto as_signedbyte_pointer( const P_<const char> p )
        -> P_<const As_signed_byte>
    { return reinterpret_cast<P_<const As_signed_byte>>( p ); }

    inline auto as_char_pointer( const P_<Byte> p )
        -> P_<char>
    { return reinterpret_cast<P_<char>>( p ); }

    inline auto as_char_pointer( const P_<const Byte> p )
        -> P_<const char>
    { return reinterpret_cast<P_<const char>>( p ); }

    inline auto as_char_pointer( const P_<As_signed_byte> p )
        -> P_<char>
    { return reinterpret_cast<P_<char>>( p ); }

    inline auto as_char_pointer( const P_<const As_signed_byte> p )
        -> P_<const char>
    { return reinterpret_cast<P_<const char>>( p ); }

    inline auto as_number( const std::byte value )
        -> Byte
    { return std::to_integer<Byte>( value ); }

    inline auto as_std_byte( const Byte value )
        -> std::byte
    { return std::byte( value ); }

}  // namespace cppx
