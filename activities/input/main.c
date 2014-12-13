/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/11/2014 06:05:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Matthew Baird (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include  <stdio.h>
#include	<stdlib.h>
#include "scanner.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main ( int argc, char **argv )
{
  char b;
  int a,c;
  FILE	*fp;										/* input-file pointer */
  char	*fp_file_name = argv[1];		/* input-file name    */

  fp	= fopen( fp_file_name, "r" );
  if ( fp == NULL ) {
    fprintf ( stderr, "couldn't open file '%s'; \n",fp_file_name  );
    exit (1);
  }
  a = readInt(fp);
  b = readToken(fp);
  c = readInt(fp);
  
  if( fclose(fp) == EOF ) {			/* close input file   */
    fprintf ( stderr, "couldn't close file '%s'; \n",fp_file_name );
    exit (1);
  }
   printf("%d \n",a+c);
  return 0;
}				/* ----------  end of function main  ---------- */

