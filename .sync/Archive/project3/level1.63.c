#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        };
void
    newBoard(struct board * p,int w, int h)
        {
        
        p->spaces = malloc( sizeof( int * ) * w );
        int i;
        p->width = w;
        p->height = h;
        for( i = 0; i < p->width; i++ )
        {
            p->spaces[i] = malloc( sizeof( int ) * h );
            p->spaces[i] = 1;
        }                  
                                                        //set to zero
        //return p;
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
    Board *p ;
    newBoard(p,2,3); 
	return 0;
}

