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
                               entryArray[i]->director,

            }
        }