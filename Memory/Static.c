#include <stdio.h>
#include <stdlib.h>


int add (int x){
    int sum = 0;
    sum += x;
    return sum;
}

int addStatic (int x){
    static int sum = 0;
    sum += x;
    return sum;
}



int main (int argc, char* argv[])
{   
    /*
        - Everytime when we call the add() function, its return the same value, 5, because sum is just a int 
        variable that get created in the stack and also get destroyed, the content of the function, when its 
        return or finish the job.
    */
    printf("%d\n", add(5)); // output = 5
    printf("%d\n", add(5)); // output = 5

    /*
        - Following printf() will not output the same value as did above because in the addStatic function
        sum variable is static.
        - Static variables can be initialized only once and it its get allocated in the run-time.
        - Static variable has a local scope, but global lifetime, it exist until the program ends, on other words
        static variable only changes the life time no the variable.
        - This variable is accessible from any function in this file and other files too (if declared as extern).

        - Therefore, static variables are mutable because it can be changed.

    */

    printf("%d\n", addStatic(5)); // output = 5
    printf("%d\n", addStatic(5)); // output = 10
    
    //printf("%d\n", sum) this is not allowed

    return 0;
}