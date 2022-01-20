#include <stdio.h>
#include <cs50.h>
#include <math.h>

int test = 1;

int main(void)
{
    long card = get_long("Enter card number: ");
    int count = 0;
    while (card != 0)
    {
        card = card/10;
        count++;
    }
    printf("%d",count);
}