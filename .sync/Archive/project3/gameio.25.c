#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "logic.h"
//#include "gameio.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        }Board;
int //replaces readInt so that the program dosnt close when a int  is not inputted
    readOption(FILE *fp)//added so that entering anything other than an int caused the program to close
    {
    int x,result;
    result = fscanf(fp,"%d",&x);
    if (result == EOF)
        {
        return 0;
        }
    if (result == 0)// return the error code 10 so that the program dosnt end
        {
        fgetc(fp);
        return 201;
        }
    return x;
    }
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
    if (p->width <= 10 )
    {
    	for(i = 0 ; i < p->width ; ++i)
    	{
    	printf(" %d  ",i);
    	}	
    }
    else 
    {
    	for(i = 0 ; i < 10 ; ++i)
    	{
    	printf(" %d  ",i);
    	}
    	for(i = 10 ; i < p->width ;++i)
    	{
    		printf("%d  ",i);
    	}

    }
    for(i = 0 ; i < p->width ; ++i){
    	printf(" %d  ",i);
    }
    printf("\n\n");
    for (j = 0; j < p->height; ++j)
         {
         	//
             for (i = 0; i < p->width; ++i)
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
         printf("\n");
}
int gamemode()
{
	int players = 0;
	printf("How many players? ");
	players = readOption(stdin);
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
int nextMove(Board * p,int player){
    int move = 0;
    while (player == 1)
    {
        printf("Enter Player 1's move: " );
        
        move = readOption(stdin);
        
        if (legalMove(p,move) == 0)
        {
           
            return move;
        }
        else {
            printf("that isnt a legal move try again \n");
            //nextMove(p,1);
        }
        

    }
    while (player == 2){
        printf("Enter Player 2's move: " );
        move = readOption(stdin);
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
void gameWin(int player){
    printf("player %d wins!",player);
}
