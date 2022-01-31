#include <stdio.h>

int main(void)
{
    int ranks[5];

    ranks[2] = 3;

    for (int i = 0; i < 5; i++)
    {
        printf("%i\t", ranks[i]);
        printf("\n");
    }
}