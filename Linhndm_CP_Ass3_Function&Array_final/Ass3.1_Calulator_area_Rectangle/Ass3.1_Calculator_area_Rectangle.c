#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/***********************************************************************************************************************
 * Variables
 **********************************************************************************************************************/
float g_par, g_dia;

/***********************************************************************************************************************
 *Prototypes
 **********************************************************************************************************************/
void readRec();
float Area (float par, float dia);

/***********************************************************************************************************************
 *Code
 **********************************************************************************************************************/
int main()
{
    float area1;
    readRec();
    
    area1 = Area(g_par, g_dia);
    
    printf("\n Area of retangle: %.3f ", area1);

    return 0;
}

/*
Function : void Input
    @brief: Enter Parameter and Diagonal line of Rectangle from keyboard.
            Check condition of Rectangle
    @param:
                + check : check condition of Parameter and Diagonal line
                + g_par : Parameter of rectangle
                + g_dir : Diagonal line of Rectangle
*/

void readRec()
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

/*
Function : float Area (float par, float dia)
    @brief: Input Parameter and Diagonal line of Rectangle.
    @param:
                + S : Area of Rectangle
                + par : Parameter of rectangle
                + dir : Diagonal line of Rectangle
*/
float Area (float par, float dia)
{
    float S;

    S = pow(par, 2) / 8 - pow(dia, 2) / 2;
    
    return S; 
}