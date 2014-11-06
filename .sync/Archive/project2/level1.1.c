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

Movie *
    readMovieRecord(char *filename,int *finalSize)         // we pass the file pointer in
        {
        char *name;
        FILE *fp = fopen(filename,"r");
        name = readString(fp);           //name is a string, not a token

        if (feof(fp)) { return 0; }      // no record, return null

        //make an empty record
        Movie *
        Movie *d = malloc(sizeof(Movie)); //malloc failure test omitted

        d->name = name;
        d->description = readString(fp);
        d->year = readInt(fp);
        d->length = readInt(fp);
        d->rating = readToken(fp);
        d->cast = readString(fp);
        d->director = readString(fp);

        while (!feof(...))
            {
            // the read was good, make room for the record if necessary
            ...
            // store the record in the array and increment the count
            ...
            d->name = name;
            d->description = readString(fp);
            d->year = readInt(fp);
            d->length = readInt(fp);
            d->rating = readToken(fp);
            d->cast = readString(fp);
            d->director = readString(fp);
            }
        fclose(fp);
        return d;
        }

void
    fillMovieArray(char *fileName, int *finalSize)
        {
        // initialize stuff (including the array, count, and size)
        ...
        // read the first record
        ...

        while (!feof(...))
            {
            // the read was good, make room for the record if necessary
            ...
            // store the record in the array and increment the count
            ...
            // read the next record
            }
        ...
        // clean things up
        ...
        }

int
    main(int argc, char **argv)
        {
        //int count;
        
        Movie *entries = malloc(sizeof(Movie));
        entries = readMovieRecord("data");
       // printMovies(entries, count);
       printf("%s\n",entries->name );
        return 0;
        }