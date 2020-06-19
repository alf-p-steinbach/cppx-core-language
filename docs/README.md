<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->
**Table of Contents**  *generated with [DocToc](https://github.com/thlorenz/doctoc)*

- [Core Language Extensions](#core-language-extensions)
  - [1. Installation & use.](#1-installation--use)
      - [*Disclaimer*](#disclaimer)
  - [2. Overview.](#2-overview)
  - [3. Examples & details.](#3-examples--details)
    - [3.0. About the examples — availability, order, notation, headers, namespaces.](#30-about-the-examples--availability-order-notation-headers-namespaces)
    - [3.1. The bit-level stuff.](#31-the-bit-level-stuff)
      - [3.1.1. Examples for header “bit-level/Bit_width.hpp”.](#311-examples-for-header-bit-levelbit_widthhpp)
      - [3.1.2. Examples for header “bit-level/bits_per_.hpp”.](#312-examples-for-header-bit-levelbits_per_hpp)
      - [3.1.3. Examples for header “bit-level/Int_.hpp”.](#313-examples-for-header-bit-levelint_hpp)
      - [3.1.4. Examples for header “bit-level/intlog2.hpp”.](#314-examples-for-header-bit-levelintlog2hpp)
      - [3.1.5. Examples for header “bit-level/sum_of_bits.hpp”.](#315-examples-for-header-bit-levelsum_of_bitshpp)
    - [3.2. The calculation stuff.](#32-the-calculation-stuff)
      - [3.2.1. Examples for header “calc/floating-point-operations.hpp”.](#321-examples-for-header-calcfloating-point-operationshpp)
      - [3.2.2. Header “calc/general-operations.hpp”.](#322-header-calcgeneral-operationshpp)
      - [3.2.3. Examples for header “calc/integer-operations.hpp”.](#323-examples-for-header-calcinteger-operationshpp)
      - [3.2.4. Examples for header “calc/named-numbers.hpp”.](#324-examples-for-header-calcnamed-numbershpp)
      - [3.2.5. Examples for header “calc/number-type-properties.hpp”.](#325-examples-for-header-calcnumber-type-propertieshpp)
    - [3.3. Mix-in classes.](#33-mix-in-classes)
    - [3.4. The syntax support.](#34-the-syntax-support)
      - [3.4.1. Examples for header “syntax/collection-util.hpp”.](#341-examples-for-header-syntaxcollection-utilhpp)
      - [3.4.2. Examples for header “syntax/declarations.hpp”.](#342-examples-for-header-syntaxdeclarationshpp)
      - [3.4.3. Examples for header “syntax/exception-throwing.hpp”.](#343-examples-for-header-syntaxexception-throwinghpp)
      - [3.4.4. Examples for header “syntax/flow-control.hpp”.](#344-examples-for-header-syntaxflow-controlhpp)
      - [3.4.5. Examples for header “syntax/string-expressions.hpp”.](#345-examples-for-header-syntaxstring-expressionshpp)
      - [3.4.6. Examples for header “syntax/types.hpp”.](#346-examples-for-header-syntaxtypeshpp)
    - [3.5. The system dependent stuff.](#35-the-system-dependent-stuff)
    - [3.6. The text handling.](#36-the-text-handling)
    - [3.7. The template meta programming support.](#37-the-template-meta-programming-support)
    - [3.8. The type checking support.](#38-the-type-checking-support)
    - [3.9. Supporting types.](#39-supporting-types)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

# Core Language Extensions

Originally a sub-folder in the *cppx-core* project, the Core Language Extensions  is a pure header micro-library that provides workarounds for various shortcomings of the C++ core language and standard library features directly supporting the core language, as of C++17.

As a simple example of a core language shortcoming that’s not addressed in C++20, the all-directions implicit conversions for the built-in `bool` type generally cause unexpected and undesired overload resolutions. For example, iostreams output of a function pointer typically results in the text “1”, via an unexpected conversion of pointer to `bool`. The Core Language Extensions’ `to_hex` function can help with this specific case, and to help avoid the general overload resolution problem the library offers the alternative boolean type `Truth`, which converts implicitly only to and from `bool`.

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

To benefit the most from the examples and discussion you may read the [information about the examples’ availability, order, notation, headers and namespaces](#30-about-the-examples--availability-order-notation-headers-namespaces).

|Folder:     | Is about:  |
|------------|------------|
|[assert-cpp](../source/cppx%2Dcore%2Dlanguage/assert%2Dcpp)   | The “is-c++17-or-later.hpp” header causes a compilation error with full stop, if the C++ standard isn’t C++17 or later. Likewise, the “has-utf8-execution-character-set.hpp” header causes a compilation error with full stop if the execution character set isn’t UTF-8.<br>*There is no further discussion or examples of this folder; check the source files for details.* |
|[bit‑level](../source/cppx%2Dcore%2Dlanguage/bit%2Dlevel)   | Examples: the `Int_` and `Unsigned_int_` template aliases let you specify an integral type via its bit width; `bits_per_`*`<T>`* gives the number of bits of a *`T`*-value; `intlog2` and `intlog2r` report the position of respectively the most and the least significant 1-bit in an integer; and `sum_of_bits` reports the sum of the bits in an integer, often called a “pop count” of the bits.<br>[*Discussion and code examples.*](#31-the-bit-level-stuff) |
|[calc](../source/cppx%2Dcore%2Dlanguage/calc)        | Calculations. Here are names of common constants such as *&pi;* (although C++20 will also provide that); general number ops such `squared`, `cubed`; floating point ops such as `intpow`; and integer arithmetic ops such as `div_up` and `is_even`. Plus a set of *consistent* numerical type properties, e.g. `min_<T>` is the most negative direction value of type `T` and `smallest_<T>` is the smallest strictly positive value of `T`.<br>[*Discussion and code examples.*](#32-the-calculation-stuff)
|[mix-in](../source/cppx%2Dcore%2Dlanguage/mix%2Din)        | Mix-in classes such as `mix_in::Adapt_as_forward_iterator_`.
|[syntax](../source/cppx%2Dcore%2Dlanguage/syntax)        | Mostly about *reduction of verbosity* for safe or best-practice constructs. For example, the `zero_to` function produces a `Sequence` which supports loops such as `for(const int i: zero_to(n))`, where there is no chance of inadvertent modification of the loop variable. With a reasonably good compiler it&rsquo;s as efficient as an ordinary counting loop &mdash; just less verbose and more safe. Some other syntax support is in the form of macros. E.g. `$use_std(A, B, C);` brings in the specified items from the standard library as if by `using std::A, std::B, std::C;`.  Perhaps of most practical utility to a new library user, here is `<<`-like support for assembling strings from parts. E.g. calls like `fail("Unable to open door "s << n)`.<br>[*Discussion and code examples.*](#34-the-syntax-support)|
|[system-dependent](../source/cppx%2Dcore%2Dlanguage/system%2Ddependent)      | System-dependent stuff. The type `Byte` + support; the enumeration `Endian` (more precisely it&rsquo;s a `struct` with an inner `enum`)  ; and the signed types `Size` and `Index` plus the corresponding `As_unsigned_size` and `As_unsigned_index`. These four are all the same size as `size_t`.
|[text](../source/cppx%2Dcore%2Dlanguage/text)    | Mainly ASCII text handling support, such as names of control characters (plus the name `bad_char` defined as `DEL`), ASCII range checking, widening, uppercasing and lowercasing, and whitespace checking and other classification functions. The C standard library defines some of this but in a form that&rsquo;s difficult to use correctly. Also, the `to_hex` function lives here.
|[tmp](../source/cppx%2Dcore%2Dlanguage/tmp)         | Template meta-programming support, or just, support for defining templates. A number of type traits such as `is_integral_`, type modifiers such as `As_referent_` and `As_unsigned_`, and the class templates `Enable_if_`, `Type_choice_` and `Type_carrier_`. The two first templates are simple wrappers around `std::enable_if_t` and `std::conditional_t`, mostly for readability. |
|[type‑checking](../source/cppx%2Dcore%2Dlanguage/type%2Dchecking) | `downcasted_to` guarantees a downcast as opposed to a sideways cast, using a safe `dynamic_cast`; `is_of_derived_class` checks whether a pure downcast is possible; and `array_size_of` and `length_of_literal` do compile time size checking. The `type_name_of_` function template obtains a readable description of a type, based on `typeid(T).name()`. For the g++ compiler it translates to readable form like *c++filt* does, and for the Visual C++ compiler (and possibly other compilers) it removes that compiler’s `struct`, `class` and `enum` keyword verbiage. |
|[types](../source/cppx%2Dcore%2Dlanguage/types)        | The `Truth` type is a boolean that doesn't implicitly convert to or from anything other than `bool`; `C_str` and family are type names for simple `char` pointers, indicating use for C strings; and `No_copy` and `No_copy_or_move` can be used as base classes with the properties indicated by the names. Except for `C_str` these are types and names, or features, that are missing in the core language as of C++17. Additionally here is an internally used class template `C_buffer_param_` which associates a pointer-to-first-item-in-array with a minimum size of the array.   |


## 3. Examples & details.

### 3.0. About the examples — availability, order, notation, headers, namespaces.

***Availability***  
These code examples are all available in [the “examples” top level folder](../examples).

---

***Order***  
The examples and discussions are given here in alphabetical order of folders and headers.

All examples draw on the relevant parts of the full library. With alphabetical ordering of discussion that means that many things are necessarily used in examples before these things are (more fully) explained. An alternative could have been to only use the library for each feature to be exemplified, but that would have given unnatural and verbose code.

I’ve tried to explain enough about each example to leave no “mystery”.

---

***Notation***  
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

***Headers***  
In practical use of the library one will just include ***the top level “all”  header***,

    #include <cppx-core-language/all.hpp>

And this is also how each example is presented.

However, it’s possible to use much more specific, less inclusive headers, and to show that each example “foo.cpp” has a corresponding file “foo.using-specific-headers.cpp” that instead uses the most specific headers. For your information these includes are presented after the “foo.cpp” code. But since the Core Language Extensions is a micro-library client code build time is not significantly reduced by using more specific headers: it’s already a small dependency.

Note: the most specific header that provides the `$use_std` and `$use_cppx` macros,

~~~cpp
#include <cppx-core-language/syntax/declarations/macro-use_from_namespace.hpp>  // $use_...
~~~

… is not repeated in the list of most specific headers for each example.

---

***Namespaces***  
An ***exporting namespace*** has `using` declarations of a bunch of related stuff, so that you can obtain unqualified versions of these names simply by e.g.

~~~cppx
using namespace cppx::bitlevel;
~~~

This doesn’t drag in other names from `cppx`.

Generally (but there are exceptions to all rules),

* a header may have its own exporting namespace, e.g. `cppx::basic_string_assembly`,
* a folder has an exporting namespace, e.g. `cppx::syntax`, that exports everything exported by the headers in that folder, and
* the `cppx` namespace serves as a top-level catch-all exporting namespace so that you can use the `$use_cppx` macro to bring in unqualified individual names.

Mostly things are *defined* in a special namespace `cppx::_`. A lot of names from the standard library are brought into this namespace to support the implementation code, and you may not necessarily want those standard library names colliding with something in your code. So, use the exporting namespaces, and not `_`.


### 3.1. The bit-level stuff.

Folder: “**[bit‑level](../source/cppx%2Dcore%2Dlanguage/bit%2Dlevel)**”. *Exporting namespace: `cppx::bitlevel`.*

Headers:
- 3.1.1. “bit-level/[Bit_width.hpp](#311-examples-for-header-bit-levelbit_widthhpp)”
- 3.1.2. “bit-level/[bits_per_.hpp](#312-examples-for-header-bit-levelbits_per_hpp)”
- 3.1.3. “bit-level/[Int_.hpp](#313-examples-for-header-bit-levelint_hpp)”
- 3.1.4. “bit-level/[intlog2.hpp](#314-examples-for-header-bit-levelintlog2hpp)”
- 3.1.5. “bit-level/[sum_of_bits.hpp](#315-examples-for-header-bit-levelsum_of_bitshpp)”

#### 3.1.1. Examples for header “bit-level/Bit_width.hpp”.

*Exporting namespaces: the folder’s `cppx::bitlevel`, the library’s `cppx`.*

The `Bit_width::Enum` type, defined as

~~~cpp
struct Bit_width{ enum Enum {
    _8 = 8, _16 = 16, _32 = 32, _64 = 64, _128 = 128, system = bits_per_<void*>
}; };
~~~

… is intended as a formal parameter type where you want the argument value constrained to one in this list.

---

***Types from bit widths***  

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

template< cppx::Bit_width::Enum... n_bits >
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
    $use_cppx( Bit_width );
    cout << "Data addresses in this process are " << Bit_width::system << "-bit." << endl;
    cout << endl;
    display_info_for_<Bit_width::_8, Bit_width::_16, Bit_width::_32, Bit_width::_64>();
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
#include <cppx-core-language/bit-level/Bit_width.hpp>           // cppx::Bit_width
#include <cppx-core-language/bit-level/bits_per_.hpp>           // cppx::bits_per...
#include <cppx-core-language/bit-level/Int_.hpp>                // cppx::(Int_, Unsigned_int_)
#include <cppx-core-language/type-checking/Type_name_of_.hpp>   // cppx::type_name_of_
~~~


#### 3.1.2. Examples for header “bit-level/bits_per_.hpp”.

*Exporting namespaces: the folder’s `cppx::bitlevel`, the library’s `cppx`.*

The “bits_per_.hpp” header provides convenient notation for the bit widths of fundamental types, as `int` values: `bits_per_<T>`, `value_bits_per_<T>` and `magnitude_bits_per_<T>`.

---

***Bits per int***  
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
        Bit_width::system, bits_per_<int>, value_bits_per_<int>, magnitude_bits_per_<int>
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


#### 3.1.3. Examples for header “bit-level/Int_.hpp”.

*Exporting namespaces: the folder’s `cppx::bitlevel`, the library’s `cppx`.*

The “Int_.hpp” header provides a correspondence from bit width to integer type, via the template aliases `Int_` and `Unsigned_int_`.

An example “Types from bit widths”  is given in [3.1.1 Examples for header “bit-level/Bit_width.hpp”](#311-examples-for-header-bit-levelbit_widthhpp).


#### 3.1.4. Examples for header “bit-level/intlog2.hpp”.

*Exporting namespaces: the folder’s `cppx::bitlevel`, the library’s `cppx`.*

The “intlog2.hpp” header provides the `constexpr` function `intlog2`, which, using a number of steps logarithmic in the bit width, returns the zero based bit position of the most signficant `1` in the binary representation of the unsigned argument. I.e., it returns the integer part of the two’s logarithm.

The corresponding convenience function `intlog2r` (“r” for “reverse”) returns the bit position of the least significant `1`. The general case of `intlog2r(x)` for non-zero `x` of type `unsigned int` or wider, can be expressed as just `intlog2(x^(x-1))`. But to many code readers the name `intlog2r` is probably considerably less cryptic, it can provide tooltip documentation in an editor, and it’s more robust for use with narrow types.

Both functions return -1 when the argument is zero.

C++20 will provide a number of bit level functions via [header `<bit>`](https://en.cppreference.com/w/cpp/header/bit), also these functions restricted to unsigned:

| *C++20 function* | *Rough `intlog2` equivalence* |
|----------------|------------------|
| `std::countl_zero` | = `(x==0? value_bits_per_<decltype(x)> : intlog2(x)` |
| `std::log2pl` | = `intlog2(x) + 1` |
| `std::countr_zero` | = `(x==0? value_bits_per_<decltype(x)> : intlog2r(x))` |

Since the functions are not completely identical there may be uses for both sets.

---

***Positions of most and least significant `1` in bit pattern***  
<small>*examples/bit-level/positions-of-msb-and-lsb.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdint.hpp>     // uint32_t
#include <bitset>           // std::bitset
#include <iomanip>          // std::setw
#include <iostream>         // std::(cout, endl)

const int n_bits = 16;

template< class... Args >
void display_row( const Args&... args )
{
    static const int widths[] = {n_bits, 10, 10};
    const int* pw = widths;
    $use_std( cout, endl, setw );
    ((cout << setw( *pw++ ) << args), ...);  cout << endl;
}

auto main()
    -> int
{
    $use_std( bitset );
    $use_cppx( Unsigned_int_, intlog2, intlog2r );

    const unsigned short_pattern = 42 >> 1;
    const int n_left_zeroes = n_bits - (intlog2( short_pattern ) + 1);
    Unsigned_int_<n_bits> bits = 0;
    display_row( "Bits:", "intlog2:", "intlog2r:" );
    $repeat_times( n_left_zeroes + 2 ) {
        switch( _i ) {
            case 0:     { break; }      // Use bitpattern all zeros for first row.
            case 1:     { bits = short_pattern;  break; }
            default:    { bits <<= 1;  break; }
        }
        display_row( bitset<n_bits>( bits ), intlog2( bits ), intlog2r( bits ) );
    }
}
~~~

Here the `$repeat_times` macro evaluates the argument just once and provides that value to the loop body as `_n`, and the current loop index as `_i`, both `[[maybe_unused]]`.

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
           Bits:  intlog2: intlog2r:
0000000000000000        -1        -1
0000000000010101         4         0
0000000000101010         5         1
0000000001010100         6         2
0000000010101000         7         3
0000000101010000         8         4
0000001010100000         9         5
0000010101000000        10         6
0000101010000000        11         7
0001010100000000        12         8
0010101000000000        13         9
0101010000000000        14        10
1010100000000000        15        11
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/bit-level/Int_.hpp>            // cppx::Unsigned_int_
#include <cppx-core-language/bit-level/intlog2.hpp>         // cppx::(intlog2, intlog2r)
#include <cppx-core-language/syntax/flow-control.hpp>       // $repeat_times
~~~

#### 3.1.5. Examples for header “bit-level/sum_of_bits.hpp”.

*Exporting namespaces: the folder’s `cppx::bitlevel`, the library’s `cppx`.*

The “sum_of_bits.hpp” header provides the `sum_of_bits` function, implemented in terms of `std::bitset` as simply

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

C++20 will provide a  `std::popcount` function via [header `<bit>`](https://en.cppreference.com/w/cpp/header/bit). Unlike the present `cppx::sum_of_bits` the C++20 function will be `constexpr`. Probably this library will follow suit.

---

***Sum of bits & integral log₂***  
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
#include <cppx-core-language/syntax/collection-util.hpp>    // cppx::Sequence
~~~


### 3.2. The calculation stuff.

Folder: “**[calc](../source/cppx%2Dcore%2Dlanguage/calc)**”. *Exporting namespaces: `calc` and `m`.*

`calc` is used as a general exporting namespace for headers in the “calc” folder, but in order to minimize the risk of name collisions after C++20 the named numbers such as `pi` are exported via `m` instead (mnemonic: `m::pi` is like Posix’ `M_PI`). Hence you can have a convenient `using namespace cppx::calc` also where you have a ditto convenient `using namespace std::numbers`. I hope.

***Tip***:  
The “C++ Headers Collection” micro-library provides [a wrapper header `<cpp/calc.hpp>`](https://github.com/alf-p-steinbach/Cpp-Header-Collections/blob/master/source/cpp/calc.hpp) that includes all the calculation stuff from the standard library, including various overloads of `abs` and `div` from different standard library headers, and including both `::` and `std` namespace variants. Well, it includes “all” except the very rarely used `valarray`. Handy.

Headers:

- 3.2.1. “calc/[floating-point-operations.hpp](#321-examples-for-header-calcfloating-point-operationshpp)”
- 3.2.2. “calc/[general-operations.hpp](#322-header-calcgeneral-operationshpp)”
- 3.2.3. “calc/[integer-operations.hpp](#323-examples-for-header-calcinteger-operationshpp)”
- 3.2.4. “calc/[named-numbers.hpp](#324-examples-for-header-calcnamed-numbershpp)”
- 3.2.5. “calc/[number-type-properties.hpp](#325-examples-for-header-calcnumber-type-propertieshpp)”

#### 3.2.1. Examples for header “calc/floating-point-operations.hpp”.

*Exporting namespaces: the folder’s `cppx::calc`, the library’s `cppx`.*

The “floating-point-operations.hpp” header provides three `double` functions: `intpow(x,n)`, `squared(x)` and `cubed(x)`. All are `constexpr`. The `squared` and `cubed` functions are function templates defined in the “*general-operations.hpp*” header, which is included here for convenience.

---

***`constexpr` powers***  
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

#### 3.2.2. Header “calc/general-operations.hpp”.

*Exporting namespaces: the folder’s `cppx::calc`, the library’s `cppx`.*

The “general-operations.hpp” header provides the `squared` and `cubed` function templates already discussed in the previous section.


#### 3.2.3. Examples for header “calc/integer-operations.hpp”.

*Exporting namespaces: the folder’s `cppx::calc`, the library’s `cppx`.*

The “integer-operations.hpp” header provides a suite of `constexpr` integer functions: `is_even(x)`, `is_odd(x)`, `is_zero(x)`, `div_down(a,b)`, `div_up(a,b)` and `mod(a,b)`. In addition the “*general-operations.hpp*” header is included for convenience. It defines the functions `squared` and `cubed`.

All these functions are templated on the integer (or general number) type.

---

***Even and odd checking***  
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
#include <cppx-core-language/syntax/collection-util/Sequence_.hpp>    // cppx::(Sequence, zero_to)
~~~

---

***Zero checking***  
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
#include <cppx-core-language/syntax/collection-util/Sequence_.hpp>    // cppx::zero_to
~~~

---

***Up and down-rounding integer division***  
Throughout C++98 and C++03 the `%` remainder operator had partially implementation defined behavior, because the rounding behavior of integer `/` was unspecified. Integer `/` could round down towards negative infinity, or in towards zero. With C++11 `/` and `%` were finally completely specified, with `/` rounding in towards zero:

*C++11 §5.6/4:*
> **”** For integral operands the `/` operator yields the algebraic quotient with any fractional part discarded; if the quotient `a/b` is representable in the type of the result, `(a/b)*b + a%b` is equal to `a`.

This matches how humans and most (possibly all) computers do integer division, but it complicates the programming.

Consider, if one taxi can take 3 passengers, how many taxies are needed for a group of 10 people? Integer division `10/3` yields 3, which leaves one person stranded… The C++ expression `(10 + (3 - 1))/3` works for positive numbers, and is not uncommon. In Python, where integer division rounds down towards negative infinity, one can write the more elegant `-(10//-3)`. However, neither expression is intuitive and clear at a glance. So, this is `div_up`:

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

***Remainder for down-division***  
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


#### 3.2.4. Examples for header “calc/named-numbers.hpp”.

*Exporting namespace: `cppx::m`.*

In order to avoid potential name collisions after C++20, the names provided by “named-numbers.hpp”, like `pi`, are not made available in the folder’s namespace `calc` or in the common `cppx` namespace. But you can still use the `$use_cppx` macro to easily bring in individual unqualified names. For example, `$use_cppx( m::pi );` (think Posix `M_PI`).

This header provides

* the `double` constants `e`, `log2e`, `log10e`, `ln2`, `ln10`, `pi`, `inv_sqrt_pi`, `sqrt2` and `inv_sqrt2`;
* the `Truth` constants `has_nan`_, `has_nan`, `has_infinity_` and `has_infinity`; and
* the  `constexpr` functions `nan_`, `nan`, `infinity_` and `infinity`.

The names that end with underscore are templates. The set of double constants are defined in terms of [the Posix standard’s `M_PI` etc.](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html), if available, and otherwise simple literals, copied from a `<math.h>` header, are used. The `nan` and `infinity` functions are simple wrappers around the corresponding `std::numeric_limits` functions.

C++20’s [new header `<numbers>`](https://en.cppreference.com/w/cpp/header/numbers) will define all of the `double` constants, plus a few more esoteric ones.

---

***Values of the named constants***  
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

#define DISPLAY( name ) display( cppx::m::name, #name );

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

Specific headers:

~~~cpp
#include <cppx-core-language/calc/named-numbers.hpp>            // cppx::calc::*
#include <cppx-core-language/syntax/type-builders.hpp>    // cppx::Type_
#include <cppx-core-language-meta-macro/macro-apply.hpp>        // $apply    
~~~

---

***Degrees-to-radians conversion***  
The most common use of the named numbers is probably using `pi` in conversions between degrees and radians.

One way to judge the accuracy of that is to compute the sine or cosine of an angle with well-known simple sine or cosine. For example, which you can figure out from considering an equilateral triangle and applying Pythagora’s law, sin(60°) = sin(π/3) = ½√3. So, four times the square of that should ideally be exactly 3, and we do get pretty close:

<small>*examples/calc/trig.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/math.hpp>       // sin
#include <iostream>         // std::(cout, endl, fixed)
#include <iomanip>          // std::setprecision

auto main()
    -> int
{
    $use_std( cout, endl, fixed, setprecision );
    $use_cppx( squared );
    using namespace cppx::m;    // pi, etc.
    
    cout << "60 degrees ~= " << 60*(pi/180) << " radians." << endl;

    cout << fixed << setprecision( 20 );
    const double atp = 2*atan2( 1, 0 );     // Pi computed using arc tan of 90 degrees.
    cout << "Error when using '3.14'  : " << 4*squared( sin( 3.14/3 ) ) - 3 << "." << endl;
    cout << "Error when using arctan  : " << 4*squared( sin( atp/3 ) ) - 3 << "." << endl;
    cout << "Error when using cppx:pi : " << 4*squared( sin( pi/3 ) ) - 3 << "." << endl;
}
~~~

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
60 degrees ~= 1.0472 radians.
Error when using '3.14'  : -0.00183960128876048401.
Error when using arctan  : -0.00000000000000044409.
Error when using cppx:pi : -0.00000000000000044409.
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/calc/named-numbers.hpp>                            // cppx::m::*
#include <cppx-core-language/calc/general-operations.hpp>                       // cppx::squared
#include <cppx-core-language/syntax/declarations/macro-use_from_namespace.hpp>  // $use_std
~~~

#### 3.2.5. Examples for header “calc/number-type-properties.hpp”.

*Exporting namespaces: the folder’s `cppx::calc`, the library’s `cppx`.*

The “number-type-properties.hpp” header provides much of the same information as `std::numeric_limits`, but more consistently as `constexpr` values instead of a mix of values and functions, and more consistently with a single meaning of e.g. `min`, instead of a type-dependent meaning.

The common set of properties for any numerical type `T` is defined by

| Expression | Yields |
|------------|--------|
| `smallest_<T>` | The smallest positive non-zero `T` value. |
| `largest_<T>` | The largest positive `T` value. |
| `min_<T>` | The `T` value farthest in the direction of negative infinity. |
| `max_<T>` | The `T` value farthest in the direction of positive infinity, = `largest_<T>`. |
| `n_digits_<T>` | The number of decimal digits that can survive a round-trip to and back from `T` value. |

A possible implementation for integral types:

> ~~~cpp
> constexpr T     smallest_       = 1;                            // Smallest non-zero.
> constexpr T     largest_        = numeric_limits<T>::max();
> constexpr T     min_            = numeric_limits<T>::min();     // 0 or `-largest_ - 1`.
> constexpr T     max_            = largest;
> constexpr int   n_digits_       = numeric_limits<T>::digits10;
> ~~~

For a floating point type `T` the set has some additional properties, for which the possible implementation in terms of `numeric_limits` serves best as description:

> ~~~cpp
> constexpr T     smallest_           = numeric_limits<T>::min();     // Smallest non-zero.
> constexpr T     largest_            = numeric_limits<T>::max();
> constexpr T     min_                = -largest;                     // Largest negative.
> constexpr T     max_                = largest;
> constexpr int   n_digits_           = numeric_limits<T>::digits10;
> 
> constexpr Truth is_ieee754_format_  = numeric_limits<T>::is_iec559;
> constexpr int   min_exp_            = numeric_limits<T>::min_exponent10;
> constexpr int   max_exp_            = numeric_limits<T>::max_exponent10;
> constexpr int   radix_              = numeric_limits<T>::radix;
> constexpr T     epsilon_            = numeric_limits<T>::epsilon();
> ~~~

Note that the floating point implementation of the common 5 properties differs from the integral type implementation: with direct use of `numeric_limits` different code would be needed to express the same notions.

Also note that since `is_ieee754_format_` is defined in terms of `numeric_limits::is_iec559`, it's subject to the same compiler idiosyncracies as the latter. In particular, as of late 2019, with “fast” floating point arithmetic option selected both the g++ and Visual C++ compilers report IEEE 754 / IEC 559 conformance via `is_iec559`, while e.g. comparison of NaN values is then non-conforming. And so for the in-practice these properties are about *the binary memory representation* only, and I try to make that more clear via the name `is_ieee754_format_`.

Use of a floating point-specific property for an integral type, would most likely be an error. Therefore, unlike `std::numeric_limits` the floating point-specific properties *do not exist* for integral types. So, this set is more consistent wrt. form (value or function), more consistent wrt. meaning, more truthful, and more safe, than `std::numeric_limits`.

Not to mention that `min_<double>` is very much shorter and readable than (!) `-std::numeric_limits<double>::max()`.

---

***The properties of `bool`, `int` and `double`***  
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
            is_ieee754_format_<Type>,
            min_exp_<Type>, max_exp_<Type>, radix_<Type>, epsilon_<Type>
            );
    }
    cout << endl;
}

template< class... Type >
void display_properties_of_() { (display_properties_of_type_<Type>(),...); }

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
#include <cppx-core-language/tmp/type-checkers.hpp>               // cppx::is_floating_point_
#include <cppx-core-language/type-checking/type_name_of_.hpp>   // cppx::type_name_of_
~~~

### 3.3. Mix-in classes.

asdlkj

### 3.4. The syntax support.

Folder: “**[syntax](../source/cppx%2Dcore%2Dlanguage/syntax)**”. *Exporting namespace: `syntax`.*

Some headers in this folder have their own smaller exporting namespaces in addition to `syntax`, e.g. namespace `cppx::string_operators`. These per-header namespaces provide more fine grained control over which identifiers you bring in unqualified. And of course, in the other direction, just `using namespace cppx;` brings in everything plus plus.

---

This folder contains the direct support for expressing things in ways that feel like a new syntax, and/or that expose strong potentials for improvements in the existing C++ syntax.

An example: though the purely *syntactical* aspect was introduced in C++11, the indexing loop `for(const int i: zero_to(n))` can feel like a new syntax. The shortcoming of C++17 here isn’t syntactical, it’s just the lack of a function like `zero_to` (C++20 will introduce the less than intelligently named [`std::views::iota`](https://en.cppreference.com/w/cpp/ranges/iota_view)). Also as an example, the declaration `$use_std(cout,endl,setw);` exposes a strong potential for improvement in the existing C++ syntax, namely its requirement that you repeat the namespace name for each name that you want to use unqualified.

The syntax support is intended to give you a more [DRY](https://en.wikipedia.org/wiki/Don%27t_repeat_yourself) and more joyful C++ coding experience, via

* automation of required repetitions of information, e.g. for `using` declarations,
* easy ways to express constraints such as a `const` loop variable, and
* recognizable common abstractions of coding patterns such as `throw` with source location.

Main headers:

- 3.4.1. “syntax/[collection-util.hpp](#341-examples-for-header-syntaxcollection-utilhpp)”
- 3.4.2. “syntax/[declarations.hpp](#342-examples-for-header-syntaxdeclarationshpp)”
- 3.4.3. “syntax/[exception-throwing.hpp](#343-examples-for-header-syntaxexception-throwinghpp)”
- 3.4.4. “syntax/[flow-control.hpp](#344-examples-for-header-syntaxflow-controlhpp)”
- 3.4.5. “syntax/[string-expressions.hpp](#345-examples-for-header-syntaxstring-expressionshpp)”
- 3.4.6. “syntax/[types.hpp](#346-examples-for-header-syntaxtypeshpp)”

---

There are 6 main areas, each in a sub-folder with a small set of detail headers. The detail headers are not documented here; see the source code for detail header names etc. Each sub-folder *X* has a corresponding header “*X*.hpp” that includes the detail headers from that sub-folder, and it has an exporting namespace `cppx::`*X*.

| Area | *X*.hpp | Functionality |
|------|---------|---------------|
| Collection handling | “collection-util.hpp” | Mainly a general `is_empty` function and the `$items_of` syntactic sugar macro. |
| Declaration statements| “declarations.hpp” | `using` ordinary names from a given namespace unqualified, e.g. via `$use_std`; declaring aliases of nested namespaces without repeating the names, most generally via `$alias_namespaces_from`; defining or redeclaring tag types via `$define_tag`; and the construct `$with` for executing a block with a variable scoped to that block, like the C# and Java auto cleanup constructs (C# `using`, Java `try()`). This is all necessarily macro-based. One wishes for ch-ch-ch-changes. |
| Exception throwing | “exception-throwing.hpp” | Primarily `fail` for writing things like `do_something() or fail("Oops")`. The `hopefully` function to use in conjunction with `fail`, plus the ditto more advanced syntax `>>` *Property*. Both `hopefully` and `>>` rely on short circuit evaluation of `or` to avoid evaluation of the argument(s) to `fail` except when it’s actually called. |
| Flow control | “flow-control.hpp” | Class templates `Sequence_` and `Span_`, plus supporting functions such as `zero_to`, let you used safer, shorter and more readable range based `for` loops in a great many cases, with the same efficiency as index based loops. `Sequence_` is for integers and `Span_` is for arrays. However, the types also have other uses and so their definitions reside in the “types” sub-folder. The headers are included here for convenience. This sub-folder itself defines the macro `$repeat_times` to repeat something *n* times; a corresponding non-macro function `repeat_times` (less convenient but it’s just *not a macro*); and the `[[noreturn]]` function `noreturn` that throws integer `666`, which can help to avoid silly­warnings. |
| Creating or<br> assembling<br> `std::string`s | “string-expressions.hpp” | A `<<` notation in order to assemble text pieces and io-streamable values, which can be very convenient for function arguments, e.g. for `fail`; operator `*` to specify *n* repeats of a string; and pseudo-operator `^sz` to call `.c_str()`. |
| Type machinery | “types.hpp” | The type builders such as `Type_` let you avoid nasty C type expressions, and let you use prefix `const` consistently. Class templates `Sequence_` and `Span_` are mainly in support of range based `for` loops. However, a `Sequence_` is nice as a simple set of a contiguous range of values, and a `Span_` is useful as a formal parameter type. |

#### 3.4.1. Examples for header “syntax/collection-util.hpp”.

In C++17 and earlier C++ standards the standard library algorithms that operate on sequences, like `std::sort`, generally take two iterators as arguments: a  “begin” iterator that refers to the start of the sequence, and an “end” iterator that refers to just beyond the sequence. For example, `std::sort(std::begin(the_numbers),std::end(the_numbers))`. The standard is very annoyingly at odds with the Don't Repeat Yourself principle for all these algorithms.

To help with that the lvalue-restricted macro `$items_of` and its sibling `$reverse_items_of` allow you to write things like `std::sort($items_of(v))` instead of `std::sort(std::begin(v),std::end(v))`. With C++20 the Ranges sub-library of the standard library will define overloads of `sort` etc. that admit similarly or even more concise & DRY calls. However, that doesn’t help with 3ʳᵈ party libraries that require iterator pairs, while `$items_of` does help in general.

“syntax/collection-util.hpp” includes the standard library’s `<iterator>` header and defines the `$items_of` macro as


~~~cpp
#ifndef CPPX_NO_DOLLARS_PLEASE
#   define  $items_of CPPX_ITEMS_OF
#endif

#define CPPX_ITEMS_OF( c ) \
    std::begin( cppx::lvalue_ref_to( c ) ), \
    std::end( c )
~~~

… where `lvalue_ref_to` implements a restriction to lvalue.

`$items_of(c)`, where `c` must be an lvalue expression, produces (as-if) the iterator pair text “`std::begin(c),std::end(c)`”. For example, you can write just `std::sort($items_of(the_numbers))`. The name of a variable is an lvalue expression.

If `c` is an rvalue expression, e.g. a temporary such as a value result of a function call, then by design you get a compilation error. This *lvalue restriction* removes almost all cases where an argument expression could have its side effect or resource usage duplicated. However, for an rvalue expression `c` one can write the non-expression statement

>     $with( expression ) { foobar( $items_of( _ ) ); }

The `$reverse_items_of` macro is mainly for completeness, as a complement of `$items_of`.

Definition:

~~~cpp
#ifndef CPPX_NO_DOLLARS_PLEASE
#   define  $reverse_items_of CPPX_REVERSE_ITEMS_OF
#endif

#define CPPX_REVERSE_ITEMS_OF( c ) \
    std::make_reverse_iterator( std::end( cppx::lvalue_ref_to( c ) ) ), \
    std::make_reverse_iterator( std::begin( c ) )
~~~

---

***Sorting and searching of a raw array***  

In the following example I use a raw array for `sorted_digits`, which complicates things a little, in order to show how `$items_of` also works nicely with a raw array:

<small>*examples/syntax/sort-and-search.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <iostream>         // std::(cout, endl)
#include <algorithm>        // std::(copy, sort, equal_range)
#include <string_view>      // std::string_view

auto main()
    -> int
{
    $use_std( copy, cout, endl, equal_range, sort, string_view );

    constexpr string_view   pi_digits   = "3141592653589793238462643383279";      // 30 decimals.
    constexpr int           n_digits    = pi_digits.length();
    
    char sorted_digits[n_digits];
    copy( $items_of( pi_digits ), &sorted_digits[0] );
    sort( $items_of( sorted_digits ) );

    cout << pi_digits << endl;
    cout << string_view( sorted_digits, n_digits ) << endl;
    
    const auto range_pair = equal_range( $items_of( sorted_digits ), '6' );
    const int n = range_pair.second - range_pair.first;
    if( n == 0 ) {
        cout << "... No 6-digits, weird." << endl;
    } else {
        using namespace cppx::syntax;
        cout << spaces( range_pair.first - &sorted_digits[0] ) << n*"^"s << endl;
        cout << "The digit 6 occurs " << n << " times." << endl;
    }
}
~~~

C++17’s `string_view` is one of the rare cases (for the standard library) where a span is not specified via a pair of iterators. It could have followed the precedent of the `std::vector` constructor design, but it didn’t. And so `$items_of` could not be used in the construction of the `string_view` in the output of `sorted_digits`.

The output via a `string_view` could alternatively have been accomplished e.g. via `std::copy` and an output stream iterator, which is a more general approach:

>     copy( $items_of( sorted_digits ), ostream_iterator<char>( cout ) );  cout << endl;

Anyway, result with 64-bit MinGW g++ in Windows 10:

~~~txt
3141592653589793238462643383279
1122223333333444555666778889999
                   ^^^
The digit 6 occurs 3 times.
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/syntax/collection-util.hpp>        // $items_of
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::(spaces, n*s)
~~~

---

***Direct `$reverse_items_of`, and combined with `span_of`***  
The following example first shows direct use of `$reverse_items_of` with a standard library function, namely `std::copy`, and then shows it used in combination with the Core Language Extensions library’s `span_of`:

<small>*examples/syntax/palindrome.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <algorithm>            // std::copy
#include <iostream>
#include <iterator>             // std::ostream_iterator
#include <string>               // std::string
#include <string_view>          // std::string_view
#include <vector>               // std::vector
$use_std( string, string_view, vector );
$alias_cppx_namespaces( ascii );

struct Classified
{
    string          letters;
    vector<string>  non_letters;

    Classified( const string_view& s ) {
        for( const char ch: s ) {
            if( ascii::is_letter( ch ) ) {
                letters += ch;
            }
        }

        non_letters.resize( letters.size() + 1 );
        int i = 0;
        for( const char ch: s ) {
            if( ascii::is_letter( ch ) ) {
                ++i;
            } else {
                non_letters[i] += ch;
            }
        }
    }
};

auto main()
    -> int
{
    $use_std( ostream_iterator, cout, endl );
    $use_cppx( span_of );
    
    const auto s = string_view( "$$$ A man, a plan, a canal: panama!" );

    copy( $reverse_items_of( s ), ostream_iterator<char>( cout ) );
    cout << "  (reversed)" << endl;
    
    const auto the = Classified( s );
    int i = 0;
    cout << the.non_letters[0];
    for( const char ch: span_of( $reverse_items_of( the.letters ) ) ) {
        cout << ch;
        ++i;
        cout << the.non_letters[i];
    }
    cout << "  (smart-reversed)" << endl;
    
    cout << s << "  (original)" << endl;
}
~~~

Here the `span_of` function creates a little object holding the two iterators and providing them via `.begin()` and `.end()` member functions to the C++ range based `for`, i.e., it’s just shallow (but important) syntactical glue.

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
!amanap :lanac a ,nalp a ,nam A $$$  (reversed)
$$$ a man, a plan, a canal: panamA!  (smart-reversed)
$$$ A man, a plan, a canal: panama!  (original)
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/syntax/declarations.hpp>               // $alias.., $use_...
#include <cppx-core-language/syntax/macro-reverse_items_of.hpp>     // $reverse_items_of
#include <cppx-core-language/syntax/types.hpp>                      // cppx::span_of
#include <cppx-core-language/text/ascii-character-util.hpp>         // cppx::ascii
~~~


#### 3.4.2. Examples for header “syntax/declarations.hpp”.
#### 3.4.3. Examples for header “syntax/exception-throwing.hpp”.

#### 3.4.4. Examples for header “syntax/flow-control.hpp”.

*Exporting namespaces: the folder’s `cppx::syntax`, the library’s `cppx`.*

The “flow-control.hpp” header mainly provides the templated types `Sequence_` and `Span_`, as support for the range based `for` loop.

Since these types are more generally usable their definitions reside elsewhere, in the “syntax/types” folder. In this section is discussion and examples of their use with the range based `for`. In [the “syntax/types” section]((#347-examples-for-header-syntaxtypeshpp)) is discussion and examples of more general use.

In addition to the above two types & their support functions, “flow-control.hpp” provides a macro `$repeat_times`; a ditto function `repeat_times`; and the `[[noreturn]]` function `noreturn`.

---

***The efficiency of a range based `for` using a `Sequence_`.***  
The vast majority of loops are simple C style counting `for` loops that can be more clearly and safely expressed as C++11 range based loops. A range based loop often also yields shorter code, which further helps clarity. However, one may shy away from doing that because [the TANSTAAFL principle](https://en.wikipedia.org/wiki/There_ain%27t_no_such_thing_as_a_free_lunch) popularized by Heinlein — *There Ain’t No Such Thing As A Free Lunch* — rules the universe in general, and so surely there must be some huge overhead, yes?

*Without* any optimization the range based loop indeed generates a lot of inefficient machine code, probably so that one can delve into it with a debugger. But with the g++ compiler *with* just option `-O`, the lowest lowest level of actual optimization, all that disappears. The machine code is then just as with the more complex and unsafe C style loop.

The same happens with the Visual C++ compiler.

<small>*examples/syntax/c-style-versus-range-based-with-Sequence.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

namespace examples {
    $use_cppx( zero_to );

    void c_style()
    {
        for( int i = 0; i < 10; ++i ) {
            printf( "%d ", 100 + i );
        }
        printf( "\n" );
    }

    void cpp_range_based()
    {
        for( const int i: zero_to( 10 ) ) {
            printf( "%d ", 200 + i );
        }
        printf( "\n" );
    }
}

auto main()
    -> int
{
    examples::c_style();
    examples::cpp_range_based();
}
~~~

Here the call `zero_to(10)` produces a `Sequence_<int>` of 0 through 9.

PC machine code in Intel assembly notation with 64-bit MinGW g++ 9.2, generated by

    g++ -std=c++17 c-style-versus-range-based-with-Sequence.cpp -S -masm=intel -O

~~~assembly
; The loop in c_style():             | ; The loop in cpp_range_based():
                                     |
    mov ebx, 100                     |     mov ebx, 200
    lea rsi, .LC0[rip]               |     lea rsi, .LC0[rip]
.L3:                                 | .L6:
    mov edx, ebx                     |     mov edx, ebx
    mov rcx, rsi                     |     mov rcx, rsi
    call    _ZL6printfPKcz           |     call    _ZL6printfPKcz
    inc ebx                          |     inc ebx
    cmp ebx, 110                     |     cmp ebx, 210
    jne .L3                          |     jne .L6
~~~

PC machine code in Intel assembly notation with 64-bit Visual C++ 2019, generated by

    cl /std:c++17 /Zc:__cplusplus /FI"iso646.h" /EHsc c-style-versus-range-based-with-Sequence.cpp /FA /O1

~~~assembly
; The loop in c_style():                            | ; The loop in cpp_range_based():
                                                    |
    xor ebx, ebx                                    |     xor ebx, ebx
$LL4@c_style:                                       | $LL4@cpp_range_:
    lea edx, DWORD PTR [rbx+100]                    |     lea edx, DWORD PTR [rbx+200]
    lea rcx, OFFSET FLAT:??_C@_03JDANDILB@?$CFd?5@  |     lea rcx, OFFSET FLAT:??_C@_03JDANDILB@?$CFd?5@
    call    printf                                  |     call    printf
    inc ebx                                         |     inc ebx
    cmp ebx, 10                                     |     cmp ebx, 10
    jl  SHORT $LL4@c_style                          |     jne SHORT $LL4@cpp_range_
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/syntax/flow-control.hpp>   // cppx::zero_to
~~~


#### 3.4.5. Examples for header “syntax/string-expressions.hpp”.
*Exporting namespaces: `string_expressions`, the folder’s `cppx::syntax`, the library’s `cppx`.  
Smaller functional area exporting namespaces: `basic_string_assembly` and `string_operators`.*

Provides a `<<` notation in order to assemble text pieces and io-streamable values, which can be very convenient for function arguments, e.g. for `fail`; a `*`-notation to specify *n* repeats of a string; and pseudo-operator `^sz` to call `.c_str()`.

The `*` operator just invokes the function `repeated_times`, e.g. `7*"yes"s` invokes `repeated_times(7,"yes"s)`, and for convenience and optimization functions `spaces` and `dashes`, which also just (as-if) call `repeated_times`, are provided.

These notations play well together, e.g. like

>     infobox( "The answer is "s << 6*7 << "." ^sz );

The `<<` notation is available on its own via exporting namespace `basic_string_assembly` and ditto sub-header, and the `*` and `^sz` (pseudo-) operators are available on their own via exporting namespace `string_operators` and ditto sub-header.

There is no stream object that persists from one `<<` invocation to the next, and therefore manipulators such as `std::setprecision` have no effect. Use of the simplest manipulators such as `endl` and `fixed` is detected and transformed to compilation errors. However, the stateful manipulators such as `std::setprecision` have no identifying features apart from their individual types, so use of such manipulators is not detected and will compile, but with no result effect.

---

***Basic string assembly notation***  
As a first example, instead of

>     display( "Welcome, user #" + to_string( user_id ) + "!" );

… one writes just

>     display( "Welcome, user #"s << user_id << "!" );

Here the `s` suffix essentially produces a `std::string` type object, via the standard library’s `operator""s`, and the `user_id`, if it is numeric or other non-string, is converted (as-if) via a `std::ostringstream` with default options, except that (as-if) `std::boolalpha` is applied so that boolean values result in text “true” and “false”.

---

***Generating a C string pointer***

The pseudo-operator notation *some_std_string* `^sz` for invoking the `.c_str()` member function can be practically useful when the left operand is a general `std::string` type expression and not just a variable or literal.

**`^`** has lower precedence than `<<`, so `^sz` can be placed at the end of a basic string assembly expression.

<small>*examples/syntax/sz.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( m::pi );
    using namespace cppx::syntax;       // s, "<<", "^" and sz.

    printf( "Pi is roughly "s << pi << ", or thereabouts.\n" ^sz );
}
~~~

Imagine that instead of `printf` the above uses some 3ʳᵈ party library function that takes a C string pointer argument.

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
Pi is roughly 3.14159, or thereabouts.
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/calc/named-numbers.hpp>            // cppx::m::pi
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::*
~~~

---

***Invoking custom `<<` operators***  
Some of the standard library’s conversion-to-text functionality is expressed as `operator<<` overloads for iostreams output, and that means that the Core Language Extensions string assembly sometimes is not just more efficient and concise than `+` concatenation, but also saves you from declaring helper variables and/or support functions.

<small>*examples/syntax/error-code-logging.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>      // fprintf, stderr
#include <system_error>     // std::(errc, make_error_code)
$use_cppx( Type_ );

void log( const Type_<const char*> s ) { fprintf( stderr, "!%s\n", s ); }

auto main()
    -> int
{
    $use_std( errc, make_error_code );
    using namespace cppx::syntax;

    const auto code = make_error_code( errc::network_down );
    log( "Oops - error code " << code << " (" << code.message() << ")." ^sz );
}
~~~

Result with Visual C++ 2019 in Windows 10:

~~~txt
!Oops - error code generic:116 (network down).
~~~

The text part “generic: 116” is produced by the standard library’s iostream `<<` output support for error codes. That `<<` operator is invoked in the internal implementation of the string assembly notation’s `<<`, where the error code object is output to a `std::ostringstream`. In passing: with MinGW g++ 9.2 the text part “network down” is replaced with “Unknown error”, which is a deficiency of that compiler’s standard library implementation.

Why no `s` suffix?

The `s` suffix or other measure to ensure type `std::string` for the left operand of `<<` is necessary when both operands of `<<` are otherwise of primitive type, such as `const char*` and `int` — because one can’t overload operators for just primitive type arguments. However, after the first `<<` the left hand side of the subsequent `<<` invocations is of type `std::string`, so an `s` suffix can only be necessary for the first item. Also, when the right hand side is of class type there is no such problem so then one can do without an `s` suffix, and that’s the situation in the above code.

Specific headers:

~~~cpp
#include <cppx-core-language/syntax/declarations.hpp>           // $use_std
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::*
~~~

---

***English and numerical specifications of booleans***  
The Core Language Extensions string assembly translates booleans to “false” and “true” by default, because arranging that would be quite inconvenient if it weren’t the default. Getting “0” and “1” instead, where that’s desired for a value, is as easy as writing a **`+`** in front of the value. That's the old *promotion trick*, also useful for e.g. displaying the numerical value of a `char`.

Unfortunately, with the standard library’s iostreams the default is the opposite, so that one has to apply the `std::boolalpha` manipulator to get “false” and “true”.

For example, both programs below produce the following output:

~~~txt
Most people say that 2 + 2 = 4 is true.
However, some people maintain that 2 + 2 = 4 is 1...
~~~

A program using only the standard library:

<small>*examples/syntax/booleans-as-truth-values.stdlib.cpp*</small>
~~~cpp
#include <stdlib.h>     // printf
#include <sstream>      // std::ostringstream
#include <string>       // std::string
using std::boolalpha, std::string, std::ostringstream;

void say( const string& s ) { printf( "%s\n", s.c_str() ); }

auto main()
    -> int
{
    ostringstream stream;
 
    stream << boolalpha;
    stream << "Most people say that 2 + 2 = 4 is " << (2 + 2 == 4) << ".";
    say( stream.str() );
    
    stream = ostringstream();   // Reset. Effect as-if with `std::noboolalpha` is default.
    stream << "However, some people maintain that 2 + 2 = 4 is " << (2 + 2 == 4) << "...";
    say( stream.str() );
}
~~~

Corresponding program using (also) the Core Language Extensions library and its string assembly support:

<small>*examples/syntax/booleans-as-truth-values.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdlib.hpp>     // printf
#include <string>           // std::string
$use_std( string );
using namespace cppx::syntax;

void say( const string& s ) { printf( "%s\n", s.c_str() ); }

auto main()
    -> int
{
    say( "Most people say that 2 + 2 = 4 is "s << (2 + 2 == 4) << "." );
    say( "However, some people maintain that 2 + 2 = 4 is "s << +(2 + 2 == 4) << "..." );
}
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/syntax/declarations.hpp>           // $use_std
#include <cppx-core-language/syntax/string-expressions.hpp>     // cppx::syntax::*
~~~

---

***Floating point value formatting***

The default iostreams presentation of floating point values, e.g. like `3.14159` with six digits, is sometimes/often insufficient or at least undesired. To address that issue the following functions are provided:

|Function: | *As-if* this effect internally in a string assembly expression evaluation:|
|---------|------- |
| `fp::smart`(*v*, *n*) | `stream << std::defaultfloat << std::setprecision( n ) << v`
| `fp::fix`(*v*, *n*)   | `stream << std::fixed << std::setprecision( n ) << v`
| `fp::sci`(*v*, *n*)   | `stream << std::scientific << std::setprecision( n ) << v`
| `fp::sci_uc`(*v*, *n*) | `stream << std::scientific << std::uppercase << std::setprecision( n ) << v`

For the `smart` function *n* specifies the total number of digits, while for the other functions it specifies the number of fractional part digits, a.k.a. decimals. For all four functions it defaults to 6 because that’s the iostreams default. The iostreams in turn default to 6 because that was/is the default in C’s `printf` family of functions.

Each function produces an instance of `fp::Text_spec`, which contains the specified value as a `double`, and information about the desired formatting, which is then used by the string assembly `<<` machinery (and can be used in other ways by other code).

The `fp` namespace with these functions and the `Text_spec` class etc. is provided by the  “format-specs.hpp” header in the “text” folder, and that header is included by “string-expressions.hpp”.

Exporting namespaces for the `fp` namespace:
* the defining header’s own `cppx::format_specs`,
* the defining header’s folder namespace `cppx::text`,
* for convenience also the folder namespace `cppx::syntax`, and
* the general `cppx`.

<small>*examples/syntax/fp-values-in-string-assembly.cpp*</small>
~~~cpp
#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>
#include <string>
$use_std( string );

void say( const string& s ) { printf( "%s\n", s.c_str() ); }

auto main()
    -> int
{
    $use_cppx( intpow, m::pi, n_digits_, spaces, Sequence );
    using namespace cppx::syntax;       // "<<"

    const int max_decimals = n_digits_<double> - 1;
    say( "Pi is roughly "s << pi << ", or thereabouts." );
    say( "More precisely it's "s << fp::fix( pi, max_decimals ) << ", and so on." );

    say( "" );
    for( const int n: Sequence( 0, max_decimals ) ) {
        const double c = intpow( 10, n );
        const int n_spaces = 30 - n + (n == 0);
        say( ""s << fp::fix( pi, n ) << spaces( n_spaces ) << fp::sci( c*pi ) );
    }
}
~~~

The `spaces` function usage here is a kludge to achieve column formatting for a fixed width console window font. The string assembly syntax doesn’t support such formatting in general. The minimal formatting support for floating point values is there out of necessity, because it’s generally needed in order to create strings with the desired content.

Result with 64-bit MinGW g++ in Windows 10:

~~~txt
Pi is roughly 3.14159, or thereabouts.
More precisely it's 3.14159265358979, and so on.

3                               3.141593e+00
3.1                             3.141593e+01
3.14                            3.141593e+02
3.142                           3.141593e+03
3.1416                          3.141593e+04
3.14159                         3.141593e+05
3.141593                        3.141593e+06
3.1415927                       3.141593e+07
3.14159265                      3.141593e+08
3.141592654                     3.141593e+09
3.1415926536                    3.141593e+10
3.14159265359                   3.141593e+11
3.141592653590                  3.141593e+12
3.1415926535898                 3.141593e+13
3.14159265358979                3.141593e+14
~~~

Specific headers:

~~~cpp
#include <cppx-core-language/calc/floating-point-operations.hpp>    // cppx::intpow
#include <cppx-core-language/calc/named-numbers.hpp>                // cppx::m::pi
#include <cppx-core-language/calc/number-type-properties.hpp>       // cppx::n_digits_
#include <cppx-core-language/syntax/types.hpp>                      // cppx::Sequence
#include <cppx-core-language/syntax/string-expressions.hpp>         // cppx::syntax::*
~~~

#### 3.4.6. Examples for header “syntax/types.hpp”.


### 3.5. The system dependent stuff.

### 3.6. The text handling.


### 3.7. The template meta programming support.

### 3.8. The type checking support.

### 3.9. Supporting types.
