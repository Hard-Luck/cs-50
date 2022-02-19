// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;


// TODO: Choose number of buckets in hash table
const unsigned int N = 677;

// Hash table
node *table[N];

int dic_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    // incase of single letter words.
    if(!(word[1]))
    {
        return 677;
    }
    //Hashing using first two letters
    //26* 1st + second AA 0*26 + 0 = 0, AB 0*26 + 1 = 1... , AZ = 26*0 +25 = 25, BA = 26*1 + 0
    return (toupper(word[0]) - 'A') * 26 + word[1] - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Initialise word array
    char next_word[LENGTH + 1];
    //open file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Error opening file");
        return false;
    }
    while(fscanf(dict, "%s", next_word) != EOF)
    {
        //find hash value
        int hash_val = hash(next_word);
        //allocate space for new node
        node *n = malloc(sizeof(node));
        //test for memory allocation
        if(n == NULL)
        {
            printf("Error allocating memory");
            fclose(dict);
            return false;
        }
        //give node word value and null pointer
        strcpy(n->word , next_word);
        n->next = table[hash_val];
        table[hash_val] = n;
        dic_size++;
    }
    //close file
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
        return dic_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for(int i = 0; i < N; i++)
    {
        while(table[i] != NULL)
        {
            node *temp = table[i]->next;
            free(table[i]);
            table[i] = temp;
        }
        return true;
    }
    return false;
}

