# The *cppx-core-language* micro library

Originally a sub-folder in the *cppx-core* project, the ***cppx-core-language*** header micro-library provides workarounds for various shortcomings of the C++ core language.

For example, the all-directions implicit conversions for the built-in `bool` type sometimes cause problems with overload resolution. One infamous case is that of iostreams output of a function pointer resulting in the text “1”, via an unexpected conversion to `bool`. *cppx-core-language* offers the alternative `cppx::Truth`, which converts implicitly only to and from `bool`, as a drop-in replacement.

Even if you don&rsquo;t use it for anything else you may find it useful to use a `vector<Truth>` instead of `vector<bool>`, because with the `vector<Truth>` you can have a reference or pointer to an item.

## 1. Installation & use.

After cloning, checking out or downloading the library:

1. Make the library source code available via C++ include path &ldquo;`cppx-core-language/`&rdquo;.  
   ***Info***: in Windows I prefer to use junctions in a common include folder. E.g., in that folder I&rsquo;d use the command `mklink /j cppx-core-language c:\somewhere\cppx-core-language\source\cppx-core-language`. With a junction you don't have to configure Windows to developer mode to create it, and you can remove it with an `rd` command, consistent with that command&rsquo;s use for other things that act like directories. However, in \*nix a symlink would be natural. But just copying the source folder is also fine.  
   ***Test***: for example, `#include <cppx-core-language/all.hpp>` should now work in C++ source code.

2. Ditto, make the &ldquo;C header wrappers&rdquo; source code available via C++ include path &ldquo;`c/`&rdquo;.  
   ***Info***: &ldquo;C header wrappers&rdquo; is a project that *cppx-core-language* depends on. You find it as a GIT sub-module in the folder &ldquo;dependencies&rdquo;.  
   ***Test***: For example, `#include <c/stdio.hpp>` should work.  

Test the installation with a simple C++ program using the include directive

>     #include <cppx-core-language/all.hpp>

This is a pure header library so you don't need to build or link with anything (other than the program itself).

However, the automated unit tests use the Boost Test framework and so running the automated unit tests additionally requires the Boost library.

----
#### *Disclaimer*

<img align="right" style="padding-left: 1em" src="images/under-construction.25-pct.png">

The library is still evolving, which means that *if* one wants to use the latest version everywhere, *and* one has used this library extensively, *and* e.g. a name changes in a new version, then there can be some cost of updating the client source code.

Use in student projects is fine.

Further work on this library is expected to be additions. Major changes in file locations or file names, or of C++ identifiers, will probably not happen.

## 2. Overview.

Each main area of functionality is a sub-folder in the library.

|Folder:     | Is about:  |
|------------|------------|
|[ascii](../source/ascii)    | ASCII text handling support, such as names of control characters (plus the name `bad_char` defined as `DEL`), ASCII range checking, widening, uppercasing and lowercasing, and whitespace checking and other classification functions. The C standard library defines some of this but in a form that&rsquo;s difficult to use correctly. For example, the *cppx-core-language* library's single code overload of `ascii::is_whitespace` (1) checks whether the code is in the ASCII range, and if so (2) casts it to unsigned `Byte` before passing it to the C library&rsquo;s `isspace`, because that function has UB for negative values other than `EOF`, and (3) casts the result from `int` to `bool`.
|[bit‑level](../source/bit%2Dlevel)   | Examples: `bits_per_`*`<T>`* gives the number of bits of a *`T`*-value, `intlog2` reports the position of the most significant 1-bit in an integer, and `sum_of_bits` reports the sum of the bits in an integer (note: in some contexts `sum_of_bits` is known as [&ldquo;pop-count&rdquo;](https://en.wikipedia.org/wiki/Hamming_weight)). |
|[calc](../source/calc)        | Calculations. Here is a header `<cppx-core-language/calc/stdlib-headers.hpp>` that includes all the relevant standard library calculation stuff, here are names of common constants such as *&pi;* (although C++20 will also provide that), floating point ops such as `squared`, `cubed` and `intpow`, and integer arithmetic ops such as `div_up` and `is_even` (and more). Plus a set of *consistent* numerical type properties, e.g. `min_<T>` is always the most negative value of type `T` and `smallest_<T>` is always the smallest absolute value of `T`.
|[meta‑macro](../source/meta%2Dmacro)  | Mainly support for defining macros with lists of arguments. For example, `CPPX_APPLY` invokes a specified single-argument macro with each argument in an arbitrarily long argument list (or, OK, up to 63 arguments). For convenience, although `$` in a name is formally non-standard, `CPPX_APPLY` can also be written as `$apply`, and ditto for other macros. |
|[syntax](../source/syntax)        | Mostly about *reduction of verbosity* for safe or best-practice constructs. For example, the `zero_to` function produces a `Sequence` which supports loops such as `for(const int i: zero_to(n))`, where there is no chance of inadvertent modification of the loop variable. With a reasonably good compiler it&rsquo;s as efficient as an ordinary counting loop &mdash; just less verbose and more safe. Some other syntax support is in the form of macros. E.g. `$use_std(A, B, C);` brings in the specified items from the standard library as if by `using std::A, std::B, std::C;`.  Perhaps of most practical utility to a new library user, here is `<<`-like support for assembling strings from parts. E.g. calls like `fail("Unable to open door "s << n)`. |
|[system](../source/system)      | System-dependent stuff. The type `Byte` + support; the enumeration `Endian` (more precisely it&rsquo;s a `struct` with an inner `enum`)  ; and the signed types `Size` and `Index` plus the corresponding `Unsigned_size` and `Unsigned_index`. These four are all the same size as `size_t`.
|[tmp](../source/tmp)         | Template meta-programming support, or just, support for defining templates. A number of type traits such as `is_integral_`, type modifiers such as `Unref_` and `Unsigned_`, and the class templates `Enable_if_`, `Type_choice_` and `Type_carrier_`. The two first templates are simple wrappers around `std::enable_if_t` and `std::conditional_t`, mostly for readability. |
|[type‑checking](../source/type%2Dchecking) | `downcasted_to` guarantees a downcast as opposed to a sideways cast, using a safe `dynamic_cast`; `is_of_derived_class` checks whether a pure downcast is possible; and `array_size_of` and `length_of_literal` do compile time size checking.  |
|[types](../source/types)        | The `Truth` type is a boolean that doesn't implicitly convert to or from anything other than `bool`; the `Int_` template alias lets you specify an integral type via its bit width; `C_str` and family are type names for simple `char` pointers, indicating use for C strings; and `No_copy` and `No_copy_or_move` can be used as base classes with the properties indicated by the names. Essentially these are types and names that are missing in the core language as of C++17.   |



## 3. Tutorial.

The code examples in this tutorial are all available via the “examples” top level folder.

### 3.1 An ASCII support example.

All three variants of this section&rsquo;s example produce the following hex-based ASCII code table:

~~~txt
       0   1   2   3   4   5   6   7   8   9   A   B   C   D   E   F

   0   □   □   □   □   □   □   □   □   □   □   □   □   □   □   □   □
   1   □   □   □   □   □   □   □   □   □   □   □   □   □   □   □   □
   2       !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
   3   0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
   4   @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
   5   P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
   6   `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
   7   p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~   □
~~~

For example, uppercase &ldquo;A&rdquo; is in row 4 column 1, which means that it's represented by ASCII code 41₁₆ = 4×16 + 1 = 65. Non-displayable characters, called *control characters*, are here depicted as small squares &ldquo;□&rdquo;, which is Unicode character U+25A1. It&rsquo;s used because the actual output&rsquo;s ASCII 127, which presents as nice rectangles in the console window, causes some formatting problems in the web browser&rsquo;s presentation of this README file.

First a pure standard C++ variant of the program:

<small>***examples/tutorial/ascii/ascii-table.stdlib.cpp***:</small>
~~~cpp
#include <ctype.h>          // ::isprint
#include <iomanip>          // std::setw
#include <iostream>
#include <limits.h>         // CHAR_MIN, UCHAR_MAX    

using Byte = unsigned char;

auto is_noncontrol_ascii( const int code )
    -> bool
{ return code >= CHAR_MIN and code <= UCHAR_MAX and ::isprint( Byte( code ) ); }

auto main()
    -> int
{
    using std::cout, std::endl, std::left, std::setw;

    const auto& hex_digits = "0123456789ABCDEF";
    const auto field = setw( 4 );
    const auto ascii_del = char( 127 );

    // Column headers.
    cout << field << "";
    for( int i = 0; i < 16; ++i ) { cout << field << hex_digits[i]; }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( int y = 0; y < 8; ++y ) {
        cout << field << hex_digits[y];
        for( int x = 0; x < 16; ++x ) {
            const int code = 16*y + x;
            const auto ch = char( is_noncontrol_ascii( code )? code: ascii_del );
            cout << field << ch;
        }
        cout << endl;
    }
}
~~~

In this code it's known that `is_noncontrol_ascii` is never called with an out-of-ASCII-range argument. And so, if one discards the source code after writing it and building then the checking in that function is a bit of overkill. However, such a function is *reusable* if it&rsquo;s safe enough, and that&rsquo;s one reason to add the argument checking: put in some effort up front, in order to save work later.

The *cppx-core-language* function `cppx::ascii::is_noncontrol` does such checking and is therefore a drop-in replacement for any such DIY function:

<small>***examples/tutorial/ascii/ascii-table.hybrid.cpp***:</small>
~~~cpp
#include <cppx-core-language/ascii/all.hpp>
#include <iomanip>          // std::setw
#include <iostream>

auto main()
    -> int
{
    using std::cout, std::endl, std::left, std::setw;
    using cppx::hex_digit;
    namespace ascii = cppx::ascii;

    const auto field = setw( 4 );
    
    // Column headers.
    cout << field << "";
    for( int i = 0; i < 16; ++i ) { cout << field << hex_digit( i ); }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( int y = 0; y < 8; ++y ) {
        cout << field << hex_digit( y );
        for( int x = 0; x < 16; ++x ) {
            const int code = 16*y + x;
            const auto ch = char( ascii::is_noncontrol( code )? code: ascii::del );
            cout << field << ch;
        }
        cout << endl;
    }
}
~~~

With use of the *cppx-core-language* library&rsquo;s ASCII support the code is already shorter and more clear.

This program uses just a specific part of the library, namely the ASCII support, so it includes &ldquo;cppx-core-language/ascii/all.hpp&rdquo;. Every folder has an &ldquo;***all.hpp***&rdquo; file that includes all headers in that folder. The top level &ldquo;all.hpp&rdquo; is just a special case, the one that happens to be at the root of the library.

I described the above as hybrid code because apart from the ASCII support it&rsquo;s the same as the pure standard C++ first version. But when one has installed *cppx-core-language* and uses some of it, then it&rsquo;s natural to also use its syntax support, which makes the code more readable, even shorter, and more safe to boot. More safe in that loop variables can then be `const`, which prevents inadvertent modification:

<small>***examples/tutorial/ascii/ascii-table.cpp***:</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iomanip>          // std::setw
#include <iostream>

auto main()
    -> int
{
    $use_std( cout, endl, left, setw );
    $use_cppx( zero_to, hex_digit );
    $alias_cppx_ns( ascii );
    
    const auto field = setw( 4 );

    // Column headers.
    cout << field << "";
    $repeat_times( 16 ) { cout << field << hex_digit( _i ); }
    cout << endl;
    cout << endl;               // Spacer line to make the header row stand out as such.
    
    // Main table with a row header column to the left.
    for( const int y: zero_to( 8 ) ) {
        cout << field << hex_digit( y );
        for( const int x: zero_to( 16 ) ) {
            const int code = 16*y + x;
            const auto ch = char( ascii::is_noncontrol( code )? code: ascii::del );
            cout << field << ch;
        }
        cout << endl;
    }
}
~~~

The brevity, readability and safety of this 3ʳᵈ version has a cost:

* One must learn the library&rsquo;s notation.

Every library effectively defines a notation and language, with action functions as verbs and inspection functions as pronouns, but usually this is limited to the stuff that the library specifically is about and doesn&rsquo;t affect the flow control structures. With *cppx-core-language* one can choose to express flow control structures in ways like above. Since e.g. use of range based `for` loops, especially with the *cppx-core-language*&rsquo;s `zero_to`, is still quite rare, it can be perceived as *foreign* or *alien*. Especially old-timers can perceive it as something not-C++-as-we&rsquo;ve-learned-to-know-it. The feedback I&rsquo;ve had about *cppx* in general is that this is problematic to old-timers, but not to fresh learners.

Anyway, in the above code the `$...` names are simple macros that do what they say they do. The $ naming is formally non-standard, but AFAIK it&rsquo;s accepted by all extant C++ compilers for desktop systems. It&rsquo;s possible to write e.g. `CPPX_USE_STD` instead of `$use_std`, and ditto (systematically) for other such names.

### 3.2 Syntax: a string argument building example.

Both variants of this section&rsquo;s example produce the following output:

~~~txt
One would expect that 1.23 + 4.56 = 5.79, not 5.790000!
However, integer arithmetic is exact; 2 + 2 = 4.
~~~

In this code imagine that `my::display` uses complex means to display the string in a message box pop up, rather than via `cout`. That way it serves a purpose and must be called, rather than just specifying the same action directly at the call site. Pure standard C++ code for this program can then go like this:

<small>***examples/tutorial/syntax/string-argument-formatting.stdlib.cpp***:</small>
~~~cpp
#include <iostream>         // std::(cout, endl)
#include <sstream>          // std::ostringstream
#include <string>           // std::(to_string, operator ""s)
#include <string_view>      // std::string_view

namespace my{
    using std::string_view, std::cout, std::endl;

    void display( const string_view& s )
    {
        cout << s << endl;
    }
}  // namespace my

auto main()
    -> int
{
    using std::ostringstream, std::to_string;

    const double    a   = 1.23;
    const double    b   = 4.56;
    
    ostringstream stream;
    stream
        << "One would expect that " << a << " + " << b << " = " << a + b
        << ", not " << to_string( a + b ) << "!";
    my::display( stream.str() );
    
    stream = ostringstream();       // Resets the stream object by move assigning.
    stream << "However, integer arithmetic is exact; 2 + 2 = " << 2 + 2 << ".";
    my::display( stream.str() );
}
~~~

Declaring one `ostringstream` variable for each call argument that needs some formatting, is awkward and verbose. Resetting one such object, as shown above, is just slightly less awkward and verbose. And that&rsquo;s the primary rationale for the *cppx-core-language*&rsquo;s argument string formatting support, *convenience* and *clarity*.

With this support you apply ordinary `<<` output notation to a `string` object, which can be a temporary.

A concise way to get an initial `string` object is to use the `"`&hellip;`"s` notation, which passes the string literal to the standard library&rsquo;s `operator""s`, which produces a `string`:

<small>***examples/tutorial/syntax/string-argument-formatting.cpp***:</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>         // std::(cout, endl)
#include <string>           // std::(to_string, operator ""s)
#include <string_view>      // std::string_view

namespace my{
    $use_std( string_view, cout, endl );

    void display( const string_view& s )
    {
        cout << s << endl;
    }
}  // namespace my

auto main()
    -> int
{
    using namespace cppx::basic_string_building;
    $use_std( to_string );

    const double    a   = 1.23;
    const double    b   = 4.56;
    
    my::display( ""s
        << "One would expect that " << a << " + " << b << " = " << a + b
        << ", not " << to_string( a + b ) << "!"
        );
    my::display( "However, integer arithmetic is exact; 2 + 2 = "s << 2 + 2 << "." );
}
~~~

Technical point 1: there is no $-macro for `using namespace`, because one doesn&rsquo;t ordinarily do that for more than a single namespace.

Technical point 2: the `cppx::basic_string_building` namespace supplies not just an `operator<<` overload but also the `std::operator""s`, otherwise one would have had to e.g. `using namespace std::literals;`.

Technical point 3: the formatting support is limited, hence &ldquo;basic&rdquo; in the name. In particular it doesn&rsquo;t support use of `std::endl`, and while use of other manipulators may compile they will not have any effect. However, `std::ostringstream` is used as a general fallback, and so custom formatting is automagically supported.

