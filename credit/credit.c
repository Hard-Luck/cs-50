#include <stdio.h>
#include <cs50.h>
#include <math.h>

int test = 1;
int length(long card);
int sumdigit(long card, int len);
string check_type(long card, int length);
int main(void)
{
    long card = get_long("Enter card number: ");
    int x = length(card);
    if ((x == 13 || x == 15 || x == 16))
    {
        int checksum = sumdigit(card, x);
        if (checksum % 10 == 0)
        {
            printf("%s\n", check_type(card, x));
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}










int length(long card)
{
    int count = 0;
    while (card != 0)
    {
        card = card / 10;
        count++;
    }
    return count;
}

string check_type(long card, int length)
{
    int first_one = card / pow(10, length - 1);
    int first_two = card / pow(10, length - 2);
    if ((length == 13 || length == 16) && first_one == 4)
    {
        return "VISA";
    }
    else if ((length == 15) && ((first_two == 34) || (first_two == 37)))
    {
        return "AMEX";
    }
    else if ((length == 16) && ((first_two > 50) && (first_two <= 55)))
    {
        return "MASTERCARD";
    }
    else
    {
        return "INVALID";
    }
}


int sumdigit(long card, int len)
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
        }
        for (int j = 1; j < len; j += 2)
        {
            int digits = (2 * ((card_ev % 100) / 10));
            if (digits >= 10)
            {
                digits =((digits % 10) + (digits / 10));
            }
            sum += digits;
            card_ev /= 100;
        }
    }
        else
        {
            for (int a = 1; a <= len; a += 2)
            {
                sum += (card_odd % 10);
                card_odd /= 100;
            }
            for (int b = 2; b < len; b += 2)
            {
                int digits = (2 * ((card_ev % 100) / 10));
                if (digits >= 10)
                {
                    digits =((digits % 10) + (digits / 10));
                }
                sum += digits;
                card_ev /= 100;
            }
        }
    return sum;
}