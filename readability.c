#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Enter text: ");

    int letters = 0, words = 1, sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        char ch = text[i];

        if (isalpha(ch))
        {
            letters++;
        }
        else if (ch == ' ')
        {
            words++;
        }
        else if (ch == '.' || ch == '!' || ch == '?')
        {
            sentences++;
        }
    }

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

