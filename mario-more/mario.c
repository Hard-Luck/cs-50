#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("Height: ");
    for(int i=n; i > 0; i--)
        {
        for(int j=(n-i); j > 0; j--)
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