#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>  // CPPX_USE_STD
#include <cppx-core-language/types/C_str_.hpp>      // cppx::C_str

#include <string>           // std::string
#include <string_view>      // std::string_view
#include <sstream>          // std::ostringstream

namespace cppx
{
    CPPX_USE_STD( ostringstream, string, string_view );

    namespace basic_string_building
    {
        using namespace std::string_literals;       // E.g. ""s

        // Quite inefficient but this is the general case fallback. Client code might specialize
        // it for efficiency. That's not a concern here, except to support that it can be done.
        template< class Type >
        inline auto string_from( const Type& value )
            -> string
        {
            ostringstream stream;
            stream << value;
            return stream.str();
        }

        template< class Type >
        inline auto operator<<( string& s, const Type& value )
            -> string&
        {
            s += string_from( value );
            return s;
        }

        template<>
        inline auto operator<< <char>( string& s, const char& more )
            -> string&
        {
            s += more;
            return s;
        }

        template<>
        inline auto operator<< <C_str>( string& s, const C_str& more )
            -> string&
        {
            s += more;
            return s;
        }

        template<>
        inline auto operator<< <string_view>( string& s, const string_view& more )
            -> string&
        {
            s += more;
            return s;
        }

        template<>
        inline auto operator<< <string>( string& s, const string& more )
            -> string&
        {
            s += more;
            return s;
        }

        template< class Type >
        inline auto operator<<( string&& s, Type const& value )
            -> string&&
        { return move( operator<<( s, value ) ); }

    }  // namespace basic_string_building

    // Intentionally not exposing `basic_string_building::string_from` here.
    // It might interfere with other `string_from` functions.
    using namespace std::string_literals;       // E.g. ""s
    using basic_string_building::operator<<;

}  // namespace cppx
