#include <stdio.h>
#include <string.h>

int array[5] = {1,4,6,5,3};

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        if(array[i] < array[i + 1])
        {
            int temp = array[i];
            array[i] = array[i -1];
            array[i - 1] = array[i];
        }
    for (int j = 0; array[j]; i++)
    {
        printf("%i\t", array[i]);
    }
    }
}