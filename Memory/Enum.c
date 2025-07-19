#include <stdlib.h>
#include <stdio.h>


/*
    - An enumerated type is a user defined type which is used to assign names to integral 
    constant because names are easier to handle in program.
    - If we don't assign values to enum then, compiler will assign integer values to them starting from 0 or
    values of previous name + 1;

    - Why do we need enum:
        - Enum can be declared in the local scope --> #define (macro) only in the global scope.
        - Enum are automatically assigned by the compiler.
        - Two or more names can have the same value.
*/


typedef enum Color {
    RED = 7,
    BLUE,
    YELLOW
}Color;


int main (int argc, char* argv[])
{
    Color c = RED;
    printf("%d\n", c);
    printf("%zu\n", sizeof(c));
    return 0;
}