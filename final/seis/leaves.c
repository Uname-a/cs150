/*
 * =====================================================================================
 *
 *       Filename:  leaves.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 12:55:52 PM
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
  
  FILE	*fp;										/* input-file pointer */
  char	*fp_file_name = argv[1];		/* input-file name    */
  float data;
  fp	= fopen( fp_file_name, "r" );
  if ( fp == NULL ) {
    fprintf ( stderr, "couldn't open file '%s'\n",fp_file_name );
    exit (EXIT_FAILURE);
  }
  int num=0;
  data = readReal(fp);
  while(!feof(fp))
  {
    ++num;
    data = data + readReal(fp);
  }
  printf ( "The average number of leaves that fell over %d days was %f\n",num,data / num );
  if( fclose(fp) == EOF ) {			/* close input file   */
    fprintf ( stderr, "couldn't close file '%s'\n",fp_file_name );
    exit (EXIT_FAILURE);
  }/*========= File Close =========*/
    
    return 0;
}				/* ----------  end of function main  ---------- */

