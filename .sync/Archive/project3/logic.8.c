#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"

int legalMove(Board * p, int move){
    int i;
    //printf("%d\n",move );
    if (move < p->width  && move >= 0)
    {
        for (i = 0; i < p->height  ; i++)
        {
            if ((p->spaces[move][i]) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;//might brake things

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