#include<cs50.h>
#include<stdio.h>
#include <string.h>

int main(void)
{
    float index = 0;
    float letters = 0;
    float words = 1 ;
    float sentences = 0;
    string text = get_string("Text: ");     //get string from user
    for (int i = 0, n = strlen(text); i < n; i++)       //Counting number of letters words and sentences.
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
        if (text[i] == ' ')
        {
            words++;
        }
        if (text[i] == '.' ||  text[i] == '?' ||  text[i] == '!')
        {
            sentences++;
        }
    }
    float L = (letters / words) * 100; // calculate amount of letters per 100 words and amount of sentences per 100 words
    float S = (sentences / words) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8; // run values through Coleman-Liau index
    if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", index);
    }
}
