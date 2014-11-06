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
        
        	*entries = fillMovieArray("data",&count);
        
        printf("%d\n",count );
        //entries[i] = fillMovieArray("data",&count);
       // printf("%s\n",entries->name );
        printMovies(entries[0], count);
        return 0;
        }