﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#include <cppx-core-language/assert-cpp/is-c++17-or-later.hpp>
/// \file
/// \brief Simple type builders
/// \make_name_ref{cppx,Type_},
/// \make_name_ref{cppx,Func_},
/// \make_name_ref{cppx,P_},
/// \make_name_ref{cppx,R_},
/// \make_name_ref{cppx,Raw_array_} and
/// \make_name_ref{cppx,Raw_array_of_}.
///
/// The more safe standard library generators such as std::add_pointer_t
/// are not used because they would prevent template argument deduction. The basic
/// builders defined here are just names for the conventional way of writing e.g.
/// formal argument types, i.e. they're simple assemblers. As such they carry
/// the same risk of unintended type result as the raw operator notation does,
/// but they have advantages such as supporting uniform `const` first notation,
/// more generally read-left-to-right declarations, and being self-descriptive.

#include <cppx-core-language/syntax/declarations.hpp>           // CPPX_USE_CPPX

#include <c/stddef.hpp>     // size_t
#include <array>            // std::array

namespace cppx::type_builders {
    using std::array;

    //----------------------------------------------- Specialized basic builders:
    //

    /// \brief Makes a C style type specification substitutable.
    ///
    /// `Type_<T>` is the type denoted by the type expression `T`, wrapped up so that
    /// other type builders (e.g. `const`) can be applied to it.
    ///
    /// E.g. instead of the difficult-to-parse
    ///
    ///     int (& (*const fp)())[42];
    ///
    /// you can write it with prefix `const` as
    ///
    ///     const Type_< Type_<auto()->Type_<int[42]>&>* > fp;
    ///
    /// although for this particular example using the `#P_` and `#R_` type builders is more clean:
    ///
    ///     const P_< auto()->R_<int[42]> > fp;
    ///
    /// Credit: I first saw a template like `Type_` suggested by Johannes “litb” Schaub.
    template< class Some_type >
    using Type_ = Some_type;

    /// `Func_<R, A1, A2, A3>` is the type denoted by the type expression
    /// `auto(A1, A2, A4) -> R`, wrapped up so that other type builders can be applied.
    /// Note that `const` **can't** be applied to a function type. Or, g++ doesn't
    /// support it.
    template< class Result, class... Args >
    using Func_ = auto( Args... ) -> Result;

    /// \brief Creates a raw pointer type.
    ///
    /// `P_<T>` is the type denoted by `Type_<T>*`, wrapped up. It's equivalent to writing
    /// `Type_<Type_<T>*>`. Except for missing template argument deduction ability and
    /// added verbosity it can also be expressed as `std::add_pointer_t<T>`.
    template< class Some_type >
    using P_ = Some_type*;

    /// \brief Included for completeness, creates an lvalue reference type.
    ///
    /// `R_<T>` is the type denoted by `Type_<T>&`, wrapped up. It's equivalent to writing
    /// `Type_<Type_<T>&>`. Except for missing template argument deduction and added
    /// verbosity it can also be expressed as `std::add_lvalue_reference_t<T>`.
    ///
    /// Preferably write just `T&` or `Type_<T>&`, and not the less eye-friendly `R_<T>`.
    template< class Some_type >
    using R_ = Some_type&;

    //----------------------------------------------- Arrays:
    //

    /// \brief Ceates a raw array type of unknown size.
    ///
    /// `Raw_array_<T>` is the type denoted by `Type_<T>[]`, wrapped up. It's equivalent to
    /// writing `Type_<Type_<T>[]>`. The C++17 standard library provides no notation for
    /// this.
    ///
    /// A raw array of unknown size can acquire a size via an initializer, e.g.
    /// `const Raw_array_of<int> numbers = {1, 2, 3};` (where the size is then 3).
    template< class Item >
    using Raw_array_ = Item[];

    /// \brief Creates a raw array type of a specified size.
    ///
    /// `Raw_array_of_<n, T>` is the type denoted by `Type_<T>[n]`, wrapped up. It's
    /// equivalent to writing `Type_<Type_<T>[n]>`. The C++17 standard library provides no
    /// notation for this.
    template< size_t n, class Item >
    using Raw_array_of_ = Item[n];

    /// \brief `Array_of_<n, T>` is just more left-to-right direction readable than
    /// `std::array<T, n>`, which is the type it produces.
    template< size_t n, class Item >
    using Array_of_                 = array<Item, n>;

    /// \brief Provides
    /// \make_name_ref{cppx,Type_},
    /// \make_name_ref{cppx,P_},
    /// \make_name_ref{cppx,R_},
    /// \make_name_ref{cppx,Raw_array_},
    /// \make_name_ref{cppx,Raw_array_of_} and
    /// \make_name_ref{cppx,Array_of_}.

    /// Self-descriptive but more wordy `Ptr_` and `Ref_` aliases for
    /// `P_` and `R_`.
    namespace ptr_and_ref
    {
        template< class T > using Ptr_ = P_<T>;
        template< class T > using Ref_ = R_<T>;
    }   // namespace ptr_and_ref
}  // namespace cppx::type_builders

namespace cppx
{
    using namespace type_builders;
}  // namespace cppx
