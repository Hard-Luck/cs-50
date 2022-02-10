// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    //Copy header from input file to output file
    uint8_t *header_arr = malloc(sizeof(uint8_t) * HEADER_SIZE);
    fread(header_arr,sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header_arr,sizeof(uint8_t), HEADER_SIZE, output);
    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer[200];
    size_t num_read = fread(buffer, sizeof(int16_t), 200, input);
    buffer[num_read] = '\0';
    int16_t double_buffer[num_read];
    for (int i = 0; i <= num_read; i++)
    {
        double_buffer[i] = 2 * buffer[i];
    }
    fwrite(double_buffer, sizeof(int16_t), num_read, output);
    // Close files
    fclose(input);
    fclose(output);
    free(header_arr);
}
