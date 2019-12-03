#include <cppx-core-language/bit-level/bits_per_.hpp>           // ” Bit-level stuff.
#include <cppx-core-language/type-checking/Type_name_of_.hpp>   // cppx::type_name_of_
#include <cppx-core-language/types/Int_.hpp>            // cppx::(Int_, Unsigned_int_)

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
