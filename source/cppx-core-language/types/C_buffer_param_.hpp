#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/type-builders.hpp>              // cppx::(Type_, Raw_array_of_)
#include <cppx-core-language/system-dependent/size-types.hpp>       // cppx::(Index, Size )

namespace cppx::c_level_stuff
{
    template< class A_unit, Size a_minimum_size >
    class C_buffer_param_
    {
    public:
        using Unit = A_unit;
        static constexpr Size minimum_size = a_minimum_size;

    private:
        Unit*       m_p_buffer;

    public:
        auto ptr() const -> Unit* { return m_p_buffer; }
        operator Unit*() const { return ptr(); }

        explicit C_buffer_param_( const Type_<Unit*> p_buffer ):
            m_p_buffer( p_buffer )
        {}

        template< Size n >
        C_buffer_param_( Raw_array_of_<n, Unit>& buffer ):
            m_p_buffer( buffer )
        { 
            static_assert( n >= minimum_size );
        }
    };
} // namespace cppx::::c_level_stuff

namespace cppx {
    using namespace c_level_stuff;
}  // namespace cppx
