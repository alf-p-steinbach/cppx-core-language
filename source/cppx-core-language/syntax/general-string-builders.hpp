#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/macro-use.hpp>      // CPPX_USE_STD
#include <cppx-core-language/syntax/Span_.hpp>          // cppx::Span_

#include <string>           // std::string
#include <string_view>      // std::string_view

namespace cppx::general_string_builders {
    CPPX_USE_STD( string, string_view );

    inline auto spaces( const int n )
        -> string
    { return (n <= 0? "" : string( n, ' ')); }

    inline auto repeated_times( const int n, const string_view& s )
        -> string
    {
        if( n <= 0 ) { return ""; }

        string result;
        result.reserve( n*s.length() );
        for( int i = 1; i <= n; ++i )
        {
            result += s;
        }
        return result;
    }

    inline auto operator*( const int n, const string_view& s )
        -> string
    { return repeated_times( n, s ); }

    template< class Iterator >      // TODO: Enable_if_
    inline auto joined(
        const Span_<Iterator>       range,
        const string_view&          separator = " "
        ) -> string
    {
        if( is_empty( range ) ) { return ""; }

        string result = range.front();
        for( const auto& item : all_but_first_of( range ) )
        {
            result += separator;
            result += item;
        }
        return result;
    }

}  // namespace cppx::general_string_builders

namespace cppx{
    using namespace general_string_builders;
}  // namespace cppx
