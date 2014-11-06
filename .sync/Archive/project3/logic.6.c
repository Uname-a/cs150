#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gameio.h"

int legalMove(Board * p, int move){
    int i;
    //printf("%d\n",move );
    if (move < p->width  && move >= 0)
    {
        for (i = 0; i < p->height  ; i++)
        {
            if ((p->spaces[move][i]) == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;

    }
