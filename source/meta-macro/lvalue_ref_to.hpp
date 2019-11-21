#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief Provides the `lvalue_ref_to` helper for restricting macro arguments.

namespace cppx
{
    /// A helper for restricting macro arguments, used e.g. in `$items_of`.
    template< class Type >
    inline auto lvalue_ref_to( Type& c )
        -> Type&
    { return c; }

}  // namespace cppx
