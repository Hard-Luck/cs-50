#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 Wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!");
    }
    else if (score1 == score2)
    {
        printf("Tie!");
    }
}

//Tally the scores of each letter in the string and return the total
int compute_score(string word)
{
    //set score to zero to add too when looping through the string
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //looping through each letter of the alphabet
        for (int j = 0; j <= 25; j++)
        {
            //converting all letters to UPPER case to disambiguate. Using Ascii values 65-90 -> A-C
            if (toupper(word[i]) == j + 65)
            {
                //if the character is a match add the correstponding points to score
                score += POINTS[j];
            }
        }
    }
    return score;
}
