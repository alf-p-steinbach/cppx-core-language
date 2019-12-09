#include <cppx-core-language/all.hpp>
#include <c/stdio.hpp>
#include <ostream>
#include <string>
$use_std( string, ostream );

void display( const string& s ) { printf( "%s\n", s.c_str() ); }

template< class Value >
struct Boxed{ Value value; };

template< class Value >
auto operator<<( ostream& stream, const Value& v )
    -> ostream&
{ return stream << v.value; }

auto main() -> int
{
    const int user_id = 12345;
    
    using namespace cppx::syntax;
    display( "Welcome, user #" << user_id << "!" );
}
