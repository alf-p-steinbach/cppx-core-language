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
