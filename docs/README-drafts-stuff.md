

xxx

# x. The syntax support.

The syntax support is about

* reducing verbosity,
* reducing complexity (generally by imposing constraints), and
* increasing readability.

For example, simple counting loops are very common, and a counting loop

>     for( int i = 0, n = expression; i < n; ++i ) {
>         cout << "iteration " << i + 1 << " of " << n << endl;
>     }

… can be expressed as

>     $repeat_times( expression ) {
>         cout << "iteration " << _i + 1 << " of " << _n << endl;
>     }

… where `_i` and `_n` are `const` within the loop body.

Advantages wrt. verbosity, complexity and readability:

* it’s shorter code,
* the number of variables the code must handle and update correctly is reduced from 2 to 0, and now the code can’t inadvertently change a variable, and
* it’s English rather than a jumble of operators.

As the above shows some of the syntax support is in the form of macros (here `$repeat_times`). Macros are for the cases where systematic text generation is necessary, and/or where the best alternative would be too complex, ugly or verbose. In some cases, and this is one, it’s up to the library user to choose whether to use a macro such as `$repeat_times` or instead a function such as `one_through`, which produces an efficiently iterable `Sequence`:

>     const int n = expression;
>     for( const int count: one_through( n ) ) {
>         cout << "iteration " << count << " of " << n << endl;
>     }

Avoiding a macro generally increases verbosity and reduces constraints. As an example of what reduced constraints is about, why that’s undesirable, the `goto` statement is very unconstrained compared to structured control statements such as `while` and `for`. And just as use of unconstrained `goto` can encourage bugs to enter, so use of unconstrained non-macro alternatives can encourage bugs to enter.

However, the syntax support is ***not*** about replacing perfectly good C++ constructs with e.g. favorite Ada keywords, just for readability, or that sort of thing.

For example, C++ has an idiomatic construct `for(;;)` for expressing an infinite loop. It’s a bit cryptic to a beginner so readability could be improved by a macro, but against that: by adding a layer of indirection complexity would be increased instead of reduced, and verbosity would be increased or at least not much reduced. So there’s no `$loop` macro, or the sort.

Costs:

* A reader — especially an old-timer — unfamiliar with `$repeat_times` may balk at the code, perceiving it as foreign or alien, not the C++ that we learned, etc. etc.
* As far as I know all extant desktop system C++ compilers support &ldquo;$&rdquo; in names, but reportedly at least one compiler for an embedded device does not.
* For macros that take an arbitrary number of arguments, such as `$use_std`, misspelling a name in the argument list may cause the compiler to emit a *diagnostics avalanche* (just as with template errors) where it delves into many levels of nested macro calls.

To address the not perfect portability of “$” one can write `CPPX_REPEAT_TIMES` instead of `$repeat_times`, and ditto for other macros, and define **`CPPX_NO_DOLLARS_PLEASE`** to avoid even an attempted definition of `$repeat_times`. Or, easier, just don't use the library with the embedded device compiler that balks at “$”. One way is to not use that compiler.

With the costs summarized like above they may seem excessive, but in practice, for my own hobby programming I&rsquo;ve found the actual costs to be roughly zero.

The syntax support presented here has been honed down from a much larger set I devised. I’ve only kept the stuff that I’m actually using, or strongly related to that. In my experience over the years I’ve experimented with this, in the end it makes for less work and more pleasant coding.

#### 3.1.1 Syntax support for loops: `Sequence`, `zero_to`, `$repeat_times`.



asdasd

----

Both variants of this section&rsquo;s example produce the following output:

~~~txt
One would expect that 1.23 + 4.56 = 5.79, not 5.790000!
However, integer arithmetic is exact; 2 + 2 = 4.
~~~

In the following purely standard C++ code imagine that `my::display` uses complex means to display the string in a message box pop up, rather than via `cout`. That way it serves a purpose and must be called, rather than just specifying the same action directly at the call site. Then it can go like this:

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

Declaring one `ostringstream` variable for each call argument that needs some formatting, is awkward and verbose. Resetting one such object, as shown above, is just slightly less awkward and verbose. And that&rsquo;s the primary rationale for the Core Language Extensions&rsquo;s argument string formatting support, *convenience* and *clarity*.

With this support you apply ordinary `<<` output notation to a `string` object, which can be a temporary.

A concise way to get an initial `string` object is to use the `"`&hellip;`"s` notation, which passes the string literal to the standard library&rsquo;s `operator""s`, which produces a `string`:

<small>***examples/tutorial/syntax/string-argument-formatting.hybrid.cpp***:</small>
~~~cpp
#include <cppx-core-language/syntax/basic-string-building.hpp>
#include <iostream>         // std::(cout, endl)
#include <string>           // std::to_string
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
    using namespace cppx::basic_string_building;
    using std::to_string;

    const double    a   = 1.23;
    const double    b   = 4.56;
    
    my::display( ""s
        << "One would expect that " << a << " + " << b << " = " << a + b
        << ", not " << to_string( a + b ) << "!"
        );
    my::display( "However, integer arithmetic is exact; 2 + 2 = "s << 2 + 2 << "." );
}
~~~

Here the `cppx::basic_string_building` namespace supplies not just an `operator<<` overload but also the `std::operator""s`, otherwise one would have had to e.g. `using namespace std::literals;`.

The formatting support is quite limited, hence &ldquo;basic&rdquo; in the name. In particular it doesn&rsquo;t support use of `std::endl`, and while use of other manipulators may compile they will not have any effect. However, `std::ostringstream` is used as a general fallback, and so custom formatting is automagically supported.

### 3.2. Syntax: `$use_std`.

The last program’s `using`-declaration

>     using std::string_view, std::cout, std::endl;

… is ungood in two ways:

* Verbosity: it repeats `std::` as many times as there are names to import.
* Unconstrained: one is free to import names from a mix of namespaces, in the same comma-list, which makes it harder to see what’s coming from a particular namespace.

The Core Language Extension macro `$use_std` addresses both points, allowing you to write just

>     $use_std( string_view, cout, endl );

Here’s the program modified to use this shorter and constrained-to-one-namespace form also for the second `using`-declaration:

<small>***examples/tutorial/syntax/string-argument-formatting.cpp***:</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>         // std::(cout, endl)
#include <string>           // std::to_string
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

xxx



The third point, diagnostics avalanche, is also a problem with template code. Every practicing C++ programmer is familiar with diagnostics avalanches! And it’s partly due to C++ language deficiencies (in this case, no macro apply operation) that cause high level concepts to be implemented in terms of limited operations that are all the compiler knows, and partly due to a common C++ tooling deficiency, namely no smart diagnostics presentation.

I find that in my personal programming the costs are near to non-existent so that `$use_std` is well worth it.


asdasd

---


### 3.x An ASCII support example.

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

<small>***examples/tutorial/text/ascii-table.stdlib.cpp***:</small>
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

The Core Language Extensions function `cppx::ascii::is_noncontrol` does such checking and is therefore a drop-in replacement for any such DIY function:

<small>***examples/tutorial/text/ascii-table.hybrid.cpp***:</small>
~~~cpp
#include <cppx-core-language/text/all.hpp>
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

With use of the Core Language Extensions library&rsquo;s ASCII support the code is already shorter and more clear.

This program uses just a specific part of the library, namely the ASCII support, so it includes &ldquo;cppx-core-language/text/all.hpp&rdquo;. Every folder has an &ldquo;***all.hpp***&rdquo; file that includes all headers in that folder. The top level &ldquo;all.hpp&rdquo; is just a special case, the one that happens to be at the root of the library.

I described the above as hybrid code because apart from the ASCII support it&rsquo;s the same as the pure standard C++ first version. But when one has installed Core Language Extensions and uses some of it, then it&rsquo;s natural to also use its syntax support, which makes the code more readable, even shorter, and more safe to boot. More safe in that loop variables can then be `const`, which prevents inadvertent modification:

<small>***examples/tutorial/text/ascii-table.cpp***:</small>
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

Every library effectively defines a notation and language, with action functions as verbs and inspection functions as pronouns, but usually this is limited to the stuff that the library specifically is about and doesn&rsquo;t affect the flow control structures. With Core Language Extensions one can choose to express flow control structures in ways like above. Since e.g. use of range based `for` loops, especially with the Core Language Extensions&rsquo;s `zero_to`, is still quite rare, it can be perceived as *foreign* or *alien*. Especially old-timers can perceive it as something not-C++-as-we&rsquo;ve-learned-to-know-it. The feedback I&rsquo;ve had about *cppx* in general is that this is problematic to old-timers, but not to fresh learners.

Anyway, in the above code the `$...` names are simple macros that do what they say they do. The $ naming is formally non-standard, but AFAIK it&rsquo;s accepted by all extant C++ compilers for desktop systems. It&rsquo;s possible to write e.g. `CPPX_USE_STD` instead of `$use_std`, and ditto (systematically) for other such names.




----

I regard `std::string` as effectively part of the C++ core language, because it plays the same rôle as the core language string types do in other programming languages, and because it’s critical for both throwing and handling exceptions. Mostly for use in exception throwing, but also generally for function arguments, 
Core Language Extensions provides a simple notation for assembling strings from parts, e.g. `foo( "The answer is "s << 6*7 << "." )`. For exception throwing there is support for automatically including the throw point source location, and for exception handling there is support for inspecting and retrieving the messages of standard nested exceptions.
