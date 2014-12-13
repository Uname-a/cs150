
#include  <stdio.h>
#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int ** makeMatrix(int col, int row);
int main ( int argc, char **argv )
{
  int ** matrix;
  matrix = makeMatrix(4,5);

    return 0;
}				/* ----------  end of function main  ---------- */


 int ** makeMatrix  (int col, int row )
{
  int **Matrix = malloc(sizeof(int * )* col);

  int i;
  for (i = 0; i < row; i++) {
    Matrix[i] = malloc(sizeof(int)* row);
  }
  return Matrix;
}		/* -----  end of function   ----- */


