#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 4;
    }
}