#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
///
/// \brief `$repeat(n, what)` produces the `what` text `n` times.

#include <cppx-core-language/meta-macro/macro-n_arguments.hpp>
#include <cppx-core-language/meta-macro/macro-invoke_macro.hpp>
#include <cppx-core-language/meta-macro/macro-joined.hpp>

#ifndef CPPX_NO_DOLLARS_PLEASE
#   define $duplicate       CPPX_DUPLICATE         ///< \dollarname{repeat}
#endif

/// \brief `CPPX_DUPLICATE(n, what)` produces the `what` text `n` times.
/// \hideinitializer
///
/// \param  n       The number of times (minimum 1) to produce the `what` text.
/// \param  what    The text to produce repeatedly.

#define CPPX_DUPLICATE( n, what ) \
    CPPX_DUPLICATE_EXPANSION_HELPER_( what, n )

/// @cond DOXY_SHOW_IMPL_DETAILS
#define CPPX_DUPLICATE_EXPANSION_HELPER_( m, n_times ) \
    CPPX_INVOKE_MACRO( CPPX_JOINED( CPPX_DUPLICATE_, n_times ), ( m ) )

#define CPPX_DUPLICATE_63( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_62( m )

#define CPPX_DUPLICATE_62( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_61( m )

#define CPPX_DUPLICATE_61( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_60( m )

#define CPPX_DUPLICATE_60( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_59( m )

#define CPPX_DUPLICATE_59( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_58( m )

#define CPPX_DUPLICATE_58( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_57( m )

#define CPPX_DUPLICATE_57( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_56( m )

#define CPPX_DUPLICATE_56( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_55( m )

#define CPPX_DUPLICATE_55( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_54( m )

#define CPPX_DUPLICATE_54( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_53( m )

#define CPPX_DUPLICATE_53( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_52( m )

#define CPPX_DUPLICATE_52( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_51( m )

#define CPPX_DUPLICATE_51( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_50( m )

#define CPPX_DUPLICATE_50( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_49( m )

#define CPPX_DUPLICATE_49( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_48( m )

#define CPPX_DUPLICATE_48( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_47( m )

#define CPPX_DUPLICATE_47( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_46( m )

#define CPPX_DUPLICATE_46( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_45( m )

#define CPPX_DUPLICATE_45( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_44( m )

#define CPPX_DUPLICATE_44( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_43( m )

#define CPPX_DUPLICATE_43( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_42( m )

#define CPPX_DUPLICATE_42( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_41( m )

#define CPPX_DUPLICATE_41( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_40( m )

#define CPPX_DUPLICATE_40( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_39( m )

#define CPPX_DUPLICATE_39( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_38( m )

#define CPPX_DUPLICATE_38( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_37( m )

#define CPPX_DUPLICATE_37( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_36( m )

#define CPPX_DUPLICATE_36( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_35( m )

#define CPPX_DUPLICATE_35( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_34( m )

#define CPPX_DUPLICATE_34( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_33( m )

#define CPPX_DUPLICATE_33( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_32( m )

#define CPPX_DUPLICATE_32( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_31( m )

#define CPPX_DUPLICATE_31( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_30( m )

#define CPPX_DUPLICATE_30( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_29( m )

#define CPPX_DUPLICATE_29( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_28( m )

#define CPPX_DUPLICATE_28( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_27( m )

#define CPPX_DUPLICATE_27( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_26( m )

#define CPPX_DUPLICATE_26( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_25( m )

#define CPPX_DUPLICATE_25( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_24( m )

#define CPPX_DUPLICATE_24( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_23( m )

#define CPPX_DUPLICATE_23( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_22( m )

#define CPPX_DUPLICATE_22( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_21( m )

#define CPPX_DUPLICATE_21( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_20( m )

#define CPPX_DUPLICATE_20( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_19( m )

#define CPPX_DUPLICATE_19( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_18( m )

#define CPPX_DUPLICATE_18( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_17( m )

#define CPPX_DUPLICATE_17( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_16( m )

#define CPPX_DUPLICATE_16( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_15( m )

#define CPPX_DUPLICATE_15( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_14( m )

#define CPPX_DUPLICATE_14( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_13( m )

#define CPPX_DUPLICATE_13( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_12( m )

#define CPPX_DUPLICATE_12( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_11( m )

#define CPPX_DUPLICATE_11( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_10( m )

#define CPPX_DUPLICATE_10( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_9( m )

#define CPPX_DUPLICATE_9( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_8( m )

#define CPPX_DUPLICATE_8( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_7( m )

#define CPPX_DUPLICATE_7( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_6( m )

#define CPPX_DUPLICATE_6( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_5( m )

#define CPPX_DUPLICATE_5( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_4( m )

#define CPPX_DUPLICATE_4( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_3( m )

#define CPPX_DUPLICATE_3( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_2( m )

#define CPPX_DUPLICATE_2( m ) \
    CPPX_INVOKE_MACRO_B( m, () ) \
    CPPX_DUPLICATE_1( m )

#define CPPX_DUPLICATE_1( m ) \
    CPPX_INVOKE_MACRO_B( m, () )
/// @endcond
