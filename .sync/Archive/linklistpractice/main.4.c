#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
	struct stuff {  int s; int r; }; //define the struct
    struct stuff n;  
                               //allocate the struct
    //n.x = 1;
    n.s = 2;
    n.r = 3;
    //printf("n.x is %d\n",n.x);
    printf("n.s is %d\n",n.s);
    printf("n.r is %d\n",n.r);
	return 0;
}
