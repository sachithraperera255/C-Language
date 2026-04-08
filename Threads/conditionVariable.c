#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* fuel_filling(void* arg)
{

}

void* car(void* arg)
{

}

int main (int argc, char* argv[])
{
    pthread_t th[2];

    for(int i = 0; i < 2; i++)
    {
        if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
        {
            perror("Failed to create threads\n");

        }else
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
            {
                perror("Failed to create thread\n");
            }
            
        }
        
    }

    for(int i = 0; i < 2; i++)
    {
        if(pthread_join(th[i], NULL) != 0)
        {
            printf("Thread failed to join\n");
        }
    }

    return 0;
}