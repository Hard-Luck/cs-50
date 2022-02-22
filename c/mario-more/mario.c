#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (!(n <= 8 && n > 0));
    //Variable i controls line by line
    for (int i = 1; i <= n; i++)
    {
        //Prints the leading spaces which decreses by 1 per line
        for (int j = (n - i); j > 0; j--)
        {
            printf(" ");
        }
        //Prints the number of "#" which increases by 1 per line
        for (int k = (n + 1 - i); k <= n ; k++)
        {
            printf("#");
        }
        printf("  ");
        //Prints the number of "#" after the center spacing which increases by 1 per line
        for (int m = (n + 1 - i); m <= n ; m++)
        {
            printf("#");
        }
        printf("\n");
    }
}