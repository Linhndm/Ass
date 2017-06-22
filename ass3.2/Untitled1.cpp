#include <stdio.h>
#include <stdlib.h>
 
#define N_MAX 100
#define M_MAX 100
 
float matrix1[N_MAX][M_MAX], matrix2[N_MAX][M_MAX], matrix3[N_MAX][M_MAX], matrix4[N_MAX][M_MAX];
int row1, col1, row2, col2;

int check(float row, float col);
void ReadMatrix();
int isMulMatrix();
void Multiple();
int isAddMatrix(); 
void Add();
void PrintMatrix(float matrix[N_MAX][M_MAX]);

int main()
{   

	float r1, c1, r2, c2;

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

		check_final = 0;
	}
	while(check_final);
	
	row1 = (int)r1;
	row2 = (int)r2;
	col1 = (int)c1;
	col2 = (int)c2;

	if(isMulMatrix() == 0 && isAddMatrix() == 0)
	{
		return 0;
	}

	ReadMatrix();

	if (isMulMatrix() == 1) {
		Multiple();
		printf("\nProduct of two matrices: ");
		PrintMatrix(matrix3);
		printf("\n********************\n");
	if (isAddMatrix() == 1) {
		Add();
		printf("\nSum of two matrices: ");
		PrintMatrix(matrix4);
		printf("\n********************\n");
 
 
	return 0;
}

/*
Function : int check(float row, float columns)
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


void ReadMatrix() {
	int i, j;
 
	for(i=0; i< row1; i++)
	{
		for(j=0; j< col1; j++)
		{
			printf("\tA[%d][%d] = ",i, j);
			scanf("%f", &matrix1[i][j]);
		}
	}
 
	printf("\nEnter elements of second matrix :\n");
	for(i=0; i< row2; i++)
	{
		for(j=0; j< col2; j++)
		{
			printf("\tB[%d][%d] = ",i, j);
			scanf("%f", &matrix2[i][j]);
		}
	}
}
 
int isMulMatrix() {
	if(col1 != row2 && col2 != row1)
	{
		/* Cannot multiply */
		printf("\nCannot multiply two matrices. ");
		printf("\nBecause:  \nColumns of first matrix and Rows of second matrix is different. And ");
		printf("\nRows of first matrix and Columns of second matrix is different");
		printf("\n********************\n");
		return 0;
	}
 
	return 1;
}
 
void Multiple()
{
	int i, j, k;


	/* Multiply with A x B and print to screen*/
	if(row2 == col1)
	{
		for(i=0; i < row1; i++)
		{
			for(j=0; j < col1; j++)
			{
				matrix3[i][j] = 0;
				for(k=0; k<col2; k++)
				matrix3[i][j] = matrix3[i][j] + matrix1[i][k] * matrix2[k][j];
			}
		}
	}

	/* Multiply with B x A and print to screen*/
	else if(row1 == col2)
	{
		for(i=0; i < row2; i++)
		{
			for(j=0; j < col2; j++)
			{
				matrix3[i][j] = 0;
				for(k=0; k<col1; k++)
				matrix3[i][j] = matrix3[i][j] + matrix2[i][k] * matrix1[k][j];
			}
		}
	}
}
 
int isAddMatrix() {
	if(col1 != col2 || row1 != row2)
	{
		printf("\nCannot add two matrices.Because \nTheir size are different");
		printf("\n********************\n");
		return 0;
	}
 
	return 1;
}
 
void Add() {
	int i, j;
	for (i = 0; i < row1; i++)
		for (j = 0; j < col1; j++)
			matrix4[i][j] = matrix1[i][j] + matrix2[i][j];
}
 
void PrintMatrix(float	 matrix[N_MAX][M_MAX]) {
	int i, j;
 
	for(i=0; i< row1; i++)
	{
		printf("\n\t\t\t");
		for(j=0; j < col2; j++)
			printf("%.3f     ", matrix[i][j]);
	}
}
