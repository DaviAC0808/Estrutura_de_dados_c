#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    for (int i = 0; i <= 10; i++)
    {
        printf("%d ", i);
        if (i == 5)
        {
            break;
        }
    }
}