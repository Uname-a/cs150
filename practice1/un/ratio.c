#include <stdio.h>
#include <math.h>

int
main(int argc,char **argv)
    {
   int radius; 
    printf("circle radius? ");
    scanf("%d",&radius);
    double pi = 3.14159;
    printf("the circumference is %f \n",(2 * pi * radius));
    printf("the area is %f \n",( pi * radius * radius));
    printf("the ratio of the circumference to the area is %f \n",(2 * pi * radius)/(pi * radius * radius));
    return 0;

    }
