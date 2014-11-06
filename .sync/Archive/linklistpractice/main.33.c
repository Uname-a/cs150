#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodes.h"
#include "scanner.h"

int main(int argc,char *argv[])
{
	FILE *fp;
    if ((fp = fopen("data.txt","r")) == 0)
        {
        fprintf(stderr,"data.txt missing\n");
        exit(-1);
        }
    Node *items = readIntegers(fp);
    displayList(items);
	return 0;
}
