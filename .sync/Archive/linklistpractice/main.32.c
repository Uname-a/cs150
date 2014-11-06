#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "structures.h"

typedef struct board
        {
        	int** spaces;
        	int width;
        	int height;
        } Board;

 Board 
    newEmptyEmployee(int h,int w)
        {
        Board p; //malloc failure test omitted
        p.spaces[w][h] = 1;                           //set to the empty string
        p.width = 1;                          //set to the empty string
        p.height = 1;                           //set to zero
                             //set to zero
        return p;
        }
int main(int argc,
 char *argv[])
{
	int **x;
	int a =1;
	int s = 1;
	Board n = newEmptyEmployee();
	printf("%d\n",n.width );
	//a = atoi(argv[1]);
	//s = atoi(argv[2]);
	//**x = malloc((sizeof int));
	 //define the struct
   

       //int x[a-1][s-1];                       //allocate the struct
   
	return 0;
}
