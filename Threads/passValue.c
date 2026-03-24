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
        int* heap = malloc(sizeof(int));
        *heap = i;
        if(pthread_create(&numThreads[i], NULL, &routine, heap) != 0)
        {
            perror("Failed to create threads!\n");
        }

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