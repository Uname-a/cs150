
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
Movie **
    mergeAllArrays(Movie **a,int aSize,Movie **b,int bSize);
int shortestMovie(Movie **array,int count);
int longestMovie(Movie **array,int count);
void displayMenu();
 void query(Movie **db, int count);
int moviesBefore(Movie **array,int count);

