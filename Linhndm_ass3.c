#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float g_par, g_dia;

int Input()
{	
	int check = 0;
	do 
	{
		printf("\n Please enter a Parameter of Rectangle: ");
		scanf("%f", &g_par);
	
		printf("\n Please enter a Diagonal line of Rectangle: ");
		scanf("%f", &g_dia);

		if(g_par > 0 && g_dia > 0)
		{
			if( g_dia >= (g_par / sqrt( 8 )) && g_dia < (g_par / 2) )
			{
				check = 1;
			}
			else
			{
				printf("\n Invalid variable.!!!! \n Please Re-Enter your Rectangle \n");
				printf("\n****************************************");
			}
		}
		else
		{
			printf("\n Please enter a Parameter or Diagonal of Rectangle with positive real number");
			printf("\n Please Re-Enter your Rectangle \n ");
			printf("\n****************************************");
		}
	}	
	while(check == 0);

}


float Area (float par, float dia)
{	
	float S;

	S = pow(par, 2) / 8 - pow(dia, 2) / 2;
	
	return S; 
}

int main()
{	
	float area1;
	Input();
	
	area1 = Area(g_par, g_dia);
	
	printf("\n Area of retangle: %.3f ", area1);
	return 0;

}