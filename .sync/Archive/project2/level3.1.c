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
    newMovie(char *n,char *des,int y,int l,char * r,char *c, char * dir)
        {
        Movie *d = malloc(sizeof(Movie)); //malloc failure test omitted
        d->name = n;
        d->description = des;
        d->year = y;
        d->length = l;
        d->rating = r;
        d->cast = c;
        d->director = dir;
        return d;
        }

Movie *
    readMovieRecord(FILE *fp)         // we pass the file pointer in
        {
        char *name;
        char *description;
        int year;
        int length;
        char * rating;
        char * cast;
        char * director;
        
        name = readString(fp);           //name is a string, not a token

        if (feof(fp)) { return 0; }      // no record, return the null pointer

        name = name;
        description = readString(fp);
        year = readInt(fp);
        length = readInt(fp);
        rating = readToken(fp);
        cast = readString(fp);
        director = readString(fp);

        return newMovie(name,description,year,length,rating,cast,director);
        }
Movie **
    readAllMovieRecords(char *fileName,int *finalSize)
        {
        FILE *fp;
        int count;
        int size = 10;                //initial size of destination array
        Movie *record;
        Movie **table;

        fp = fopen(fileName,"r");     //open failure test omitted

        //allocate the destination array
        table = allocate(sizeof(Movie *) * size);

        count = 0;
        record = readMovieRecord(fp);
        while (!feof(fp))
            {
            if (count == size)              //array is full!
                {
                // grow the array by doubling its size
                size = size * 2;
                table = reallocate(table,sizeof(Movie *) * size);
                //now there is enough room
                }
            table[count] = record;           //DO NOT FREE THE RECORD!
            ++count;
            record = readMovieRecord(fp);
            }
        fclose(fp);

        //shrink the array to 'count' number of elements
        table = reallocate(table,sizeof(Movie *) * count);

        //count holds the number of items, store it in *finalSize
        *finalSize = count;
        return table;
        }
void printMovies(Movie **entries,int count)
{
    int i;
        
        printf("Movie Listings:\n");
        //printf("%s\n",entries[0]->name);
        for (i=0; i < count; ++i)
            {
           // printf("%s\n",entries[0]->name);
            printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                               entries[i]->name,
                               entries[i]->description,
                               entries[i]->year,
                               entries[i]->length,
                               entries[i]->rating,
                               entries[i]->cast,
                               entries[i]->director);


            }
}

int
    main(int argc, char **argv)
        {
        int count;
        if (argc != 3)
            {
            printf("need one arguments!\n");
            exit(1);
            }
        Movie **arrayone;
        Movie **arraytwo;
        arrayone = readAllMovieRecords(argv[1],&count);
        printMovies(arrayone, countone);
        arraytwo = readAllMovieRecords(argv[2],&count);
        printMovies(arraytwo, counttwo);
        return 0;
        }