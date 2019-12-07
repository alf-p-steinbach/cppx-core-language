<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Core Language Extensions](#core-language-extensions)
  - [1. Installation & use.](#1-installation--use)
      - [*Disclaimer*](#disclaimer)
  - [2. Overview.](#2-overview)
  - [3. Examples.](#3-examples)
    - [3.1. The bit-level stuff.](#31-the-bit-level-stuff)
      - [3.1.1. Examples for “*bits_per_.hpp*”.](#311-examples-for-bits_per_hpp)
      - [3.1.2. Header “*intlog2.hpp*”.](#312-header-intlog2hpp)
      - [3.1.3. Examples for “*sum_of_bits.hpp*”.](#313-examples-for-sum_of_bitshpp)
    - [3.2. The calculation stuff.](#32-the-calculation-stuff)
      - [3.2.1. Examples for “*floating-point-operations.hpp*”.](#321-examples-for-floating-point-operationshpp)
      - [3.2.2. Header “*general-operations.hpp*”.](#322-header-general-operationshpp)
      - [3.2.3. Examples for “*integer-operations.hpp*”.](#323-examples-for-integer-operationshpp)
      - [3.2.4. Examples for “*named-numbers.hpp*”.](#324-examples-for-named-numbershpp)
      - [3.2.5. Examples for “*number-type-properties.hpp*”.](#325-examples-for-number-type-propertieshpp)
    - [3.3. The syntax support.](#33-the-syntax-support)
    - [3.4. The system dependent stuff.](#34-the-system-dependent-stuff)
    - [3.5. The text handling.](#35-the-text-handling)
    - [3.6. The template meta programming support.](#36-the-template-meta-programming-support)
    - [3.7. The type checking support.](#37-the-type-checking-support)
    - [3.8. Supporting types.](#38-supporting-types)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Core Language Extensions

Originally a sub-folder in the *cppx-core* project, the Core Language Extensions  is a pure header micro-library that provides workarounds for various shortcomings of the C++ core language and standard library features directly supporting the core language, as of C++17.

As a simple example of a core language shortcoming that’s not addressed in C++20, the all-directions implicit conversions for the built-in `bool` type generally cause unexpected and undesired overload resolutions. For example, iostreams output of a function pointer typically results in the text “1”, via an unexpected conversion to `bool`. To overcome the specific problem manifestation with function pointer output Core Language Extensions offers the `to_hex` function, and more, and to help you avoid the general overload resolution problem Core Language Extensions offers the alternative boolean type `Truth`, which converts implicitly only to and from `bool`.

`Truth` is a drop-in replacement for the too-eagerly converting `bool`.

Even if you don&rsquo;t use it for anything else you may find it useful to use a `vector<Truth>` instead of `vector<bool>`, because with the `vector<Truth>` you can have a reference or pointer to an item.

 In passing, everything is provided in the `cppx` namespace so it’s really `cppx::to_hex` and `cppx::Truth`, and so on, but for readability I’ll refer to these names unqualified.

## 1. Installation & use.

After cloning, checking out or downloading the library:

1. Make the C Header Wrappers source code available via C++ include path &ldquo;`c/`&rdquo;.  
   ***Info***: C header Wrappers is a project that Core Language Extensions depends on. You find it as a GIT sub-module in the folder &ldquo;dependencies&rdquo;. In Windows I prefer to make library headers available by using junctions in a common include folder. For example, in that folder I&rsquo;d use the command `mklink /j c c:\somewhere\c-header-wrappers\source\c`. Just copying the source is also fine.  
   ***Test***: For example, `#include <c/math.hpp>` should now work in C++ source code.  

2. Make the Meta Macro source code available via C++ include path &ldquo;`cppx-core-language-meta-macro/`&rdquo;.  
   ***Info***: Meta Macro is a project that Core Language Extensions depends on. You find it as a GIT sub-module in the folder &ldquo;dependencies&rdquo;.  
   ***Test***: For example, `#include <cppx-core-language-meta-macro/all.hpp>` should work.  

3. Make the library source code available via C++ include path &ldquo;`cppx-core-language/`&rdquo;.  
   ***Info***: Now it’s this library so it’s not a GIT sub-module.  
   ***Test***: for example, `#include <cppx-core-language/all.hpp>` should work.

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
|[bit‑level](../source/cppx%2Dcore%2Dlanguage/bit%2Dlevel)   | Examples: `bits_per_`*`<T>`* gives the number of bits of a *`T`*-value, `intlog2` reports the position of the most significant 1-bit in an integer, and `sum_of_bits` reports the sum of the bits in an integer (note: in some contexts `sum_of_bits` is known as [&ldquo;pop-count&rdquo;](https://en.wikipedia.org/wiki/Hamming_weight)). |
|[calc](../source/cppx%2Dcore%2Dlanguage/calc)        | Calculations. Here are names of common constants such as *&pi;* (although C++20 will also provide that), floating point ops such as `squared`, `cubed` and `intpow`, and integer arithmetic ops such as `div_up` and `is_even` (and more). Plus a set of *consistent* numerical type properties, e.g. `min_<T>` is always the most negative value of type `T` and `smallest_<T>` is always the smallest absolute value of `T`.
|[syntax](../source/cppx%2Dcore%2Dlanguage/syntax)        | Mostly about *reduction of verbosity* for safe or best-practice constructs. For example, the `zero_to` function produces a `Sequence` which supports loops such as `for(const int i: zero_to(n))`, where there is no chance of inadvertent modification of the loop variable. With a reasonably good compiler it&rsquo;s as efficient as an ordinary counting loop &mdash; just less verbose and more safe. Some other syntax support is in the form of macros. E.g. `$use_std(A, B, C);` brings in the specified items from the standard library as if by `using std::A, std::B, std::C;`.  Perhaps of most practical utility to a new library user, here is `<<`-like support for assembling strings from parts. E.g. calls like `fail("Unable to open door "s << n)`. |
|[system-dependent](../source/cppx%2Dcore%2Dlanguage/system%2Ddependent)      | System-dependent stuff. The type `Byte` + support; the enumeration `Endian` (more precisely it&rsquo;s a `struct` with an inner `enum`)  ; and the signed types `Size` and `Index` plus the corresponding `Unsigned_size` and `Unsigned_index`. These four are all the same size as `size_t`.
|[text](../source/cppx%2Dcore%2Dlanguage/text)    | Mainly ASCII text handling support, such as names of control characters (plus the name `bad_char` defined as `DEL`), ASCII range checking, widening, uppercasing and lowercasing, and whitespace checking and other classification functions. The C standard library defines some of this but in a form that&rsquo;s difficult to use correctly. Also, the `to_hex` function lives here.
|[tmp](../source/cppx%2Dcore%2Dlanguage/tmp)         | Template meta-programming support, or just, support for defining templates. A number of type traits such as `is_integral_`, type modifiers such as `Unref_` and `Unsigned_`, and the class templates `Enable_if_`, `Type_choice_` and `Type_carrier_`. The two first templates are simple wrappers around `std::enable_if_t` and `std::conditional_t`, mostly for readability. |
|[type‑checking](../source/cppx%2Dcore%2Dlanguage/type%2Dchecking) | `downcasted_to` guarantees a downcast as opposed to a sideways cast, using a safe `dynamic_cast`; `is_of_derived_class` checks whether a pure downcast is possible; and `array_size_of` and `length_of_literal` do compile time size checking. The `type_name_of_` function template obtains a readable description of a type, based on `typeid(T).name()`. For the g++ compiler it translates to readable form like *c++filt* does, and for the Visual C++ compiler (and possibly other compilers) it removes that compiler’s `struct`, `class` and `enum` keyword verbiage. |
|[types](../source/cppx%2Dcore%2Dlanguage/types)        | The `Truth` type is a boolean that doesn't implicitly convert to or from anything other than `bool`; the `Int_` template alias lets you specify an integral type via its bit width; `C_str` and family are type names for simple `char` pointers, indicating use for C strings; and `No_copy` and `No_copy_or_move` can be used as base classes with the properties indicated by the names. Except for `C_str` these are types and names, or features, that are missing in the core language as of C++17. Additionally here is an internally used class template `C_buffer_param_` which associates a pointer-to-first-item-in-array with a minimum size of the array.   |


## 3. Examples.

These code examples are all available in the “examples” top level folder.

---

Most of the examples use the Core Language Extensions syntax support. In particular, where the examples use things from the C++ standard library the unqualified names are brought in via a macro **`$use_std`**, like this:

    $use_std( cout, endl, setw );

That expands to the corresponding C++11 single-item `using`-declarations

>     using std::cout;  using std::endl;  using std::setw;

Unqualified names from the Core Language Extensions library and other `cppx` namespace libraries are likewise brought in via macro invocations like

    $use_cppx( zero_to, hex_digit );

… which expands to

>     using cppx::zero_to;  using cppx::hex_digit;

The examples use the macros and other syntax support like the `zero_to` function because that yields shorter, simpler and more readable-as-English code. However, some people reportedly feel uncomfortable reading (not to mention writing!) C++ code with `$`-macro invocations. If that applies to you then just replace all instances of `$use_std` with `CPPX_USE_STD`, and all instances of `$use_cppx` with `CPPX_USE_CPPX`, and correspondingly for other macros.

---

In practical use of the library one will just include ***the top level “all”  header***,

    #include <cppx-core-language/all.hpp>

And this is also how each example is presented.

However, it’s possible to use much more specific, less inclusive headers, and to show that each example “foo.cpp” has a corresponding file “foo.using-specific-headers.cpp” that instead uses the most specific headers. For your information these includes are presented after the “foo.cpp” code. But since the Core Language Extensions is a micro-library client code build time is not significantly reduced by using more specific headers: it’s already a small dependency.


### 3.1. The bit-level stuff.

Folder: “**[bit‑level](../source/cppx%2Dcore%2Dlanguage/bit%2Dlevel)**”. Exporting namespace: `bitlevel`.

An ***exporting namespace*** has `using` declarations of a bunch of related stuff, so that you can obtain unqualified versions of these names simply by e.g.

~~~cppx
using namespace cppx::bitlevel;
~~~

This doesn’t drag in other names from `cppx`.

The names are however originally defined directly in the `cppx` namespace, so you can also use e.g. just `using cppx::bits_per_;`, or `$use_cppx( bits_per_ );`, for individual names.


#### 3.1.1. Examples for “*bits_per_.hpp*”.

The “*bits_per_.hpp*” header provides convenient notation for the bit widths of fundamental types, as `int` values:

<small>*examples/bit-level/bit-widths-of-int.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    const auto& s =
        "Data addresses in this process are %d-bit.\n"
        "\n"
        "With this compiler an `int` is %d bits. %d of those are value representation\n"
        "bits, and of those again %d bits encode the magnitude.\n";

    using namespace cppx;
    printf( s,
        Bitness::system, bits_per_<int>, value_bits_per_<int>, magnitude_bits_per_<int>
        );
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
Data addresses in this process are 64-bit.

With this compiler an `int` is 32 bits. 32 of those are value representation
bits, and of those again 31 bits encode the magnitude.
~~~

Without the Core Language Extensions library you could do this using `std::numeric_limits` and perhaps the `CHAR_BIT` constant from C.

Specific header:

~~~cpp
#include <cppx-core-language/bit-level/bits_per_.hpp>           // ” Bit-level stuff.
~~~


---

The `Bitness::Enum` enumeration type, defined as

>     struct Bitness{ enum Enum {
>         _8 = 8, _16 = 16, _32 = 32, _64 = 64, _128 = 128, system = bits_per_<void*>
>         }; };

… is intended as a formal parameter type where you want the argument value constrained to one in this list.

For example as in the `display_info_for_` function template below:

<small>*examples/bit-level/table-of-bit-widths.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>
#include <iomanip>
$use_std( cout, endl, setw );

template< class... Args >
void display_row( const Args&... args )
{
    ((cout << setw( 20 ) << args), ...) << endl;
}

template< class Type >
void display_info_for_type_()
{
    using namespace cppx;
    display_row(
        type_name_of_<Type>(),
        bits_per_<Type>,
        value_bits_per_<Type>,
        magnitude_bits_per_<Type>
        );
}

template< cppx::Bitness::Enum... n_bits >
void display_info_for_()
{
    $use_cppx( Int_, Unsigned_int_ );
    display_row( "Type:", "Bits per value:", "Value repr. bits:", "Magnitude bits:" );
    cout << endl;
    (display_info_for_type_< Int_<n_bits> >(), ...);
    (display_info_for_type_< Unsigned_int_<n_bits> >(), ...);
}

auto main()
    -> int
{
    $use_cppx( Bitness );
    cout << "Data addresses in this process are " << Bitness::system << "-bit." << endl;
    cout << endl;
    display_info_for_<Bitness::_8, Bitness::_16, Bitness::_32, Bitness::_64>();
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
Data addresses in this process are 64-bit.

               Type:     Bits per value:   Value repr. bits:     Magnitude bits:

         signed char                   8                   8                   7
               short                  16                  16                  15
                 int                  32                  32                  31
           long long                  64                  64                  63
       unsigned char                   8                   8                   8
      unsigned short                  16                  16                  16
        unsigned int                  32                  32                  32
  unsigned long long                  64                  64                  64
~~~

The standard library has nothing like `Int_<n>` and `Unsigned_int_<n>` to go from bit width to type, and also the standard library lacks a portable way to get a readable name of a type, like `type_name_of_`. I can’t think of a good simple way to do the latter directly, but without the Core Language Extensions library one could go from bit widths to types by defining the main code here as a macro. Then a bit width specified as macro argument could just be concatened with a prefix and suffix, forming e.g. `int8_t` and `uint8_t` (type names from the `<stdint.h>` header). So essentially, for the above program the library helps avoid coding the main stuff as a macro, and gives the ability to obtain readable names of types. That ability is based on `typeid(T).name()`, just with added demangling applied for the g++ compiler and with removal of `struct`, `class` and `enum` keywords for Visual C++ and other compilers.

Specific headers:

~~~cpp
#include <cppx-core-language/bit-level/bits_per_.hpp>           // ” Bit-level stuff.
#include <cppx-core-language/type-checking/Type_name_of_.hpp>   // cppx::type_name_of_
#include <cppx-core-language/types/Int_.hpp>            // cppx::(Int_, Unsigned_int_)
~~~


#### 3.1.2. Header “*intlog2.hpp*”.

The “*intlog2.hpp*” header provides the `constexpr` function `intlog2`, which returns the bit position of the most signficant `1` in the binary representation of the argument.


#### 3.1.3. Examples for “*sum_of_bits.hpp*”.

The “*sum_of_bits.hpp*” header provides the `sum_of_bits` function, implemented in terms of `std::bitset` as simply

~~~cpp
    /// The number of 1-bits in an unsigned value.
    template< class Unsigned >
    inline auto sum_of_bits( const Unsigned x ) noexcept
        -> int
    {
        static_assert( is_unsigned_<Unsigned> );
        return bitset< bits_per_<Unsigned> >( x ).count();
    }
~~~

There is also an overload for a `std::bitset` as argument.

This is generally known as a “**pop count**”, short for “population count”, which presumably refers to the bits as representing a set. With the g++ compiler the function can possibly be optimized in terms of the intrinsic `__builtin_popcount` and family, and with the Visual C++ compiler it can possibly be optimized in terms of the intrinsic `__popcnt` and family. The header provides a rough outline of these optimizations as dead code in a preprocessor `#if 0` conditional, but I haven’t measured, and chances are that `std::bitset::count` is expressed via an intrinsic anyway.

Example:

<small>*examples/bit-level/pop-counts.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdint.hpp>         // uint8_t
#include <bitset>               // std::bitset
#include <iostream>             // std::(cout, endl)
#include <iomanip>              // std::setw
$use_std( bitset, cout, endl, setw );

template< class... Args >
void display_row( const Args&... args )
{
    ((cout << setw( 16 ) << args), ...) << endl;
}

auto main()
    -> int
{
    $use_cppx( bits_per_, Sequence, is_even, intlog2, sum_of_bits );
    
    using U = uint8_t;
    const int n_bits = bits_per_<U>;
    const int max_bit_pos = n_bits - 1;
    using Bits = bitset<n_bits>;

    display_row( "Value:", "Bits:", "MSB pos:", "Sum of bits:" );
    cout << endl;

    U u = 0;
    for( const int i: Sequence( -1, max_bit_pos ) ) {
        u <<= 1;
        if( is_even( i ) ) { u |= 1; }
        display_row( +u, Bits( u ), intlog2( u ), sum_of_bits( u ) );
    }
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
          Value:           Bits:        MSB pos:    Sum of bits:

               0        00000000              -1               0
               1        00000001               0               1
               2        00000010               1               1
               5        00000101               2               2
              10        00001010               3               2
              21        00010101               4               3
              42        00101010               5               3
              85        01010101               6               4
             170        10101010               7               4
~~~

In passing, `Sequence` is a further example of Core Language Extensions syntax support, namely for the range based `for`. The aforementioned `zero_to(n)` function simply produces a `Sequence(0, n-1)`. There is also `one_through`.

Specific headers:

~~~cpp
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_even
#include <cppx-core-language/bit-level/bits_per_.hpp>       // cppx::bits_per_
#include <cppx-core-language/bit-level/intlog2.hpp>         // cppx::intlog2
#include <cppx-core-language/bit-level/sum_of_bits.hpp>     // cppx::sum_of_bits
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::Sequence
~~~



### 3.2. The calculation stuff.

Folder: “**[calc](../source/cppx%2Dcore%2Dlanguage/calc)**”. Exporting namespaces: `calc` and `m`.

An ***exporting namespace*** has `using` declarations of a bunch of related stuff, so that you can obtain unqualified versions of these names simply by e.g.

~~~cppx
using namespace cppx::calc;
~~~

This doesn’t drag in other names from `cppx`.

`calc` is used as a general exporting namespace for headers in the “calc” folder, but in order to minimize the risk of name collisions after C++20, the named numbers such as `pi` are exported via `m` instead (mnemonic: `m::pi` is like Posix’ `M_PI`). Hence, you can have a convenient `using namespace cppx::calc` also where you have a ditto convenient `using namespace std::numbers`. I hope.

The names are however originally defined directly in the `cppx` namespace, so you can also use e.g. just `using cppx::pi;`, or `$use_cppx( pi );`, for individual names.

**Tip**:  
*The “C++ Headers Collection” micro-library provides [a wrapper header `<cpp/calc.hpp>`](https://github.com/alf-p-steinbach/Cpp-Header-Collections/blob/master/source/cpp/calc.hpp) that includes all the calculation stuff from the standard library, including various overloads of `abs` and `div` from different standard library headers, and including both `::` and `std` namespace variants. Well, it includes “all” except the very rarely used `valarray`. Handy.*


#### 3.2.1. Examples for “*floating-point-operations.hpp*”.

The “*floating-point-operations.hpp*” header provides three `double` functions: `intpow(x,n)`, `squared(x)` and `cubed(x)`. All are `constexpr`. The `squared` and `cubed` functions are function templates defined in the “*general-operations.hpp*” header, which is included here for convenience.

 I can’t think of any situation where one would need compile time evaluation of any of these functions, but it’s nice to have the ability.

<small>*examples/calc/floating-point-constexpr.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>     // std::(cout, endl, fixed)
#include <iomanip>      // std::setprecision
$use_std( cout, endl, fixed, setprecision );

auto main()
    -> int
{
    $use_cppx( intpow, squared, cubed );
    constexpr int n = 10'000;
    constexpr double base = 1 + 1.0/n;
    cout << fixed << setprecision( 16 );

    constexpr double x2 = squared( base );
    cout << base << " ^ 2 ~= " << x2 << "." << endl;

    constexpr double x3 = cubed( base );
    cout << base << " ^ 3 ~= " << x3 << "." << endl;

    constexpr double xn = intpow( base, n );
    cout << base << " ^ " << n << " ~= " << xn << "." << endl;
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
1.0001000000000000 ^ 2 ~= 1.0002000099999999.
1.0001000000000000 ^ 3 ~= 1.0003000300009999.
1.0001000000000000 ^ 10000 ~= 2.7181459268243562.
~~~

The last result is an approximation of Euler’s number *e* ≈ 2.718281828…, and thereby provides a simple check that the power is computed correctly.

Such checking is needed because the whole point of an integral power function is efficiency, compared to the more general C `pow` function, and so the calculation is non-trivial, not just a simple loop doing *n* multiplications. It wouldn't do to use time O( *n* ) for exponent *n*! `intpow` uses divide-and-conquer to evaluate an integral power of floating point base, *x*<sup>*n*</sup>, in just O( log₂|*n*| ) steps.

Negative exponent is supported.

Note: the standard library’s [`ldexp` function](https://en.cppreference.com/w/cpp/numeric/math/ldexp) could in principle be used to create integral powers of 2 efficiently, because on extant C++ implementations as of 2019, with binary floating point representation, it could just specify the power internally in the floating point representation. However, its page on cppreference.com notes that “On many implementations, `std::ldexp` is less efficient than multiplication or division by a power of two using arithmetic operators.”. I don’t know why.

Specific header:

~~~cpp
// cppx::(intpow, squared, cubed)
#include <cppx-core-language/calc/floating-point-operations.hpp>
~~~

#### 3.2.2. Header “*general-operations.hpp*”.

The “*general-operations.hpp*” header provides the `squared` and `cubed` function templates already discussed in the previous section.


#### 3.2.3. Examples for “*integer-operations.hpp*”.

The “*integer-operations.hpp*” header provides a suite of `constexpr` integer functions: `is_even(x)`, `is_odd(x)`, `is_zero(x)`, `div_down(a,b)`, `div_up(a,b)` and `mod(a,b)`. In addition the “*general-operations.hpp*” header is included for convenience. It defines the functions `squared` and `cubed`.

All these functions are templated on the integer (or general number) type.

`is_even` and `is_odd` do what their names say. Typically they’re used for checking the value of the least significant bit in an integer. For example, `is_odd` is used in the integral-power-of-floating-point function `intpow` discussed above.

A somewhat construed example:

<small>*examples/calc/pascal-as-sierpinsky.cpp*</small>
~~~cpp
// Display the positions of the odd numbers in Pascal's triangle.
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>  // printf
#include <vector>       // std::vector

auto main()
    -> int
{
    $use_std( vector );
    $use_cppx( is_odd, Sequence, zero_to );

    const int n = 1 << 4;
    vector<int> row = {1};

    for( const int y: zero_to( n ) ) {
        if( y > 0 ) {
            // Compute the next row.
            vector<int> next_row = {1};
            for( const int i: Sequence( 1, row.size() - 1 ) ) {
                next_row.push_back( row[i] + row[i - 1] );
            }
            next_row.push_back( 1 );
            swap( next_row, row );
        }

        // Display the odd numbers’ positions.
        printf( "%*c", n - y, ' ' );
        for( const int x: row ) {
            printf( " %c", is_odd( x )? 'o' : ' ' );
        }
        printf( "\n" );
    }
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
                 o
                o o
               o   o
              o o o o
             o       o
            o o     o o
           o   o   o   o
          o o o o o o o o
         o               o
        o o             o o
       o   o           o   o
      o o o o         o o o o
     o       o       o       o
    o o     o o     o o     o o
   o   o   o   o   o   o   o   o
  o o o o o o o o o o o o o o o o
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_odd
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::(Sequence, zero_to)
~~~

---

The Pascal’s triangle example above is “somewhat construed” because all that matters for the oddness or not of a number in Pascal’s triangle, is the oddness of the numbers above. So the above needlessly computes numbers that for a larger triangle (think about a high resolution graphics presentation) can easily exceed the range of `int`. All that needs to be stored each place in a row, is a `Truth` value representing the oddness.

A bit of analysis can reduce that further down to an apparently very simple program, showing how the `is_zero` function can be of practical use. For, the expression `x & ~y == 0` means something very different from the intended `(x & ~y) == 0`. Using `is_zero` and writing it as `is_zero(x & ~y)` the operator precedence problem just doesn't pop up:

<small>*examples/calc/sierpinsky.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( zero_to, is_zero );

    const int n = 1 << 4;
    for( const int y: zero_to( n ) ) {
        printf( "%*c", n - y, ' ' );
        for( const int x: zero_to( n ) ) {
            printf( " %c", is_zero( x & ~y )? 'o' : ' ' );
        }
        printf( "\n" );
    }
}
~~~

Same result as before.

Specific headers:

~~~cpp
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_zero
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::zero_to
~~~

---

Throughout C++98 and C++03 the `%` remainder operator had partially implementation defined behavior, because the rounding behavior of integer `/` was unspecified. Integer `/` could round down towards negative infinity, or in towards zero. With C++11 `/` and `%` were finally completely specified, with `/` rounding in towards zero:

*C++11 §5.6/4:*
> **”** For integral operands the `/` operator yields the algebraic quotient with any fractional part discarded; if the quotient `a/b` is representable in the type of the result, `(a/b)*b + a%b` is equal to `a`.

This matches how humans and most (possibly all) computers do integer division, but it complicates the programming.

Consider, if one taxi can take 3 passengers, how many taxies are needed for a group of 10 people? Integer division `10/3` yields 3, which leaves one person stranded… The C++ expression `(10 + (3 - 1))/3` works for positive numbers, and is not uncommon. In Python, where integer division rounds down towards negative infinity, one can write `-(10//-3)`. However, neither expression is intuitive and clear at a glance. So, this is `div_up`:

<small>*examples/calc/div-up-and-down.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( div_up, div_down );

    const int   n_per_taxi      = 3;
    const int   n_persons       = 10;
    const int   n_choco_bars    = 27;
    
    const auto& txinfo = "With %d persons and max %d per taxi, %d taxis are needed.\n";
    printf( txinfo, n_persons, n_per_taxi, div_up( n_persons, n_per_taxi ) );
    
    const auto& cbinfo = "With %d chocolate bars and %d persons, each gets %d bars.\n";
    printf( cbinfo, n_choco_bars, n_persons, div_down( n_choco_bars, n_persons ) );
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
With 10 persons and max 3 per taxi, 4 taxis are needed.
With 27 chocolate bars and 10 persons, each gets 2 bars.
~~~

In terms of the mathematical floor and ceiling functions, `div_up` is ⌈*a*/*b*⌉ and `div_down` is ⌊*a*/*b*⌋.

Specific header:

~~~cpp
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::(div_up, div_down)
~~~

---

The `mod` function is defined in terms of `div_down`,

~~~cpp
    constexpr inline auto mod( const int a, const int b ) noexcept
        -> int
    { return a - b*div_down( a, b ); }
~~~

… which makes it more like mathematics than the built in `%`.

I’ve provided `mod` for *completeness*, that there ought to be this operation complementing `div_down` just as in the core language there is `%` complementing integer `/`, and just as in the standard library there is `fmod` complementing floating point `/`. However, I’m at a loss coming up with a practical example where `mod` would be clearly useful. The following example just illustrates the signs and magnitudes that one can expect:

<small>*examples/calc/remainders.cpp*</small>
~~~cpp
#include <cppx-core-language/calc/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( div_down, mod );

    for( const int a: {13, -13} ) {
        for( const int b: {5, -5} ) {
            const auto& s =
                "%3d / %3d = %3d,  %% = %3d; %10c div_down(%3d, %3d) = %3d,  mod = %3d\n";
            printf( s,
                a, b, a/b, a%b,
                ' ',
                a, b, div_down( a, b ), mod( a, b )
                );
        }
    }
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
 13 /   5 =   2,  % =   3;            div_down( 13,   5) =   2,  mod =   3
 13 /  -5 =  -2,  % =   3;            div_down( 13,  -5) =  -3,  mod =  -2
-13 /   5 =  -2,  % =  -3;            div_down(-13,   5) =  -3,  mod =   2
-13 /  -5 =   2,  % =  -3;            div_down(-13,  -5) =   2,  mod =  -3
~~~

Specific header:

~~~cpp
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::(div_down, mod)
~~~


#### 3.2.4. Examples for “*named-numbers.hpp*”.

The “*named-numbers.hpp*” header provides the `double` constants `e`, `log2e`, `log10e`, `ln2`, `ln10`, `pi`, `inv_sqrt_pi`, `sqrt2` and `inv_sqrt2`; the `Truth` constants `has_nan`_, `has_nan`, `has_infinity_` and `has_infinity`; and the  `constexpr` functions `nan_`, `nan`, `infinity_` and `infinity`.

The names that end with underscore are templates. The set of double constants are defined in terms of [the Posix standard’s `M_PI` etc.](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html), if available, and otherwise simple literals, copied from a `<math.h>` header, are used. The `nan` and `infinity` functions are simple wrappers around the corresponding `std::numeric_limits` functions.

C++20’s [new header `<numbers>`](https://en.cppreference.com/w/cpp/header/numbers) will define all of the `double` constants, plus a few more esoteric ones.

<small>*examples/calc/named-numbers.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>     // std::(cout, endl)
#include <iomanip>      // std::setw
$use_std( cout, endl, setw, left, right, fixed, setprecision );
$use_cppx( Type_ );

void display( const double number, const Type_<const char*> name )
{
    cout << left << setw( 12 ) << name << " = " << right << setw( 15 ) << number << endl;
}

#define DISPLAY( name ) display( cppx::name, #name );

auto main()
    -> int
{
    cout << fixed << setprecision( 10 );
    $apply( DISPLAY, e, log2e, log10e, ln2, ln10, pi, inv_sqrt_pi, sqrt2, inv_sqrt2 );
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
e            =    2.7182818285
log2e        =    1.4426950409
log10e       =    0.4342944819
ln2          =    0.6931471806
ln10         =    2.3025850930
pi           =    3.1415926536
inv_sqrt_pi  =    0.5641895835
sqrt2        =    1.4142135624
inv_sqrt2    =    0.7071067812
~~~

Here the `$apply` macro is from the Meta Macro library, but that library is included wholesale by the Core Language Extensions “all” header. For each of the following arguments `$apply` invokes the specified macro, here `DISPLAY`, with that argument. The `Type_` template alias is a nice way to support prefix `const`, as far as I know originally proposed by Johannes “litb” Schaub.

Not exemplified by the code above: the names are available via the exporting namespace `m`, e.g. `using namespace cppx::m;` brings in all these names unqualified.

Specific headers:

~~~cpp
#include <cppx-core-language/calc/named-numbers.hpp>        // cppx::calc::*
#include <cppx-core-language/syntax/type-builders.hpp>      // cppx::Type_
#include <cppx-core-language-meta-macro/macro-apply.hpp>    // $apply    
~~~


#### 3.2.5. Examples for “*number-type-properties.hpp*”.

The “*named-numbers.hpp*” header provides much of the same information as `std::numeric_limits`, but more consistently as `constexpr` values instead of a mix of values and functions, and more consistently with a single meaning of e.g. `min`, instead of a type-dependent meaning.

For an integral type `T` the set is

~~~cpp
constexpr T     smallest_       = 1;                            // Smallest non-zero.
constexpr T     largest_        = numeric_limits<T>::max();
constexpr T     min_            = numeric_limits<T>::min();     // Usually `-largest_ - 1`.
constexpr T     max_            = largest;
constexpr int   n_digits_       = numeric_limits<T>::digits10;
~~~

… and for a floating point type `T` the set has some additional properties:

~~~cpp
constexpr T     smallest_       = numeric_limits<T>::min();     // Smallest non-zero.
constexpr T     largest_        = numeric_limits<T>::max();
constexpr T     min_            = -largest;                     // Largest negative.
constexpr T     max_            = largest;
constexpr int   n_digits_       = numeric_limits<T>::digits10;
            
constexpr Truth is_ieee_754_    = numeric_limits<T>::is_iec559;
constexpr int   min_exp_        = numeric_limits<T>::min_exponent10;
constexpr int   max_exp_        = numeric_limits<T>::max_exponent10;
constexpr int   radix_          = numeric_limits<T>::radix;
constexpr T     epsilon_        = numeric_limits<T>::epsilon();
~~~

Use of a floating point-specific property for an integral type, would most likely be an error. Therefore, unlike `std::numeric_limits` the floating point-specific properties *do not exist* for integral types. So, this set is more consistent wrt. form (value or function), more consistent wrt. meaning, and more safe, than `std::numeric_limits`.

Not to mention that `min_<double>` is very much shorter and readable than (!) `-std::numeric_limits<double>::max()`.

A program that diplays these properties for types `bool`, `int` and `double`:

<small>*examples/calc/number-type-properties.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>     // std::(cout, endl)
#include <iomanip>      // std::setw
$use_std( cout, endl, setw, setprecision, boolalpha );

constexpr int field_widths[] =
{
    6,
    18, 18, 18, 18, 5,
    8, 8, 8, 5, 18
};

template< class... Args >
void display_fields( const int*& p_width, const Args&... args )
{
    ((cout << setw( *p_width++ ) << args), ...);
}

template< class Type >
void display_properties_of_type_()
{
    const int* widths = field_widths;

    $use_cppx( is_floating_point_, type_name_of_ );
    using namespace cppx::calc;
    display_fields( widths,
        type_name_of_<Type>(),
        smallest_<Type>, largest_<Type>, min_<Type>, max_<Type>, n_digits_<Type>
        );
    if constexpr( is_floating_point_<Type> ) {
        display_fields( widths,
            is_ieee_754_<Type>,
            min_exp_<Type>, max_exp_<Type>, radix_<Type>, epsilon_<Type>
            );
    }
    cout << endl;
}

template< class... Type >
void display_properties_of_()
{
    (display_properties_of_type_<Type>(),...);
}

void display_column_headers()
{
    const int* widths = field_widths;
    display_fields( widths,
        "Name:",
        "Smallest:", "Largest:", "Min:", "Max:", "Dig:",
        "IEEE?", "Min E:", "Max E:", "R:", "Epsilon:"
        );
    cout << endl;
}

auto main()
    -> int
{
    display_column_headers();
    cout << endl;
    cout << setprecision( 8 ) << boolalpha;
    display_properties_of_<bool, int, double>();
}
~~~


Result with 64-bit MinGW g++ in Windows 10:

~~~txt
 Name:         Smallest:          Largest:              Min:              Max: Dig:   IEEE?  Min E:  Max E:   R:          Epsilon:

  bool              true              true             false              true    0
   int                 1        2147483647       -2147483648        2147483647    9
double    2.2250739e-308    1.7976931e+308   -1.7976931e+308    1.7976931e+308   15    true    -307     308    2      2.220446e-16
~~~

How come `true` is the “smallest” value of type `bool`?

The “Smallest:” column shows the *smallest strictly positive* value. The value 0 could in some sense be regarded as smallest, but as the value of `smallest_<T>` it would have no practical value. One could then, better, just write `0` instead.

How come that the minimum value of the exponent is reported as `-307`, when the very first `double` value in the table has exponent `-308`?

`min_exp_` is effectively an alias for `std::numeric_limits::min_exponent10`, which in C++17 is defined as

> **”** Minimum negative integer such that 10 raised to that power is in the range of normalized floating-point numbers.

Even without considering normalization and denormal numbers, since 10⁻³⁰⁸ < 2.23⋅10⁻³⁰⁸ the former is not “in the range” of the type. But 10⁻³⁰⁷ is. A practical view is that the range 10⁻³⁰⁷ … 10⁺³⁰⁸ is a subset of the range of the type, and that the powers of 10 immediately outside that sub-range are outside the range of the type.

Specific headers:

~~~cpp
#include <cppx-core-language/calc/number-type-properties.hpp>   // cppx::calc::*
#include <cppx-core-language/tmp/type-traits.hpp>               // cppx::is_floating_point_
#include <cppx-core-language/type-checking/type_name_of_.hpp>   // cppx::type_name_of_
~~~





---



asdasd

### 3.3. The syntax support.

### 3.4. The system dependent stuff.

### 3.5. The text handling.

### 3.6. The template meta programming support.

### 3.7. The type checking support.

### 3.8. Supporting types.
