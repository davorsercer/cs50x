#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            float average =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int average_to_int = (int) round(average);
            // printf("%.1f\n", average);

            // Update pixel values
            image[i][j].rgbtRed = average_to_int;
            image[i][j].rgbtGreen = average_to_int;
            image[i][j].rgbtBlue = average_to_int;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            // Swap pixels
            int tmp_red = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = tmp_red;

            int tmp_green = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = tmp_green;

            int tmp_blue = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = tmp_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Initializing variables for blurring before loops
    int blur_red_sum;
    int blur_green_sum;
    int blur_blue_sum;
    int average_divisor;

    // Iterating over every pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Resetting variables to zero
            blur_red_sum = 0;
            blur_green_sum = 0;
            blur_blue_sum = 0;
            average_divisor = 0;

            // Iterating over i,j pixel and neighboring pixels 3x3
            // Box 3x3 values: rb = row_box (-1, 0, 1), cb = column_box (-1 0 1)
            for (int rb = -1; rb < 2; rb++)
            {
                for (int cb = -1; cb < 2; cb++)
                {
                    if (i + rb < 0 || j + cb < 0 || i + rb > height - 1 || j + cb > width - 1)
                        continue;

                    blur_red_sum += copy[i + rb][j + cb].rgbtRed;
                    blur_green_sum += copy[i + rb][j + cb].rgbtGreen;
                    blur_blue_sum += copy[i + rb][j + cb].rgbtBlue;
                    average_divisor++;
                }
            }
            // Assigning blurred color to every pixel
            image[i][j].rgbtRed = (int) round((float) blur_red_sum / (float) average_divisor);
            image[i][j].rgbtGreen = (int) round((float) blur_green_sum / (float) average_divisor);
            image[i][j].rgbtBlue = (int) round((float) blur_blue_sum / (float) average_divisor);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
