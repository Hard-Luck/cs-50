#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Ensure arv length is 2
    if (len(argv) != 2)
    {
        printf("Error, too many arguments")
        return 1
    }
        // Remember filenames
    char *rawfile = argv[1];

        // Open input file
    FILE *f = fopen(rawfile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", f);
        return 1;
    }
    // Allocate memory for the buffer
    char *buffer = malloc(512 * sizeof(byte))
    while (fread(buffer, 1, sizeof(BYTE), f) == BLOCK_SIZE)
    {


    }
}