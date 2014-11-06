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
Node *
    newEmptyNode(void)
        {
        Node *p = malloc(sizeof(Node));     //check for malloc failure omitted
        p->value = 0;                       //set to empty
        p->next = 0;                        //set to the null pointer
        return p;
        }
void
    printMovies(Movie **entries, int num)
        {
        int i;
        
        printf("Movie Listings:\n");
        printf("%s\n",entries[0]->name);
        for (i=0; i < num; ++i)
            {
            printf("%s\n",entries[0]->name);
            printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                               entries[i]->name,
                               entries[i]->description,
                               entries[i]->year,
                               entries[i]->length,
                               entries[i]->rating,
                               entries[i]->cast,
                               entries[i]->director);


            }
           // printf("hello\n");
        }
Movie *
    readMovieRecord(FILE *fp)         // we pass the file pointer in
        {
        char *name;
        
        name = readString(fp);           //name is a string, not a token

        if (feof(fp)) { return 0; }      // no record, return null

        //make an empty record

        Movie *d = malloc(sizeof(Movie)); //malloc failure test omitted

        d->name = name;
        d->description = readString(fp);
        d->year = readInt(fp);
        d->length = readInt(fp);
        d->rating = readToken(fp);
        d->cast = readString(fp);
        d->director = readString(fp);




        return d;
        }

void fillMovieArray(char *fileName, int *finalSize,Movie **e)
        {
         
        FILE *fp = fopen(fileName,"r"); //open failure test omitted
        
        //Movie **e;
        //e = malloc(sizeof(Movie));
        //Movie *e = malloc(sizeof(Movie));

        e[0] = readMovieRecord(fp);
       
      
       /* e->name = readString(fp);
        e->description = readString(fp);
        e->year = readInt(fp);
        e->length = readInt(fp);
        e->rating = readToken(fp);
        e->cast = readString(fp);
        e->director = readString(fp);*/

        ++*finalSize;
        int i;
        for ( i = 1; i < 2; i++)
        {
        
       	    //printMovies(e,0);
            e[i] = readMovieRecord(fp);
            ++*finalSize;
            }

        fclose(fp);
        //return *e;
        }

    