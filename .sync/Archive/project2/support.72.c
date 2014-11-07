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
void
    printMovies(Movie **entryArray, int num)
        {
        int i;
        
        printf("Movie Listings:\n");
         num =1;
        for (i=0; i<num; ++i)
            {
            //printf("test\n");
            printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                               entryArray[i]->name,
                               entryArray[i]->description,
                               entryArray[i]->year,
                               entryArray[i]->length,
                               entryArray[i]->rating,
                               entryArray[i]->cast,
                               entryArray[i]->director);


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

Movie * fillMovieArray(char *fileName, int *finalSize)
        {
         
        FILE *fp = fopen(fileName,"r"); //open failure test omitted
        
        Movie **e;
        e = malloc(sizeof(Movie));
        //Movie *e = malloc(sizeof(Movie));

        e[0] = readMovieRecord(fp);
       
      
       /* e->name = readString(fp);
        e->description = readString(fp);
        e->year = readInt(fp);
        e->length = readInt(fp);
        e->rating = readToken(fp);
        e->cast = readString(fp);
        e->director = readString(fp);*/

        finalSize[0] = 1;
        int i;
        for ( i = 1; i < 1; ++i)
        {
        
       	    //printMovies(e,0);
            e[i] = readMovieRecord(fp);
           // ++finalSize[0];
            }

        fclose(fp);
        return *e;
        }

    