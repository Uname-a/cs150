#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char const *argv[])
{
	printf("Give me a Bool: ");
	char *  Bool;
	Bool = readToken(stdin);
	printf("Give me a String:");
	char * string;
	string = readString(stdin);
	printf("Give me a Int: ");
	int Ints;
	Ints = readInt(stdin);
	if (strcmp("True",Bool) == 0)
	{
		printf("%s\n\"%s\" \n ",string,string );
	}
	if (strcmp("False",Bool) == 0)
	{
		printf("%d\n",Ints * 2 );
	}
	return 0;
}