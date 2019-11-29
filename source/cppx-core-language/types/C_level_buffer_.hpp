#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/syntax/type-builders.hpp>              // cppx::Type_
#include <cppx-core-language/system-dependent/size-types.hpp>       // cppx::Index

namespace cppx::c_level_stuff
{

    template< class Unit >
    class C_level_buffer_
    {
        Unit*       m_p_buffer;

    public:
        C_level_buffer( const Type_<Unit*> p_buffer ):
            m_p_buffer( p_buffer )
        {}
    };

} // namespace cppx::::c_level_stuff

namespace cppx {
    using namespace c_level_stuff;
}  // namespace cppx
