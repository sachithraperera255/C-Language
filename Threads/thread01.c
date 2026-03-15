#include <stdlib.h>
#include <stdio.h>
// POSIX operating system API
#include <unistd.h>
// POSIX thread library
#include <pthread.h>


// This function is called thread routine and it will be executed by thread
void* routine(){
    printf("Testing Threads");
}

int main(int argc, char* argv[])
{
    pthread_t t1;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_join(t1, NULL);
    return 0;
}