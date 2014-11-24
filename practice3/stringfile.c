#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "slist.h"

char * getSmallest(Node *items);
int main(int argc, char **argv)
{
	 FILE *fp = fopen(argv[1],"r");
          if (fp == 0)
            {
            fprintf(stderr,"file %s could not be opened for reading\n","info.dat");
            exit(1);
            }
            //int i;
            
        Node * list;
        list = newEmptyList();

        int count = 0;
        char * string = readString(fp);
        
        while (!feof(fp))
            {
            
            list = join(string,list);        //DO NOT FREE THE string!
            ++count;
            string = readString(fp);
            }
        fclose(fp);
        //shrink the items to 'count' number of elements
    
      printf("the smallest string is \"%s\" \n",getSmallest(list));
    
        
	return 0;
}
 char * 
    getSmallest(Node *items)
        {
        char *  smallest = head(items); //assume first is smallest
        while (items != 0)
            {
            char *  v = head(items);
            if (strlen(v) < strlen(smallest))
                smallest = v;
            items = tail(items);
            }
        return smallest;
        }