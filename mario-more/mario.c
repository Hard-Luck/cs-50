#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Height: ");
    for(int i=0; i < n; i++)
        {
        for(int j=(n-1-i); j > 0; j--)
            {
                printf("!");
            }
        for(int k=(n-i); k >= i ; k--)
            {
                printf("#");
            }
        printf(" \n");
        }
}