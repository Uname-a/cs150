/*
 * =====================================================================================
 *
 *       Filename:  extreme.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/12/2014 12:00:11 PM
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
void
    displayMatrix(int **m,int rows,int cols);

void
    matrixMinIndex(int **m,int rows,int cols,int *minr,int *minc);

int main ( int argc, char **argv )
{
  int ** matrix;
  matrix = malloc(sizeof(int *)* 4);
  int i;
  for ( i = 0; i < 4; i += 1 ) {
    matrix[i] = malloc(sizeof(int)*3);
  }

  FILE	*fp;										/* input-file pointer */
  char	*fp_file_name = argv[1];		/* input-file name    */

  fp	= fopen( fp_file_name, "r" );
  if ( fp == NULL ) {
    fprintf ( stderr, "couldn't open file '%s'\n",fp_file_name );
    exit (EXIT_FAILURE);
  }
  int j,x;
  for ( i = 0; i < 4; i += 1 ) {
  
    for ( j = 0; j < 3; j += 1 ) {
      fscanf(fp,"%d",&x);
      matrix[i][j] = x;
    }
  }

  if( fclose(fp) == EOF ) {			/* close input file   */
    fprintf ( stderr, "couldn't close file '%s'\n",fp_file_name );
    exit (EXIT_FAILURE);
  }/*========= File Close =========*/
  int   minr,minc;
  printf ( "The Matrix: \n" );
  displayMatrix(matrix,4, 3);
  matrixMinIndex(matrix,4,3,&minr,&minc);
  printf ( "The smallest number is at indices: \n  row %d, column %d\n",minr,minc );
    return 0;
}				/* ----------  end of function main  ---------- */
void
    matrixMinIndex(int **m,int rows,int cols,int *minr,int *minc)
        {
        int r,c;
        *minr = 0;
        *minc = 0;
        for (r = 0; r < rows; ++r)
            for (c = 0; c < cols; ++c)
                {
                if (m[r][c] < m[*minr][*minc])
                    {
                    *minr = r;
                    *minc = c;
                    }
                }
        }

void
    displayMatrix(int **m,int rows,int cols)
        {
        int r,c;
        for (r = 0; r < rows; ++r)
            {
            for (c = 0; c < cols; ++c)
                {
                printf("[%d] ",m[r][c]); //%3d to pad values with spaces
                }
            printf("\n");
            }
        }
