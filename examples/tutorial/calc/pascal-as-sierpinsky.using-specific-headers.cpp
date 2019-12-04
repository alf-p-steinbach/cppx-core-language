// Display the positions of the odd numbers in Pascal's triangle.
#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::is_odd
#include <cppx-core-language/syntax/Sequence_.hpp>          // cppx::(Sequence, zero_to)
#include <c/stdio.hpp>  // printf
#include <vector>       // std::vector

auto main()
    -> int
{
    $use_std( vector );
    $use_cppx( is_odd, Sequence, zero_to );

    const int n = 1 << 4;
    vector<int> row = {1};

    for( const int y: zero_to( n ) ) {
        if( y > 0 ) {
            // Compute the next row.
            vector<int> next_row = {1};
            for( const int i: Sequence( 1, row.size() - 1 ) ) {
                next_row.push_back( row[i] + row[i - 1] );
            }
            next_row.push_back( 1 );
            swap( next_row, row );
        }

        // Display the odd number positions.
        printf( "%*c", n - y, ' ' );
        for( const int x: row ) {
            printf( " %c", is_odd( x )? 'o' : ' ' );
        }
        printf( "\n" );
    }
}
