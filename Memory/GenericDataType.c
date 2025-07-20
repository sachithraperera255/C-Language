#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/*
    - This program defines a stack structure that can store integers, characters, and unsigned 64-bit
    integers.
    - This program utilizes following:
        - enums.
        - stack.
        - size_t
        - void*
*/


// this enum is used to define and identify what data will store
typedef enum {
    STACK_INT,
    STACK_CHAR,
    STACK_UNIT64
}DataType;


typedef struct Stack {
    DataType type;  // type of data
    size_t size; // number of elements
    void* data; // pointer to the data array (point to the 1st element)
    void* top; // point to the current first element of the array.
}Stack;


// stackCreate function calculate size of the array using size and the type and save provided data in the 
//stack
Stack stackCreate(size_t size, DataType type){
    
    size_t effectiveSize = 0;
    if (type == STACK_CHAR)
    {
        effectiveSize = size * sizeof(char);
    }else if (type == STACK_INT)
    {
        effectiveSize = size * sizeof(int);
    }else if (type == STACK_UNIT64)
    {
        effectiveSize = size * sizeof(unsigned long long);
    }
    
    
    Stack s = {
        .type = type,
        .size = size,
        .data = malloc(effectiveSize),
        .top = NULL
    };

    return s;
}

// This function free the dynamically allocated memory which used to store data by the stackCreate function
void stackDelete(Stack* s){
    free(s->data);
    s->data = NULL;
}


int main (int argc, char* argv[])
{
    Stack s = stackCreate(10, STACK_INT);
    ((int*)s.data)[0] = 64;
    s.top = ((int*)s.data) + 0;

    ((int*)s.data)[1] = 128;
    s.top = ((int*)s.data) + 1;

    stackDelete(&s);


    return 0;
}