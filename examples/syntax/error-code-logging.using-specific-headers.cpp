#include <cppx-core-language/syntax/basic-string-assembly.hpp>      // cppx::syntax::*
#include <cppx-core-language/syntax/macro-use.hpp>                  // $use_std
#include <stdio.h>          // fprintf, stderr
#include <system_error>     // std::(errc, make_error_code)

void log( const std::string& s )
{
    fprintf( stderr, "!%s\n", s.c_str() );
}

auto main()
    -> int
{
    $use_std( errc, make_error_code );
    const auto code = make_error_code( errc::network_down );

    using namespace cppx::syntax;
    log( "Oops - error code " << code << " (" << code.message() << ")." );
}
