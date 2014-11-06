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



int
    main(int argc, char **argv)
        {
        //int count;
        Movie *entries;
        
        entries = fillMovieArray("data");
       // printMovies(entries, count);
       //...
        return 0;
        }