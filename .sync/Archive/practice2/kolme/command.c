#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"


int main(int argc, char *argv[])
{
	int Ints;
	char *  Bool;
	char * string;
	
   FILE *fp = fopen("info.dat","r");
          if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n","info.dat");
            exit(1);
            }
	

	Bool = readToken(fp);
	string = readString(fp);
	Ints = readInt(fp);

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