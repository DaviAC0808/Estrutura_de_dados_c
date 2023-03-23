#include <stdio.h>
#include <stdlib.h>

int main()
{
    //matriz
    int mat[3][3]={{0, 0, 0},
                   {0, 0, 0},
                   {0, 0, 0}};
    int i, j;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", mat[i][j]);
        }   
        printf("\n"); 
    }
    
}
