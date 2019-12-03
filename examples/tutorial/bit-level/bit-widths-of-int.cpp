#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main() -> int
{
    static const auto& s =
        "Data addresses in this process are %d-bit.\n"
        "\n"
        "With this compiler an `int` is %d bits. %d of those are value representation\n"
        "bits, and of those again %d bits encode the magnitude.\n";

    using namespace cppx;
    printf( s,
        Bitness::system, bits_per_<int>, value_bits_per_<int>, magnitude_bits_per_<int>
        );
}
