#include <stdio.h>
#include <cs50.h>
#include <string.h>

//including prototypes of functions
int key_check(string s);

//using argc and argv
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

// Check that each letter is mapped only once A-Z occurs once only.
int key_check(string s)
{
    string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int check = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (strchr(s , t[i]))
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