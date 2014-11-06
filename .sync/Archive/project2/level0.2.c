#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"


typedef struct entry
        {
        char *name;
        char *description;
        int year;
        int length;
        char * rating;
        char * cast;
        char * director;
        } Movie;

int main(int argc, char  **argv)
{
    struct stuff { int x; char *s; double r; }; //define the struct
    struct stuff *n;                            //create the pointer
    n = malloc(sizeof(struct stuff));           //malloc failure test omitted
    n->x = 42;
    n->s = "hello, world!";
    n->r = 3.14159;
    printf("n->x is %d\n",n->x);
    printf("n->s is %s\n",n->s);
    printf("n->r is %f\n",n->r);
    return 0;
}