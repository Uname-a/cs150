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
        
        Movie **entries;
       entries = readAllMovieRecords("data",&count);
       printMovies(entries, count);
      // printf("%s\n",entries[0]->name );
        return 0;
        }