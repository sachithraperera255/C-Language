#include <stdlib.h>
#include <stdio.h>

/*
    What is typedef --> typedef let we create a nickname for a data type. it's purely a syntactic
    convenience. consider the following examples.
*/

typedef unsigned long long UINT64;

typedef struct Point
{
    double x,y;
}Point;

// Another way of declaring the struct

// struct Point
// {
//     double x,y;
// };

int main (int argc, char* argv[])
{
    //struct Point p;
    Point p = {
        .x = 0.25,
        .y = .43
    };

    printf("%lf %lf\n", p.x, p.y);

    UINT64 l = 14;
    printf("%llu\n", l);

    return 0;
}