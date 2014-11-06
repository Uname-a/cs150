//mathew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"


int math(int* array)
{
	int result;
	result = (array[0]-)
}









int main(int argc, char const *argv[])
{
	int * First[3];
	int * Second[3];
	int first,second;
	int comp;

	printf("First set, First number: ");
	First[0] = readInt(stdin);
	printf("\n");
	printf("First set, Second number: ");
	First[1] = readInt(stdin);
	printf("\n");
	printf("First set, Third number: ");
	First[2] = readInt(stdin);
	printf("\n");

	first = math(First);
	printf("For this set, the variance is %d\n",first);

	printf("Second set, First number: ");
	Second[0] = readInt(stdin);
	printf("\n");
	printf("Second set, Second number: ");
	Second[1] = readInt(stdin);
	printf("\n");
	printf("Second set, Third number: ");
	Second[2] = readInt(stdin);
	printf("\n");

	second = math(Second);
	printf("For this set, the variance is %d\n",second);

	comp = compaire(first,second);

	if (comp ==1)
	{
		printf("The first set has a larger variance\n", );
	}
	else if (comp == 2)
	{
		printf("The second set has a larger variance\n");
	}
	else
	{
		printf("The sets have the same variance\n");
	}
	return 0;
}