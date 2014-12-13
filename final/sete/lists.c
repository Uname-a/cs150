/*
 * =====================================================================================
 *
 *       Filename:  lists.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 01:07:37 PM
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
#include "slist.h"
int same(Node * items , char * first);
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char **argv )
{
  Node * list;
  list = newEmptyList();
  printf ( "Enter a list of tokens: " );
  list = readList();
  printf ( "The list:\n" );
  displayList(list);
  printf ( "\n" );
  int a = same(list,head(list));
  
  printf ( "There are %d more string(s) with the same length as the first string.\n",a-1  );

    return 0;
}				/* ----------  end of function main  ---------- */

int
    same(Node *items,char * first)
        {
        if (items == 0) //base case
            return 0;
        else if (strlen(head(items)) == strlen(first) )
            return 1 + same(tail(items),first);
        else
            return 0 + same(tail(items),first);
        }
