#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int x = 2;

void* func1()
{
    /*
        - This would print the same process IDs because threads are running insdie a process. A 
        process can have a multiple threads.
    */
    printf("Process id %d\n", getpid());

    x++;
    sleep(2);
    printf("Value of x: %d\n", x);

}

void* func2()
{
    sleep(2);
    printf("Value of x: %d\n", x);
}

/*
    - Both func1() and func2() will print the same value because threads share the same memory space.
    This tell us that threads shares resources from its process
*/

int main(int argc, char* argv[])
{
    pthread_t t1, t2;

    if(pthread_create(&t1, NULL, &func1, NULL))
    {
        return 1;
    }
    if(pthread_create(&t2, NULL, &func2, NULL))
    {
        return 2;
    }

    if(pthread_join(t1, NULL))
    {
        return 3;
    }

    if(pthread_join(t2, NULL))
    {
        return 4;
    }

    return 0;
}