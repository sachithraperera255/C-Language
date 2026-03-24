#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/*
    Problem statement: Create 10 threads, each taking a unique prime from the primes arrays
    and print it on the screen.
*/

int prime[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int size = 10;

void* routine(void* arg)
{   
    sleep(1);
    // In here, arg is type casted to type integer pointer then dereference the arg value
    int index = *(int*)arg;
    printf("%d \n", prime[index]);
    free(arg);
}

int main(int argc, char* argv[])
{
    pthread_t numThreads[size];

    for(int i = 0; i < size; i++)
    {
        /*
            - It is very important remember that threads share memory and other resources. if 
            address of i was passed to the thread, its behaviour will be unpredictable because 
            even though i increments in the loop it shares the same address.

            - As a solution to the above mentioned issue, memory is created in the heap and incremented i
            is saved there to give each threads its own memory address.
        */
        int* heap = malloc(sizeof(int));
        *heap = i;
        if(pthread_create(&numThreads[i], NULL, &routine, heap) != 0)
        {
            perror("Failed to create threads!\n");
        }

        /*
            - Using following method, allocation memory can be avoided. In this case, address of
            array's elements are used.
        if(pthread_create(&numThreads[i], NULL, &routine, prime + i) != 0)
        {
            perror("Failed to create threads!\n");
        }

        */

    }

    for (int i = 0; i < size; i++)
    {
        if(pthread_join(numThreads[i], NULL) != 0)
        {
            perror("Failed to join threads\n");
        }
    }
    

    return 0;
}