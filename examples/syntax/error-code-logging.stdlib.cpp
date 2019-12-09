#include <stdio.h>          // fprintf, stderr
#include <sstream>          // std::ostringstream
#include <system_error>     // std::(errc, make_error_code)

void log( const std::string& s )
{
    fprintf( stderr, "!%s\n", s.c_str() );
}

auto main()
    -> int
{
    using std::errc, std::make_error_code, std::ostringstream;
    const auto code = make_error_code( errc::network_down );
    
    ostringstream stream;
    stream << "Oops - error code " << code << " (" << code.message() << ").";
    log( stream.str() );
}
