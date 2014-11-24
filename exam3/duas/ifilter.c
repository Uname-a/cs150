#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "ilist.h"

Node * extractLarger(Node *items, int num);
int main(int argc, char **argv)
{
	Node * list;
        list = newEmptyList();
        printf("Give me the list: ");
        
		list = readList();
		printf("give me the threshold value: ");
		int num;
		scanf("%d",&num);
        printf("\n");
        printf("The original list is: ");

        displayList(list);

        list = extractLarger(list,num);
        printf("\n");
        if(list == NULL)
        {
        	printf("The filtered list is empty\n");
        }
        else
        {
        printf("The filtered list is: ");
		displayList(list);
		printf("\n");
		}
        freeList(list);
        printf("The filtered list has been freed\n");
	return 0;
}
Node *
    extractLarger(Node *items,int num)
        {
        Node *result = 0;
        
        while (items != 0)
            {
            
            if (head(items)> num)
            {
                result = join(head(items),result);
            }
            	
            items = tail(items);
            }
        return result;
        }
