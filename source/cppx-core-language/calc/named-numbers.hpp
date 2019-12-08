#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// Common math/calculator constants:
/// \make_name_ref{cppx,e},
/// \make_name_ref{cppx,log2e},
/// \make_name_ref{cppx,log10e},
/// \make_name_ref{cppx,ln2},
/// \make_name_ref{cppx,ln10},
/// \make_name_ref{cppx,pi},
/// \make_name_ref{cppx,inv_sqrt_pi},
/// \make_name_ref{cppx,sqrt2},
/// \make_name_ref{cppx,inv_sqrt2},
/// \make_name_ref{cppx,has_nan_} and \make_name_ref{cppx,has_nan},
/// \make_name_ref{cppx,nan_} and \make_name_ref{cppx,nan},
/// \make_name_ref{cppx,has_infinity_} and \make_name_ref{cppx,has_infinity}, and
/// \make_name_ref{cppx,infinity_} and \make_name_ref{cppx,infinity}.

#include <cppx-core-language/syntax/macro-use.hpp>
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

#include <c/math.hpp>
#include <limits>           // std::numeric_limits

namespace cppx::definitions {
    CPPX_USE_STD( numeric_limits );

#ifdef M_PI
    constexpr auto e                = M_E;              // e              2.71828182845904523536
    constexpr auto log2e            = M_LOG2E;          // log2(e)        1.44269504088896340736
    constexpr auto log10e           = M_LOG10E;         // log10(e)       0.434294481903251827651
    constexpr auto ln2              = M_LN2;            // ln(2)          0.693147180559945309417
    constexpr auto ln10             = M_LN10;           // ln(10)         2.30258509299404568402
    constexpr auto pi               = M_PI;             // pi             3.14159265358979323846
                                                    // pi/2 M_PI_2    1.57079632679489661923
                                                    // pi/4 M_PI_4    0.785398163397448309616
                                                    // 1/pi M_1_PI    0.318309886183790671538
                                                    // 2/pi M_2_PI    0.636619772367581343076
    constexpr auto inv_sqrt_pi      = M_2_SQRTPI/2;     // 2/sqrt(pi)     1.12837916709551257390
    constexpr auto sqrt2            = M_SQRT2;          // sqrt(2)        1.41421356237309504880
    constexpr auto inv_sqrt2        = M_SQRT1_2;        // 1/sqrt(2)      0.707106781186547524401
#else
    constexpr auto e                = 2.71828182845904523536;
    constexpr auto log2e            = 1.44269504088896340736;
    constexpr auto log10e           = 0.434294481903251827651;
    constexpr auto ln2              = 0.693147180559945309417;
    constexpr auto ln10             = 2.30258509299404568402;
    constexpr auto pi               = 3.14159265358979323846;
                                    //1.57079632679489661923
                                    //0.785398163397448309616
                                    //0.318309886183790671538
                                    //0.636619772367581343076
    constexpr auto inv_sqrt_pi      = 1.12837916709551257390;
    constexpr auto sqrt2            = 1.41421356237309504880;
    constexpr auto inv_sqrt2        = 0.707106781186547524401;
#endif
    template< class Number>
    constexpr Truth has_nan_        = numeric_limits<Number>::has_quiet_NaN;

    constexpr Truth has_nan         = has_nan_<double>;

    template< class Number>
    constexpr Truth has_infinity_   = numeric_limits<double>::has_infinity;

    constexpr Truth has_infinity    = has_infinity_<double>;

    template< class Number >
    constexpr auto nan_()
        -> Number
    { return numeric_limits<Number>::quiet_NaN(); }

    constexpr inline auto nan()
        -> double
    { return nan_<double>(); }

    template< class Number >
    constexpr auto infinity_()
        -> Number
    { return numeric_limits<Number>::infinity(); }

    constexpr inline auto infinity()
        -> double
    { return infinity_<double>(); }

}  // namespace cppx::definitions

// Exporting namespaces.
namespace cppx {
    namespace m {
        CPPX_USE_CPPX(
            definitions::e,
            definitions::log2e,
            definitions::log10e,
            definitions::ln2,
            definitions::ln10,
            definitions::pi,
            definitions::inv_sqrt_pi,
            definitions::sqrt2,
            definitions::inv_sqrt2,

            definitions::has_nan_,
            definitions::has_nan,
            definitions::nan_,
            definitions::nan,
            definitions::has_infinity_,
            definitions::has_infinity,
            definitions::infinity_,
            definitions::infinity
        );
    }  // namespace m
    // Intentionally not placed in namespace `calc` or directly in `cppx`, avoid collisions.

}  // namespace cppx
