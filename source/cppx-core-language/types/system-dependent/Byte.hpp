#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief
/// \make_name_ref{cppx,Byte},
/// \make_name_ref{cppx,Signed_byte},
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

#include <cppx-core-language/syntax/declarations.hpp>                   // CPPX_USE_...
#include <cppx-core-language/types/system-dependent/size-types.hpp>     // cppx::Size
#include <cppx-core-language/syntax/type-builders.hpp>                  // cppx::Type_

#include <c/limits.hpp>     // CHAR_BIT
#include <c/stddef.hpp>     // std::byte

namespace cppx::_ {
    /// \brief Default choice of byte type.
    using Byte              = unsigned char;
    using Signed_byte       = signed char;

    constexpr auto max_byte = static_cast<Byte>( -1 );

    /// \brief The number of bytes per instance of a type.
    template< class Type > constexpr Size bytes_per_ = sizeof( Type );

    inline auto as_byte_pointer( Signed_byte* p )           -> Byte*;
    inline auto as_byte_pointer( const Signed_byte* p )     -> const Byte*;
    inline auto as_byte_pointer( char* p )                  -> Byte*;
    inline auto as_byte_pointer( const char* p )            -> const Byte*;
    inline auto as_signedbyte_pointer( Byte* p )            -> Signed_byte*;
    inline auto as_signedbyte_pointer( const Byte* p )      -> const Signed_byte*;
    inline auto as_signedbyte_pointer( char* p )            -> Signed_byte*;
    inline auto as_signedbyte_pointer( const char* p )      -> const Signed_byte*;
    inline auto as_char_pointer( Byte* p )                  -> char*;
    inline auto as_char_pointer( const Byte* p )            -> const char*;
    inline auto as_char_pointer( Signed_byte* p )           -> char*;
    inline auto as_char_pointer( const Signed_byte* p )     -> const char*;

    /// \brief Usually 8, but e.g. 16 on some DSPs.
    constexpr int bits_per_byte = CHAR_BIT;

    // Conversions to/from C++17 `std::byte`:
    inline auto as_number( const std::byte value ) -> Byte;
    inline auto as_std_byte( const Byte value ) -> std::byte;

    //------------------------------------------------------- impl

    inline auto as_byte_pointer( const Type_<Signed_byte*> p )
        -> Byte*
    { return reinterpret_cast<Byte*>( p ); }

    inline auto as_byte_pointer( const Type_<const Signed_byte*> p )
        -> const Byte*
    { return reinterpret_cast<const Byte*>( p ); }

    inline auto as_byte_pointer( const Type_<char*> p )
        -> Byte*
    { return reinterpret_cast<Byte*>( p ); }

    inline auto as_byte_pointer( const Type_<const char*> p )
        -> const Byte*
    { return reinterpret_cast<const Byte*>( p ); }

    inline auto as_signedbyte_pointer( const Type_<Byte*> p )
        -> Signed_byte*
    { return reinterpret_cast<Signed_byte*>( p ); }

    inline auto as_signedbyte_pointer( const Type_<const Byte*> p )
        -> const Signed_byte*
    { return reinterpret_cast<const Signed_byte*>( p ); }

    inline auto as_signedbyte_pointer( const Type_<char*> p )
        -> Signed_byte*
    { return reinterpret_cast<Signed_byte*>( p ); }

    inline auto as_signedbyte_pointer( const Type_<const char*> p )
        -> const Signed_byte*
    { return reinterpret_cast<const Signed_byte*>( p ); }

    inline auto as_char_pointer( const Type_<Byte*> p )
        -> char*
    { return reinterpret_cast<char*>( p ); }

    inline auto as_char_pointer( const Type_<const Byte*> p )
        -> const char*
    { return reinterpret_cast<const char*>( p ); }

    inline auto as_char_pointer( const Type_<Signed_byte*> p )
        -> char*
    { return reinterpret_cast<char*>( p ); }

    inline auto as_char_pointer( const Type_<const Signed_byte*> p )
        -> const char*
    { return reinterpret_cast<const char*>( p ); }

    inline auto as_number( const std::byte value )
        -> Byte
    { return std::to_integer<Byte>( value ); }

    inline auto as_std_byte( const Byte value )
        -> std::byte
    { return std::byte( value ); }
 }  // namespace cppx::_

 // Exporting namespaces:
 namespace cppx {
    namespace byte_stuff {
        CPPX_USE_FROM_NAMESPACE( _,
            Byte,
            Signed_byte,
            bits_per_byte,
            bytes_per_,
            max_byte,
            as_number,
            as_std_byte,
            as_byte_pointer,
            as_signedbyte_pointer,
            as_char_pointer
        );
    }  // namespace byte_stuff

    namespace system_dependent {
        using namespace byte_stuff;
    }  //  namespace system_dependent

    using namespace system_dependent;
 }  // namespace cppx
