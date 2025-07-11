#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    - void* is a generic pointer which can points to any data type, but you cannot dereference it
    directly without first casting it to a specific type.

    - In the following function, elements of the array are casted into char type because we are trying
    to deal with individual bytes.
*/


void printBytes(void* arr, int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("%08x ", ((char*)arr)[i]);
    }

    //%08 --> print in hexadecimal format and print it on eight character and fill rest with 0s.
    
}


int main (int argc, char* argv[])
{
    long long arr[] = {12,31,34,65};
    printBytes(arr, 4 * sizeof(long long));
    return 0;
}