#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
int ** spaces;
typedef struct board
        {
        	int spaces;
        	int width;
        	int height;
        } Board;
 Employee *
    newEmptyEmployee(void)
        {
        Employee *p = malloc(sizeof(Employee)); //malloc failure test omitted
        p->name = "";                           //set to the empty string
        p->title = "";                          //set to the empty string
        p->years = 0;                           //set to zero
        p->salary = 0.0;                        //set to zero
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
