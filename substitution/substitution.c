#include <stdio.h>
#include <cs50.h>
#include <string.h>

int key_check(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Must enter a key\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key entered must be exactly 26 characters");
        printf("\n");
        return 2;
    }
    if (key_check(argv[1]) != 1)
    {
        printf("Key is good\n");
    }
    else
    {
        printf("Invalid key\n");
    }
    return 0;
}


int key_check(string s)
{
    string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int check = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (strchr(t , s[i]))
        {
            check++;
        }
    }
    if (check == 26)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}