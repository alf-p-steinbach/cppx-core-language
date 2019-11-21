#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief
/// \make_name_ref{cppx,C_str} for `char const*`;
/// \make_name_ref{cppx,Wide_c_str} for `wchar_t const*`; and
/// \make_name_ref{cppx,Mutable_c_str} and
/// \make_name_ref{cppx,Mutable_wide_c_str} as ditto mutable types.
///
/// The shortest names like `C_str` stand for `const` string data. The prefix `Mutable_`,
/// as in `Mutable_c_str`, indicates mutable string data. This naming reflects
/// an experience that handling `const` string data is by far most common.
///
/// Using the type names avoids issues with non-reading direction placement of `*`,
/// and it supports prefix `const`. For example, instead of
///
///     char const* const s = "Blah";
///
/// ... you can write
///
///     const C_str s = "Blah";
///
/// Of course, for this particular example it would be silly to throw away the string
/// length information, so one should better just reference the string data,
///
///     constexpr auto& s = "Blah";
///
/// ... which supports compile time construction of a `string_view`, if desired.

#include <cppx-core-language/syntax/type-builders.hpp>      // cppx::(Type_)
#include <cppx-core-language/tmp/type-modifiers.hpp>        // cppx::(Const_, Unconst_)

namespace cppx
{
    template< class Char >
    using C_str_            = Type_<const Char*>;

    // Note: Unconst_ introduces an indirection that foils template arg deduction.
    template< class Char >
    using Mutable_c_str_    = Type_<Char*>;

    using C_str                 = C_str_<char>;             // Effectively `char const*`.
    using Wide_c_str            = C_str_<wchar_t>;          // Effectively `wchar_t const*`.
    using Mutable_c_str         = Mutable_c_str_<char>;     // Effectively `char*`.
    using Mutable_wide_c_str    = Mutable_c_str_<wchar_t>;  // Effectively `wchar_t*`.

} // namespace cppx
