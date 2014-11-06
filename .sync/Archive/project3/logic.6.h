#include "gameio.h"

int legalMove(Board * p, int move);
Board * MoveBoard(Board * p, int move,int player);
int checkGame(Board * p );
int compMove(Board *p);
int helpWin(Board * p,int num,int row,int col,int rowDir,int colDir,int player,int count);

int checkWin(Board * p,int player,int num,int move );
