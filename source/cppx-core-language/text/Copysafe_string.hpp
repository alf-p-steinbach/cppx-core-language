#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

// A noexcept copyable string carrier, mainly for use in exceptions.
//
// It /may/ be able to construct a string even in low memory conditions where e.g. `std::string`
// construction would fail. However there's no guarantee.
//
// NOTE: it's assumed that a `std::string` argument does not contain embedded null-bytes.

#include <cppx-core-language/syntax/declarations/macro-use_from_namespace.hpp>  // CPPX_USE_STD
#include <cppx-core-language/text/C_str_.hpp>                                   // cppx::C_str
#include <cppx-core-language/types/system-dependent/size-types.hpp>             // cppx::Size

#include <c/string.hpp>     // strlen

#include <stdexcept>        // std::runtime_error
#include <string>           // std::string
#include <string_view>      // std::string_view

namespace cppx::definitions {
    CPPX_USE_STD( runtime_error, string, string_view );

    class Copysafe_string
    {
        runtime_error   m_data;
        Size            m_length;

    public:
        Copysafe_string( const C_str s ):
            m_data( s ),
            m_length( strlen( s ) )
        {}

        Copysafe_string( const string_view& s ):
            m_data( string( s ) ),
            m_length( s.length() )
        {}

        Copysafe_string( const string& s ):
            m_data( s ),
            m_length( s.length() )
        {}

        Copysafe_string( const Copysafe_string& other ) noexcept
            = default;

        Copysafe_string( Copysafe_string&& other ) noexcept:
            Copysafe_string( other )        // Logical copy, noexcept.
        {}

        auto operator=( const Copysafe_string& other ) noexcept
            -> Copysafe_string&
            = default;

        auto operator=( Copysafe_string&& other ) noexcept
            -> Copysafe_string&
        { return (*this = other); }

        auto c_str() const noexcept
            -> C_str
        { return m_data.what(); }

        auto length() const noexcept
            -> Size
        { return m_length; }

        auto view() const noexcept
            -> string_view
        { return string_view( c_str(), length() ); }

        auto str() const
            -> string
        { return string( c_str(), length() ); }
    };
}  // namespace cppx::definitions

namespace cppx::text        { using definitions::Copysafe_string; }
namespace cppx              { using definitions::Copysafe_string; }
