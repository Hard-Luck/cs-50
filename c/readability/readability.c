#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>

//Prototypes of functions below
int count_words(string text);
int count_letters(string text);
int count_sentences(string text);

int main(void)
{
    //using all made functions to get all the approprate values
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    //using double for maximum accuracy
    double L = 100 * letters / words;
    double S = 100 * sentences / words;

    //formula for reading grade
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
    return 0;
}

//Count letters by looping through the given text and adding 1 for each "isalpha" (is letter)
//returning the value as an int
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

//Count letters by looping through the given text and adding 1 for each space "Ascii 32"
//returning the value as an int
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

//Count letters by looping through the given text and adding 1 for each "." "!" or "?" ascii 46,33,63
//returning the value as an int
int count_sentences(string text)
{
    int sentence_count = 0;
    for (int i = 0; text[i]; i++)
    {
        //"." "!" "?" --> ascii 46,33,63
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentence_count++;
        }
    }
    return sentence_count;
}