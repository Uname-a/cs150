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
    printMovies(Movie *entryArray, int num)
        {
        int i;
        printf("Movie Listings:\n");
        for (i=0; i<num; ++i)
            {
            printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                               entryArray[i]->name,
                               entryArray[i]->description,
                               entryArray[i]->year,
                               entryArray[i]->length,
                               entryArray[i]->rating,
                               entryArray[i]->cast,
                               entryArray[i]->director);

            }
        }
Movie *
    readMovieRecord(FILE *fp)         // we pass the file pointer in
        {
        char *name;
        
        name = readString(fp);           //name is a string, not a token

        if (feof(fp)) { return 0; }      // no record, return null

        //make an empty record

        Movie *e = malloc(sizeof(Movie)); //malloc failure test omitted

        e->name = name;
        e->description = readString(fp);
        e->year = readInt(fp);
        e->length = readInt(fp);
        e->rating = readToken(fp);
        e->cast = readString(fp);
        e->director = readString(fp);




        return e;
        }
void
    fillMovieArray(char *fileName, int *finalSize)
        {
         Movie *e;
        FILE *fp = fopen(fileName,"r"); //open failure test omitted
        
        
        e = readMovieRecord(fp);
        finalSize[0] = 1;
        while (!feof(fp))
            {
            //printMovies(e,0);
            e = readMovieRecord(fp);
            ++finalSize[0];
            }

        fclose(fp);
        }

    