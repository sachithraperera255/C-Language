#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mutex;

void* function1()
{
    pthread_mutex_lock(&mutex);
    count++;
    pthread_mutex_unlock(&mutex);
}

int main (int argc, char* argv[])
{
    
    pthread_t threads[4];
    pthread_mutex_init(&mutex, NULL);
    /*
        - It is important to have thread creation and joining in two different loops. if they both done 
        in the same loop it would be similar to linear execution of a program.
    */
    for(int i = 0; i < 4; i++)
    {
        if(pthread_create(&threads[0] + i, NULL, &function1, NULL) != 0)
        {
            printf("Failed to create threads\n");
            return 1;
        }

        printf("Thread has started %d: \n",i);
    }

    for(int i = 0; i < 4; i++)
    {
        if(pthread_join(threads[i], NULL) != 0)
        {
            printf("Thread failed to join\n");
        }

        printf("Thread %d has finished execution\n",i);
    }
    pthread_mutex_destroy(&mutex);

    return 0;
}