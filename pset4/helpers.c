#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float blue, green, red;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = image[i][j].rgbtBlue;
            green = image[i][j].rgbtGreen;
            red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = round((blue + green + red) / 3);
            image[i][j].rgbtGreen = round((blue + green + red) / 3);
            image[i][j].rgbtRed = round((blue + green + red) / 3);

        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int blue, green, red;
    int mid = width / 2;
    int i = 0;
    int j = 0;
    int k = width - 1;

    while (i < height)
    {
        if (j > mid - 1)
        {
            j = 0;
            k = width - 1;
            i++;
        }

        blue = image[i][j].rgbtBlue;
        image[i][j].rgbtBlue = image[i][k].rgbtBlue;
        image[i][k].rgbtBlue =    blue;

        green = image[i][j].rgbtGreen;
        image[i][j].rgbtGreen = image[i][k].rgbtGreen;
        image[i][k].rgbtGreen = green;

        red = image[i][j].rgbtRed;
        image[i][j].rgbtRed = image[i][k].rgbtRed;
        image[i][k].rgbtRed = red;

        k--;
        j++;
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float blue, green, red;
    int count, greenAvg, blueAvg, redAvg;
    RGBTRIPLE tempImage[height][width];

    // populate the temporary image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j].rgbtBlue = image[i][j].rgbtBlue;
            tempImage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tempImage[i][j].rgbtRed = image[i][j].rgbtRed;
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            blue = 0;
            green = 0;
            red = 0;
            count = 1;
            greenAvg = 0;
            blueAvg = 0;
            redAvg = 0;
            // test left
            if (j - 1 >= 0)
            {
                blue += tempImage[i][j - 1].rgbtBlue;
                green += tempImage[i][j - 1].rgbtGreen;
                red += tempImage[i][j - 1].rgbtRed;
                count++;
            }
            // test right
            if (j + 1 < width)
            {
                blue += tempImage[i][j + 1].rgbtBlue;
                green += tempImage[i][j + 1].rgbtGreen;
                red += tempImage[i][j + 1].rgbtRed;
                count++;
            }
            // test up
            if (i - 1 >= 0)
            {
                blue += tempImage[i - 1][j].rgbtBlue;
                green += tempImage[i - 1][j].rgbtGreen;
                red += tempImage[i - 1][j].rgbtRed;
                count++;
            }
            // test down
            if (i + 1 < height)
            {
                blue += tempImage[i + 1][j].rgbtBlue;
                green += tempImage[i + 1][j].rgbtGreen;
                red += tempImage[i + 1][j].rgbtRed;
                count++;
            }
            // test up left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                blue += tempImage[i - 1][j - 1].rgbtBlue;
                green += tempImage[i - 1][j - 1].rgbtGreen;
                red += tempImage[i - 1][j - 1].rgbtRed;
                count++;
            }
            // test up right
            if (i - 1 >= 0 && j + 1 < width)
            {
                blue += tempImage[i - 1][j + 1].rgbtBlue;
                green += tempImage[i - 1][j + 1].rgbtGreen;
                red += tempImage[i - 1][j + 1].rgbtRed;
                count++;
            }
            // test bottom left
            if (i + 1 < height && j - 1 >= 0)
            {
                blue += tempImage[i + 1][j - 1].rgbtBlue;
                green += tempImage[i + 1][j - 1].rgbtGreen;
                red += tempImage[i + 1][j - 1].rgbtRed;
                count++;
            }
            // test bottom right
            if (i + 1 < height && j + 1 < width)
            {
                blue += tempImage[i + 1][j + 1].rgbtBlue;
                green += tempImage[i + 1][j + 1].rgbtGreen;
                red += tempImage[i + 1][j + 1].rgbtRed;
                count++;
            }

            blueAvg = round((blue + tempImage[i][j].rgbtBlue) / count);
            greenAvg = round((green + tempImage[i][j].rgbtGreen) / count);
            redAvg = round((red + tempImage[i][j].rgbtRed) / count);

            image[i][j].rgbtBlue = blueAvg;
            image[i][j].rgbtGreen = greenAvg;
            image[i][j].rgbtRed = redAvg;
        }

    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    double newBluex, newGreenx, newRedx, newBluey, newGreeny, newRedy;
    double actualBluex, actualGreenx, actualRedx, actualBluey, actualGreeny, actualRedy;
    double leftBluex, leftGreenx, leftRedx, leftBluey, leftGreeny, leftRedy;
    double rightBluex, rightGreenx, rightRedx, rightBluey, rightGreeny, rightRedy;
    double upBluex, upGreenx, upRedx, upBluey, upGreeny, upRedy;
    double downBluex, downGreenx, downRedx, downBluey, downGreeny, downRedy;
    double uplBluex, uplGreenx, uplRedx, uplBluey, uplGreeny, uplRedy;
    double uprBluex, uprGreenx, uprRedx, uprBluey, uprGreeny, uprRedy;
    double downlBluex, downlGreenx, downlRedx, downlBluey, downlGreeny, downlRedy;
    double downrBluex, downrGreenx, downrRedx, downrBluey, downrGreeny, downrRedy;
    double red, blue, green;

    RGBTRIPLE tempImage[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // populate the temporary image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j].rgbtBlue = image[i][j].rgbtBlue;
            tempImage[i][j].rgbtGreen = image[i][j].rgbtGreen;
            tempImage[i][j].rgbtRed = image[i][j].rgbtRed;
        }

    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            newBluex = 0, newGreenx = 0, newRedx = 0, newBluey = 0, newGreeny = 0, newRedy = 0;
            actualBluex = 0, actualGreenx = 0, actualRedx = 0, actualBluey = 0, actualGreeny = 0, actualRedy = 0;
            leftBluex = 0, leftGreenx = 0, leftRedx = 0, leftBluey = 0, leftGreeny = 0, leftRedy = 0;
            rightBluex = 0, rightGreenx = 0, rightRedx = 0, rightBluey = 0, rightGreeny = 0, rightRedy = 0;
            upBluex = 0, upGreenx = 0, upRedx = 0, upBluey = 0, upGreeny = 0, upRedy = 0;
            downBluex = 0, downGreenx = 0, downRedx = 0, downBluey = 0, downGreeny = 0, downRedy = 0;
            uplBluex = 0, uplGreenx = 0, uplRedx = 0, uplBluey = 0, uplGreeny = 0, uplRedy = 0;
            uprBluex = 0, uprGreenx = 0, uprRedx = 0, uprBluey = 0, uprGreeny = 0, uprRedy = 0;
            downlBluex = 0, downlGreenx = 0, downlRedx = 0, downlBluey = 0, downlGreeny = 0, downlRedy = 0;
            downrBluex = 0, downrGreenx = 0, downrRedx = 0, downrBluey = 0, downrGreeny = 0, downrRedy = 0;
            red = 0, blue = 0, green = 0;

            actualBluex =  tempImage[i][j].rgbtBlue * gx[1][1];
            actualGreenx = tempImage[i][j].rgbtGreen * gx[1][1];
            actualRedx = tempImage[i][j].rgbtRed * gx[1][1];

            actualBluey = tempImage[i][j].rgbtBlue * gy[1][1];
            actualGreeny = tempImage[i][j].rgbtGreen * gy[1][1];
            actualRedy = tempImage[i][j].rgbtRed * gy[1][1];


            // test left
            if (j - 1 >= 0)
            {
                leftBluex = tempImage[i][j - 1].rgbtBlue * gx[1][0];
                leftGreenx = tempImage[i][j - 1].rgbtGreen * gx[1][0];
                leftRedx = tempImage[i][j - 1].rgbtRed * gx[1][0];

                leftBluey = tempImage[i][j - 1].rgbtBlue * gy[1][0];
                leftGreeny = tempImage[i][j - 1].rgbtGreen * gy[1][0];
                leftRedy =  tempImage[i][j - 1].rgbtRed * gy[1][0];
            }
            // test right
            if (j + 1 < width)
            {
                rightBluex =  tempImage[i][j + 1].rgbtBlue * gx[1][2];
                rightGreenx =  tempImage[i][j + 1].rgbtGreen * gx[1][2];
                rightRedx = tempImage[i][j + 1].rgbtRed * gx[1][2];

                rightBluey = tempImage[i][j + 1].rgbtBlue * gy[1][2];
                rightGreeny =  tempImage[i][j + 1].rgbtGreen * gy[1][2];
                rightRedy =  tempImage[i][j + 1].rgbtRed * gy[1][2];
            }
            // test up
            if (i - 1 >= 0)
            {
                upBluex = tempImage[i - 1][j].rgbtBlue * gx[0][1];
                upGreenx = tempImage[i - 1][j].rgbtGreen * gx[0][1];
                upRedx = tempImage[i - 1][j].rgbtRed * gx[0][1];

                upBluey = tempImage[i - 1][j].rgbtBlue * gy[0][1];
                upGreeny = tempImage[i - 1][j].rgbtGreen * gy[0][1];
                upRedy = tempImage[i - 1][j].rgbtRed * gy[0][1];
            }

            // test down
            if (i + 1 < height)
            {
                downBluex = tempImage[i + 1][j].rgbtBlue * gx[2][1];
                downGreenx = tempImage[i + 1][j].rgbtGreen * gx[2][1];
                downRedx = tempImage[i + 1][j].rgbtRed * gx[2][1];

                downBluey = tempImage[i + 1][j].rgbtBlue * gy[2][1];
                downGreeny = tempImage[i + 1][j].rgbtGreen * gy[2][1];
                downRedy = tempImage[i + 1][j].rgbtRed * gy[2][1];
            }
            // test up left
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                uplBluex = tempImage[i - 1][j - 1].rgbtBlue * gx[0][0];
                uplGreenx = tempImage[i - 1][j - 1].rgbtGreen * gx[0][0];
                uplRedx =  tempImage[i - 1][j - 1].rgbtRed * gx[0][0];

                uplBluey = tempImage[i - 1][j - 1].rgbtBlue * gy[0][0];
                uplGreeny = tempImage[i - 1][j - 1].rgbtGreen * gy[0][0];
                uplRedy = tempImage[i - 1][j - 1].rgbtRed * gy[0][0];
            }
            // test up right
            if (i - 1 >= 0 && j + 1 < width)
            {
                uprBluex = tempImage[i - 1][j + 1].rgbtBlue * gx[0][2];
                uprGreenx = tempImage[i - 1][j + 1].rgbtGreen * gx[0][2];
                uprRedx = tempImage[i - 1][j + 1].rgbtRed * gx[0][2];

                uprBluey = tempImage[i - 1][j + 1].rgbtBlue * gy[0][2];
                uprGreeny = tempImage[i - 1][j + 1].rgbtGreen * gy[0][2];
                uprRedy = tempImage[i - 1][j + 1].rgbtRed * gy[0][2];
            }
            // test down left
            if (i + 1 < height && j - 1 >= 0)
            {
                downlBluex = tempImage[i + 1][j - 1].rgbtBlue * gx[2][0];
                downlGreenx = tempImage[i + 1][j - 1].rgbtGreen * gx[2][0];
                downlRedx = tempImage[i + 1][j - 1].rgbtRed * gx[2][0];

                downlBluey = tempImage[i + 1][j - 1].rgbtBlue * gy[2][0];
                downlGreeny =  tempImage[i + 1][j - 1].rgbtGreen * gy[2][0];
                downlRedy = tempImage[i + 1][j - 1].rgbtRed * gy[2][0];
            }
            // test down right
            if (i + 1 < height && j + 1 < width)
            {
                downrBluex = tempImage[i + 1][j + 1].rgbtBlue * gx[2][2];
                downrGreenx = tempImage[i + 1][j + 1].rgbtGreen * gx[2][2];
                downrRedx = tempImage[i + 1][j + 1].rgbtRed * gx[2][2];

                downrBluey = tempImage[i + 1][j + 1].rgbtBlue * gy[2][2];
                downrGreeny = tempImage[i + 1][j + 1].rgbtGreen * gy[2][2];
                downrRedy = tempImage[i + 1][j + 1].rgbtRed * gy[2][2];
            }

            newBluex = actualBluex + leftBluex + rightBluex + upBluex + downBluex + uplBluex + uprBluex + downlBluex + downrBluex;
            newGreenx = actualGreenx + leftGreenx + rightGreenx + upGreenx + downGreenx + uplGreenx + uprGreenx + downlGreenx + downrGreenx;
            newRedx = actualRedx + leftRedx + rightRedx + upRedx + downRedx + uplRedx + uprRedx + downlRedx + downrRedx;

            newBluey = actualBluey + leftBluey + rightBluey + upBluey + downBluey + uplBluey + uprBluey + downlBluey + downrBluey;
            newGreeny = actualGreeny + leftGreeny + rightGreeny + upGreeny + downGreeny + uplGreeny + uprGreeny + downlGreeny + downrGreeny;
            newRedy = actualRedy + leftRedy + rightRedy + upRedy + downRedy + uplRedy + uprRedy + downlRedy + downrRedy;

            blue = round(sqrt((newBluex * newBluex) + (newBluey * newBluey)));
            green = round(sqrt((newGreenx * newGreenx) + (newGreeny * newGreeny)));
            red = round(sqrt((newRedx * newRedx) + (newRedy * newRedy)));

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

            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtRed = red;
        }

    }
    return;
}
