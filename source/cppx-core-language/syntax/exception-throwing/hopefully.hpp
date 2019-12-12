#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/macro-use.hpp>          // CPPX_USE_STD
#include <cppx-core-language/types/Truth.hpp>               // cppx::Truth

namespace cppx::_ {

    //------------------------------------------ hopefully
    //
    // Typical usage pattern:
    //
    //      const Size n_values = to_wide_from_utf8( &s[0], &wide_s[0] );
    //      hopefully( n_values >= 0 )
    //          or fail( "foo - to_wide_from_utf8 failed" );
    //      wide_s.resize( n_values );

    inline auto hopefully( const Truth condition )
        -> Truth
    { return condition; }

}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace x_throwing {
        using _::hopefully;
    }  // namespace x_throwing

    using namespace x_throwing;
}  // namespace cppx
