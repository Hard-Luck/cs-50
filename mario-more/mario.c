#include <stdio.h>
#include <cs50.h>

int main(void)
{
    do
    {
    int n = get_int("Height: ");
    }
    while(n < 8 && n >= 0);

    for(int i=1; i <= n; i++)
    {
        for(int j=(n-i); j > 0; j--)
        {
            printf(" ");
        }
        for(int k=(n+1-i); k <= n ; k++)
        {
            printf("#");
        }
            printf("  ");
        for(int m=(n+1-i); m <= n ; m++)
        {
            printf("#");
            }
        printf(" \n");
        }
}