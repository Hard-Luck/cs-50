#include <stdio.h>

int main(void)
{
    int ranks[5];

    ranks[2] = 3;

    for (int i = 1; i <= 4; i++)
    {
        printf("%d\t", ranks[i]);
        printf("\n");
    }
}