#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

// Example usage:
//
//    struct Foo
//    {
//        virtual void something()
//        {}
//    };
//
//    class Bar: Extends_<Foo>
//    {
//        void something() override
//        {
//            Base_::something();
//            // + Bar-specific code here.
//        }
//    };

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_...
#include <iterator>     // std::forward

namespace cppx::definitions_ {
    CPPX_USE_STD( forward );

    template< class Base_class >
    class Base_:
        public Base_class
    {
    public:
        template< class... Args >
        Base_( Args&&... args ):
            Base_class( forward<Args>( args )... )
        {}
    };

    template< class Base_class >
    using Extends_ = Base_<Base_class>;

    namespace class_util_exports {
        CPPX_USE_FROM_NAMESPACE( definitions_,
            Base_,
            Extends_
        );
    }  // namespace class_util_exports
}  // namespace cppx::definitions_

namespace cppx::class_util      { using namespace definitions_::class_util_exports; }
namespace cppx::syntax          { using namespace definitions_::class_util_exports; }
namespace cppx                  { using namespace definitions_::class_util_exports; }
