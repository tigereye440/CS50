#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int averageColor = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtRed = averageColor;
            image[i][j].rgbtGreen = averageColor;
            image[i][j].rgbtBlue = averageColor;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp_image[i][j] = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp_image[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j] = image[i][j];
        }
    }

    // Looping through rows
    for (int i = 0; i < height; i++)
    {
        // Looping through columns
        for (int j = 0; j < width; j++)
        {
            // Declare and initialise values of sum of colors
            float sumOfBlue = 0;
            float sumOfGreen = 0;
            float sumOfRed = 0;
            int counter = 0;
            for (int ri = -1; ri < 2; ri++)
            {
                for (int rj = -1; rj < 2; rj++)
                {
                    if (i + ri < 0 || i + ri > height - 1)
                    {
                        continue;
                    }
                    if (j + rj < 0 || j + rj > width - 1)
                    {
                        continue;
                    }
                    sumOfBlue += temp_image[i + ri][j + rj].rgbtBlue;
                    sumOfGreen += temp_image[i + ri][j + rj].rgbtGreen;
                    sumOfRed += temp_image[i + ri][j + rj].rgbtRed;
                    counter++;
                }
            }

            image[i][j].rgbtBlue = round(sumOfBlue / counter);
            image[i][j].rgbtGreen = round(sumOfGreen / counter);
            image[i][j].rgbtRed = round(sumOfRed / counter);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    // Creating temporary array of image pixels
    RGBTRIPLE temp_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_image[i][j] = image[i][j];
        }
    }

    // Create and initialise kernel matrices
    int gx_array[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy_array[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Looping through rows
    for (int i = 0; i < height; i++)
    {
        // Looping through columns
        for (int j = 0; j < width; j++)
        {

            float gxOfBlue;
            float gxOfGreen;
            float gxOfRed;
            float gyOfBlue;
            float gyOfGreen;
            float gyOfRed;

            gxOfBlue = gxOfGreen = gxOfRed = gyOfBlue = gyOfGreen = gyOfRed = 0;

            for (int ri = -1; ri < 2; ri++)
            {
                for (int rj = -1; rj < 2; rj++)
                {
                    if (i + ri < 0 || i + ri >= height)
                    {
                        continue;
                    }
                    if (j + rj < 0 || j + rj >= width)
                    {
                        continue;
                    }

                    gxOfBlue += temp_image[i + ri][j + rj].rgbtBlue * gx_array[ri + 1][rj + 1];
                    gxOfGreen += temp_image[i + ri][j + rj].rgbtGreen * gx_array[ri + 1][rj + 1];
                    gxOfRed += temp_image[i + ri][j + rj].rgbtRed * gx_array[ri + 1][rj + 1];

                    gyOfBlue += temp_image[i + ri][j + rj].rgbtBlue * gy_array[ri + 1][rj + 1];
                    gyOfGreen += temp_image[i + ri][j + rj].rgbtGreen * gy_array[ri + 1][rj + 1];
                    gyOfRed += temp_image[i + ri][j + rj].rgbtRed * gy_array[ri + 1][rj + 1];
                }
            }

            // Calculating values of sobel operation
            int blue = round(sqrt(gxOfBlue * gxOfBlue + gyOfBlue * gyOfBlue));
            int green = round(sqrt(gxOfGreen * gxOfGreen + gyOfGreen * gyOfGreen));
            int red = round(sqrt(gxOfRed * gxOfRed + gyOfRed * gyOfRed));

            // Caping at 255
            if (blue > 255)
            {
                blue = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (red > 255)
            {
                red = 255;
            }

            // Assigning new values
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }
    }
    return;
}
