#ifndef __MATRIX_H_
#define __MATRIX_H_

#include <stdio.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define FALSE 0 
#define TRUE 1
#define MULTIPLY_AB_OR_BA 1
#define MULTIPLY_AB 2
#define MULTIPLY_BA 3
#define ADD_AB 4
#define ALL 5
#define MAX_LENG_ROW 20
#define MAX_LENG_COLUMN 20
#define MIN_LENG 1
/*******************************************************************************
 * API
 ******************************************************************************/
/*!
 * @brief <Test value rows and column>
 *
 * @param row<the number rows of matrix>
 * @param column<the number column of matrix>
 *
 * @return <return FALSE: can't define matrix
                   TRUE: can define matrix >
 */
int testIsMatrix(int *row, int *column);
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
int testMultiply(int *rowA, int *columnA,int *rowB ,int *columnB);
/*!
 * @brief <input matrix with size row*column>
 *
 * @param row<the number rows of matrix>
 * @param column<the number column of matrix>
 *
 * @return <return matrix[row][column]>
 */
void inputMatrix(float matrix[][MAX_LENG_COLUMN], int* row, int* column);
/*!
 * @brief <output matrix with size row*column on interface>
 *
 * @param matrix[][]<transmitted to the address matrix>
 * @param row<the number rows of matrix>
 * @param column<the number column of matrix>
 *
 * @return <matrix value's on interface>
 */
void outputMatrix(float matrix[][MAX_LENG_COLUMN], int* row, int* column);
/*!
 * @brief <Perform multiplication matrixA and matrixB>
 *
 * @param matrixA[][]<transmitted to the address matrixA>
 * @param rowA<the number rows of matrixA>
 * @param columnA<the number column of matrixA>
 * @param matrixB[][]<transmitted to the address matrixB>
 * @param rowB<the number rows of matrixB>
 * @param columnB<the number column of matrixB>
 *
 * @return < then their matrix product matrixA*matrixB is the rowA-by-columnB matrix>
 */
void multiplyMatrix(float matrixResult[][MAX_LENG_COLUMN], float matrixA[][MAX_LENG_COLUMN],int* rowA,
                    int* columnA, float matrixB[][MAX_LENG_COLUMN], int* rowB, int* columnB);
/*!
 * @brief <Perform add matrixA and matrixB>
 *
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
                int* columnA, float matrixB[][MAX_LENG_COLUMN], int* rowB, int* columnB);
#endif /*__MATRIX_H_*/