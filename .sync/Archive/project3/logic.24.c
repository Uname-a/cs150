#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"
//#include "logic.h"
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        }Board;
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
int checkGame(Board * p ){
    int i;
    for(i = 0 ; i < p->width ;i++){
        if (p->spaces[i][0] == 0){
            return 0;
        }

    }
    return 3;
}
int compMove(Board *p)
{
	srand(time(NULL));
	int num = (rand() % p->width);
    if (legalMove(p,num)== 0)
    {
        return num;
    }
    return compMove(p);
}
int helpWin(Board * p,int num,int row,int col,int rowDir,int colDir,int player,int count){

    if (player != 2){
        if (p->spaces[col][row] == 1 && col + colDir >= 0&& col + colDir < p->width && row + rowDir >= 0&& row + rowDir < p->height){
            col = col + colDir;
            row = row + rowDir;
            count ++;
            helpWin(p,num,row,col,rowDir,colDir,1,count);
        }
        else if(p->spaces[col][row] != 1){
            //printf("%d\n",count );
            return count;
        }
        else{
           // printf("%d\n",count + 1);
            return count + 1;
        }
    }

    else if(player == 2){
        if (p->spaces[col][row] == 2 && col + colDir >= 0&& col + colDir < p->width && row + rowDir >= 0&& row + rowDir < p->height){
            col = col + colDir;
            row = row + rowDir;
            count ++;
            helpWin(p,num,row,col,rowDir,colDir,2,count);
        }
        else if(p->spaces[col][row] != 2){
            //printf("%d\n",count );
            return count;
        }
        else{
            return count + 1;
        }

    }
    return helpWin(p,num,row,col,rowDir,colDir,player,count);
    
}
int checkWin(Board * p,int player,int num,int move ){
    int check,i,row;
    for( i = p->height -1 ; i >= 0 ; i--)
        {
        if (p->spaces[move][i] != 0)
        {
            row = i;
        }

        }
    check = 0;
    check = helpWin(p,num,row,move,-1,0,player,0);
    if (check >= 4)
    {
        return 1;
    }
    check =  helpWin(p,num,row,move,1,0,player,0);
    if (check >= 4)
    {
        return 1;
    }

    
    
    check = helpWin(p,num,row,move,0,1,player,0);
    
    if (check >= 4)
    {
        return 1;
    }
    
    check = helpWin(p,num,row,move,0,-1,player,0);
    if (check >= 4)
    {
        return 1;
    }
    check = helpWin(p,num,row,move,1,1,player,0);
    if (check >= 4)
    {
        return 1;
    }
    check = helpWin(p,num,row,move,-1,-1,player,0);
    if (check >= 4)
    {
        return 1;
    }
    check = helpWin(p,num,row,move,-1,1,player,0);
    if (check >= 4)
    {
        return 1;
    }
    check = helpWin(p,num,row,move,1,-1,player,0);
    if (check >= 4)
    {
        return 1;
    }
    return 0;

}