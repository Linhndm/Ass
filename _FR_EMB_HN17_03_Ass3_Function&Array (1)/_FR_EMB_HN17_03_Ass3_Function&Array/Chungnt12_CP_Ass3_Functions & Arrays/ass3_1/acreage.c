#include "acreage.h"
 /*code*/
float acreage (float perimeter, float diagonals)
{
    return ((perimeter*perimeter)/4 - diagonals*diagonals)/2;
}

int testInput (float perimeter, float diagonals)
{
    if (0 >= perimeter || 0 >= diagonals)
    {
        return ERR;
    }
    else if ((perimeter/2 < diagonals) || (perimeter/sqrt(8)) > diagonals)
    {
        return ERR;
    }
    else
    {
        return RECTANGLE;
    }
}