#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
int ** spaces;
typedef struct board
        {
        	int spaces[1][1];
        	int width;
        	int height;
        } Board;
 Board *
    newEmptyEmployee(void)
        {
        Board *p = malloc(sizeof(Board)); //malloc failure test omitted
        p->spaces[1][1] = 1;                           //set to the empty string
        p->width = 1;                          //set to the empty string
        p->height = 1;                           //set to zero
                             //set to zero
        return p;
        }
int main(int argc,
 char *argv[])
{
	int **x;
	int a =1;
	int s = 1;
	//a = atoi(argv[1]);
	//s = atoi(argv[2]);
	//**x = malloc((sizeof int));
	 //define the struct
    Board n;

       //int x[a-1][s-1];                       //allocate the struct
   
	return 0;
}
