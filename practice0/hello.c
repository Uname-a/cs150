#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void greet(char *);

int
main(int argc,char **argv)
    {
    int n;
    srand(time(0));  //reset the random number generator
    n = rand() % 100;
    greet("multiverse");
    printf("Hello, world number %d!\n",n);

    return 0;
    }

void
greet(char *who)
    {
    printf("Greetings to the %s...\n",who);
    return;
    }
