# The cppx-core-language micro library

Originally a sub-folder in the *cppx-core* project, the ***cppx-core-language*** header micro-library provides workarounds for various shortcomings of the C++ core language.

For example, the all-directions implicit conversions for the built-in `bool` type sometimes cause problems with overload resolution. One infamous case is that of iostreams output of a function pointer resulting in the text “1”, via an unexpected conversion to `bool`. *cppx-core-language* offers the alternative `cppx::Truth`, which converts implicitly only to and from `bool`, as a drop-in replacement.

Even if you don&rsquo;t use it for anything else you may find it useful to use a `vector<Truth>` instead of `vector<bool>`, because with the `vector<Truth>` you can have a reference or pointer to an item.

## 1. Installation & use.

After cloning, checking out or downloading the library:

1. Make the library source code available via C++ include path &ldquo;`cppx-core-language/`&rdquo;.  
   ***Info***: in Windows I prefer to use junctions in a common include folder. E.g., in that folder I&rsquo;d use the command `mklink /j cppx-core-language c:\somewhere\cppx-core-language\source\cppx-core-language`. With a junction you don't have to configure Windows to developer mode to create it, and you can remove it with an `rd` command, consistent with its use for other things that act like directories. However, in \*nix a symlink would be natural. But just copying the source folder is also fine.  
   ***Test***: for example, `#include <cppx-core-language/all.hpp>` should now work in C++ source code.

2. Ditto, make the &ldquo;C header wrappers&rdquo; source code available via C++ include path &ldquo;`c/`&rdquo;.  
   ***Info***: &ldquo;C header wrappers&rdquo; is a project that *cppx-core-language* depends on. You find it as a GIT sub-module in the folder &ldquo;dependencies&rdquo;.  
   ***Test***: For example, `#include <c/stdio.hpp>` should work.  

Test the installation with a simple C++ program using the include directive

>     #include <cppx-core-language/all.hpp>

This is a pure header library so you don't need to build or link with anything (other than the program itself).

However, the automated unit tests use Boost Test framework and so running the automated unit tests additionally requires the Boost library.

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



