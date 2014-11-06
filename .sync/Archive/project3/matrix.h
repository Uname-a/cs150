#include "scanner.h"

int **newMatrix(int rows,int cols);
int **newRandomMatrix(int rows,int cols,int max);
void displayMatrix(int **m,int rows,int cols);
void readMatrix(char *fileName,int **m,int rows,int cols);
int countArrayEvens(int *items,int size);
int countMatrixEvens(int **items,int rows,int cols);
int matrixMin(int **m,int rows,int cols);
void matrixMinIndex(int **m,int rows,int cols,int *minr,int *minc);
int largestRow(int **m,int row,int col);
int sum(int *items,int size);
int findMatrix(int target,int **m,int rows,int cols);
int simple2DIndex(int r,int c,int cols);
void display1DMatrix(int *n,int size,int cols);
int isEven(int x);
