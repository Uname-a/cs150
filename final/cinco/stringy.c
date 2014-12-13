/*
 * =====================================================================================
 *
 *       Filename:  stringy.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 12:43:23 PM
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
#include "scanner.h"
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char **argv )
{
  printf ( "How many strings? " );
  int num;
  scanf("%d",&num);
  char ** array = malloc(sizeof(char * )* num);
  int i,times = 0;
  for (i = 0 ; i < num; ++i)
  {
    printf ( "String? " );
    array[i] = readString(stdin);
  }
  for( i = 1 ; i < num; ++i )
  {
    if(strcmp(array[0],array[i]) ==0)
    {
      ++times;
    }
  }
  printf ( "There are %d strings that differ from the first string.\n",times );
    return 0;
}				/* ----------  end of function main  ---------- */

