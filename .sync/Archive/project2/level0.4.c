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
     //define the struct
    struct stuff *e;                            //create the pointer
    e = malloc(sizeof(struct Movie));           //malloc failure test omitted
    e->name = "hello";
        e->description = "hello";
        e->year = 10;
        e->length = 11;
        e->rating = "readToken(fp)";
        e->cast = "hello";
        e->director = "readString(fp)";

    printf("n->x is %d\n",n->x);
    printf("n->s is %s\n",n->s);
    printf("n->r is %f\n",n->r);
    return 0;
}