#include "helpers.h"
#include <stdbool.h>

//neighbour check 0 = false, 1 = true
int neighbours[3][3];

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
    RGBTRIPLE blur_img[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //count for how many neighbours
            int count = 0;
            //keeping sum of the neighbours rgb values
            int blue = 0;
            int red = 0;
            int green = 0;

        for (int k = -1; k < 2; k++)
        {
            for (int l = -1; l < 2; l++)
            {
                if (image[i + k][j + l].rgbtBlue != "\0" || image[i + k][j + l].rgbtBlue != "\0" || image[i + k][j + l].rgbtRed != "\0" )
                {
                    neighbours[k][l] = 1;
                }
                else
                {
                    neighbours[k][l] = 0;
                }
            }
        }
            for (int a = 0; a < 3; a++)
            {
                for (int b = 0; b < 3; b++)
                {
                    if (neighbours[a][b] == true)
                    {
                        count++;
                        blue += image[a - 1][b -1].rgbtBlue;
                        green += image[a - 1][b -1].rgbtGreen;
                        red += image[a - 1][b -1].rgbtRed;
                    }

                }
            }
            blur_img[i][j].rgbtBlue = blue / count;
            blur_img[i][j].rgbtGreen = green / count;
            blur_img[i][j].rgbtRed = red / count;

        }
    }
    image = blur_img;

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

