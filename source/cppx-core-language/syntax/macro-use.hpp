#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief Macros for generating more concise and clear `using` statements:
/// `$use_from_namespace`,
/// `$use_cppx`,
/// `$use_std`,
/// `$use_ns_from`,
/// `$use_cppx_ns`,
/// `$use_std_ns`,
/// `$use_namespaces_from`,
/// `$use_cppx_namespaces` and
/// `$use_std_namespaces`.


#include <cppx-core-language/meta-macro/macro-apply_with_fixed_arg.hpp>

#ifndef CPPX_NO_DOLLARS_PLEASE
#   // Use items from namespaces.
#   define $use_from_namespace          CPPX_USE_FROM_NAMESPACE         ///< \dollarname{use_from_namespace}
#   define $use_cppx                    CPPX_USE_CPPX                   ///< \dollarname{use_cppx}
#   define $use_std                     CPPX_USE_STD                    ///< \dollarname{use_std}
#
#   // Use nested namespace names.
#   define $use_namespaces_from         CPPX_USE_NAMESPACES_FROM        ///< \dollarname{use_namespaces_from}
#   define $use_cppx_namespaces         CPPX_USE_CPPX_NAMESPACES        ///< \dollarname{use_cppx_namespaces}
#   define $use_std_namespaces          CPPX_USE_STD_NAMESPACES         ///< \dollarname{use_std_namespaces}
#   define $use_ns_from                 CPPX_USE_NS_FROM                ///< \dollarname{use_ns_from}
#   define $use_cppx_ns                 CPPX_USE_CPPX_NS                ///< \dollarname{use_cppx_ns}
#   define $use_std_ns                  CPPX_USE_STD_NS                 ///< \dollarname{use_std_ns}
#endif


/// \hideinitializer
/// \brief Use each specified item `ITEM` from namespace `NS` as if by `using NS::ITEM;`.
///
/// \param  ns      The namespace name.
/// \param  ...     A comma separated list of items to use unqualified.
#define CPPX_USE_FROM_NAMESPACE( ns, ... ) \
    CPPX_APPLY_WITH_FIXED_ARG( CPPX_GENERATE_USING_DECLARATION_FOR, ns, __VA_ARGS__ ) \
    static_assert( !!"Terminate this statement with a semicolon" )

/// @cond DOXY_SHOW_IMPL_DETAILS
#define CPPX_GENERATE_USING_DECLARATION_FOR( ns, name ) \
    using ns::name;
/// @endcond

/// \brief Use each specified item `ITEM` from namespace `cppx` as if by `using cppx::ITEM;`.
///
/// \param  ...     A comma separated list of items to use unqualified.
#define CPPX_USE_CPPX( ... ) \
    CPPX_USE_FROM_NAMESPACE( cppx, __VA_ARGS__ )

/// \brief Use each specified item `ITEM` from namespace `std` as if by `using std::ITEM;`.
///
/// \param  ...     A comma separated list of items to use unqualified.
#define CPPX_USE_STD( ... ) \
    CPPX_USE_FROM_NAMESPACE( std, __VA_ARGS__ )

/// \brief Use `NESTED_NS` as an alias for namespace `PARENT_NS::NESTED_NS`.
///
/// \param  parent_ns   The namespace containing the relevant nested namespace.
/// \param  nested_ns   The nested namespace.
#define CPPX_USE_NS_FROM( parent_ns, nested_ns ) \
    namespace nested_ns = parent_ns::nested_ns

/// \brief Use `NESTED_NS` as an alias for namespace `cppx::NESTED_NS`.
///
/// \param  nested_ns   The nested namespace.
#define CPPX_USE_CPPX_NS( nested_ns ) \
    CPPX_USE_NS_FROM( cppx, nested_ns )

/// \brief Use `NESTED_NS` as an alias for namespace `std::NESTED_NS`.
///
/// \param  nested_ns   The nested namespace.
#define CPPX_USE_STD_NS( nested_ns ) \
    CPPX_USE_NS_FROM( std, nested_ns )

/// \hideinitializer
/// \brief Use each specified `NESTED_NS` as an alias for namespace `PARENT_NS::NESTED_NS`.
///
/// \param  parent_ns   The namespace containing the relevant nested namespace.
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_USE_NAMESPACES_FROM( parent_ns, ... ) \
    CPPX_APPLY_WITH_FIXED_ARG( CPPX_GENERATE_NSNAME_USAGE, parent_ns, __VA_ARGS__ ) \
    static_assert( !!"Terminate this statement with a semicolon" )

/// @cond DOXY_SHOW_IMPL_DETAILS
#define CPPX_GENERATE_NSNAME_USAGE( parent_ns, nested_ns ) \
    namespace nested_ns = parent_ns::nested_ns;
/// @endcond

/// \brief Use each specified `NESTED_NS` as an alias for namespace `cppx::NESTED_NS`.
///
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_USE_CPPX_NAMESPACES( ... ) \
    CPPX_USE_NAMESPACES_FROM( cppx, __VA_ARGS__ )

/// \brief Use each specified `NESTED_NS` as an alias for namespace `std::NESTED_NS`.
///
/// \param  ...         A comma separated list of names of nested namespaces.
#define CPPX_USE_STD_NAMESPACES( ... ) \
    CPPX_USE_NAMESPACES_FROM( std, __VA_ARGS__ )
