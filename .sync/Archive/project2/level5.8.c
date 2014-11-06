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
            printf("%d \"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",i+1,
                               entries[i]->name,
                               entries[i]->description,
                               entries[i]->year,
                               entries[i]->length,
                               entries[i]->rating,
                               entries[i]->cast,
                               entries[i]->director);


            }
}

Movie **
    mergeAllArrays(Movie **a,int aSize,Movie **b,int bSize)
        {
        Movie **c; //a pointer to the destination array
        int i,j,spot;
        
        c = malloc(sizeof(Movie) * (aSize+bSize)); //malloc failure test omitted

        //merge until one source is exhausted
        spot = 0;
        for (i = 0,j = 0; i < aSize && j < bSize; ++spot)
            {
            if (a[i] < b[j])    //a's element is smaller, use it
                {
                c[spot] = a[i];
                i++;
                }
            else                //b's element is smaller, use it
                {
                c[spot] = b[j];
                j++;
                }
            }

        //i is either equal to aSize or j is equal to bSize
        //spot holds the index of the 1st available slot in c

        // copy over leftover elements in a, if any
        for ( ; i < aSize; ++i)
            {
            c[spot] = a[i];
            ++spot;
            }

        // copy over leftover elements in b, if any
        for ( ; j < bSize; ++j)
            {
            c[spot] = b[j];
            ++spot;
            }

        //c now holds the shuffle of a and b

        return c;
        }

int shortestMovie(Movie **array,int count)
{
   // Movie * shortest = malloc(sizeof(Movie));
    int i,ilargest = 0;
    for (i = 0; i < count; ++i)
        {
        if (array[i]->length < array[ilargest]->length)
            {
            ilargest = i;
            }
        }
    return ilargest;
}
void displayMenu()
{
    printf("Welcome to the Movie Database!\nMain menu:\n\t1:\tdisplay all movies\n\t2:\tdisplay shortest movie");
}
 void
    query(Movie **db, int count)
        {
        int option;

        displayMenu();

        // read the option
        option = readInt(stdin); //read from the keyboard
        while (option != 0)
            {
            if (option == 1)
                printMovies(db,count);
            else if (option == 2)
                printf("option 2 not implemented yet\n");
            else
                {
                printf("option not understood\n");
                displayMenu();
                }
            option = readInt(stdin);
            }
        }
int
    main(int argc, char **argv)
        {
        int countone,counttwo;
        if (argc != 3)
            {
            printf("need one arguments!\n");
            exit(1);
            }
        Movie **arrayone,**arraytwo,**finalarray;
       
        arrayone = readAllMovieRecords(argv[1],&countone);
        arraytwo = readAllMovieRecords(argv[2],&counttwo);

        finalarray = mergeAllArrays(arrayone,countone,arraytwo,counttwo);
        query(finalarray,countone+counttwo);

       // printMovies(finalarray, counttwo + countone);
        //int result = shortestMovie(finalarray,countone+counttwo);

        /*printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                               finalarray[result]->name,
                               finalarray[result]->description,
                               finalarray[result]->year,
                               finalarray[result]->length,
                               finalarray[result]->rating,
                               finalarray[result]->cast,
                               finalarray[result]->director);*/

        return 0;
        }