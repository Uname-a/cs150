#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gameio.h"
#include "logic.h"


int main(int argc, char const *argv[])
{ 
    if (argc >= 3)
        {
        printf("need three argvs\n");
        return -1;
        }
	int mode,w,h,move,played,win,n;
    mode = gamemode();
    Board *gameboard ;
    
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    n = atoi(argv[3]);
    gameboard = fillBoard(w,h); 
    showBoard(gameboard);
    win = 0;
    while( win == 0)
        {
        move = nextMove(gameboard,1);
        gameboard = MoveBoard(gameboard,move,1);
        showBoard(gameboard);
       //system("clear");
        played =0;
        win = checkWin(gameboard,1,n,move);
        win = checkGame(gameboard);
        if ( win == 0 )
            {
            while(mode == 1 && played == 0 && win == 0)
                {
                printf("comperters's turn\n");
                move = compMove(gameboard);
                gameboard = MoveBoard(gameboard,move,2);
                showBoard(gameboard);
                played = 1;
                }
            while(mode == 2 && played ==0 && win ==0)
                {
                move = nextMove(gameboard,2);
                gameboard = MoveBoard(gameboard,move,2);
                showBoard(gameboard);
                played =1;
                }
            win= checkWin(gameboard,2,n,move);
            win = checkGame(gameboard);
            }
        }   
    return 0;
}