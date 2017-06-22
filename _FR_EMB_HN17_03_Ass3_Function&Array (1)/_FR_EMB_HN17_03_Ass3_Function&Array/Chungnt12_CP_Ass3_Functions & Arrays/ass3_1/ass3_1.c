#include <stdio.h>
#include <windows.h>
#include "acreage.h"
/*******************************************************************************
 * Prototypes
 ******************************************************************************/

static float input(const char* str);

/******************************************************************************/
/*code*/
static float input(const char* str)
{
    float temp = 0;
    printf("%s",str);
    scanf("%f",&temp);
    return temp;
}

int main()
{
    /*to take one's choice of used*/
    char opt;
    float perimeter = 0;
    float diagonals = 0;
    float resultAcreage = 0;
    do
    {
        system("cls");
        printf("\nArea of a rectangle");
        printf("\nEnter the two perimeter and diagonals the rest will be calculated");
        perimeter = input("\nEnter perimeter: ");
        diagonals = input("\nEnter diagonals: ");
        if (testInput(perimeter,diagonals)==ERR) 
        {
            printf("\nYour perimeter and diagonals false!");
            printf("\nDo you want enter again? Y/N: ");
        }/*if testInput*/
        else
        {
            resultAcreage = acreage(perimeter, diagonals);
            printf("\nAcreage: %0.3f",resultAcreage);
            printf("\nDo you want continue? Y/N: ");
        }/*if not testInput*/
        fflush(stdin);
        scanf("%c",&opt);
    }
    while(opt == 'y' || opt == 'Y');
    return 0;
}