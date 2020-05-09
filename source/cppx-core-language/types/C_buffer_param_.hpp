#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

#include <cppx-core-language/syntax/type-builders.hpp>                  // cppx::(Type_, Raw_array_of_)
#include <cppx-core-language/types/system-dependent/size-types.hpp>     // cppx::(Index, Size )

namespace cppx::c_level_stuff
{
    template<
        class A_unit,
        Size a_size_per_unit,
        Size an_adjustment = 0
        >
    class C_buffer_param_
    {
    public:
        using Unit = A_unit;
        static constexpr Size size_per_unit     = a_size_per_unit;
        static constexpr Size size_adjustment   = an_adjustment;

    private:
        Unit*       m_p_buffer;

    public:
        auto ptr() const -> Unit* { return m_p_buffer; }
        operator Unit*() const { return ptr(); }

        static constexpr auto size_for_1()
            -> Size
        { return size_per_unit + size_adjustment; }

        static constexpr auto size_for( const Size n_units )
            -> Size
        { return n_units*size_per_unit + size_adjustment; }

        explicit C_buffer_param_( const Type_<Unit*> p_buffer ):
            m_p_buffer( p_buffer )
        {}

        template< Size n >
        C_buffer_param_( const Size n_units, Raw_array_of_<n, Unit>& buffer ):
            m_p_buffer( buffer )
        { 
            static_assert( n >= size_for( n_units ) );
        }
    };
} // namespace cppx::::c_level_stuff

namespace cppx {
    using namespace c_level_stuff;
}  // namespace cppx
