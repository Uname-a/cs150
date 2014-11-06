//mathew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"












int main(int argc, char const *argv[])
{
	int * First[3];
	int * Second[3];

	printf("First set, First number: \n");
	First[0] = readInt(stdin);
	printf("First set, Second number: \n");
	First[1] = readInt(stdin);
	printf("First set, Third number: \n");
	First[2] = readInt(stdin);
	return 0;
}