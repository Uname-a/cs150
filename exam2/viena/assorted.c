//mathew baird
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int order(int one, int two, int three);


int main(int argc, char *argv[])
{
	int one,two,three;
	one = atoi(argv[1]);
	two = atoi(argv[2]);
	three = atoi(argv[3]);
	printf("Args: %d, %d, and %d\n",one,two,three);
	printf("Next: %d, %d, and %d\n",one + 1,two +1 ,three + 1);
	int find;
	find = order(one,two,three);
	if (find == 1)
	{
		printf("The numbers are in decending order\n");
	}
	else if(find == 2){
		printf("The numbers are in ascending order\n");
	}
	else if (find == 3 )
	{
		printf("The numbers are not in order\n");
	}
	return 0;
}
int order(int one, int two, int three)
{
	
	if (one >= two && two >= three && one > three)
	{
		return 1;
	}
	else if (three >= two && two >= one && three > one)
	{
		
		return 2;
	}
	else
	{
		
		return 3;
	}
	
}