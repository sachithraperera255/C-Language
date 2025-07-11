#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argc, char* argv[])
{
    long long a = 15;
    long long b = 20;
    long long c[] = {1, 2, 3};

    long long* z = c + 1; 
    /* - The above expression doesn't mean that get the address of 'c' and add 1 to it,
      it means get the address of c and add 1 times sizeof(type of c). 

      - We can not multiply or subtract pointers.

      - Substraction is allowed, behave same way the addition does, must be mindful since
      stack grows downward and heap grows upwards. if you try to access memory that is allowed by the OS
      the compiler will throw a segmentation error.
    */
    printf("Result is %lld at address %p\n", *z, z);

    long long results = &a - &b;

    printf("Result is %lld at address %p and %p\n", results, &a, &b);

    /*
        - Their difference in memory divided by sizeof(their type). This mostly work for same type of
        data.
    */

    long long* p = malloc(sizeof(long long));
    long long* q = malloc(sizeof(long long));

    long long res = p - q;
    /*
        - The above expression is subtracting the addresses values that in the heap, but 
        if you use the expression  long long res = &p - &q;, it would subtract the addresses that in 
        the stack, because p and q are just two pointers that are stored in the stack.
    */


    printf("Result is %lld at address %p and %p\n", res, &p, &q);



    return 0;
}