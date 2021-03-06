﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief Concise, clear & consistent notation for number type properties:
/// \make_name_ref{cppx,is_ieee754_format_},
/// \make_name_ref{cppx,largest_},
/// \make_name_ref{cppx,smallest_},
/// \make_name_ref{cppx,max_},
/// \make_name_ref{cppx,min_},
/// \make_name_ref{cppx,max_exp_},
/// \make_name_ref{cppx,min_exp_},
/// \make_name_ref{cppx,n_digits_},
/// \make_name_ref{cppx,radix_} and
/// \make_name_ref{cppx,epsilon_}.
///
/// The `std::numeric_limits` facility is very verbose, has in part cryptic names, is
/// non-systematic in what values mean for different kinds of types, and needlessly
/// (and bafflingly for one without historical knowledge of C++) expresses integral
/// values as values but floating point type values as functions that must be invoked.
/// Hence this more consistent and easy-to-use, but limited, facility.

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_STD, CPPX_USE_CPPX
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

#include <limits>       // std::numeric_limits
#include <type_traits>  // std::is_integral_v

namespace cppx::_ {
    /// @cond DOXY_SHOW_IMPL_DETAILS
    CPPX_USE_STD( conditional_t );

    namespace impl
    {
        template< class T > using Info_ = std::numeric_limits<T>;

        template< class T, bool is_integral_type = std::is_integral_v<T> >  // "bool" until C++20.
        struct Number_properties_;

        template< class T >
        struct Number_properties_<T, true>    // Integral types
        {
            static_assert( std::is_integral_v<T> );

            static constexpr T      smallest            = 1;                // Smallest non-zero.
            static constexpr T      largest             = Info_<T>::max();
            static constexpr T      min                 = Info_<T>::min();  // 0 or `-largest_ - 1`.
            static constexpr T      max                 = largest;
            static constexpr int    n_digits            = Info_<T>::digits10;
        };

        template< class T >
        struct Number_properties_<T, false>    // Floating point and fixed point types
        {
            static_assert( not std::is_integral_v<T> );

            static constexpr T      smallest            = Info_<T>::min();  // Smallest non-zero.
            static constexpr T      largest             = Info_<T>::max();
            static constexpr T      min                 = -largest;         // Largest negative.
            static constexpr T      max                 = largest;
            static constexpr int    n_digits            = Info_<T>::digits10;

            static constexpr Truth  is_ieee754_format   = Info_<T>::is_iec559;
            static constexpr int    min_exp             = Info_<T>::min_exponent10;
            static constexpr int    max_exp             = Info_<T>::max_exponent10;
            static constexpr int    radix               = Info_<T>::radix;
            static constexpr T      epsilon             = Info_<T>::epsilon();
        };

        //TODO: good isnan()
    }  // namespace impl
    /// @endcond

    /// \brief The property values as members of class, so that they can be inherited in.
    template< class Type >
    struct Number_properties_;
    
    /// @cond DOXY_SHOW_IMPL_DETAILS
        template< class Type >
        struct Number_properties_: impl::Number_properties_<Type> {};
    /// @endcond

    /// \hideinitializer
    /// \brief The smallest non-zero absolute value of the type.
    ///
    /// For integer `T` this is just 1, and for floating point `T` the expression
    /// `smallest_<T>` is an alias for `std::numeric_limits<T>::min()`.
        template< class T > constexpr T smallest_       = Number_properties_<T>::smallest;

    /// \hideinitializer
    /// \brief The largest representable-as-positive absolute value of the type.
    ///
    /// `largest_<T>` is an alias for `std::numeric_limits<T>::max()`.
    template< class T > constexpr T     largest_        = Number_properties_<T>::largest;

    /// \hideinitializer
    /// \brief The largest (yes, the largest) negative value of the type.
    ///
    /// For integer `T` the expression `min_<T>` is an alias for
    /// `std::numeric_limits<T>::min()`, which is usually/always `-largest_<T> - 1`.
    ///
    /// For floating point `T` the expression `min_<T>` is an alias for `-largest_<T>`.
    template< class T > constexpr T     min_            = Number_properties_<T>::min;

    /// \hideinitializer
    /// \brief The largest positive value of the type.
    ///
    /// The expression `max_<T>` is an alias for `largest_<T>`.
    template< class T > constexpr T     max_            = Number_properties_<T>::max;

    /// \hideinitializer
    /// \brief Number of decimal digits that guaranteed can be represented.
    ///
    /// The expression `n_digits_<T>` is an alias for `std::numeric_limits<T>::digits10`.
    template< class T > constexpr int   n_digits_       = Number_properties_<T>::n_digits;

    /// \hideinitializer
    /// \brief FP only. Whether the implementation claims to conform to the IEEE 754 standard.
    ///    
    /// `is_ieee_754_<T>` is an alias for `std::numeric_limits<T>::is_iec559`.
    ///
    /// IEC 559 is just the European name of the IEEE 754 floating point standard.
    ///
    /// Note that (at the writing of this documentation) both the Visual C++ and g++
    /// compilers report IEEE 754 conformance when their fast-math options are used, which
    /// in particular causes incorrect NaN-checking, i.e. non-conformance.
    template< class T > constexpr Truth is_ieee754_format_  =
        Number_properties_<T>::is_ieee754_format;

    /// \hideinitializer
    /// \brief FP only. E-notation minimum (largest negative) exponent value.
    ///
    /// The expression `min_exp_<T>` is an alias for
    /// `std::numeric_limits<T>::min_exponent10`.
    template< class T > constexpr int   min_exp_        = Number_properties_<T>::min_exp;

    /// \hideinitializer
    /// \brief FP only. E-notation maximum (largest positive) exponent value.
    ///
    /// The expression `max_exp_<T>` is an alias for
    /// `std::numeric_limits<T>::max_exponent10`.
    template< class T > constexpr int   max_exp_        = Number_properties_<T>::max_exp;

     /// \hideinitializer
    /// \brief FP only. The numeral system base of the floating point representation,
    /// 2 or 10.
    ///
    /// The C++ standard requires integer types to be represented in binary, as either
    /// two's complement (now universal), ones' complement or sign and magnitude. From
    /// C++20 it will require two's complement form. However, it allows a floating point
    /// type to use a representation in some other numeral system such as 10, decimal.
    ///
    /// The expression `radix_<T>` is an alias for `std::numeric_limits<T>::radix`.
    template< class T > constexpr int   radix_          = Number_properties_<T>::radix;

    /// \hideinitializer
    /// \brief The difference between 1 and the least floating point value greater than 1.
    ///
    /// The expression `epsilon_<T>` is an alias for `std::numeric_limits<T>::epsilon()`.
    template< class T > constexpr T     epsilon_        = Number_properties_<T>::epsilon;

}  // namespace cppx::_

// Exporting namespaces.
namespace cppx {
    namespace calc {
        CPPX_USE_CPPX(
            _::smallest_,
            _::largest_,
            _::min_,
            _::max_,
            _::n_digits_,
            _::is_ieee754_format_,
            _::min_exp_,
            _::max_exp_,
            _::radix_,
            _::epsilon_
        );
    }  // namespace calc

    using namespace calc;
}  // namespace cppx
