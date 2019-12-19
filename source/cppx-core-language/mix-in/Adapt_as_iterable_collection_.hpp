#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_...
#include <cppx-core-language/system-dependent/size-types.hpp>   // cppx::Size
#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

#include <iterator>

namespace cppx::_ {
    CPPX_USE_STD( make_reverse_iterator );

    template< class Derived >
    class Adapt_as_iterable_collection_
    {
        auto self()
            -> Derived&
        { return static_cast<Derived&>( *this ); }

        auto const_self() const
            -> const Derived&
        { return static_cast<const Derived&>( *this ); }

    public:
        // Standard library & core language naming convention adapters.
        // Based on Derived::(first, beyond, is_empty, n_items).

        auto begin()            -> auto     { return self().first(); }
        auto begin() const      -> auto     { return const_self().first(); }
        auto cbegin() const     -> auto     { return const_self().first(); }

        auto end()              -> auto     { return self().beyond(); }
        auto end() const        -> auto     { return const_self().beyond(); }
        auto cend() const       -> auto     { return const_self().beyond(); }

        auto rbegin()           -> auto     { return make_reverse_iterator( self().beyond() ); }
        auto rbegin() const     -> auto     { return make_reverse_iterator( const_self().beyond() ); }
        auto crbegin() const    -> auto     { return make_reverse_iterator( const_self().beyond() ); }

        auto rend()             -> auto     { return make_reverse_iterator( self().first() ); }
        auto rend() const       -> auto     { return make_reverse_iterator( const_self().first() ); }
        auto crend() const      -> auto     { return make_reverse_iterator( const_self().first() ); }

        auto empty() const      -> Truth    { return const_self().is_empty(); }
        auto size() const       -> Size     { return const_self().n_items(); }
    };
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
