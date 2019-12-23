#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

/// \file
/// \brief Macros for generating more concise and clear `using` statements:
/// `$alias_namespaces_from`,
/// `$alias_cppx_namespaces` and
/// `$alias_std_namespaces`.

#include <cppx-core-language-meta-macro/macro-apply_with_fixed_arg.hpp>

#ifndef CPPX_NO_DOLLARS_PLEASE
#   // Use nested namespace names.
#   define $alias_namespaces_from       CPPX_ALIAS_NAMESPACES_FROM      ///< \dollarname{alias_namespaces_from}
#   define $alias_cppx_namespaces       CPPX_ALIAS_CPPX_NAMESPACES      ///< \dollarname{alias_cppx_namespaces}
#   define $alias_std_namespaces        CPPX_ALIAS_STD_NAMESPACES       ///< \dollarname{alias_std_namespaces}
#endif

/// \hideinitializer
/// \brief Use each specified `NESTED_NS` as an alias for namespace `PARENT_NS::NESTED_NS`.
///
/// \param  parent_ns   The namespace containing the relevant nested namespace.
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_ALIAS_NAMESPACES_FROM( parent_ns, ... ) \
    CPPX_APPLY_WITH_FIXED_ARG( CPPX_GENERATE_NSNAME_ALIAS, parent_ns, __VA_ARGS__ ) \
    static_assert( !!"Terminate this statement with a semicolon" )

/// @cond DOXY_SHOW_IMPL_DETAILS
#define CPPX_GENERATE_NSNAME_ALIAS( parent_ns, nested_ns ) \
    namespace nested_ns = parent_ns::nested_ns;
/// @endcond

/// \brief Use each specified `NESTED_NS` as an alias for namespace `cppx::NESTED_NS`.
///
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_ALIAS_CPPX_NAMESPACES( ... ) \
    CPPX_ALIAS_NAMESPACES_FROM( cppx, __VA_ARGS__ )

/// \brief Use each specified `NESTED_NS` as an alias for namespace `std::NESTED_NS`.
///
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_ALIAS_STD_NAMESPACES( ... ) \
    CPPX_ALIAS_NAMESPACES_FROM( std, __VA_ARGS__ )
