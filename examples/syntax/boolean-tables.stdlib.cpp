#include <stdio.h>          // printf

void display_table(
    char const* const row_format,
    const char* const (&str)[2]
    )
{
    printf( row_format, "A", "B", "AND", "OR" );
    for( int x = 0; x < 4; ++x ) {
        const bool a    = !!(x%2);
        const bool b    = !!(x/2);
        
        printf( row_format, str[a], str[b], str[a and b], str[a or b] );
    }
}

auto main()
    -> int
{
    printf( "Boolean ops expressed with 0/1:\n" );
    display_table( "%4s %4s %8s %8s\n", {"0", "1"} );

    printf( "\n" );
    printf( "Boolean ops expressed with false/true:\n" );
    display_table( "%8s %8s %12s %12s\n", {"false", "true"} );
}
