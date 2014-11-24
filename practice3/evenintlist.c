#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ilist.h"
int getSmallest(Node *items);
int main(int argc, char **argv)
{
	Node * list;
	list = newEmptyList();
	int i ;
	printf("The list is ");
	for ( i = 1 ; i < argc ; ++ i)
	{
		list = join(atoi(argv[argc - i]),list);
	}
	displayList(list);
	printf("\nthe smallest is %d\n",getSmallest(list));
    freeList(list);
	return 0;
}
int
    getSmallest(Node *items)
        {
        int smallest = head(items); //assume first is smallest
        while (items != 0)
            {
            int v = head(items);
            if (v < smallest)
                smallest = v;
            items = tail(items);
            }
        return smallest;
        }