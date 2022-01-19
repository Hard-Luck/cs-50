#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Height: ");
    for(int i=1; i <= n; i++)
        {
        for(int j=(n-i); j > 0; j--)
            {
                printf(" ");
            }
        for(int k=i; k <= n ; k++)
            {
                printf("#");
            }
        printf(" \n");
        }
}