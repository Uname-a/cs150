
typedef struct node
        {
        char *name;
        char *description;
        int year;
        int length;
        char * rating;
        char * cast;
        char * director;
        struct node *next;
        } Movie;

void fillMovieArray(char *fileName, int *finalSize,Movie **e);
void
    printMovies(Movie *entryArray, int num);