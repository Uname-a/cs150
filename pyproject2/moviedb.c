//mathew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"
#include "support.h"

int
main(int argc, char **argv)
    {
    int countone,counttwo;
    if (argc != 3)
        {
        printf("need two arguments!\n");
        exit(1);
        }
    Movie **arrayone,**arraytwo,**finalarray;
    arrayone = readMovieRecordsList(argv[1],&countone);
    arraytwo = readMovieRecordsList(argv[2],&counttwo);
    finalarray = mergeAllArrays(arrayone,countone,arraytwo,counttwo);
    query(finalarray,countone+counttwo);
    return 0;
    }