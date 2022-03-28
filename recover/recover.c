#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Ensure arv length is 2
    if (argc != 2)
    {
        printf("Error, too many arguments");
        return 1;
    }
    // Remember filenames
    char *file_name = argv[1];

    // Open input file
    FILE *f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf("Could not open %s.\n", file_name);
        return 1;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *img_ptr = NULL;
    char filename[8];

    while (fread(buffer, 512, 1, f) == 1)
    {
        //Check the first 4 bytes of the string 
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8  &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose(img_ptr);
            }
            // Generate file name string
            sprintf(filename, "%03i.jpg", count);
            img_ptr = fopen(filename, "w");
            count++;
        }
        // If JPEG has been found, write to file
        if (count != 0)
        {
            fwrite(&buffer, 512, 1, img_ptr);
        }
    }
    fclose(f);
    fclose(img_ptr);
    return 0;

}