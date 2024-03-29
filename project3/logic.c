//matt baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"
int legalMove(Board * p, int move)//checks if the move is legal
	{
    int i;
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
    return 1;
    }
Board * MoveBoard(Board * p, int move,int player)//marks the board with the player's move
	{
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
int checkGame(Board * p )//check if board is filled
	{
    int i;
    for(i = 0 ; i < p->width ;i++)
    	{
        if (p->spaces[i][0] == 0)
        	{
            return 0;
        	}
    	}
    return 3;
	}
int compMove(Board *p)//the comperter logic for playing
	{
	int count = 0;
	int i,j = 0;
	for(i = 0 ; i < p->width ;i++)//find the number of legal moves
    	{
        if (p->spaces[i][0] == 0)
        	{
            ++count;
        	}
    	}
    int array[count];//allocate the array
    for(i = 0 ; i < p->width ;++i)
    	{
        if (p->spaces[i][0] == 0)
        	{
        	array[j] = i;
        	++j;
        	}   
    	}
    int num = (rand() % count );//pick a random number in an array
	return array[num];
	}
//the helper function for checking if a player won
int helpWin(Board * p,int num,int row,int col,int rowDir,int colDir,int player,int count)
	{

    if (player != 2)//player one
    {
    	//make sure that it dosnt try to access out of range 
        if (p->spaces[col][row] == 1 && col + colDir >= 0&& col + colDir < p->width && row + rowDir >= 0&& row + rowDir < p->height)
        {
            col = col + colDir;
            row = row + rowDir;
            count ++;
            helpWin(p,num,row,col,rowDir,colDir,1,count);
        }
        else if(p->spaces[col][row] != 1)
        {
            return count;
        }
        else
        {
            return count + 1;
        }
    }

    else if(player == 2)//player two
    {
        if (p->spaces[col][row] == 2 && col + colDir >= 0&& col + colDir < p->width && row + rowDir >= 0&& row + rowDir < p->height)
        {
            col = col + colDir;
            row = row + rowDir;
            count ++;
            helpWin(p,num,row,col,rowDir,colDir,2,count);
        }
        else if(p->spaces[col][row] != 2)
        {
            return count;
        }
        else
        {
            return count + 1;
        }

    }
    return helpWin(p,num,row,col,rowDir,colDir,player,count);
    
	}
int checkWin(Board * p,int player,int num,int move )//checks if a player has won
{
    int check,i,row;
    for( i = p->height -1 ; i >= 0 ; i--)//gets the row 
        {
        if (p->spaces[move][i] != 0)
	        {
	        row = i;
	        }
        }
    check = 0;
    //checks all the differnt ways to win
    check = helpWin(p,num,row,move,-1,0,player,0);
    if (check >= num)
    {
        return player;
    }
    check =  helpWin(p,num,row,move,1,0,player,0);
    if (check >= num)
    {
        return player;
    }
    check = helpWin(p,num,row,move,0,1,player,0);
    if (check >= num)
    {
        return player;
    }
    
    check = helpWin(p,num,row,move,0,-1,player,0);
    if (check >= num)
    {
        return player;
    }
    check = helpWin(p,num,row,move,1,1,player,0);
    if (check >= num)
    {
        return player;
    }
    check = helpWin(p,num,row,move,-1,-1,player,0);
    if (check >= num)
    {
        return player;
    }
    check = helpWin(p,num,row,move,-1,1,player,0);
    if (check >= num)
    {
        return player;
    }
    check = helpWin(p,num,row,move,1,-1,player,0);
    if (check >= num)
    {
        return player;
    }
    return 0;

}