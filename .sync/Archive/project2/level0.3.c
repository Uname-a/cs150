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
    struct stuff *n;                            //create the pointer
    n = malloc(sizeof(struct Movie));           //malloc failure test omitted
    e->name = name;
        e->description = readString(fp);
        e->year = readInt(fp);
        e->length = readInt(fp);
        e->rating = readToken(fp);
        e->cast = readString(fp);
        e->director = readString(fp);

    printf("n->x is %d\n",n->x);
    printf("n->s is %s\n",n->s);
    printf("n->r is %f\n",n->r);
    return 0;
}