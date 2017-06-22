#include <stdio.h>
#include <stdlib.h>


int Check(float a, float b);
float* Multiple(float matrix1[], float matrix2[], int rowa, int cola, int rowb, int colb);
void PrintMatrix(float matrix4[], int row1, int col2);

int main()
{
	/* Input row, col */
	float r1, c1, r2, c2;
	int row1, col1, row2, col2;

	float *matrix1 = NULL;
	float *matrix2 = NULL;
	float *matrix4 = NULL;

	int check_final = 1;


	do 
	{
		do
		{
			printf("\nEnter number of rows for first matrix : ");
			scanf("%f", &r1);
			printf("\nEnter number of columns for first matrix : ");
			scanf("%f", &c1);
		}
		while (Check(r1, c1));

		do
		{
			printf("\nEnter number of rows for second matrix : ");
			scanf("%f", &r2);
			printf("\nEnter number of columns for second matrix : ");
			scanf("%f", &c2);
		}
		while (Check(r2, c2));

		if(c1 != r2 && c2 != r1)
		{
		printf("\nCannot multiply two matrices. ");
		printf("\nColumns of first matrix and Rows of second matrix is different. ");
		printf("\nOr Rows of first matrix and Columns of second matrix is different");
		}
		else 
		{ 
			check_final = 0;
		}
	}
	while(check_final);
	
	row1 = (int)r1;
	col1 = (int)c1;
	row2 = (int)r2;
	col2 = (int)c2;

	/* Input elemens */
	int i, j;

	matrix1 = (float *) malloc(sizeof(float) * row1 * col1);
	matrix2 = (float *) malloc(sizeof(float) * row2 * col2);

	printf("\nEnter elements of first matrix :\n");
	for(i=0; i< row1; i++)
	{
		for(j=0; j< col1; j++)
		{
			printf("\tA[%d][%d] = ",i+1, j+1);
			scanf("%f", &matrix1[i*col1+j]);
		}
	}

	printf("\nEnter elements of second matrix :\n");
	for(i=0; i< row2; i++)
	{
		for(j=0; j< col2; j++)
		{
			printf("\tB[%d][%d] = ",i+1, j+1);
			scanf("%f", &matrix2[i*col2+j]);
		}
	}

	/* Use function */
	if(row2 == col1)
	{	
		matrix4 = Multiple(matrix1, matrix2, row1, col1, row2, col2);
	}

	if(row1 == col2)
	{	
		matrix4 = Multiple(matrix2, matrix1, row2, col2, row1, col1);
	}
	
	PrintMatrix(matrix4, row1, col2);
	
	return 0;

}

int Check(float a, float b)
{
	if(a <= 0 || b <= 0)
	{
		printf("You are wrong, please re-enter");
		return 1;
	}
	if(a-(int)a != 0 || b-(int)b != 0)
	{
		printf("You are wrong, please re-enter");
		return 1;	
	}
	else return 0;
}

float* Multiple(float matrix1[], float matrix2[], int rowa, int cola, int rowb, int colb)
{
	int i, j, k;
	float *matrix3 = NULL;
	matrix3 = (float *) malloc(sizeof(float) * (rowa) * (colb));
	for(i=0; i<(rowa); i++)
	{
		for(j=0; j<(colb); j++)
		{
			for(k=0; k<(cola); k++)
			{
				matrix3[i*(colb)+j] += matrix1[i*(cola)+k] * matrix2[k*(colb)+j];
			}
		}
	}

	return matrix3;
}

void PrintMatrix(float matrix4[], int row1, int col2)
{	
	int i, j;
	printf("\nOutput matrix :");
	for(i=0; i< row1; i++)
	{
		printf("\n\t\t\t");
		for(j=0; j < col2; j++)
			printf("%.2f     ", matrix4[i*col2+j]);
	}

}