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
                    stri[i] = key[j];
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

void replacechar(char *s,char c1,char c2)
{
    int i=0;
    for(i=0;s[i];i++)
    {
        if(s[i]==c1)
        {
        s[i]=c2;
        }
    }
}

{
    // loop through the string
    for (int i = 0, n = strlen(stri); i < n; i++ )
    {
        for (int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                if (isalpha(stri[i]))
                {
                    if ((stri[i]) == 65 + k)
                    {
                        stri[i] = key[j];
                    }
                    else if ((stri[i]) == 97 + k)
                    {
                        stri[i] = tolower(key[j]);
                    }
                }
            }
        }
    }
    printf("ciphertext: %s\n", stri);
    return 0;
}