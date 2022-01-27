#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

int count_words(string text);
int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");
    printf("Letter count is %i\n", count_letters(text));
    printf("Word count is %i\n", count_words(text));
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
    for (int i = 0; text[i]; i++)
    {
        if (text[i] == "." || text[i] == "!" || text[i] == "?" )
        {
            word_count++;
        }
    }
    return word_count;
}