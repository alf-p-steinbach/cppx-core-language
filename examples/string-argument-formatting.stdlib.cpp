#include <iostream>         // std::(cout, endl)
#include <sstream>          // std::ostringstream
#include <string>           // std::(to_string, operator ""s)
#include <string_view>      // std::string_view

namespace my{
    using std::string_view, std::cout, std::endl;

    void display( const string_view& s )
    {
        cout << s << endl;
    }
}  // namespace my

auto main()
    -> int
{
    using std::ostringstream, std::to_string;

    const double    a   = 1.23;
    const double    b   = 4.56;
    
    ostringstream stream;
    stream
        << "One would expect that " << a << " + " << b << " = " << a + b
        << ", not " << to_string( a + b ) << "!";
    my::display( stream.str() );
    
    stream = ostringstream();       // Resets the stream object by move assigning.
    stream << "However, integer arithmetic is exact; 2 + 2 = " << 2 + 2 << ".";
    my::display( stream.str() );
}
