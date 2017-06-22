#include "matrix.h"
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static void initMatrix (float matrix[][MAX_LENG_COLUMN], int* row, int* column);

/*******************************************************************************
 * Code
 ******************************************************************************/
static void initMatrix(float matrix[][MAX_LENG_COLUMN], int* row, int* column)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < *row; ++i)
    {
        for (j = 0; j < *column; ++j)
        {
            matrix[i][j] = 0;
        }/*for (j = 0; j < *column; ++j)*/
    }/*for (i = 0; i < *row; ++i)*/
}
 /*!
 * @brief <Test value rows and column>
 *
 * @param row<the number rows of matrix>
 * @param column<the number column of matrix>
 *
 * @return <return FALSE: can't define matrix
                   TRUE: can define matrix >
 */
int testIsMatrix(int *row, int *column)
{
    /*rows and columns must bigger than zezo*/
    if(MIN_LENG > *row || MIN_LENG > *column)
    {
        return FALSE;
    }
    else if(MAX_LENG_ROW <= *row || MAX_LENG_COLUMN <= *column)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
/*!
 * @brief <Test multiplication matrixA and matrixB>
 *
 * @param rowA<the number rows of matrixA>
 * @param columnA<the number column of matrixA>
 * @param rowB<the number rows of matrixB>
 * @param columnB<the number column of matrixB>
 *
 * @return <return MULTIPLY_AB_OR_BA 
                   MULTIPLY_AB 
                   MULTIPLY_BA 
                   FALSE: can't multiplication>
 */
int testMultiplyAndAdd(int *rowA, int *columnA,int *rowB ,int *columnB)
{
    if(*rowA==*rowB && *columnA==*columnB && *rowA == *columnA)
    {
        return ALL;/*enable mutiply AB or mutiply BA*/
    }
    else if(*rowA==*rowB && *columnA==*columnB)
    {
        return ADD_AB;/*enable mutiply AB or mutiply BA*/
    }
    else if(*columnA==*rowB && *columnB==*rowA)
    {
        return MULTIPLY_AB_OR_BA;/*enable mutiply AB or mutiply BA*/
    }
    else if(*columnA==*rowB)
    {
        return MULTIPLY_AB;/*enable mutiply AB*/
    }
    else if(*columnB==*rowA)
    {
        return MULTIPLY_BA;/*enable mutiply BA*/
    }
    else
    {
        return FALSE;/*A and B is not mutiply matrix */
    }
}
/*!
 * @brief <input matrix with size row*column>
 *
 * @param matrix[][]<transmitted to the address matrix>
 *
 * @return <return matrix[row][column]>
 */
void inputMatrix(float matrix[][MAX_LENG_COLUMN], int* row, int* column)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < *row; ++i)
    {
        for (j = 0; j < *column; ++j)
        {
            printf ("\n[%d][%d] = ",i+1,j+1);
            scanf ("%f",&matrix[i][j]);
        }
    }
}

/*!
 * @brief <output matrix with size row*column on interface>
 *
 * @param matrix[][]<transmitted to the address matrix>
 *
 * @return <matrix value's on interface>
 */
void outputMatrix(float matrix[][MAX_LENG_COLUMN], int* row, int* column)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < *row; ++i)
    {
        for (j = 0; j < *column; ++j)
        {
            /*print matrix element on interface */
            printf ("   %0.2f   ",matrix[i][j]);
        }
        printf("\n");
    }
}
/*!
 * @brief <Perform multiplication matrixA and matrixB>
 *
 * @param matrixResult[][]<save return matrixA*matrixB>
 * @param matrixA<transmitted to the address matrixA>
 * @param rowA<the number rows of matrixA>
 * @param columnA<the number column of matrixA>
 * @param matrixB<transmitted to the address matrixB>
 * @param rowB<the number rows of matrixB>
 * @param columnB<the number column of matrixB>
 *
 * @return < then their matrix product matrixA*matrixB is the rowA-by-columnB matrix>
 */

void multiplyMatrix(float matrixResult[][MAX_LENG_COLUMN], float matrixA[][MAX_LENG_COLUMN],int* rowA,
                    int* columnA, float matrixB[][MAX_LENG_COLUMN], int* rowB, int* columnB)
{
    int i = 0;
    int j = 0;
    int r = 0;
    initMatrix(matrixResult,rowA,columnB);/*initialization matrix*/
    for(i = 0; i < *rowA; ++i)
    {
        for(j = 0; j < *columnB; ++j)
        {
            for(r = 0; r < *columnA; ++r)
            {
                matrixResult[i][j] += matrixA[i][r] * matrixB[r][j];
            }
        }
    }
}
/*!
 * @brief <Perform add matrixA and matrixB>
 *
 * @param matrixResult[][]<save return matrixA+matrixB>
 * @param matrixA[][]<transmitted to the address matrixA>
 * @param rowA<the number rows of matrixA>
 * @param columnA<the number column of matrixA>
 * @param matrixB[][]<transmitted to the address matrixB>
 * @param rowB<the number rows of matrixB>
 * @param columnB<the number column of matrixB>
 *
 * @return < then their matrix product matrixA+matrixB is the rowA-by-columnA matrix>
 */
void addMatrix(float matrixResult[][MAX_LENG_COLUMN], float matrixA[][MAX_LENG_COLUMN],int* rowA,
                int* columnA, float matrixB[][MAX_LENG_COLUMN], int* rowB, int* columnB)
{
    int i = 0;
    int j = 0;
    initMatrix(matrixResult,rowA,columnB);/*initialization matrix*/
    for(i = 0; i < *rowA; ++i)
    {
        for(j = 0; j < *columnA; ++j)
        {
            matrixResult[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}