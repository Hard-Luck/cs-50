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
        encrypt_string(argv[1]);
    }
    else
    {
        printf("Invalid key\n");
        return 1;
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
        return 1;
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
        return 1;
    }
    else
    {
        return 1;
    }
}

string encrypt_string(string key)
{
    string stri = get_string("plaintext: ");
    for (int i = 0; stri[i]; i++ )
        {
            if (isalpha(stri[i]))
            {
                for (int j = 0; j > 26; j++)
                {
                    if (toupper(stri[i]) == toupper(key[j]))
                    {
                        char diff = stri[i] - key[j];
                        stri[i] = stri[i] + diff;
                    }
                }
            }
            else
            {
                continue;
            }
        }
    printf("ciphertext: %s\n", stri);
}

