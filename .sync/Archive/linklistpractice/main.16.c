#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(int argc, char **argv)
{
	int ** x;
	int a = atoi(argv[1]);
	int s = atoi(argv[2]);
	struct stuff { int x[a][s]; int s; int r; }; //define the struct
    struct stuff n;  
       //int x[a-1][s-1];                       //allocate the struct
    n.x[a-1][s-1] = 1;
    n.s = 2;
    n.r = 3;
    printf("n.x is %d\n",n.x[a-1][s-1]);
    printf("n.s is %d\n",n.s);
    printf("n.r is %d\n",n.r);
	return 0;
}
