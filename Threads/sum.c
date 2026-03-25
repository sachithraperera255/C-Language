#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*
    Problem statement: use two threads sum values in an array, divide number of element between
    two threads
*/

int prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};


void* sum(void* value)
{   sleep(1);
    int val = *(int*)value;
    int sum = 0;

    for(int i = 0; i < 5; i++)
    {
        sum += prime[val + i];
    }

    /*
        - The argument 'value' is a pointer to heap-allocated memory passed from the main thread.
        It initially stores the starting index for this thread's computation.

        - After calculating the partial sum, we reuse the same memory location to store the result.
        This avoids additional memory allocation.

        -The pointer is returned so that the main thread can retrieve the result via pthread_join().
    */
    *(int*)value = sum;

    return value;
}

int main (int argc, char* argv[])
{
    pthread_t th[2];

    int summation = 0;

    for (int i = 0; i < 2; i++)
    {
        int* heap = malloc(sizeof(int));
        *heap = i * 5;
        if(pthread_create(&th[i], NULL, &sum, heap) != 0)
        {
            perror("Failed to create threads!\n");
        }
    }

    
    for (int i = 0; i < 2; i++)
    {
        int* ret;
        if(pthread_join(th[i], (void**)&ret) != 0)
        {
            perror("Failed to join threads\n");
        }

        summation += *ret;
        free(ret);
    }
    
    printf("total is %d \n", summation);

    return 0;
}