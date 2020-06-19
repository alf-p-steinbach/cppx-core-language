#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>       // CPPX_USE_STD

#include <string>

namespace cppx::definitions_ {
    CPPX_USE_STD( string );

    namespace fp {
        struct Precision
        {
            int     n_digits;
        };

        struct Scheme { enum Enum{ smart, fix, sci, sci_uc }; };

        struct Format
        {
            Scheme::Enum    scheme;
            Precision       precision;
        };

        struct Format_spec
        {
            double          value;
            Format          format;
        };

        inline auto smart(
            const double        value,
            int                 n_digits        = 6
            ) -> Format_spec
        { return {value, {Scheme::smart, n_digits}}; }

        inline auto fixed(
            const double        value,
            int                 n_digits        = 6
            ) -> Format_spec
        { return {value, {Scheme::fix, n_digits}}; }

        inline auto scientific(
            const double        value,
            int                 n_digits        = 6
            ) -> Format_spec
        { return {value, {Scheme::sci, n_digits}}; }


        inline auto scientific_uc(
            const double        value,
            int                 n_digits        = 6
            ) -> Format_spec
        { return {value, {Scheme::sci_uc, n_digits}}; }
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

    namespace format_specs_exports {
        namespace fp        = definitions_::fp;
        namespace integral  = definitions_::integral;
    }  // namespace format_specs_exports
}  // namespace cppx::definitions_

namespace cppx::format_specs    { using namespace cppx::definitions_::format_specs_exports; }
namespace cppx::text            { using namespace cppx::definitions_::format_specs_exports; }
namespace cppx::syntax          { using namespace cppx::definitions_::format_specs_exports; }
namespace cppx                  { using namespace cppx::definitions_::format_specs_exports; }
