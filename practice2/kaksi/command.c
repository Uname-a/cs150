#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"


int main(int argc, char *argv[])
{
	int Ints;
	char *  Bool;
	char * string;
  if (argc != 4)  {
    printf("need 3 args\n");
    exit(1);
  }
	Bool = argv[1];
	string = argv[2];
	Ints = atoi(argv[3]);

	
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
