#include <cppx-core-language/calc/named-numbers.hpp>        // cppx::calc::*
#include <cppx-core-language/syntax/type-builders.hpp>      // cppx::Type_
#include <cppx-core-language-meta-macro/macro-apply.hpp>    // $apply    
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
