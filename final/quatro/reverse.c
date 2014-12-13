/*
 * =====================================================================================
 *
 *       Filename:  reverse.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 12:25:52 PM
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
#include <math.h>
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int helper(int n, int r);
int main ( int argc, char **argv )
{
  printf ( "Give me the integer: " );
  int a;
  scanf("%d",&a);
  int reverse = helper(a,0);
  printf ( "The reversal of the digits is %d\n",reverse);
  
    return 0;
}				/* ----------  end of function main  ---------- */


int helper(int n , int r)
{
  if(n < 10 )
  {
    return r * 10+n; 
  }
  else {
   return helper(n/10,n%10+r*10);
  }
  
}

