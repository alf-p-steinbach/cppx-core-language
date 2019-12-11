#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/macro-use.hpp>              // CPPX_USE_STD, CPPX_USE_CPPX
#include <cppx-core-language/syntax/macro-repeat_times.hpp>     // CPPX_REPEAT_TIMES
#include <cppx-core-language/syntax/Span_.hpp>                  // cppx::Span_
#include <cppx-core-language/types/C_str_.hpp>                  // cppx::C_str

#include <string>           // std::string
#include <string_view>      // std::string_view

namespace cppx::_ {
    CPPX_USE_STD( string, string_view );

    struct Sz {};                   // "sz" was the Hungarian prefix for zero-terminated string.
    constexpr auto sz = Sz();

    inline auto operator^( const string& s, Sz )
        -> C_str
    { return s.c_str(); }

    inline auto repeated_times( const int n, const string_view& s )
        -> string
    {
        if( n <= 0 ) { return ""; }
        if( s.length() == 1 ) { return string( n, s[0] ); }

        string result;
        result.reserve( n*s.length() );
        CPPX_REPEAT_TIMES( n ) {
            result += s;
        }
        return result;
    }

    inline auto operator*( const int n, const string_view& s )
        -> string
    { return repeated_times( n, s ); }

    // Optimization of `repeated_times( n, " " )`.
    inline auto spaces( const int n )
        -> string
    { return (n <= 0? "" : string( n, ' ')); }

    // Optimization of `repeated_times( n, "-" )`.
    inline auto dashes( const int n )
        -> string
    { return (n <= 0? "" : string( n, '-')); }

}  // namespace cppx::_

// Exporting namespaces.
namespace cppx{
    namespace string_operators {
        CPPX_USE_CPPX(
            _::sz,
            _::operator^,
            _::repeated_times,
            _::operator*,
            _::spaces,
            _::dashes
            );
    }  // namespace string_operators

    namespace syntax{
        using namespace string_operators;
    }  // namespace syntax

    using namespace syntax;
}  // namespace cppx
