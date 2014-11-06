#ifndef GAMEIO_H
#define GAMEIO_H
typedef struct board
        {
        	int **spaces;
        	int width;
        	int height;
        }Board;
int readOption(FILE *fp);
Board * newBoard(int w, int h);
Board * fillBoard(int w, int h);
void showBoard(Board *p);
int gamemode();
int nextMove(Board * p,int player);
void gameWin(int player);
#endif