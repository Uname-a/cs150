#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int one , two;
	printf("the first integer? ");
	scanf("%d",&one);
	printf("the second integer? ");
	scanf("%d",&two);
	if (one > two)
	{
		printf("%d is larger that %d\n",one,two );
	}
	if (one < two)
	{
		printf("%d is larger that %d\n",two ,one);
	}
	return 0;
}