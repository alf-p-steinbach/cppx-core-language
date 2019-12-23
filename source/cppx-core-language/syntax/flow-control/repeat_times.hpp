#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_STD
#include <cppx-core-language/system-dependent/size-types.hpp>   // cppx::(Index, Size)

namespace cppx::_ {
    CPPX_USE_STD( forward );

    template< class Func, class... Args >
    inline void repeat_times( const Size n, const Func& f, Args&&... args )
    {
        for( Index i = 0; i < n; ++i ) {
            f( forward<Args>( args )... );
        }
    }
}  // namespace cppx::_

// Exporting namespaces:
namespace cppx {
    namespace syntax {
        CPPX_USE_FROM_NAMESPACE( _, repeat_times );
    }  // namespace syntax

    using namespace syntax;
}  // namespace cppx
