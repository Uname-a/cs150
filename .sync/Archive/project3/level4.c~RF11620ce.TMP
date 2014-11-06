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
         for (i = 0; i < p->width; ++i)
         {
             for (j = 0; j < p->height; ++j)
             {
                p->spaces[i][j] = 0;
             }
         }
         return p;
}
void showBoard(Board *p){
    int i,j;
    for (j = 0; j < p->height; j++)
         {
             for (i = 0; i < p->width; i++)
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
    //printf("%d\n",move );
    if (move < p->width  && move >= 0){
        for (i = 0; i < p->height  ; i++)
        {
            if ((p->spaces[move][i]) == 0){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
        else {
            return 1;
        }
        return 1;

    }
    
   
    
  
int nextMove(Board * p,int player){
    int move = 0;
    while (player == 1)
    {
        printf("Enter Player 1's move: " );
        scanf("%d",&move);
        
        if (legalMove(p,move) == 0)
        {
            printf("%d\n",move );
            return move;
        }
        else {
            printf("that isnt a legal move try again \n");
            //nextMove(p,1);
        }
        

    }
    while (player == 2){
        printf("Enter Player 2's move: " );
        scanf("%d",&move);
         if (legalMove(p,move) == 0)
        {
            return move;
        }
        else if (legalMove(p,move)==1){
            printf("that isnt a legal move try again \n");
            //nextMove(p,2);
        }
    }
    
    
    return 0;
  
    
}
Board * MoveBoard(Board * p, int move,int player){
    int i;
    
    if (player ==1)
    {
        //for( i = 0 ; i < p->height ; ++i)
        for(i = p->height ; i >= 0;i-- )
        {
            if (p->spaces[move][i] == 0)
            {
               
                p->spaces[move][i] = 1;
                return p;
            }
        }
    }
    else if (player == 2)
    {
        for(i = 0 ; i < p->height;++i ){
        if (p->spaces[move][i] == 0)
        {
            p->spaces[move][i] = 2;
            return p;
        }
    }
    
    
    }
    return p;
}
int main(int argc, char const *argv[])
{
	

	int mode,w,h,move,player;
    player =1;
    mode = gamemode();
    Board *gameboard ;
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    gameboard = fillBoard(w,h); 
    showBoard(gameboard);
    move = nextMove(gameboard,2);
    printf("%d \n",move );
    gameboard = MoveBoard(gameboard,move,player);
    showBoard(gameboard);
	return 0;
}

