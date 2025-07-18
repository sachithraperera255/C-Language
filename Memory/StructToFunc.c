#include <stdlib.h>
#include <stdio.h>

typedef struct Point {
    double x, y;
}Point;


/*
    - The following function return type is Point(a user defined data type), when this function is called
    in the main function, it passes the entire object of p1 and p2 to Point a and Point b parameters respectively.
    Therefore, this passed by value.

    - In this method, everytime values are passed it copy and paste from place to place, which is inconvenience when 
    dealing with large structures 
*/

Point getMiddlePoint(Point a, Point b)
{
    Point m;

    m.x = (a.x + b.x)/2;
    m.y = (a.y + b.y)/2;

    return m;
}

Point *getMiddlePointref(const Point *a, const Point *b)
{
    /*
        - Why do we need malloc() here, because when this function get called it, the function frame,
        get created in the stack segment of the memory. when the function return m, tje information that
        got created in the stack get destroyed but if you stored the Point struct in the heap and return 
        the address, m is already an address, of that memory block, you can call it from anywhere in the code.
    */
    Point *m = malloc(sizeof(Point));
    m->x = (a->x + b->x)/2;
    m->y = (a->y + b->y)/2;

    return m;
}

/*
    - When working with large project, it's always better not to have someone else free the maclloc(),
    therefore this a preferred way to pass values by reference.
*/

void getMiddlePointref2(Point *a, Point *b, Point *out)
{
    out->x = (a->x + b->x)/2;
    out->y = (a->y + b->y)/2;
}



int main (int argc, char* argv[])
{
    Point p1 = {
        .x = 1,
        .y = 1
    };

    Point p2 = {
        .x = 3,
        .y = 2
    };

    // passed by value
    Point middle = getMiddlePoint(p1, p2);
    printf("Passed by value: %.2lf, %.2lf\n", middle.x, middle.y);

    // passed by reference
    Point *middle2 = getMiddlePointref(&p1, &p2);
    printf("Passed by reference: %.2lf, %.2lf\n", middle2->x, middle2->y);
    free(middle2);

    // passed by reference
    Point middle3;
    getMiddlePointref2(&p1, &p2, &middle3);
    printf("Passed by reference: %.2lf, %.2lf\n", middle3.x, middle3.y);


    

    return 0;
}