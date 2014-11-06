#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"
#include "support.h"


int
    main(int argc, char **argv)
        {
        int count;
         Movie **entries = malloc(sizeof(Movie));
       //int i;
        
        	fillMovieArray("data",&count,&entries);
        
        printf("%d\n",count );
        //entries[i] = fillMovieArray("data",&count);
        printf("%s\n",entries[1]->name );
       // printMovies(entries[0]->name, count);
        return 0;
        }