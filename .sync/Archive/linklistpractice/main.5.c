#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
	int ** a;
	struct stuff { int a[1][1]; int s; int r; }; //define the struct
    struct stuff n;  
                               //allocate the struct
    n.x[0][0] = 1;
    n.s = 2;
    n.r = 3;
    printf("n.x is %d\n",n.x[0][0]);
    printf("n.s is %d\n",n.s);
    printf("n.r is %d\n",n.r);
	return 0;
}