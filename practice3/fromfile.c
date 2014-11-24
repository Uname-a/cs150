#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

int main(int argc, char **argv)
{
	 FILE *fp = fopen("data.txt","r");
          if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n","info.dat");
            exit(1);
            }
            int i;
            int size = 10;
    char **items = allocate(sizeof(char *) * size);

        int count = 0;
        char * string = readString(fp);
        
        while (!feof(fp))
            {
            if (count == size)              //items is full!
                {
                // grow the items by doubling its size
                size = size * 2;
                items = reallocate(items,sizeof(char *) * size);
                //now there is enough room
                }
            items[count] = string;        //DO NOT FREE THE string!
            ++count;
            string = readString(fp);
            }
        fclose(fp);
        //shrink the items to 'count' number of elements
        items = reallocate(items,sizeof(char *) * count);
        char * smallest = items[0];
    for (i = 0; i < count; ++i)
        {
        if (strlen(items[i])< strlen(smallest))
            {
            smallest = items[i];
            }
        }
        printf("the shortest string is \"%s\"\n",smallest);
	return 0;
}