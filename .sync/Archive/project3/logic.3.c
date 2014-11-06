#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"

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