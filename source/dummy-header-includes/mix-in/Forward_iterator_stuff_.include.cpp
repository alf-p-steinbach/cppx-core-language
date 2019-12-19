#include <cppx-core-language/mix-in/Forward_iterator_stuff_.hpp>

using cppx::Truth;
namespace
{
    struct S: cppx::mix_in::Forward_iterator_stuff_<S, int>
    {
        void advance() {}
        friend auto operator==( S const&, S const& ) -> Truth { return true; }
    };

    const Truth  v1  = (S() != S());
    int satisfy_linker = 42;
}  // namespace <anon>
