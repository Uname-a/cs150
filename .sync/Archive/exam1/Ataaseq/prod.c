#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	double one , two , three ;
	printf("first number? ");
	scanf("%lf",&one);
	printf("second number? ");
	scanf("%lf",&two);
	printf("third number? ");
	scanf("%lf",&three);
	printf("The three numbers are %f, %f, and %f \n",one , two, three );


	printf("The weighted product is %f \n",3* one + 4 * two + 5 * three );
	return 0;
}