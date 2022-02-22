#include <stdio.h>
#include <string.h>

int array[5] = {1,4,6,5,3};

int main(void)
{
    for (int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k<5; k++)
    {
        printf("%d\t", array[k]);
    }
     printf("\n");
}
