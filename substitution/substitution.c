#include <stdio.h>
#include <cs50.h>
#include <string.h>

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
    return 0;
}
