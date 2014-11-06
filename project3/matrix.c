#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int **
newMatrix(int rows,int cols)
    {
    int r;
    int **m = allocate(sizeof(int *) * rows);   //allocate the backbone
    for (r = 0; r < rows; ++r)
        {
        m[r] = allocate(sizeof(int) * cols);    //allocate a row
        }
    return m;
    }

int **
newRandomMatrix(int rows,int cols,int max)
    {
    int r,c;
    int **m = allocate(sizeof(int *) * rows);   //allocate the backbone
    for (r = 0; r < rows; ++r)
        {
        m[r] = allocate(sizeof(int) * cols);    //allocate a row
        for (c = 0; c < cols; ++c)              //fill the row
            m[r][c] = random() % max;
        }
    return m;
    }

void
displayMatrix(int **m,int rows,int cols)
    {
    int r,c;
    for (r = 0; r < rows; ++r)
        {
        for (c = 0; c < cols; ++c)
            {
            printf("%3d ",m[r][c]);
            }
        printf("\n");
        }
    }

void
readMatrix(char *fileName,int **m,int rows,int cols)
    {
    int r,c;
    FILE *fp = fopen(fileName,"r"); //fopen failure check omitted

    for (r = 0; r < rows; ++r)
        for (c = 0; c < cols; ++c)
            m[r][c] = readInt(fp);

    fclose(fp);
    }

int
countArrayEvens(int *items,int size)
    {
    int i;
    int count = 0;
    for (i = 0; i < size; ++i)
        {
        if (isEven(items[i]))
            ++count;
        }
    return count;
    }

int
countMatrixEvens(int **items,int rows,int cols)
    {
    int r,c;
    int count = 0;
    for (r = 0; r < rows; ++r)
        for (c = 0; c < cols; ++c)
            {
            if (isEven(items[r][c]))
                ++count;
            }
    return count;
    }

int
matrixMin(int **m,int rows,int cols)
    {
    int r,c,min;
    min = m[0][0];
    for (r = 0; r < rows; ++r)
        for (c = 0; c < cols; ++c)
            {
            if (m[r][c] < min)
                min = m[r][c];
            }
    return min;
    }

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

int
largestRow(int **m,int rows,int cols)
    {
    int r,index,largestSum;
    index = 0;
    largestSum = sum(m[0],cols);        //sum the 1st row with a helper
    for (r = 1; r < rows; ++r)          //skip first row
        {
        int s = sum(m[r],cols);          //sum this row and see if larger
        if (s > largestSum)
            {
            index = r;
            largestSum = s;
            }
        }
    return index;
    }

int
sum(int *items,int size)
    {
    int i,total;
    total = 0;
    for (i = 0; i < size; ++i)
        {
        total += items[i];
        }
    return total;
    }

int
findMatrix(int target,int **m,int rows,int cols)
    {
    int r,c;
    for (r = 0; r < rows; ++r)
        {
        for (c = 0; c < cols; ++c)
            {
            if (m[r][c] == target)
                return 1; //true
            }
        }
    return 0; //false
    }

int
simple2DIndex(int r,int c,int cols)
   {
   return r * cols + c;
   }

void
display1DMatrix(int *n,int size,int cols)
    {
    int r,c,rows;
    rows = size / cols;
    for (r = 0; r < rows; ++r)
        {
        for (c = 0; c < cols; ++c)
            printf("%3d ",n[simple2DIndex(r,c,cols)]);
        printf("\n");
        }
    }

int isEven(int x) { return x % 2 == 0; }

/************** scanner ************************/

#include "scanner.c"
