#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Creating a mutex
pthread_mutex_t mute;
// Creating a condition variable
pthread_cond_t fuelCond;

int fuel = 0;

void *fuel_filling(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mute);
        fuel += 15;
        printf("Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mute);
        pthread_cond_signal(&fuelCond);
        sleep(1);
    }
}

void *car(void *arg)
{
    pthread_mutex_lock(&mute);
    while (fuel < 40)
    {
        printf("No fuel, waiting\n");
        // Waiting for a signal from another thread
        pthread_cond_wait(&fuelCond, &mute);
    }
    
    fuel -= 40;
    printf("Got fuel. Now left: %d\n", fuel);
    pthread_mutex_unlock(&mute);
}

int main(int argc, char *argv[])
{
    pthread_t th[2];
    pthread_mutex_init(&mute, NULL);
    pthread_cond_init(&fuelCond, NULL);

    for (int i = 0; i < 2; i++)
    {
        if (i == 1)
        {

            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0)
            {
                perror("Failed to create threads\n");
            }
        }
        else
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0)
            {
                perror("Failed to create thread\n");
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        if (pthread_join(th[i], NULL) != 0)
        {
            printf("Thread failed to join\n");
        }
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mute);
    // Destroy the condition variable
    pthread_cond_destroy(&fuelCond);

    return 0;
}