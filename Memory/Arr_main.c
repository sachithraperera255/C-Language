#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
    int arr[] = {5, 13, 22};

    /*
        The conventional method to access a array is as follows arr[0], which would give
        access to the fist element in the array but what actually happens in background is
        that we calls the array as it declared, which gives the address of the array, then
        use * to dereference to access the values as shows below.
    */

    printf("%d\n", *(arr + 1)); // OUTPUT: 13

    /*
        Due to the fact that addition is commutative, A + B = c and B + A = C, following method
        can be used to get the results,

        printf("%d\n", 1[arr]); OUTPUT: 13
    */


    return 0;
}