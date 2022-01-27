#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int count_words(string text);
int count_letters(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("Letter count is %i\n", count_letters(text));
    printf("Word count is %i\n", count_words(text));
    printf("Sentence count is %i\n", count_sentences(text));
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