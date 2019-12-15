#include <cppx-core-language/calc/number-type-properties.hpp>   // cppx::calc::*
#include <cppx-core-language/tmp/type-traits.hpp>               // cppx::is_floating_point_
#include <cppx-core-language/type-checking/type_name_of_.hpp>   // cppx::type_name_of_

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
