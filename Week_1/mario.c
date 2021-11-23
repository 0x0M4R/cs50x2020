#include <stdio.h>
#include <cs50.h>

int get_positive_int(string prompt);

int main(void)
{   
    int counter = 1;                                //Set counter for amount of hashes per line
    int height = get_positive_int("Height:");       //Prompt user for perferred height
    int spaces = height - 1;                        //Set counter for spaces per line

    for (int i = 0; i < height; i++)                //Loop for amount of rows to be created
    {
        for (int y = 0; y < spaces; y++)            //Loop for amount of spaces to be printed per line
        {
            printf(" ");
        }

        for (int j = 0; j < counter; j++)           //Loop for amount of hashes to be printed per line
        {

            printf("#");

        }
        counter++;                                  // add 1 to hash counter
        spaces--;                                   // minus 1 to space counter
        printf("\n");                               // new line
    }
}


// Prompt user for positive integer that is between 1 and 8
int get_positive_int(string prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);
    }
    while (n < 1 || n > 8);
    return n;
}