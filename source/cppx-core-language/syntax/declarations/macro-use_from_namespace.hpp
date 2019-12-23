#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

/// \file
/// \brief Macros for generating more concise and clear `using` statements:
/// `$use_from_namespace`,
/// `$use_cppx` and
/// `$use_std`.

#include <cppx-core-language-meta-macro/macro-apply_with_fixed_arg.hpp>

#ifndef CPPX_NO_DOLLARS_PLEASE
#   // Use items from namespaces.
#   define $use_from_namespace          CPPX_USE_FROM_NAMESPACE         ///< \dollarname{use_from_namespace}
#   define $use_cppx                    CPPX_USE_CPPX                   ///< \dollarname{use_cppx}
#   define $use_std                     CPPX_USE_STD                    ///< \dollarname{use_std}
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
