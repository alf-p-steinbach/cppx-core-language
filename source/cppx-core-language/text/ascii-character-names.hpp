﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>

namespace cppx::text::ascii {
    // Standard but unfortunately uppercase abbreviations as per ASCII '67:
    constexpr char      NUL         = '\0';         
    constexpr char      BEL         = '\a';         
    constexpr char      BS          = '\b';         
    constexpr char      HT          = '\t';         // “Horizontal tab”
    constexpr char      LF          = '\n';         
    constexpr char      VT          = '\v';         // “Vertical tab”
    constexpr char      FF          = '\f';         
    constexpr char      CR          = '\r';         // “Carriage return”
    constexpr char      DC1         = '\x11';       // “Device control 1”
    constexpr char      DC3         = '\x13';       // “Device control 3”
    constexpr char      SUB         = '\x1A';       // “Substitute”, but see below!
    constexpr char      ESC         = '\x1B';       
    constexpr char      SPC         = ' ';          
    constexpr char      DEL         = '\x7F';       // “Delete”

    // More readable & self-describing names:
    constexpr char      null        = NUL;          // '\0' 0x00
    constexpr char      bell        = BEL;          // '\a' 0x07, ^G
    constexpr char      backspace   = BS;           // '\b' 0x07, ^H
    constexpr char      tab         = HT;           // '\t' 0x08, ^I, horizontal tab
    constexpr char      linefeed    = LF;           // '\n' 0x09, ^J
    constexpr char      vtab        = VT;           // '\v' 0x0A, ^K
    constexpr char      formfeed    = FF;           // '\f' 0x0B, ^L
    constexpr char      enter       = CR;           // '\r' 0x0C, ^M
    constexpr char      xon         = DC1;          //      0x11, ^Q, "continue"
    constexpr char      xoff        = DC3;          //      0x13, ^S, "stop"
    constexpr char      end_of_text = SUB;          //      0x1A, ^Z, non-std MS meaning.
    constexpr char      escape      = ESC;          //      0x1B
    constexpr char      space       = SPC;          //      0x20
    constexpr char      del         = DEL;          //      0x7F

    constexpr char      first_char  = char( 0 );    static_assert( first_char == null );
    constexpr char      max_value   = char( 127 );  static_assert( max_value == del );
    constexpr int       n_values    = max_value + 1;

    // ASCII DEL, code 0x7F = 127, “delete”, can be used as a replacement for encoding
    // errors or unrepresentable code point.
    //
    // ASCII has a character dedicated to the purpose: SUB “substitute”, code 26,
    // ^Z. But in Windows ^Z is used as an EOF marker for text streams. So ^Z as
    // replacement is not usable in Windows, i.e. it's not a general solution.
    //
    // Unicode, an extension of ASCII, also has its own character dedicated to
    // the purpose, namely code U+FFFD “replacement character”. It translates to
    // at least two UTF-8 bytes so it's not trivial to check for. And it can't be
    // represented in simple single byte encodings such as codepage 437, so it's
    // not usable in single byte encodings, i.e. it's not a general solution.
    //
    // Using ASCII DEL as a replacement character does not preclude using it also to
    // represent the DEL key in a keyboard interface, for in that context there is no
    // possibility of encoding errors or unrepresentable code point. It doesn't appear
    // in ordinary text. And it even has some mnemonic value as a deleted character.
    //
    // For these reasons I recommend using ASCII DEL as replacement and error
    // indication character:

    constexpr char      bad_char    = del;
}  // namespace cppx::text::ascii

// Exporting namespaces:
namespace cppx {
    using namespace text;
}
   
// Additional strongly related info but not specifically ASCII:
namespace cppx{
    constexpr char      std_ascii_bad_char      = ascii::end_of_text;       // Ungood.
    constexpr wchar_t   std_unicode_bad_char    = L'\uFFFD';                // Ungood.
}
