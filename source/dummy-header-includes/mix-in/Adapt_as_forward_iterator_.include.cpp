#include <cppx-core-language/mix-in/Adapt_as_forward_iterator_.hpp>

using cppx::Truth;
namespace
{
    struct S: cppx::mix_in::Adapt_as_forward_iterator_<S, int>
    {
        void advance() {}
        friend auto operator==( S const&, S const& ) -> Truth { return true; }
    };

    const Truth  v1  = (S() != S());
    int satisfy_linker = 42;
}  // namespace <anon>
