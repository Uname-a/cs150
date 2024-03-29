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
        Board *p = malloc(sizeof(Board *));
       int i;
 
    /* allocate each row's place holder */
    p->spaces = malloc( sizeof( int * ) * w );
    p->width = w;
    p->height = h;

    /* allocate each row's columns */
    
    for( i = 0; i < w; i++ ){
        p->spaces[i] = malloc( sizeof( int ) * h );}
        

        return p;
        }

Board * fillBoard(int w, int h){
         Board *p = malloc(sizeof(Board *));
         p = newBoard(w,h);
         int i,j;
         for (i = 0; i < w; ++i)
         {
             for (j = 0; j < h; ++j)
             {
                p->spaces[i][j] = 0;
             }
         }
         return p;
}
void showBoard(Board *p){
    int i,j;
    for (i = 0; i < p->width; ++i)
         {
             for (j = 0; j < p->height; ++j)
             {
                if (p->spaces[i][j] == 0){
                 printf("[ ] ");
                }
                else if (p->spaces[i][j] == 1 ){
                    printf("[O] ");
                }
                else if (p->spaces[i][j] == 2){
                    printf("[X] ");
                }
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
	return 0;
} 
int legalMove(Board * p, int move){
    int i;
    if (move <= p->width -1 && move >= 0){
        for (i = 0; i < p->width; ++i)
        {
            if ((p->spaces[i][p->height -1]) ==0){
                return 0;
            }
            else{
                return 1;
            }
        }

    }
    
        return 1;
    

    
}  
int nextMove(Board * p,int player){
    int move;
    if (player == 1)
    {
        printf("Enter Player 1's move: " );
        scanf("%d",&move);
        
        if (legalMove(p,move) == 0)
        {
            return move;
        }
        else{
            printf("that isnt a legal move try again \n");
            nextMove(p,player);
        }

    }
    else if (player == 2){
        printf("Enter Player 2's move: " );
        scanf("%d",&move);
    }


    return move;
}
int main(int argc, char const *argv[])
{
	

	int players,w,h,move;
    players = gamemode();
    Board *p ;
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    p = fillBoard(w,h); 
    showBoard(p);
    move = nextMove(p,1);
	return 0;
}

