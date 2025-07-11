/*
    In this file we talk about four important ways memory manipulation which methods
    are provided in the <string.h> library:

          I. memcmp()
         II. memcpy()
        III. memset()
         IV. memchr()

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[])
{
    int arr1[] = {1, 2};
    int arr2[] = {1, 2};
    short int arr3[] = {3, 4};

    /*
        - memcmp(), in library of <string.h>, is similar to the strcmp(), but memcmp() does't 
        give you warning if you're passing the wrong type of data because it takes void pointers.

            int memcmp ( const void * ptr1, const void * ptr2, size_t num );
        
        ptr1 --> pointer to block of memory.
        ptr2 --> pointer to block of memory.
        num -->  Number of bytes to compare.

        - ptr1 compare with ptr2 and return zero if they are a match, if not return value is
        greater than zero.
    
    */

    if (memcmp(arr1, arr2, 2*sizeof(int)) == 0)
    {
        printf("Arrays are the same\n"); // This is the correct ouput.

    } else
    {
        printf("Arrays are the not the same\n");
    }


    if (memcmp(arr1, arr3, 2*sizeof(short int)) == 0)
    {
        printf("Arrays are the same\n");

    } else
    {
        printf("Arrays are the not the same\n"); // This is the correct ouput.
    }


    /*
        - memcpy(), in the library of <string.h>, copies the values of num bytes from the location
        pointed to by source directly to the memory block pointed by destination.

            void * memcpy ( void * destination, const void * source, size_t num );
        
        destination --> Pointer to the destination array, type casted to a pointer of type void*
        source --> Pointer to the source of data to be copied, type casted to a pointer of type const void*.
        num --> Number of bytes to copy, size_t is an unsigned integral type.
        
    */


    memcpy(arr1, arr2, 2*sizeof(int));

    printf("%d %d\n",arr1[0],arr1[1]); // output: 1 2


    /*
        - memset(), in the library of <string.h>, replace the num bytes of memory block pointed by ptr
        to the specified value.

            void * memset ( void * ptr, int value, size_t num )
        
        ptr --> pointer to the memory to fill
        value --> value to be set, which passed as int but function filled the block of memory using the
                unsigned char values.
        num --> number of bytes to be set tot he value.
    */

    memset(arr1, 0, 2*sizeof(int));
    printf("%d %d\n",arr1[0],arr1[1]); // output: 0 0

    /*
        Remember memset() replace each byte of element in the arr1 with zero. If you try to replace
        the array values with 1 out put wouldn't be 1 1, it's gonna be something else. in this case
            arr1: 01010101 01010101
        printf() would convert the above values into decimal before the output.
    */

    


    /*
        - memchr(), find the byte in an array. It searches the number of bytes of the block of the
        memory pointed by ptr for the first occurrence of value. This function return the a pointer 
        to the that specific memory location. Both array and the ptr array are treated as unsigned char.

            const void * memchr ( const void * ptr, int value, size_t num );
        
        ptr --> pointer to the memory block where the search is performed. (In this case passing array)
        value --> Value to be located. The value is passed as a int, but the function further performs a
                byte per byte, at this level search is done by using the unsigned char conversion.
        num --> number of bytes to be analyze.
    */

    if(memchr(arr1, 0, 2*sizeof(int)) != NULL)
    {
        printf("Found the byte\n");
    }else
    {
        printf("Did not find the byte\n");
    }


    /*
        If the memchr() did not find the what was searching for, it will return a NULL.
    */

        

    return 0;
}