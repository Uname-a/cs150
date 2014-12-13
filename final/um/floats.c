/*
 * =====================================================================================
 *
 *       Filename:  floats.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 11:34:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include	<stdlib.h>
#include <stdio.h>
#include <string.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char **argv )
{
  float a,b,c;
  printf("first float: ");
  scanf("%f",&a);
  printf("second float: ");
  scanf("%f",&b);
  printf("third float: ");
  scanf("%f",&c);
  printf("The Floats, from smallest to largest, are: ");
  if(a < b && a < c )
  {
    printf("%f\n",a);
    if(b < c)
    {
      printf("%f\n",b);
      printf("%f\n",c);
    }
    else if (c < b )
    {
      printf("%f\n",c);
      printf("%f\n",b);
    }

}
  else if(b < a && b < c )
  {
    printf("%f\n",b);
    if(a < c)
    {
      printf("%f\n",a);
      printf("%f\n",c);
    }
    else if (c < a )
    {
      printf("%f\n",c);
      printf("%f\n",a);
    }

  }
  else if(c < b && c < a )
  {
    printf("%f\n",c);
    if(a < b)
    {
      printf("%f\n",a);
      printf("%f\n",b);
    }
    else if (b < a )
    {
      printf("%f\n",b);
      printf("%f\n",a);
    }

  }

    return 0;
}				/* ----------  end of function main  ---------- */

