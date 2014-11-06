#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"

int main(int argc, char const *argv[])
{
	struct stuff { int x; char *s; double r; }; //define the struct
    struct stuff n;                             //allocate the struct
    n.x = 42;
    n.s = "hello, world!";
    n.r = 3.14159;
    printf("n.x is %d\n",n.x);
    printf("n.s is %s\n",n.s);
    printf("n.r is %f\n",n.r);
	return 0;
}
