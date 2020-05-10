#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
//
// This class is used by cppx::fail. It can't use things that in turn use cppx::fail, hence the
// duplication here of functions like `has_ascii_whitespace`.
//
// Line and character position indexing is 1-based. A function name can contain whitespace, e.g.
// `operator int` or (with Visual C++) `operator ()`.
//
// A similar class will be / is part of the C++20 standard library, see
// <url: https://en.cppreference.com/w/cpp/experimental/source_location>

#include <cppx-core-language/syntax/collection-util.hpp>    // cppx::is_empty
#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_WITH, CPPX_USE_STD, CPPX_USE_FROM_NAMESPACE
#include <cppx-core-language/text/Copysafe_string.hpp>      // cppx::Copysafe_string
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

#include <c/assert.hpp>     // assert
#include <c/ctype.hpp>      // ::isspace

#include <string>           // std::string
#include <string_view>      // std::string_view
#include <optional>         // std::optional

namespace cppx::definitions
{
    CPPX_USE_STD( optional, runtime_error, string, string_view, to_string );

    class Source_location
    {
        optional<Copysafe_string>   m_funcname;
        Copysafe_string             m_filespec;
        int                         m_linenumber;
        optional<int>               m_column;

        inline auto class_invariant() const -> Truth;

    public:
        Source_location(
            const C_str     funcname,
            const C_str     filespec,
            const int       linenumber,
            const int       column          = 0 
            ):
            m_funcname( funcname and *funcname? funcname : optional<Copysafe_string>() ),
            m_filespec( filespec ),
            m_linenumber( linenumber ),
            m_column( column? column : optional<int>() )
        {
            assert( class_invariant() );
        }

        Source_location( const C_str filespec, const int linenumber, const int column = 0 ):
            Source_location( nullptr, filespec, linenumber, column )
        {}

        inline auto funcname() const noexcept       -> optional<string_view>;
        inline auto filespec() const noexcept       -> string_view;
        inline auto linenumber() const noexcept     -> int;
        inline auto column() const noexcept         -> optional<int>;

        inline auto funcname_c_str() const noexcept -> C_str;
        inline auto filespec_c_str() const noexcept -> C_str;
    };

    namespace srcloc_impl {
        using C_str = const char*;

        template< class Value >
        inline auto operator<<( string& s, const Value& v )
            -> string&
        { return (s += to_string( v )); }

        inline auto operator<<( string& s, const C_str t )
            -> string&
        { return (s += t); }
    }  // srcloc_impl

    inline auto Source_location::class_invariant() const
        -> Truth
    {
        const auto func = funcname();
        const auto file = filespec();
        const auto line = linenumber();
        const auto col  = column();

        return true
            and (not func.has_value() or not func.value().empty())
            and (not file.empty())
            and (line > 0)
            and (not col.has_value() or col.value() > 0);
    }

    inline auto Source_location::funcname() const noexcept
        -> optional<string_view>
    { return (not m_funcname? optional<string_view>() : m_funcname->view()); }

    inline auto Source_location::filespec() const noexcept
        -> string_view
    { return m_filespec.view(); }

    inline auto Source_location::linenumber() const noexcept
        -> int
    { return m_linenumber; }

    inline auto Source_location::column() const noexcept
        -> optional<int>
    { return m_column; }

    inline auto Source_location::funcname_c_str() const noexcept
        -> C_str
    { return (not m_funcname? nullptr : m_funcname->c_str()); }

    inline auto Source_location::filespec_c_str() const noexcept
        -> C_str
    { return m_filespec.c_str(); }

    inline void append_text_location_to( string& s, const Source_location& loc )
    {
        using srcloc_impl::operator<<;

        s << "“"  << loc.filespec_c_str() << "” ";
        s << "line " << loc.linenumber();
        if( const auto col = loc.column() ) {
            s << " col " << col.value();
        }
    }

    inline auto text_location_of( const Source_location& loc )
        -> string
    {
        string result;
        append_text_location_to( result, loc );
        return result;
    }

    inline auto to_string( const Source_location& loc )
        -> string
    {
        string result;
        using srcloc_impl::operator<<;

        if( const auto func = loc.funcname_c_str() ) {
            result << "“" << func << "” in ";
        }
        append_text_location_to( result, loc );
        return result;
    }

    namespace srcloc_exports {
        CPPX_USE_FROM_NAMESPACE( definitions,
            Source_location,
            append_text_location_to,
            text_location_of,
            to_string
        );
    }
}  // namespace cppx::definitions

namespace cppx::introspection       { using namespace definitions::srcloc_exports; }
namespace cppx                      { using namespace definitions::srcloc_exports; }
