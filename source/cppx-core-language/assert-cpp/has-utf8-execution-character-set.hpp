#pragma once    // Source encoding: UTF_8 with BOM (π is a lowercase Greek "pi").

namespace uuid_344a6b2a_64d6_4152_9e71_de4e73ab8b1a {
    constexpr inline auto utf8_is_the_execution_character_set()
        -> bool
    {
        constexpr auto& slashed_o = "ø";
        return (sizeof( slashed_o ) == 3 and slashed_o[0] == '\xC3' and slashed_o[1] == '\xB8');
    }

    static_assert(
        utf8_is_the_execution_character_set(),
        "The execution character set must be UTF_8 (e.g. MSVC option \"/utf_8\")."
        );
}  // namespace uuid_344a6b2a_64d6_4152_9e71_de4e73ab8b1a
