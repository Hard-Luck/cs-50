#include <stdio.h>
#include <cs50.h>
#include <math.h>
//Included <math> to use pow(d,d)



int length(long card);
int sumdigit(long card, int len);
string check_type(long card, int length);
//introducing the functions

int main(void)
{
    //asking for user input, user enters card number
    long card = get_long("Enter card number: ");
    int x = length(card);
    //check the length of the card is permissable if not return "INVALID"
    if ((x == 13 || x == 15 || x == 16))
    {
        //uses sumdigit function to get a return value
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









//function that outputs an interger representing the length of the input
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

//function to determine which type of card (if any) has been inputted
string check_type(long card, int length)
{
    int first_one = card / pow(10, length - 1);
    int first_two = card / pow(10, length - 2);
    // If length is 13/16 and the first digit of the card or 4 then return VISA
    if ((length == 13 || length == 16) && first_one == 4)
    {
        return "VISA";
    }
    // If length is 15 and the first 2 digits of the card or 34/37 then return AMEX
    else if ((length == 15) && ((first_two == 34) || (first_two == 37)))
    {
        return "AMEX";
    }
    //// If length is 15 and the first 2 digits of the card or between 51 and 55 then return Mastercard
    else if ((length == 16) && ((first_two > 50) && (first_two <= 55)))
    {
        return "MASTERCARD";
    }
    else
    {
        //If all else has not passed then card number is invalidcd
        return "INVALID";
    }
}

//function to check sum the inputted digits by incrementing and "chopping off the end numbers"
int sumdigit(long card, int len)
{
    int sum = 0;
    long card_odd = card;
    long card_ev = card;
    //for card lengths of even length
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
                digits = ((digits % 10) + (digits / 10));
            }
            sum += digits;
            card_ev /= 100;
        }
    }
    // for odd length
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
                digits = ((digits % 10) + (digits / 10));
            }
            sum += digits;
            card_ev /= 100;
        }
    }
    return sum;
}