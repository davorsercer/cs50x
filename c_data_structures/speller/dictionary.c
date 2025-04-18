// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 997; // Prime number nearest to 1000

// Hash table
node *table[N];

// Counter of nodes created by load function
unsigned int loaded_nodes_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hashing word into hash value
    unsigned int hash_value = hash(word);

    // Point node to hash table pointer
    node *n = table[hash_value];

    // While all linked list at index hash_value in hash table are not equal to NULL
    while (n != NULL)
    {
        // compare and return true if words are same
        if (strcasecmp(n->word, word) == 0)
            return true;

        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash_value = 0;

    // Calculate hash value by adding all lowercase ASCII value from word and modulo it by N
    for (unsigned int i = 0; i < strlen(word); i++)
    {
        hash_value += tolower(word[i]);
        hash_value %= N;
    }

    return hash_value;
    // return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    // Check if the file name was opened successfully
    if (source == NULL)
    {
        // If source returns NULL, the file could not be opened
        printf("Error: Could not open file\n");
        return false; // Return non-zero value to indicate faliure
    }

    // Read each word in the file
    char dictionary_word[LENGTH + 1]; // Declaring char array for words in dictionary
    // While scanning dictionary file is not equal to End Of Line (EOF)
    while (fscanf(source, "%s", dictionary_word) != EOF)
    {
        // Declare new node for each word stored in node and allocate memory
        node *n = malloc(sizeof(node));
        // Check if the memory was allocated properly to node
        if (n == NULL)
        {
            // If returns NULL, the memory was not allocated properly
            fclose(source);
            unload();
            printf("Error: Memory to new dictionary word node was not allocated properly\n");
            return false; // Return non-zero value to indicate faliure
        }

        // Count every new node created
        loaded_nodes_counter++;

        // Copying dictionary word to nodes word
        strcpy(n->word, dictionary_word);
        // Set node pointer to NULL
        n->next = NULL;

        // Add each word to the hash table
        // Hashing every word into hash value
        unsigned int hash_value = hash(dictionary_word);

        // Set node pointer to hash table index
        n->next = table[hash_value];
        // Set hash table index pointer to last node created
        table[hash_value] = n;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return loaded_nodes_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *n = NULL;
    node *tmp = NULL;

    // For all positions in hash table
    for (unsigned int i = 0; i < N; i++)
    {
        n = table[i];
        // Free all linked lists in hash table at hash table index not NULL
        while (n != NULL)
        {
            tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    return true;
}
