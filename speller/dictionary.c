// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
    node *n = malloc(sizeof(node))
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
