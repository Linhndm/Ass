#include "matrix.h"
#include <windows.h>
int main()
{
    float matrixA[MAX_LENG_ROW][MAX_LENG_COLUMN];
    float matrixB[MAX_LENG_ROW][MAX_LENG_COLUMN];
    float matrixC[MAX_LENG_ROW][MAX_LENG_COLUMN];
    int flag;/*flag Signaling*/
    char choice;/*choice use*/
    int rowA;/*row of matrixA*/
    int columnA;/*column of matrixA*/
    int rowB;/*rowS of matrixB*/
    int columnB;/*column of matrixB*/
    do
    {
        do
        {
            printf("\nEnter rows for matrixA: ");
            scanf("%d",&rowA);
            printf("\nEnter columns for matrixA: ");
            scanf("%d",&columnA);
            flag=testIsMatrix(&rowA,&columnA);
            if(flag==FALSE)
            {
                printf("\nPlease enter rows and columns again!");
                system("pause");
            }/*if flag testIsMatrix false*/
            else
            {
            }/*if not flag testIsMatrix false*/
        }
        while(flag==FALSE);
        do
        {
            printf("\nEnter rows for matrixB: ");
            scanf("%d",&rowB);
            printf("\nEnter columns for matrixB: ");
            scanf("%d",&columnB);
            flag=testIsMatrix(&rowB,&columnB);
            if(flag==FALSE)
            {
                printf("\nPlease enter rows and columns again!");
                system("pause");
            }/*if flag testIsMatrix false*/
            else
            {
            }/*if not flag testIsMatrix false*/
        }
        while(flag==FALSE);
        flag=testMultiplyAndAdd(&rowA, &columnA, &rowB, &columnB);
        if(flag==FALSE)
        {
            printf("\nCan't multiplication");
            printf("\nCan't  add");
        }/*if flag testMultiplyAndAdd false*/
        else
        {
            printf("\nEnter elements of matrix A: ");
            inputMatrix(matrixA,&rowA,&columnA);
            printf("\nEnter elements of matrix B: ");
            inputMatrix(matrixB,&rowB,&columnB);
            switch(flag)
            {
                case ALL:
                    printf("\nOutput Matrix A+B:\n");
                    addMatrix(matrixC,matrixA,&rowA,&columnA,matrixB,&rowB,&columnB);
                    outputMatrix(matrixC,&rowA,&columnB);
                case MULTIPLY_AB_OR_BA:
                    printf("\nOutput Matrix A*B:\n");
                    multiplyMatrix(matrixC,matrixA,&rowA,&columnA,matrixB,&rowB,&columnB);
                    outputMatrix(matrixC,&rowA,&columnB);
                    printf("\nOutput Matrix B*A:\n");
                    multiplyMatrix(matrixC,matrixB,&rowB,&columnB,matrixA,&rowA,&columnA);
                    outputMatrix(matrixC,&rowB,&columnA);
                    break;
                case MULTIPLY_AB:
                    printf("\nOutput Matrix A*B:\n");
                    multiplyMatrix(matrixC,matrixA,&rowA,&columnA,matrixB,&rowB,&columnB);
                    outputMatrix(matrixC,&rowA,&columnB);
                    break;
                case MULTIPLY_BA:
                    printf("\nOutput Matrix B*A:\n");
                    multiplyMatrix(matrixC,matrixB,&rowB,&columnB,matrixA,&rowA,&columnA);
                    outputMatrix(matrixC,&rowB,&columnA);
                    break;
                case ADD_AB:
                    printf("\nOutput Matrix A+B:\n");
                    addMatrix(matrixC,matrixA,&rowA,&columnA,matrixB,&rowB,&columnB);
                    outputMatrix(matrixC,&rowA,&columnB);
                    break;
                default:
                    break;
            }/*swicth flag*/
        }/*if not testMultiplyAndAdd false*/
        fflush(stdin);
        printf("\nDo you want to continue with matrix other! Y/N:  ");
        scanf("%c",&choice);
    }
    while(choice=='y'||choice=='Y');
    return 0;
}