//matt baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"
#include "logic.h"

//look at the included files to see what each function does
int main(int argc, char const *argv[])
{ 
    if (argc != 4)//checks for the correct number of argvs
        {
        printf("need three argvs\n");
        return -1;
        }
    //setup phase
    srand((int) time(NULL));//seeds the random number generator
	int mode,w,h,move,played,win,n;
    mode = gamemode();
    Board *gameboard ;
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    n = atoi(argv[3]);
    gameboard = fillBoard(w,h); 
    system("clear"); //for linux
    //system("cls"); //for windows
    showBoard(gameboard);
    win = 0;
    //the main game loop
    while( win == 0)
        {
        
        win = checkGame(gameboard);
        if (win ==0)
            {
            move = nextMove(gameboard,1);
            gameboard = MoveBoard(gameboard,move,1);
            system("clear"); //for linuc
            //system("cls"); //for windows
            showBoard(gameboard);
            played =0;
            win = checkWin(gameboard,1,n,move);
            }
        
        if ( win == 0 )
            {
            win = checkGame(gameboard);
            if(mode == 1 && played == 0 && win == 0)
                {
                printf("comperters's turn\n");
                move = compMove(gameboard);
                gameboard = MoveBoard(gameboard,move,2);
                system("clear"); //for linuc
                //system("cls"); //for windows
                showBoard(gameboard);
                played = 1;
                }
            else if(mode == 2 && played ==0 && win ==0)
                {
                move = nextMove(gameboard,2);
                gameboard = MoveBoard(gameboard,move,2);
                system("clear"); //for linuc
                //system("cls"); //for windows
                showBoard(gameboard);
                played =1;
                }
            win= checkWin(gameboard,2,n,move);
            
            }

        }
    gameWin(win);//ending
    return 0;
}