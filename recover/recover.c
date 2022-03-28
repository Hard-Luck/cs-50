#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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
    char *f = argv[1];

        // Open input file
    FILE *f = fopen(rawfile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", f);
        return 1;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *img_ptr = NULL;
    char filename[8];

    while (fread(buffer, 512, 1, f) == 1)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8  &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if count != 0:
            {
                fclose(img_ptr)
            }
            sprintf(filename, "%03i.jpg", count);
            img_pointer = fopen(filename, "w");
            count++;
        }
        
    }
}