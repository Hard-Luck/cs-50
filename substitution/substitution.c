#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Including prototypes of functions.
int key_check(string s);

//Encryption using key
string encrypt_string(string key);

//using argc and argv[] for command line argumets.
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Must enter a key\n");
        return 1;
    }
    if (key_check(argv[1]) == 0)
    {
        string new = encrypt_string(argv[1]);
        printf("%s\n", new);
    }
    else
    {
        printf("Invalid key\n");
        return 4;
    }
    return 0;
}

// Check that each letter is mapped only once A-Z occurs once only.
int key_check(string s)
{
    string t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int check = 0;
    if (strlen(s) != 26)
    {
        printf("Key entered must be exactly 26 characters");
        printf("\n");
        return 2;
    }
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //Checking if uppercase or lower case is
        if (strchr(s , toupper(t[i])) || (strchr(s , tolower(t[i]))))
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
        return 3;
    }
}

string encrypt_string(string key)
{
    string str = get_string("Enter string to encode");
    for (int i = 0; i < 26; i++ )
        {
            if (toupper(str[i]) == (i + 65))
            {
                int diff = key[i] - str[i];
                str[i] = str[i] + diff;
            }
        }
    return str;
}