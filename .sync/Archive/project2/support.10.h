
typedef struct entry
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

Movie *
    newMovie(char *n,char *des,int y,int l,char * r,char *c, char * dir);
Movie *
    readMovieRecord(FILE *fp);
Movie **
    readAllMovieRecords(char *fileName,int *finalSize);
void printMovies(Movie **entries,int count);