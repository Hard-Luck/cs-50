#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;
            int average = (blue + green + red)/3;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred[height][width];
    //Changing the corners blue values, I have to assume theres a better way than this
    blurred[0][0].rgbtBlue = (blurred[0][0] + blurred[0][1] + blurred[1][0] + blurred[1][0]) / 4;
    blurred[width - 1][0].rgbtBlue = (
                                         (blurred[width - 1][0] + blurred[width - 1][1]
                                          + blurred[width - 2][0] + blurred[width - 2][1]) / 4
                                     );
    blurred[0][height - 1].rgbtBlue = (
                                         (blurred[0][height - 1] + blurred[0][height - 2]
                                          + blurred[1][height - 1] + blurred[1][height - 2]) / 4
                                     );
    blurred[width - 1][height - 1].rgbtBlue = (blurred[width - 1][height - 1] + blurred[width - 1][height - 2]
                                                 + blurred[width - 2][height - 1] + blurred[width - 2][height - 2]) / 4
                                              );
    //Changing the corners Green values
    blurred[0][0].rgbtGreen = (blurred[0][0] + blurred[0][1] + blurred[1][0] + blurred[1][0]) / 4;
    blurred[width - 1][0].rgbtGreen = (
                                         (blurred[width - 1][0] + blurred[width - 1][1]
                                          + blurred[width - 2][0] + blurred[width - 2][1]) / 4
                                     );
    blurred[0][height - 1].rgbtGreen = (
                                         (blurred[0][height - 1] + blurred[0][height - 2]
                                          + blurred[1][height - 1] + blurred[1][height - 2]) / 4
                                     );
    blurred[width - 1][height - 1].rgbtGreen = (blurred[width - 1][height - 1] + blurred[width - 1][height - 2]
                                                 + blurred[width - 2][height - 1] + blurred[width - 2][height - 2]) / 4
                                              );

    //Changing the corners Red values
    blurred[0][0].rgbtGreen = (blurred[0][0] + blurred[0][1] + blurred[1][0] + blurred[1][0]) / 4;
    blurred[width - 1][0].rgbtRed = (
                                         (blurred[width - 1][0] + blurred[width - 1][1]
                                          + blurred[width - 2][0] + blurred[width - 2][1]) / 4
                                     );
    blurred[0][height - 1].rgbtRed = (
                                         (blurred[0][height - 1] + blurred[0][height - 2]
                                          + blurred[1][height - 1] + blurred[1][height - 2]) / 4
                                     );
    blurred[width - 1][height - 1].rgbtRed = (blurred[width - 1][height - 1] + blurred[width - 1][height - 2]
                                                 + blurred[width - 2][height - 1] + blurred[width - 2][height - 2]) / 4
                                              );

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
