//matthew baird
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

Movie * newMovie(char *n,char *des,int y,int l,char * r,char *c, char * dir);
Movie * readMovieRecord(FILE *fp);
Movie ** readMovieRecordsList(char *fileName,int *finalSize);
void printMovies(Movie **entries,int count);
Movie ** mergeAllArrays(Movie **a,int aSize,Movie **b,int bSize);
int shortestMovie(Movie **array,int count);
int longestMovie(Movie **array,int count);
void displayMenu();
void query(Movie **db, int count);
int moviesBefore(Movie **array,int count,int before);
int moviesAfter(Movie **array,int count,int before);

