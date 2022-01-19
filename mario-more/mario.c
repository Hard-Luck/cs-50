#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Height: ");
    for(int i=n; i > 0; i--)
        {
        for(int j=(n-1); j > 0; j--)
            {
                printf(" ");
            }
        for(int k=1; k <= n ; k++)
            {
                printf("#");
            }
        printf(" \n");
        }
}