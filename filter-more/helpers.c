#include "helpers.h"

void neighbour_check(i,j);

bool neighbours[3][3];

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
    RGBTRIPLE blur_image[height][width];
    for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                neighbours[i][j] = false;
            }
        }

    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            neighbour_check(image[a][b]);
            
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void neighbour_check(RGBTRIPLE image[i][j])
{

    for (int k = -1; k < 2; k++)
    {
        for (int l = -1; l < 2; l++)
        {
            if (image[i + k][j + l])
            {
                neighbours[k][l] = true;
            }
        }
    }
}