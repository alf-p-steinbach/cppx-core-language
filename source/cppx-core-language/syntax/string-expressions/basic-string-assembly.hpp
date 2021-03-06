﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_STD, CPPX_USE_FROM_NAMESPACE
#include <cppx-core-language/text/format-specs.hpp>         // cppx::fp::Text_spec
#include <cppx-core-language/text/C_str_.hpp>               // cppx::C_str
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

#include <ios>              // std::(fixed, scientific, uppercase)
#include <iomanip>          // std::setprecision
#include <ostream>          // std::ostream
#include <string>           // std::string
#include <string_view>      // std::string_view
#include <sstream>          // std::ostringstream

namespace cppx::definitions_ {
    CPPX_USE_STD(
        ostream, ostringstream, string, string_view,
        fixed, scientific, uppercase, setprecision
        );
    using namespace std::string_literals;

    // General fall-back.
    // Quite inefficient but this is the general case fallback. Client code might specialize
    // it for efficiency. That's not a concern here, except to support that it can be done.
    template< class Type >
    inline auto operator<<( string& s, const Type& value )
        -> string&
    {
        ostringstream stream;
        stream << value;
        s += stream.str();
        return s;
    }

    // TODO: Replace with more fast-ish floating point output.
    inline auto operator<<( string& s, const fp::Text_spec& fv )
        -> string&
    {
        ostringstream stream;
        switch( fv.format.scheme ) {
            case fp::Scheme::smart:
                break;      // std::defaultfloat
            case fp::Scheme::fix:
                stream << fixed;
                break;
            case fp::Scheme::sci:
                stream << scientific;
                break;
            case fp::Scheme::sci_uc:
                stream << scientific << uppercase;
                break;
        }
        stream << setprecision( fv.format.precision.n_digits ) << fv.value;
        s += stream.str();
        return s;
    }

    // Disallow simple manipulators such as `std::endl` to avoid some diagnostics avalanches:
    inline auto operator<<( const string& s, auto(ostream&) -> ostream& )
        -> string
        = delete;

    inline auto operator<<( string& s, const Truth value )
        -> string&
    {
        s += (value? "true" : "false");
        return s;
    }
        
    inline auto operator<<( string& s, const bool value )
        -> string&
    { return s << Truth( value ); }

    inline auto operator<<(  string& s, const char more )
        -> string&
    {
        s += more;
        return s;
    }

    inline auto operator<<( string& s, const C_str more )
        -> string&
    {
        s += more;
        return s;
    }

    inline auto operator<<( string& s, const string_view& more )
        -> string&
    {
        s += more;
        return s;
    }

    inline auto operator<<( string& s, const string& more )
        -> string&
    {
        s += more;
        return s;
    }

    template< class Type >
    inline auto operator<<( string&& s, Type const& value )
        -> string&&
    { return move( operator<<( s, value ) ); }

    template< class Type >
    inline auto string_from( Type const& value )
        -> string
    { return ""s << value; }

    namespace basic_string_expression_exports {
        using namespace std::string_literals;       // E.g. ""s
        using namespace cppx::format_specs;         // fp::*, integral::*

        CPPX_USE_FROM_NAMESPACE( definitions_,
            operator<<,
            string_from
            );
    }  // basic_string_expression_exports
}  // namespace cppx::definitions_

namespace cppx::basic_string_assembly   { using namespace definitions_::basic_string_expression_exports; }
namespace cppx::string_expressions      { using namespace definitions_::basic_string_expression_exports; }
namespace cppx::syntax                  { using namespace definitions_::basic_string_expression_exports; }
namespace cppx                          { using namespace definitions_::basic_string_expression_exports; }
