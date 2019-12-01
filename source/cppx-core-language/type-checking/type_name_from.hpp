#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/Sequence_.hpp>              // cppx::Sequence_
#include <cppx-core-language/syntax/type-builders.hpp>          // cppx::Type_
#include <cppx-core-language/syntax/macro-use.hpp>              // CPPX_USE_...
#include <cppx-core-language/text/ascii-character-util.hpp>     // cppx::ascii::*
#include <cppx-core-language/tmp/Type_carrier_.hpp>             // cppx::Type_carrier_
#include <cppx-core-language/tmp/type-modifiers.hpp>            // cppx::Unref_

#include <functional>   // std::invoke
#include <stdlib.h>     // free
#include <string>       // std::string
#include <typeinfo>     // std::type_info
#include <utility>      // std::forward

#ifdef __GNUC__
#   include  <cxxabi.h>
#endif

namespace cppx
{
    CPPX_USE_STD( forward, invoke, string, type_info );

    inline auto type_name_from( const type_info& info )
        -> string;

#ifdef __GNUC__
    inline auto type_name_from( const type_info& info )
        -> string
    {
        struct Malloced_string
        {
            Type_<const char*> p_chars;
            ~Malloced_string() { free( const_cast<Type_<char*>>( p_chars ) ); }
        };

        const Type_<const char*> mangled_name = info.name();
        int status = 0;
        const Malloced_string demangled = { ::abi::__cxa_demangle(
            info.name(),
            nullptr,            // Output buffer
            nullptr,            // length
            &status
        ) };
        return (status == 0? demangled.p_chars : mangled_name);
    }
#else
    namespace impl {
        inline auto is_ascii_separator( const char ch )
            -> bool
        {
            if( not ascii::contains( ch ) ) { return false; }
            return not ascii::is_identifier_character( ch );
        };

        inline auto is_identifier_character( const char ch )
            -> bool
        { return not is_ascii_separator( ch ); }
    }  // namespace impl

    inline auto type_name_from( const type_info& info )
        -> string
    {
        const string elaborated = string( info.name() ) + '\0';
        // MSVC example: "".

        string result;
        string part;
        bool is_in_name = false;

        // Assemble the parts except ditch MSVC's "struct", "class" and "enum" keywords.
        for( char ch: elaborated ) {
            if( impl::is_identifier_character( ch ) ) {
                is_in_name = true;
                part += ch;
            } else {
                if( is_in_name ) {
                    // Finish this part.
                    if( part == "struct" or part == "class" or part == "enum" ) {
                        // Ignore these keywords.
                        if( ascii::is_whitespace( ch ) ) {
                            ch = '\0';      // Don't add this whitespace to the result.
                        }
                    } else {
                        result += part;
                    }

                    part = "";
                    is_in_name = false;
                }

                if( ch != '\0' ) {
                    result += ch;
                }
            }
        }
        return result;
    }
#endif

}  // namespace cppx
