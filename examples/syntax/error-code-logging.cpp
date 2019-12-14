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
