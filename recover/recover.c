#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // Ensure arv length is 2
    if (len(argv) != 2)
    {
        printf("Error, too many arguments")
        return 1
    }
        // Remember filenames
    char *infile = argv[1];

        // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }
    
}