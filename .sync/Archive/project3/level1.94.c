#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        }Board;
Board *
    newBoard(int w, int h)
        {
        Board * p = malloc(sizeof(Board *));
       int i;
 
    /* allocate each row's place holder */
    p->spaces = malloc( sizeof( int * ) * w );
    p->width = w;
    p->height = h;

    /* allocate each row's columns */
    for( i = 0; i < w; i++ )
        p->spaces[i] = malloc( sizeof( int ) * h );
        int j;
        for (j = 0; j < h; ++i)
        {
            printf("%d",p->width); 
        }

        return p;
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
	return 0;
} 
int main(int argc, char const *argv[])
{
	

	int players;
	players = gamemode();
    Board *p ;
    p = newBoard(3,3); 
	return 0;
}

