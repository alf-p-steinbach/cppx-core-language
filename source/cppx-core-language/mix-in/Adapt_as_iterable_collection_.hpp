#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_...

namespace cppx::_ {
    template< class Derived >
    class Adapt_as_iterable_collection_
    {};
}  // namespace cppx::_


// Exporting namespaces
namespace cppx {
    namespace mix_in {
        CPPX_USE_FROM_NAMESPACE( _,
            Adapt_as_iterable_collection_
        );
    }  // namespace with

    using namespace mix_in;
}  // namespace cppx
