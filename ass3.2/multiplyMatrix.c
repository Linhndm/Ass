#include "multiplyMatrix.h"

int isMulMatrix() {
	if(col1 != row2 && col2 != row1)
	{
		/* Cannot multiply */
		printf("\nCannot multiply two matrices. ");
		printf("\nBecause:  \nColumns of first matrix and Rows of second matrix is different. And ");
		printf("\nRows of first matrix and Columns of second matrix is different");
		printf("\n********************\n");
		return FALSE;
	}
 
	return TRUE;
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