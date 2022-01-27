#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = 100 * letters / words;
    float S = 100 * sentences / words;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    printf("Grade %i\n", index);
    return 0;
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }
    return letter_count;
}
int count_words(string text)
{
    int word_count = 0;
    if (text)
    {
        word_count = 1;
    }
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == 32)
        {
            word_count++;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == 46 || text[i] == 21 || text[i] == 63 )
        {
            sentence_count++;
        }
    }
    return sentence_count;
}