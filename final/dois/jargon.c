#include <stdio.h>
#include <stdlib.h>

// scope 1
float v = 2.5;

int start()
    {
    // scope 2
    srand(0);
    int weekend;
    int day = rand() % 7;
    if (day == 0 || day == 1)
        {
        // scope 3
        weekend = 1;
        }
    else
        {
        // scope 4
        weekend = 0;
        }
    return weekend;
    }

void playSong(char *title, int time)
    {
    // scope 5
    printf("The song %s is being played for %d minutes.\n", title, time);
    }

int playTimes(char *song, int a)
    {
    // scope 6
    int m;
    for (m = 0; m < a; m++)
        // scope 7
        {
        int length = 4;
        playSong(song, length);
        }
    return a;
    }

char* description = "Welcome to the music database!  ";

void answers()
    {
    printf("In what scope or scopes is 'day' defined?\n");
    printf("scope 2\n");
    printf("In what scope or scopes is 'title' defined?\n");
    printf ( "scope 5\n" );
    printf("In what scope or scopes is 'description' defined?\n");
    printf ( "scope 1\n" );
    printf("In what scope or scopes is 'playSong' defined?\n");
    printf ( "scope 1\n" );
    printf("In what scope or scopes is 'song' defined?\n");
    printf ( "scope 6 , 8\n" );
    printf("Give two names visible in scope 8\n");
    printf ( "we , description\n" );
    printf("Give two names not defined in scope 1 that are visible in scope 2\n");
    printf ( "weekend, day\n" );
    printf("Give two names visible in scope 5\n");
    printf ( "title, time\n" );
    printf("Are there any names defined in scope 7 that are visible in scope 6?\n");
    printf ( "no\n" );
    printf("Is there one scope where all names are visible?\n");
    printf ( "no\n" );
    }

int
main()
    {
    // scope 8
    printf("%s", description);
    printf("Version: %f\n", v);
    int we = start();
    if (we == 1)
        {
        printf("It is the weekend\n");
        }
    else
        {
        printf("It is the not weekend\n");
        }
    char *song = "Jingle Bells";
    int num = 4;
    int timesPlayed = playTimes(song, num);
    printf("The song %s has been played %d times\n", song, timesPlayed);

    answers();
    return 0;
    }
