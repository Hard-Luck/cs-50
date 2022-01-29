#include <stdio.h>
#include <string.h>

int array[] = {1,4,6,5,3};

int main(void)
{
    for (int i = 0, n = ; i < n - 1; i++)
    {
        if(array[i] < array[i + 1])
        {
            temp = array[i];
            array[i] = array[i -1];
            array[i - 1] = array[i];
        }
    for (int i = 0; array[i]; i++)
    {
        printf("%i\t", array[i]);
    }
    }
}