#include <stdlib.h>
#include <stdio.h>

/*
    - In C language, struct and union are user defined data types. There are many ways to use both 
    struct and union. following example shows how to use structs and unions together.

    - When you defined struct memory get allocated during the runtime on the stack, unless if you use 
    dynamic memory allocation it will use heap, and the same case for the unions as well.

    - struct will allocate memory for all it's members/atrributes but union only allocates memory
    for its largest member and can only access one member at a time. if try to write to members at the same
    time one of them will get replace or error will thrown (Segmentation fault (core dumped)). In another
    words union use shared memory.

*/

//#pragma pack(1)
typedef struct Store{
    double price;
    union items 
    {
        struct book
        {
            char *title;
            char *author;
            int num_pages;
        }book;

        struct shirt
        {
            int color;
            int size;
            char *design;
        }shirt;
    }item;  
}Store;


int main (int argc, char* argv[])
{
    Store s;
    s.item.book.title = "The Alchemist";
    s.item.book.author = "Paulo Coelho";
    s.item.book.num_pages = 197;

    s.item.shirt.color = 12;

    

    printf("%s\n", s.item.book.title);

    //printf("%d\n", s.item.shirt.color);    This line will throw a error

    printf("%ld\n", sizeof(s));
    

    return 0;
}