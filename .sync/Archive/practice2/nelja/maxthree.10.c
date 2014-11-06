#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max3(int *Int);
int main(int argc, char const *argv[])
{
	int Int[3];
	printf("Give me an int:  ");
	scanf("%d",&Int[0]);
	printf("another:");
	scanf("%d",&Int[1]);
	printf("another: ");
	scanf("%d",&Int[2]);

	printf("the max is %d \n",max3(Int));

	return 0;
}
int max3(int *Int)
{
	if (Int[0] > Int[1] && Int[0] > Int[2])
	{
		return Int[0];
	}
	if (Int[1] > Int[0] && Int[1] > Int[2])
	{
		return Int[1];
	}
	if (Int[2] > Int[1] && Int[2] > Int[0])
	{
		return Int[2];
	}
}