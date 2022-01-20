#include <stdio.h>
#include <cs50.h>
#include <math.h>

int test = 1;
int length(long card);
int sumdigit(long card,int len);
int main(void)
{
    long card = get_long("Enter card number: ");
    int x = length(card);
    if (!(x == 13 || x == 15 || x == 16))
    {
        printf("INVALID\n");
        test = 0;
    }
    int checksum = sumdigit(card, x);
    if (!(checksum % 10 == 0))
    {
        printf("INVALID\n");
        test = 0;
    }
    else
    {
        printf("VALID\n");
    }

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

string check_type(long card, int length)
    {
        
    }

int sumdigit(long card,int len)
{
    int sum = 0;
    long card_odd = card;
    long card_ev = card;
    if (len % 2 == 0)

    {
        for (int i = 1; i < len; i += 2)
        {
            sum += (card_odd % 10);
            card_odd /= 100;
        for (int j = 1; j < len; j += 2)
        {
            //printf("%ld",card_ev);
            sum += 2*((card_ev % 100)/10);
            card_ev /= 100;
        }
        }
    }
    return sum;
}