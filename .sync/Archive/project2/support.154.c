//matthew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h> 
#include "scanner.h"

typedef struct entry
        {
        char *MOVIE_NAME;
        char *DESCRIPTION;
        int YEAR;
        int LENGTH;
        char * RATING;
        char * CAST;
        char * DIRECTOR;
        } Movie;

int
readOption(FILE *fp)//added so that entering anything other than an int caused the program to close
    {
    int x,result;
    result = fscanf(fp,"%d",&x);
    if (result == EOF)
        {
        return 0;
        }
    if (result == 0)// return the error code 10 so that the program dosnt end
        {
        fprintf(stderr,"\n Option Not Understood \n\n");
        fgetc(fp);
        return 10;
        }
    return x;
    }

Movie *
newMovie(char *n,char *des,int y,int l,char * r,char *c, char * dir)
    {
    Movie *d = malloc(sizeof(Movie)); //malloc failure test omitted
    d->MOVIE_NAME = n;
    d->DESCRIPTION = des;
    d->YEAR = y;
    d->LENGTH = l;
    d->RATING = r;
    d->CAST = c;
    d->DIRECTOR = dir;
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
    if (feof(fp))
        {
        return 0; 
        }      // no record, return the null pointer
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

void 
printMovies(Movie **entries,int count)
{
    int i;
        
    printf("Movie Listings:\n");
    
    for (i=0; i < count; ++i)
        {
      
        printf("%d \"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                           i+1,
                           entries[i]->MOVIE_NAME,
                           entries[i]->DESCRIPTION,
                           entries[i]->YEAR,
                           entries[i]->LENGTH,
                           entries[i]->RATING,
                           entries[i]->CAST,
                           entries[i]->DIRECTOR);//formatted so that it is easy to understand
        }
}

Movie **
mergeAllArrays(Movie **listOne,int oneSize,Movie **listTwo,int twoSize)
    {
    Movie **listFinal; //a pointer to the destination array
    int i,j,spot = 0;
    c = malloc(sizeof(Movie) * (aSize+bSize)); //malloc failure test omitted
    //merge until one source is exhausted
    for (i = 0,j = 0; i < oneSize && j < twoSize; ++spot)
        {
        if (listOne[i] < listTwo[j])    //listOne's element is smaller, use it
            {
            listFinal[spot] = listOne[i];
            i++;
            }
        else                //listTwo's element is smaller, use it
            {
            listFinal[spot] = listTwo[j];
            j++;
            }
        }
    //i is either equal to aSize or j is equal to twoSize
    //spot holds the index of the 1st available slot in listFinal
    // copy over leftover elements in listOne, if any
    for ( ; i < oneSize; ++i)
        {
        listFinal[spot] = listOne[i];
        ++spot;
        }
    // copy over leftover elements in listTwo, if any
    for ( ; j < twoSize; ++j)
        {
        listFinal[spot] = listTwo[j];
        ++spot;
        }
    //listFinal now holds the shuffle of a and b
    return listFinal;
    }

int shortestMovie(Movie **array,int count)
{
    int i,ilargest = 0;
    for (i = 0; i < count; ++i)
        {
            if (array[i]->LENGTH < array[ilargest]->LENGTH)
                {
                ilargest = i;
                }
        }
    return ilargest;
}
int longestMovie(Movie **array,int count)
{
    int i,ilargest = 0;
    for (i = 0; i < count; ++i)
        {
            if (array[i]->LENGTH > array[ilargest]->LENGTH)
                {
                ilargest = i;
                }
        }
    return ilargest;
}
void moviesBefore(Movie **db,int count,int before)
{
    int i;
    for (i = 0; i < count; ++i)
        {
            if (db[i]->YEAR < before )
                {
                    printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                                   db[i]->MOVIE_NAME,
                                   db[i]->DESCRIPTION,
                                   db[i]->YEAR,
                                   db[i]->LENGTH,
                                   db[i]->RATING,
                                   db[i]->CAST,
                                   db[i]->DIRECTOR);//formatted so that it is easy to read 
                }
        }
}
void moviesAfter(Movie **db,int count,int before)
{
    int i;
    for (i = 0; i < count; ++i)
        {
            if (db[i]->YEAR > before )
                {
                    printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                                   db[i]->MOVIE_NAME,
                                   db[i]->DESCRIPTION,
                                   db[i]->YEAR,
                                   db[i]->LENGTH,
                                   db[i]->RATING,
                                   db[i]->CAST,
                                   db[i]->DIRECTOR);//formatted so that it is easy to read 
                }
        }
}
void moviesRating(Movie **db,int count,char * before)
{
    int i;
    for (i = 0; i < count; ++i)
        {
            if (strcmp ( before,db[i]->RATING) == 0 )
                {
                    printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                                   db[i]->MOVIE_NAME,
                                   db[i]->DESCRIPTION,
                                   db[i]->YEAR,
                                   db[i]->LENGTH,
                                   db[i]->RATING,
                                   db[i]->CAST,
                                   db[i]->DIRECTOR);//formatted so that it is easy to read 
                }
        }
}
void displayMenu()
{
    printf("Welcome to the Movie Database!\nMain menu:\n    1:  display all movies\n    2:  display shortest movie\n    3:  display longest movie\n    4:  display older movies\n     5:  display newer movies\n     6:  display movies by rating\n    7:  add movie (CHALLENGE)\n    8:  delete movie (CHALLENGE)\n    9:  save database (CHALLENGE)\n    0:  quit the program\n    Enter an Option: ");//made easy to read and change mirrors the format it prints 
}
 void
    query(Movie **db, int count)
        {
        int option;
        displayMenu();
        // read the option
        option = readOption(stdin); //read from the keyboard
        while (option != 0)
            {
                if (option == 1)
                    {
                       printMovies(db,count);
                       printf("Enter an option: ");
                    }
                else if (option == 2)
                    {
                        int result = shortestMovie(db,count);
                        printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                                   db[result]->MOVIE_NAME,
                                   db[result]->DESCRIPTION,
                                   db[result]->YEAR,
                                   db[result]->LENGTH,
                                   db[result]->RATING,
                                   db[result]->CAST,
                                   db[result]->DIRECTOR);
                         printf("Enter an option: ");
                    }
                else if (option == 3)
                    {
                        int result = longestMovie(db,count);
                        printf("\"%s\" \"%s\" %d %d %s \"%s\" \"%s\"\n",
                                   db[result]->MOVIE_NAME,
                                   db[result]->DESCRIPTION,
                                   db[result]->YEAR,
                                   db[result]->LENGTH,
                                   db[result]->RATING,
                                   db[result]->CAST,
                                   db[result]->DIRECTOR);//formatted so that it is easy to read 
                         printf("Enter an option: ");
                    }
                else if (option ==4)
                    {
                        printf("Display movies older than what year? ");
                        int before = readInt(stdin);
                        moviesBefore(db,count,before);
                        printf("Enter an option: ");
                    }
                else if (option ==5)
                    {
                        printf("Display movies newer than what year? ");
                        int before = readInt(stdin);
                        moviesAfter(db,count,before); 
                        printf("Enter an option: ");
                    }
                else if (option ==6)
                    {
                        printf("Display movies with what rating? ");
                        char * rating = readToken(stdin);
                        moviesRating(db,count,rating);
                        printf("Enter an option: ");
                    }
                else if (option ==7)
                    {
                        printf("Option 7 has not been implemented\n" );
                        printf("Enter an option: ");
                    }
                else if (option ==8)
                    {
                        printf("Option 8 has not been implemented\n" );
                        printf("Enter an option: ");
                    }
                else if (option ==9)
                    {
                        printf("Option 9 has not been implemented\n" );
                        printf("Enter an option: ");
                    }
                else if (option ==10)
                    {
                        displayMenu();
                    }
                else
                    {
                    printf("\n Option Not Understood \n\n");
                    displayMenu();
                    }
                option = readOption(stdin);
            }
        }