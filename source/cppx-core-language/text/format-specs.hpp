#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>      // CPPX_USE_STD

#include <string>

namespace cppx::_ {
    CPPX_USE_STD( string );

    namespace fp {
        struct Precision
        {
            int     n_digits;
        };

        struct Scheme { enum Enum{ general, fixed, scientific, scientific_uc }; };

        struct Format
        {
            Scheme::Enum    scheme;
            Precision       precision;
        };

        struct Formatted
        {
            double          value;
            Format          format;
        };

        inline auto general(
            const double        value,
            int                 n_digits        = 6
            ) -> Formatted
        { return {value, {Scheme::general, n_digits}}; }

        inline auto fixed(
            const double        value,
            int                 n_digits        = 6
            ) -> Formatted
        { return {value, {Scheme::fixed, n_digits}}; }

        inline auto scientific(
            const double        value,
            int                 n_digits        = 6
            ) -> Formatted
        { return {value, {Scheme::scientific, n_digits}}; }


        inline auto scientific_uc(
            const double        value,
            int                 n_digits        = 6
            ) -> Formatted
        { return {value, {Scheme::scientific_uc, n_digits}}; }
    }  // namespace fp

    namespace integral {
        struct Digit_grouping
        {
            int     group_size;
            string  delimiter;
        };

        struct Format
        {
            Digit_grouping  grouping;
        };
    }  // namespace integral

}  // namespace cppx::_

// Exporting namespaces
namespace cppx {
    namespace format_specs {
        namespace fp        = cppx::_::fp;
        namespace integral  = cppx::_::integral;
    }  // namespace format_specs

    // Convenience inclusion.
    namespace syntax {
        using namespace format_specs;
    }  // namespace syntax

    using namespace format_specs;
}  // namespace cppx
