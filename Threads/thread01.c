#include <stdlib.h>
#include <stdio.h>
// POSIX operating system API
#include <unistd.h>
// POSIX thread library
#include <pthread.h>


// This function is called thread routine and it will be executed by thread
// This function will return a void pointer 
void* routine(){
    printf("Testing Threads\n");
    sleep(2);
    printf("Thread creation is done\n");
}

int main(int argc, char* argv[])
{   
    // t1 will store thread ID. After pthread_create() function is executed t1 will have ID of the newly 
    //created thread
    pthread_t t1, t2;

    /*
        - following function create the thread, which tells the OS that create another execution path
        (thread) inside this process and start running respective function.
        - If the function return non-zero value --> error
    */
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);

    /*
        - pthread_join() function tells main function to wait until t1 finishes. If the main function exit
        before thread finishes, t1 will terminate before its return the value.
    */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}