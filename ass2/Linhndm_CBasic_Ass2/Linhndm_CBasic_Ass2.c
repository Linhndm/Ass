#include <stdio.h>
#include <stdlib.h>

/***********************************************************************************************************************
 *Prototypes
 **********************************************************************************************************************/
int check(float a, float b);
float* p_Multiply(float matrix1[], float matrix2[], int rowa, int cola, int rowb, int colb);
void printMatrix(float matrix4[], int row1, int col2);

/***********************************************************************************************************************
 *Code
 **********************************************************************************************************************/
int main()
{   

    /*Variable local */
    float r1, c1, r2, c2;
    int row1, col1, row2, col2;

    /* Poiter declaration */
    float *matrix1 = NULL;
    float *matrix2 = NULL;
    float *matrix4 = NULL;

    /* Input row, col */
    int check_final = 1;

    do 
    {
        do
        {
            /* Input rows and columns of first matrix */
            printf("\nEnter number of rows for first matrix : ");
            scanf("%f", &r1);
            printf("\nEnter number of columns for first matrix : ");
            scanf("%f", &c1);
        }
        while (check(r1, c1));

        do
        {
            /* Input rows and columns of second matrix */
            printf("\nEnter number of rows for second matrix : ");
            scanf("%f", &r2);
            printf("\nEnter number of columns for second matrix : ");
            scanf("%f", &c2);
        }
        while (check(r2, c2));

        if(c1 != r2 && c2 != r1)
        {
            /* Cannot multiply */
            printf("\nCannot multiply two matrices. ");
            printf("\nBecause:  \nColumns of first matrix and Rows of second matrix is different. And ");
            printf("\nRows of first matrix and Columns of second matrix is different");
            printf("\n************************************************************************************************");
        }
        else 
        { 
            check_final = 0;
        }
    }
    while(check_final);
    
    /* Casting variable to integer */
    row1 = (int)r1;
    col1 = (int)c1;
    row2 = (int)r2;
    col2 = (int)c2;

    /* Input elemens */
    int i, j;

    /*dynamic memory allocation*/
    matrix1 = (float *) calloc(row1 * col1, sizeof(float));
    matrix2 = (float *) calloc(row2 * col2, sizeof(float));


    /*Input elements of first matrix*/
    printf("\nEnter elements of first matrix :\n");
    for(i=0; i< row1; i++)
    {
        for(j = 0; j< col1; j++)
        {
            printf("\tA[%d][%d] = ",i+1, j+1);
            scanf("%f", &matrix1[ i * (col1) + j ]);
        }
    }

    /*Input elements of second matrix*/
    printf("\nEnter elements of second matrix :\n");
    for(i = 0; i< row2; i++)
    {
        for(j=0; j< col2; j++)
        {
            printf("\tB[%d][%d] = ",i+1, j+1);
            scanf("%f", &matrix2[ i * (col2) + j ]);
        }
    }

    if(row2 == col1)
    {
        /* Multiply with A x B and print to screen*/
        printf("\nThe result of multiplying first matrix with second matrix");
        matrix4 = p_Multiply(matrix1, matrix2, row1, col1, row2, col2);
        printMatrix(matrix4, row1, col2);
    }

    else if(row1 == col2)
    {
        /* Multiply with B x A and print to screen*/
        printf("\nThe result of multiplying second matrix with first matrix");  
        matrix4 = p_Multiply(matrix2, matrix1, row2, col2, row1, col1);
        printMatrix(matrix4, row2, col1);
    }
    
    free(matrix1);
    free(matrix2);
    free(matrix4);
    return 0;

}

/*
Function : int Check(float row, float columns)
    @brief: Check matrix with rows and colomns. If rows or columns is a Positive or Integer Fun will return 0;
                + row: rows of matrix
                + col: columns of matrix
    @return: 
                + True or False
*/
int check(float row, float col)
{
    /* Check Negative */
    if(row <= 0 || col <= 0)
    {
        printf("\nRows or Columns is a Negative. Please re-enter");
        printf("\n");
        return 1;
    }
    /* Check Integer */
    if(row-(int)row != 0 || col-(int)col != 0)
    {
        printf("\nRow or Columns is not a Integer, please re-enter");
        return 1;   
    }
    else return 0;
}


/*
Function : float* Multiple(float matrix1[], float matrix2[], int rowa, int cola, int rowb, int colb)
    @brief: Multiple two matrices
    @param:     
                + matrix1[]
                + matrix2[]
                + rowa: rows of matrix a
                + cola: columns of matrix a
                + rowb: rows of matrix b
                + colb: columns of matrix b
                + i, j, k: count variables
    @return:
                + Poiter matrix3
*/
float* p_Multiply(float matrix1[], float matrix2[], int rowa, int cola, int rowb, int colb)
{
    int i, j, k;
    float *matrix3 = NULL;
    matrix3 = (float *) calloc((rowa) * (colb), sizeof(float));
    for(i=0; i<(rowa); i++)
    {
        for(j=0; j<(colb); j++)
        {
            matrix3[ i * (colb) + j] = 0;
            for(k=0; k<(cola); k++)
            {
                matrix3[ i * (colb) + j ] += matrix1[ i * (cola) + k ] * matrix2[ k * (colb) + j];
            }
        }
    }

    return matrix3;
}

/*
Function : void PrintMatrix(float matrix4[], int row, int col)
    @brief: Print matrix
    @param:
                + row: rows of matrix
                + col: columns of matrix
                + i,j: count variables
    
*/
void printMatrix(float matrix4[], int row, int col)
{   
    int i, j;
    printf("\nOutput matrix :");
    for(i = 0; i< row; i++)
    {
        printf("\n\t\t\t");
        for(j = 0; j < col; j++)
        {
            printf("%.2f     ", matrix4[ i * (col) + j ]);
        }
    }
}
