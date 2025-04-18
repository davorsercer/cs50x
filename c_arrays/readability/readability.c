#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");
    /* string text = "Would you like them here or there? I would not like them here or there. I
    would not like them anywhere."; //(Grade 2) */

    // Count the number of letters, words, and sentences in the text
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
            letters++;
        if (isspace(text[i]))
            words++;
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
            sentences++;
    }

    // Compute the Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float C_L_index = (0.0588 * L) - (0.296 * S) - 15.8;

    // Print the grade level
    if (C_L_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (C_L_index <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
        printf("Grade %i\n", (int) round(C_L_index));
}
