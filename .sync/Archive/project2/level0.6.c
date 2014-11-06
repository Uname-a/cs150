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
   //struct entry *e;                            //create the pointer
    e = malloc(sizeof(struct entry));           //malloc failure test omitted
    e->name = "hello";
        e->description = "hello";
        e->year = 10;
        e->length = 11;
        e->rating = "readToken(fp)";
        e->cast = "hello";
        e->director = "readString(fp)";

        printf("%s\n",e->description );
    return 0;
}