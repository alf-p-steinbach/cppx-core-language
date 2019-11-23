﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
/// \file
/// \brief
/// \make_name_ref{cppx,is_base_and_derived_},
/// \make_name_ref{cppx,is_same_type_},
/// \make_name_ref{cppx,is_a_},
/// \make_name_ref{cppx,is_trivially_copyable_},
/// \make_name_ref{cppx,is_const_},
/// \make_name_ref{cppx,is_class_},
/// \make_name_ref{cppx,is_fixed_point_},
/// \make_name_ref{cppx,is_floating_point_},
/// \make_name_ref{cppx,is_integral_},
/// \make_name_ref{cppx,is_signed_},
/// \make_name_ref{cppx,is_unsigned_},
/// \make_name_ref{cppx,is_arithmetic_},
/// \make_name_ref{cppx,is_enum_},
/// \make_name_ref{cppx,is_nullpointer_},
/// \make_name_ref{cppx,is_pointer_},
/// \make_name_ref{cppx,is_scalar_},
/// \make_name_ref{cppx,is_a_basic_char_type_} and
/// \make_name_ref{cppx,is_a_char_type_}.
///
/// `is_based_and_derived_` clarifies the roles of the template arguments, which are not
/// apparent in `std::is_base_of_t`. `is_based_and_derived_` is also more clean regarded
/// as English. `is_const` doesn't care if you feed it a reference, it then reports about
/// the referent type. The numerical category type traits provide a common notation for
/// checking also for fixed point type, which is an omission in the standard library. But
/// in general it's all mainly about readability and convenience.

#include <cppx-core-language/types/Truth.hpp>                   // cppx::Truth

#include <type_traits>      // std::(is_*, std::remove_reference_t)

namespace cppx
{
    //----------------------------------------------------------------------------------------------

    template< class Base, class Derived >
    constexpr Truth is_base_and_derived_    = std::is_base_of_v<Base, Derived>;

    template< class T, class U >
    constexpr Truth is_same_type_           = std::is_same_v<T, U>;

    template< class T, class U >
    constexpr Truth is_a_                   = is_same_type_<T, U> or is_base_and_derived_<T, U>;

    //----------------------------------------------------------------------------------------------

    template< class T >
    constexpr Truth is_trivially_copyable_  = std::is_trivially_copyable_v<T>;

    template< class T >
    constexpr Truth is_const_               = std::is_const_v<std::remove_reference_t<T>>;

    template< class T >
    constexpr Truth is_class_               = std::is_class_v<T>;

    template< class T >
    constexpr Truth is_fixed_point_         = false;

    template< class T >
    constexpr Truth is_floating_point_      = std::is_floating_point_v<T>;

    template< class T >
    constexpr Truth is_integral_            = std::is_integral_v<T>;

    template< class Int >
    constexpr Truth is_signed_              = std::is_signed_v<Int>;

    template< class Int >
    constexpr Truth is_unsigned_            = std::is_unsigned_v<Int>;

    template< class T >
    constexpr Truth is_arithmetic_          = std::is_arithmetic_v<T>;

    template< class T >
    constexpr Truth is_enum_                = std::is_enum_v<T>;

    template< class T >
    constexpr Truth is_nullpointer_         = std::is_null_pointer_v<T>;

    template< class T >
    constexpr Truth is_pointer_             = std::is_pointer_v<T>;

    template< class T >
    constexpr Truth is_scalar_              = std::is_scalar_v<T>;

    //----------------------------------------------------------------------------------------------

    template< class Char >
    constexpr Truth is_a_byte_char_type_ =
        is_same_type_<Char, char> or
        is_same_type_<Char, unsigned char> or
        is_same_type_<Char, signed char>;

    template< class Char >
    constexpr Truth is_a_char_type_ =
        is_a_byte_char_type_<Char> or
        is_same_type_<Char, wchar_t> or
        is_same_type_<Char, char16_t> or
        is_same_type_<Char, char32_t>;
        // For C++20 maybe add `char8_t` Ada-ish monstrosity to the list.

}  // namespace cppx