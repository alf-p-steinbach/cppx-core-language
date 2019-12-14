#include <stdio.h>          // fprintf, stderr
#include <sstream>          // std::ostringstream
#include <system_error>     // std::(errc, make_error_code)

void log( char const* const s ) { fprintf( stderr, "!%s\n", s ); }

auto main()
    -> int
{
    using std::errc, std::make_error_code, std::ostringstream;

    auto const code = make_error_code( errc::network_down );

    ostringstream stream;
    stream << "Oops - error code " << code << " (" << code.message() << ").";
    log( stream.str().c_str() );
}
