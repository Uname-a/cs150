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
    newBoard(int w, int h)
        {
        Board *p;
        spaces = malloc( sizeof( int * ) * p->width );

        for( i = 0; i < p->width; i++ )
        {
            p->spaces[i] = malloc( sizeof( int ) * p->height );
            p->spaces[i] = 1;
        }                  
        p.width = 0;                          
        p.height = 0;                                                //set to zero
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
	
} 
int main(int argc, char const *argv[])
{
	

	int players;
	players = gamemode();
    Board gameboard = newBoard(2,3); 
	return 0;
}

