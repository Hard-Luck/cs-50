#include <stdio.h>
#include <cs50.h>
#include <math.h>

int test = 1;
int length(long card);
int main(void)
{
    long card = get_long("Enter card number: ");
    int x = length(card);
    printf("%d\n",x);
}


int length(long card)
{
    int count = 0;
    while (card != 0)
    {
        card = card/10;
        count++;
    }
    return count;
}