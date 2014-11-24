#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "scanner.h"

int * readNumbers(char * file, int * finalcount);
int howMany(int * items, int  count);

int main(int argc, char **argv)
{
    int  count;
	int * items;
    items = readNumbers(argv[1],&count);
    printf("%d",items[1]);
    int num = howMany(items,count);
    printf("There were %d numbers in the file\n",count);
    printf("There are %d numbers greater than %d, which is the first number\n",num,items[0]);
	return 0;
}
int * readNumbers(char * file,int * finalcount)
{
    FILE *fp = fopen(file,"r");
          if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n","info.dat");
            exit(1);
            }
            
            int size = 10;
            int count = 0;
    int * items = allocate(sizeof(int ) * size);

        
        
        int number = readInt(fp);
        count++;
        while (!feof(fp))
            {
            if (count == size)              //items is full!
                {
                // grow the items by doubling its size
                size = size * 2;
                items = reallocate(items,sizeof(int) * size);
                //now there is enough room
                }
            items[count -1 ] = number;        //DO NOT FREE THE number!
            count++;
            number = readInt(fp);
            }
            
        fclose(fp);
        *finalcount = count;
        //shrink the items to 'count' number of elements
        items = reallocate(items,sizeof(int) * count);
        return items;
}
int howMany(int * items,int count)
{
    int i,num = 0;
    for (i = 0; i < count; ++i)
        {
        if (items[i] > items[0])
            {
            num++;
            }
        }
    return num;
}