// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 383;
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    // Get the index of the wors from the hash function
    int word_index = hash(word);

    // Points to the head node in the hash table
    node *cursor = table[word_index];

    // Loop through list until the end is reached
    while (cursor != NULL)
    {
        // Case sensitive comparison of word and word in current node
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }

        // Move cursor to the next node in list
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int index = toupper(word[0]) + toupper(word[1]) + toupper(word[2]);
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open dictionary file
    FILE *dictionary_file = fopen(dictionary, "r");

    // Check for file open errors
    if (dictionary_file == NULL)
    {
        printf("Failed to open dictionary file.\n");
        return false;
    }

    char words[LENGTH + 1];

    // Read every word in dictionary file until end is reached
    while (fscanf(dictionary_file, "%s", words) != EOF)
    {
        // Keep track of number of words being read
        word_count++;

        // Allocate memory for node
        node *n = malloc(sizeof(node));

        // Check if memory allocation operation was unsuccessful
        if (n == NULL)
        {
            printf("Memeory allocation error.\n");
            return false;
        }

        // Copy word into the next node
        strcpy(n->word, words);
        n->next = NULL;

        // Insert words into lists in hash table
        int word_hash = hash(words);
        if (table[word_hash] == NULL)
        {
            table[word_hash] = n;
        }
        else
        {
            n->next = table[word_hash];
            table[word_hash] = n;
        }
    }

    // Close dictionary file and return true for successful function operation completion
    fclose(dictionary_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO: Free all allocated nodes
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
