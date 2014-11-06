#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#include "scanner.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        } Board;
void *
allocate(size_t size)
    {
    char *s;
    s = malloc(size);
    if (s == 0)
        {
        fprintf(stderr,"could not allocate string, out of memory\n");
        exit(3);
        }

    return s;
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
 int **
    newRandomMatrix(int rows,int cols,int max)
        {
        int r,c;
        int **m = allocate(sizeof(int *) * rows);   //allocate the backbone
        for (r = 0; r < rows; ++r)
            {
            m[r] = allocate(sizeof(int) * cols);    //allocate a row
            for (c = 0; c < cols; ++c)              //fill the row
                m[r][c] = random() % max;
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
	int players;
	players = gamemode();

	int **matrix;
	matrix = newMatrix(4,3);
	displayMatrix(matrix,4,3);

	return 0;
}

