#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	
	double height;
	printf("Drop height (meeters)? "); // I know it is spelled meters
	scanf("%lf", &height);
	height = height * 3.2808;
	printf("Podiatrically speaking, that's %f feet \n",height );

	printf("At the given height, velocity before impact is %f feet per second \n",pow((2 * 32.185 * height),.5));
	return 0;
}