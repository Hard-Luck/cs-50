#include <stdio.h>

int main(void)
{
    char x =  97;
    char y = 99;
    char z = 100 + y-x;
    printf("%c,%c,%c,\n",x,y,z);
}



void encrypt_string(string stri, string key)
{
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
    return 0;
}

