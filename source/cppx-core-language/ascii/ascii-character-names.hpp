#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").

namespace cppx
{
    namespace ascii
    {
        // Standard but unfortunately uppercase abbreviations as per ASCII '67:
        const char      NUL         = '\0';         
        const char      BEL         = '\a';         
        const char      BS          = '\b';         
        const char      HT          = '\t';         // “Horizontal tab”
        const char      LF          = '\n';         
        const char      VT          = '\v';         // “Vertical tab”
        const char      FF          = '\f';         
        const char      CR          = '\r';         // “Carriage return”
        const char      DC1         = '\x11';       // “Device control 1”
        const char      DC3         = '\x13';       // “Device control 3”
        const char      SUB         = '\x1A';       // “Substitute”, but see below!
        const char      ESC         = '\x1B';       
        const char      SPC         = ' ';          
        const char      DEL         = '\x7F';       // “Delete”

        // More readable & self-describing names:
        const char      null        = NUL;          // '\0' 0x00
        const char      bell        = BEL;          // '\a' 0x07, ^G
        const char      backspace   = BS;           // '\b' 0x07, ^H
        const char      tab         = HT;           // '\t' 0x08, ^I, horizontal tab
        const char      linefeed    = LF;           // '\n' 0x09, ^J
        const char      vtab        = VT;           // '\v' 0x0A, ^K
        const char      formfeed    = FF;           // '\f' 0x0B, ^L
        const char      enter       = CR;           // '\r' 0x0C, ^M
        const char      xon         = DC1;          //      0x11, ^Q, "continue"
        const char      xoff        = DC3;          //      0x13, ^S, "stop"
        const char      end_of_text = SUB;          //      0x1A, ^Z, non-std MS meaning.
        const char      escape      = ESC;          //      0x1B
        const char      space       = SPC;          //      0x20
        const char      del         = DEL;          //      0x7F

        const char      first_char  = char( 0 );    static_assert( first_char == null );
        const char      max_value   = char( 127 );  static_assert( max_value == del );

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

        const char      bad_char    = del;

    }  // namespace ascii

    const char      std_ascii_bad_char      = ascii::end_of_text;       // Ungood.
    const wchar_t   std_unicode_bad_char    = L'\uFFFD';                // Ungood.

}  // namespace cppx
