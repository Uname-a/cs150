//mathew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "scanner.h"

int comp(char * one, char * two , char * three);
int main(int argc, char *argv[])
{
	char * one;
	char * two;
	char * three;
	
   FILE *fp = fopen("3.strings","r");
          if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n","info.dat");
            exit(1);
            }
	
one = readString(fp);
two = readString(fp);
three = readString(fp);
printf("Strings: \"%s\", \"%s\", and \"%s\" \n",one ,two, three );
	int find;
	find = comp(one,two,three);

	if (find == 1)
	{
		printf("\"%s\" is not the same\n",one);
	}
	else if(find == 2){
		printf("\"%s\" is not the same\n",two);
	}
	else if (find == 3 )
	{
		printf("\"%s\" is not the same\n",three);
	}
	return 0;
}
int comp(char * one, char * two , char * three)
{
	if ((strcmp(one,two) == 0))
	{
		return 3;
	}
	else if ((strcmp(two,three) == 0))
	{
		return 1;
	}
	else if ((strcmp(three,one) == 0))
	{
		return 2;
	}
	return 0;
}