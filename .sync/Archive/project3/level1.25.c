#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        } Board;
Board 
    newEmptyEmployee(void)
        {
        Board p = malloc(sizeof(Board)); //malloc failure test omitted
        p->spaces = "";                           //set to the empty string
        p->width = "";                          //set to the empty string
        p->height = 0;                           //set to zero                        //set to zero
        return p;
        }

int **
    newMatrix(int rows,int cols)
        {
        int r;
        int **m = allocate(sizeof(int *) * rows);   //allocate the backbone
        for (r = 0; r < rows; ++r)
            {
            m[r] = allocate(sizeof(int) * cols);    //allocate a row
            }
        return m;
        }

void
    displayMatrix(int **m,int rows,int cols)
        {
        int r,c;
        for (r = 0; r < rows; ++r)
            {
            for (c = 0; c < cols; ++c)
                {
                printf("%3d ",m[r][c]); //%3d to pad values with spaces
                }
            printf("\n");
            }
        }
int gamemode()
{
	int players = 0;
	printf("How many players? ");
	scanf("%d",&players);
	if (players > 2 )
	{
		printf("too many players\n");
		gamemode();
	}
	else if ( players == 0 ){
		printf("not enough players\n");
		gamemode();
		}
	else
	{
		return players;
	}
	
} 
int main(int argc, char const *argv[])
{
	Board gameboard; 

	int players;
	players = gamemode();

	//int **matrix;
	gameboard->spaces = newMatrix(4,3);
	int i;
	for ( i = 0 ; i < 3 ;++i)
	{
		//matrix[0][i] = i;
	}
	//displayMatrix(matrix,4,3);

	return 0;
}

