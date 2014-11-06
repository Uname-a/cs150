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
Board * MoveBoard(Board * p, int move,int player){
    int i;
    
    if (player ==1)
    {

        for( i = p->height -1 ; i >= 0 ; i--)
        
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
        for( i = p->height -1 ; i >= 0 ; i--)
        {
        if (p->spaces[move][i] == 0)
        {
            p->spaces[move][i] = 2;
            return p;
        }
    }
    
    
    }
    return p;
}
int checkGame(Board * p ){
    int i;
    for(i = 0 ; i < p->width ;i++){
        if (p->spaces[i][0] == 0){
            return 0;
        }

    }
    return 0;
}
int main(int argc, char const *argv[])
{
	
    srand((int) .11);
	int mode,w,h,move,played;
    
    mode = gamemode();
    Board *gameboard ;
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    gameboard = fillBoard(w,h); 
    showBoard(gameboard);
    int gameover = 0;



    while(!gameover){
    move = nextMove(gameboard,1);
    
    gameboard = MoveBoard(gameboard,move,1);
    showBoard(gameboard);
   //system("clear");

    played =0;
    
    gameover = checkGame(gameboard);
    if (gameover != 0){
    while(mode == 1 && played == 0 && gameover == 0){
        int num = (rand() % w);
        
        
        if (legalMove(gameboard,num)== 0){
            //move = nextMove(gameboard,2);
    
            gameboard = MoveBoard(gameboard,num,2);
            printf("comperters's turn\n");
            showBoard(gameboard);

            played = 1;
        }
    }
    
        
    while(mode == 2 && played ==0 && gameover == 0){
        move = nextMove(gameboard,2);
    
        gameboard = MoveBoard(gameboard,move,2);
        showBoard(gameboard);
    }
    
    }
    
    }
    
	return 0;
}


