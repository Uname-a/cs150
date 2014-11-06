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
        struct node *next;
        } Movie;
Movie *
    newEmptyNode(void)
        {
        Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
        p->value = 0;                       //set to empty
        p->next = 0;                        //set to the null pointer
        return p;
        }
Node *
    newNode(int v,Node *n)
        {
        Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
        p->value = v;
        p->next = n;
        return p;
        }
int main(int argc, char  **argv)
{
     //define the struct
    Movie *e;                            //create the pointer
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