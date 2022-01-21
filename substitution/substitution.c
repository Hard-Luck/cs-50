#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    //if (!argv[2]) --- Need to figure this out 
    {
        printf("Must enter a key");
        printf("\n");
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key entered must be exactly 26 characters");
        printf("\n");
        return 2;
    }
}