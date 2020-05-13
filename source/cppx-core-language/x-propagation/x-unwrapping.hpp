#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/string-expressions/basic-string-assembly.hpp>
#include <cppx-core-language/syntax/collection-util.hpp>            // cppx::is_empty
#include <cppx-core-language/syntax/declarations.hpp>               // CPPX_USE_STD
#include <cppx-core-language/text/C_str_.hpp>                       // cppx::C_str

#include <exception>        // std::(exception, rethrow_exception)
#include <functional>       // std::function
#include <utility>          // std::move
#include <vector>           // std::vector

namespace cppx::definitions_ {
    CPPX_USE_STD(
        exception, function, move, rethrow_if_nested, string, vector
        );

    inline void for_each_description_line_from(
        const exception&                            x,
        const function<void( const C_str )>&        f
        )
    {
        f( x.what() );
        try {
            rethrow_if_nested( x );
        } catch( const exception& rx ) {
            for_each_description_line_from( rx, f );
        } catch( const C_str sz ) {
            f( sz );
        } catch( const int code ) {
            const auto s = "<integer value "s << code << ">";
            f( s.c_str() );
        } catch( ... ) {
            f( "<a non-standard exception>" );
        }
    }

    inline auto to_string( const exception& x )
        -> string
    {
        string result;
        const auto add_it = [&]( const C_str s )
            -> void
        {
            const bool is_first = is_empty( result );
            result << (is_first? "• " : "\n• because ") << s;
        };

        for_each_description_line_from( x, add_it );
        return result;
    }

    inline auto description_lines_from( const exception& x )
        -> vector<string>
    {
        vector<string> result;
        const auto add_it = [&]( const C_str s )
            -> void
        {
            result.push_back( s );
        };

        for_each_description_line_from( x, add_it );
        return result;
    }

    namespace x_propagation_exports {
        CPPX_USE_FROM_NAMESPACE( definitions_,
            for_each_description_line_from,
            to_string,
            description_lines_from
        );
    }  // namespace x_propagation_exports
}  // namespace cppx::definitions_

namespace cppx::x_propagation       { using namespace cppx::definitions_::x_propagation_exports; }
namespace cppx                      { using namespace cppx::definitions_::x_propagation_exports; }
