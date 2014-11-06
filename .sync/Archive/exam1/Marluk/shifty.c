#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
main(int argc, char **argv)
    {
    int array[3];


    
    printf("first integer? ");

    scanf("%d",&array[0]);
    printf("second integer? ");

        scanf("%d",&array[1]);
        printf("third integer? ");

            scanf("%d",&array[2]);
printf("Filled array: \n");
    printf("\telement 0: %d \n", array[0]);
    
    printf("\telement 1: %d \n", array[1]);
            
    printf("\telement 2: %d \n", array[2]);

    
    int swap;
    int four;
    printf("Fourth integer? ");
    scanf("%d",&four);

    swap = array[2];
    array[2] = four;
    four = array[1];
    array[1] = swap;
    array[0] = four;


    printf("Rearranged array: \n");
    printf("\telement 0: %d \n", array[0]);
    
    printf("\telement 1: %d \n", array[1]);
            
    printf("\telement 2: %d \n", array[2]);

    

    return 0;
    }
