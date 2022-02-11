#include "helpers.h"
#include <math.h>

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
            float average = (blue + green + red)/3.0;
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtRed = round(average);
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
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
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
            float blue = 0;
            float red = 0;
            float green = 0;

            for (int a = - 1; a < 2; a++)
            {
                for (int b = - 1; b < 2; b++)
                {
                    if ((i + a >= 0) && (i + a < height) && (j + b >= 0) && (j + b < width))
                    {
                        blue += image[i + a][j + b].rgbtBlue;
                        green += image[i + a][j + b].rgbtGreen;
                        red += image[i + a][j + b].rgbtRed;
                        count++;
                    }
                }
            }

            blur_img[i][j].rgbtBlue = round(blue / count);
            blur_img[i][j].rgbtGreen = round(green / count);
            blur_img[i][j].rgbtRed = round(red / count);

        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = blur_img[x][y];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE edges[height][width];
    int gx_matrix[3][3] = {{1-, 0, 1}, {-2, 0, 2}, {-1, 0, 2}};
    int gy_matrix[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //keeping sum of the Gx values
            float gxblue = 0;
            float gyblue = 0;

            float gxred = 0;
            float gyred = 0;

            float gxgreen = 0;
            float gygreen = 0;

            for (int a = - 1; a < 2; a++)
            {
                for (int b = - 1; b < 2; b++)
                {
                    //checking pixel neighbours are in the image
                    if ((i + a >= 0) && (i + a < height) && (j + b >= 0) && (j + b < width))
                    {
                        //multipling the pixel RGB values by the Gx/y scalars
                        gxblue += image[i + a][j + b].rgbtBlue * gx_matrix[a][b];
                        gyblue += image[i + a][j + b].rgbtBlue * gx_matrix[a][b];
                        gxgreen += image[i + a][j + b].rgbtGreen * gx_matrix[a][b];
                        gygreen += image[i + a][j + b].rgbtGreen * gx_matrix[a][b];
                        gxred += image[i + a][j + b].rgbtRed * gx_matrix[a][b];
                        gyred += image[i + a][j + b].rgbtRed * gx_matrix[a][b];
                    }
                }
            }
            //variables for RGB calculations
            int blue = pow((pow(gxblue, 2) + pow(gyblue, 2)), 0.5);
            int green = pow((pow(gxgreen, 2) + pow(gygreen, 2)), 0.5);
            int red = pow((pow(gxred, 2) + pow(gyred, 2)), 0.5);
            
            blur_img[i][j].rgbtBlue = round(blue / count);
            blur_img[i][j].rgbtGreen = round(green / count);
            blur_img[i][j].rgbtRed = round(red / count);

        }
    }
    for (int x = 0; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            image[x][y] = blur_img[x][y];
        }
    }

    return;
}
    return;
}

