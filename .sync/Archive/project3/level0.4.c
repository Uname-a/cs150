#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	


	return 0;
}
int gamemode()
{
	int players;
	printf("How many players? ");
	scanf("%d",&players);
	if (players > 2 )
		printf("too many players\n");
		gamemode();
	else if ( players = 0 ){
		printf("not enough players\n");
		gamemode();
		}
	else{
		return players;
	}
} 
