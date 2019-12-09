#include <stdlib.h>     // printf
#include <sstream>      // std::ostringstream
#include <string>       // std::string
using std::boolalpha, std::string, std::ostringstream;

void say( const string& s ) { printf( "%s\n", s.c_str() ); }

auto main()
    -> int
{

    ostringstream stream;
 
    stream << boolalpha;
    stream << "Most people say that 2 + 2 = 4 is " << (2 + 2 == 4) << ".";
    say( stream.str() );
    
    stream = ostringstream();   // Reset. Effect as-if with `std::noboolalpha` is default.
    stream << "However, some people maintain that 2 + 2 = 4 is " << (2 + 2 == 4) << "...";
    say( stream.str() );
}
