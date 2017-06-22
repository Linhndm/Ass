#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/***********************************************************************************************************************
 *Prototype
 **********************************************************************************************************************/
int checkPositive(float per,float dia)
int checkCondition(float per, float dia)
float Area (float per, float dia)

/***********************************************************************************************************************
 *Code
 **********************************************************************************************************************/
int main()
{
    /*Local variables*/
    float area1;
    int check1 = 0;
    float per, dia;

    /*Enter value of Perimeter and Diagonal of Rectangle*/
    do
    {
        printf("\n Please enter a Perimeter of Rectangle: ");
        scanf("%f", &per);
    
        printf("\n Please enter a Diagonal line of Rectangle: ");
        scanf("%f", &dia);

        /*Check Rectangle*/
        if(checkPositive(per, dia))
        {
            if(checkCondition(per, dia))
            {
                check1 = 1;
            }
        }

    }
    while(!check1);

    /*Use function for caculator are of Rectangle*/
    area1 = Area(per, dia);

    printf("\n Area of retangle: %.3f ", area1);
    return 0;

}

/*
Function : int checkPositive(float per,float dia)
    @brief: Check if user enter a negative or decimal number
                + float dia- diagonal of the rectangle
                + float per - perimeter of the rectangle
    @return: 
                + 0 - the input valid need further check
                + 1 - the input invalid
*/
int checkPositive(float per,float dia)
{
    int check = 0;

    if(dia < 0 && per < 0)
    {
        printf("\n Your diagonal and perimeter value is negative");
        printf("\n****************************************");
    }

    else if (dia < 0)
    {
        printf("\n Your diagonal value is negative");
        printf("\n****************************************");

    }

    else if (per < 0)
    {
        printf("\n Your perimeter value is negative");
        printf("\n****************************************");

    }
    else
    {
        check = 1;
    }

    return check;
}

/*
Function : int checkCondition(float per, float dia)
    @brief: Check condition of retangle
                + float per - perimeter of the rectangle
                + float dia- diagonal of the rectangle
                
    @return: 
                + 0 - the input valid with check
                + 0 - the input invalid
*/
int checkCondition(float per, float dia)
{

    /*Check condition of diagonal*/
    if( dia >= (per / sqrt( 8 )) && dia < (per / 2) )
        {
            return 1;
        }
    else
    {
        printf("\n Invalid variable.!!!! \n Please Re-Enter your Rectangle \n");
        printf("\n****************************************");
        return 0;
    }
}

/*
Function : float Area (float per, float dia)
    @brief: Caculator Area of Rectangle
                + float dia- diagonal of the rectangle
                + float per - perimeter of the rectangle
                + S: Area of Rectangle
    @return: 
                S: Area of Rectangle
*/
float Area (float per, float dia)
{
    float S;

    S = pow(per, 2) / 8 - pow(dia, 2) / 2;

    return S; 
}
