#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //blkwht image array
    int bw[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //assigning average of all colours to blkwht array
            bw[i][j] = (((float)image[i][j].rgbtBlue + (float)image[i][j].rgbtGreen + (float)image[i][j].rgbtRed) / 3) + 0.5;
            //assigning blkwht array value to color values of original image
            image[i][j].rgbtBlue = bw[i][j];
            image[i][j].rgbtGreen = bw[i][j];
            image[i][j].rgbtRed = bw[i][j];
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculating sephia value for each pixel
            int sephiared = (0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue) + 0.5;
            int sephiagreen = (0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue) + 0.5;
            int sephiablue = (0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue) + 0.5;
            //capping values at 255
            if (sephiared > 255)
            {
                sephiared = 255;
            }
            if (sephiagreen > 255)
            {
                sephiagreen = 255;
            }
            if (sephiablue > 255)
            {
                sephiablue = 255;
            }
            // assigning calculated values to orginal image
            image[i][j].rgbtRed = sephiared;
            image[i][j].rgbtGreen = sephiagreen;
            image[i][j].rgbtBlue = sephiablue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //take rgb of each pixel and get average and make it bw
    int tmp;
    int tmp1;
    int tmp2;
    int a = 0;
    //swapping left half of pixels with right half of pixels
    for (int i = 0; i < width / 2; i++)
    {
        for (int j = 0; j < height; j++)
        {
            //swap red of each pixel
            tmp = image[j][i].rgbtRed;
            image[j][i].rgbtRed = image[j][width - (i + 1)].rgbtRed;
            image[j][width - (i + 1)].rgbtRed = tmp;
            //swap blue of each pixel
            tmp1 = image[j][i].rgbtBlue;
            image[j][i].rgbtBlue = image[j][width - (i + 1)].rgbtBlue;
            image[j][width - (i + 1)].rgbtBlue = tmp1;
            //swap green of each pixel
            tmp2 = image[j][i].rgbtGreen;
            image[j][i].rgbtGreen = image[j][width - (i + 1)].rgbtGreen;
            image[j][width - (i + 1)].rgbtGreen = tmp2;
            a++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //blurred image array
    int bl[height][width][3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = 0;
            int green = 0;
            int red = 0;
            //for top row
            if (i == 0)
            {
                //for top left corner pixel
                if (j == 0)
                {
                    blue = 0.5 + (((float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue +
                                   (float)image[i + 1][j + 1].rgbtBlue) / 4);
                    green = 0.5 + (((float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen +
                                    (float)image[i + 1][j + 1].rgbtGreen) / 4);
                    red = 0.5 + (((float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j].rgbtRed +
                                  (float)image[i + 1][j + 1].rgbtRed) / 4);
                }
                //for top right corner pixel
                else if (j == width - 1)
                {
                    blue = 0.5 + (((float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i + 1][j - 1].rgbtBlue + 
                                   (float)image[i + 1][j].rgbtBlue) / 4);
                    green = 0.5 + (((float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i + 1][j - 1].rgbtGreen +
                                    (float)image[i + 1][j].rgbtGreen) / 4);
                    red = 0.5 + (((float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i + 1][j - 1].rgbtRed +
                                  (float)image[i + 1][j].rgbtRed) / 4);
                }
                //for top edge pixels
                else
                {
                    blue = 0.5 + (((float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue + 
                                   (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 6);
                    green = 0.5 + (((float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen +
                                    (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 6);
                    red = 0.5 + (((float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed +
                                  (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 6);
                }
            }
            //for bottom row
            else if (i == height - 1)
            {
                //for bottom left pixel
                if (j == 0)
                {
                    blue = 0.5 + (((float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j].rgbtBlue + 
                                   (float)image[i][j + 1].rgbtBlue) / 4);
                    green = 0.5 + (((float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j].rgbtGreen +
                                    (float)image[i][j + 1].rgbtGreen) / 4);
                    red = 0.5 + (((float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j].rgbtRed +
                                  (float)image[i][j + 1].rgbtRed) / 4);
                }
                //for bottom right pixel
                else if (j == width - 1)
                {
                    blue = 0.5 + (((float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i - 1][j - 1].rgbtBlue +
                                   (float)image[i - 1][j].rgbtBlue) / 4);
                    green = 0.5 + (((float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i - 1][j - 1].rgbtGreen +
                                    (float)image[i - 1][j].rgbtGreen) / 4);
                    red = 0.5 + (((float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i - 1][j - 1].rgbtRed +
                                  (float)image[i - 1][j].rgbtRed) / 4);
                }
                //for bottom edge pixels
                else
                {
                    blue = 0.5 + (((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue +
                                   (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue) / 6);
                    green = 0.5 + (((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen +
                                    (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen) / 6);
                    red = 0.5 + (((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed +
                                  (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed) / 6);
                }
            }
            else
            {
                //for right side edge pixels
                if (j == 0)
                {
                    blue = 0.5 + (((float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue + (float)image[i][j].rgbtBlue +
                                   (float)image[i][j + 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 6);
                    green = 0.5 + (((float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen + (float)image[i][j].rgbtGreen +
                                    (float)image[i][j + 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 6);
                    red = 0.5 + (((float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed + (float)image[i][j].rgbtRed +
                                  (float)image[i][j + 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 6);
                }
                //for left side edge pixels
                else if (j == width - 1)
                {
                    blue = 0.5 + (((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i][j - 1].rgbtBlue +
                                   (float)image[i][j].rgbtBlue  + (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue) / 6);
                    green = 0.5 + (((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i][j - 1].rgbtGreen +
                                    (float)image[i][j].rgbtGreen  + (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen) / 6);
                    red = 0.5 + (((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i][j - 1].rgbtRed +
                                  (float)image[i][j].rgbtRed  + (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed) / 6);
                }
                //for middle pixels
                else
                {
                    blue = 0.5 + (((float)image[i - 1][j - 1].rgbtBlue + (float)image[i - 1][j].rgbtBlue + (float)image[i - 1][j + 1].rgbtBlue +
                                   (float)image[i][j - 1].rgbtBlue + (float)image[i][j].rgbtBlue + (float)image[i][j + 1].rgbtBlue +
                                   (float)image[i + 1][j - 1].rgbtBlue + (float)image[i + 1][j].rgbtBlue + (float)image[i + 1][j + 1].rgbtBlue) / 9);
                    green = 0.5 + (((float)image[i - 1][j - 1].rgbtGreen + (float)image[i - 1][j].rgbtGreen + (float)image[i - 1][j + 1].rgbtGreen +
                                    (float)image[i][j - 1].rgbtGreen + (float)image[i][j].rgbtGreen + (float)image[i][j + 1].rgbtGreen +
                                    (float)image[i + 1][j - 1].rgbtGreen + (float)image[i + 1][j].rgbtGreen + (float)image[i + 1][j + 1].rgbtGreen) / 9);
                    red = 0.5 + (((float)image[i - 1][j - 1].rgbtRed + (float)image[i - 1][j].rgbtRed + (float)image[i - 1][j + 1].rgbtRed +
                                  (float)image[i][j - 1].rgbtRed + (float)image[i][j].rgbtRed + (float)image[i][j + 1].rgbtRed +
                                  (float)image[i + 1][j - 1].rgbtRed + (float)image[i + 1][j].rgbtRed + (float)image[i + 1][j + 1].rgbtRed) / 9);
                }
            }
            //assigning average to the blurred image array
            bl[i][j][0] = blue;
            bl[i][j][1] = green;
            bl[i][j][2] = red;
            
        }
    }
    //assigning pixels of blurred image to orgingal image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = bl[i][j][0];
            image[i][j].rgbtGreen = bl[i][j][1];
            image[i][j].rgbtRed = bl[i][j][2];
        }
    }
}
