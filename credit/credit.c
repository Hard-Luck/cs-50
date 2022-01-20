#include <stdio.h>
#include <cs50.h>
#include <math.h>

int test = 1;
int length(long card);
int main(void)
{
    long card = get_long("Enter card number: ");
    int x = length(card);
    if (!(x == 13 || x == 15 || x == 16))
    {
        printf("INVALID\n");
        test = 0;
    }

}




int sumdigit(long card,int len)
{
    int sum = 0;
    if (len % 2 == 0)
    {
        for (i = 0; i < len; i += 2)
        {
            
        }
    }

    while (card != 0)
    {
        card = card/10;
        count++;
    }
    return count;






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