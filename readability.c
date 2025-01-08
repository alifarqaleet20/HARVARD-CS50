#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // prompt for text
    string text = get_string("Text: ");
    // length of text
    int textLen = strlen(text);
    // iterating through text to find number of letters
    int letterscount = 0;
    for (int i = 0; i < textLen; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letterscount++;
        }
    }
    // finding total words
    int wordsCount = 0;
    for (int i = 0; i < textLen; i++)
    {
        if (text[i] == 32)
        {
            wordsCount++;
        }
    }
    wordsCount += 1;
    // finding total sentences
    int sentences = 0;
    for (int i = 0; i < textLen; i++)
    {
        if ((text[i] == 33) || (text[i] == 63) || (text[i] == 46))
        {
            sentences++;
        }
    }
    // letters per hundred words
    double L;
    double S;
    L = ((double) letterscount / wordsCount) * 100;
    // sentences per hundred words
    S = ((double) sentences / wordsCount) * 100;

    // index
    double index;
    index = 0.0588 * L - 0.296 * S - 15.8;

    // rounding it off
    int roundedIndex = (int) round(index);

    // printing Grade
    if (roundedIndex >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", roundedIndex);
    }
}