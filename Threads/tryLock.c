#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
/*
    - Threads will simply skip the critical section if the mutex is not available, this could be more
    of a design choice. It's better to
    use try lock if the waiting threads have other tasks to achieve while waiting for the critical
    section

    - Make sure to always check the return of the pthread_mutex_trylock(), you should only unlock threads
    that got locked.
*/
void* function1()
{

    if(pthread_mutex_trylock(&mutex) == 0 )
    {
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }else
    {
        printf("Did not get the mutex\n");
    }
    
}

int main (int argc, char* argv[])
{
    
    pthread_t threads[4];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < 4; i++)
    {
        if(pthread_create(&threads[i], NULL, &function1, NULL) != 0)
        {
            printf("Failed to create threads\n");
            return 1;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if(pthread_join(threads[i], NULL) != 0)
        {
            printf("Thread failed to join\n");
        }
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}