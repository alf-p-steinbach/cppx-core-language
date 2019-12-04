#include <cppx-core-language/calc/integer-operations.hpp>   // cppx::(div_up, div_down)
#include <c/stdio.hpp>

auto main()
    -> int
{
    $use_cppx( div_up, div_down );

    const int   n_per_taxi      = 3;
    const int   n_persons       = 10;
    const int   n_choco_bars    = 27;
    
    const auto& txinfo = "With %d persons and max %d per taxi, %d taxis are needed.\n";
    printf( txinfo, n_persons, n_per_taxi, div_up( n_persons, n_per_taxi ) );
    
    const auto& cbinfo = "With %d chocolate bars and %d persons, each gets %d bars.\n";
    printf( cbinfo, n_choco_bars, n_persons, div_down( n_choco_bars, n_persons ) );
}
