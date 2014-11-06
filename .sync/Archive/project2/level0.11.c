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
    newNode(int v,Movie *n)
        {
        Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
        p->value = v;
        p->next = n;
        return p;
        }
Movie *
    readIntegers(FILE *fp)
        {
        int x;
        Movie *items;

        items = 0; //items starts out as null

        //employ the standard reading pattern
        x = readint(fp);
        while (!feof(fp))
            {
            items = newNode(x,items);
            x = readint(fp);
            }
        return items;
        }