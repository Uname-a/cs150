#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int one , two , three;
	printf("the first integer? ");
	scanf("%d",&one);
	printf("the second integer? ");
	scanf("%d",&two);
	printf("the third integer? ");
	scanf("%d",&three);
	if (one > two && one > three)
	{
		printf("%d is the largest number\n",one );
	}
	if (two > one && two > three)
	{
		printf("%d is the largest number\n",two );
	}
	if (three > one && three > two)
	{
		printf("%d is the largest number\n",three );
	}

	return 0;
}