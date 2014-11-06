int main(int argc, char const *argv[])
{ 
	
    srand(time(NULL));
	int mode,w,h,move,played,win,n;
    
    mode = gamemode();
    Board *gameboard ;
    w = atoi(argv[1]);
    h = atoi(argv[2]);
    n = atoi(argv[3]);
    gameboard = fillBoard(w,h); 
    showBoard(gameboard);
    int gameover = 0;
    win = 0;



    while(gameover == 0 && win == 0){
    move = nextMove(gameboard,1);
    
    gameboard = MoveBoard(gameboard,move,1);
    showBoard(gameboard);
   //system("clear");

    played =0;
    
    gameover = checkGame(gameboard);
    //printf("hello\n");
    win= checkWin(gameboard,1,n,move);
    //printf("hello%d\n",gameover );
    if (gameover != 1 && win == 0 )
    {
        while(mode == 1 && played == 0 && win == 0){
            int num = (rand() % w);
            
            
            if (legalMove(gameboard,num)== 0){
                gameboard = MoveBoard(gameboard,num,2);
                printf("comperters's turn\n");
                showBoard(gameboard);

                played = 1;
            }
        }
        
            
        while(mode == 2 && played ==0 && win ==0)
            {
            move = nextMove(gameboard,2);
        
            gameboard = MoveBoard(gameboard,move,2);
            showBoard(gameboard);
            played =1;
            }
        win= checkWin(gameboard,2,n,move);
        gameover = checkGame(gameboard);
    }
    
    //printf("%d\n",win );
    }
    
	return 0;

}