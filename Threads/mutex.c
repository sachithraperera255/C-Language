#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

/*
    - What is a rece condition?
        - Race condition occurs when multiple threads trying access or modify shared data at the 
        same time. this could lead to unpredictable results.

    - Ways to prevent and handle the race condition:
        - Locks/Mutex (Mutula exclusion): this method make sure that only one thread is 
        allow inside the critical section at a time.
        - Semaphore: This method is synchronization tool that controls how many threads can access
        a resource at the same time.
            - There are two main types:
                - Binary semaphores
                - Counting semaphores
        - Atomic operations: This method is an operation that execute completely or not at all
        without been interupted from other threads
*/

/*
    - 
*/

void* routine()
{
    for (int i = 0; i < 100000; i++)
    {
        mails++;
    }
}

int main(int argc, char* argv[])
{
    pthread_t p1, p2;

    if(pthread_create(&p1, NULL, &routine, NULL) != 0)
    {
        return 1;
    }

    if(pthread_create(&p2, NULL, &routine, NULL) != 0)
    {
        return 2;
    }

    if(pthread_join(p1, NULL) != 0)
    {
        return 3;
    }

    if(pthread_join(p2, NULL) != 0)
    {
        return 4;
    }

    printf("Number of mails %d\n", mails);

    return 0;
}