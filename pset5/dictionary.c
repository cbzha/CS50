// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 140000;

// Hash table
node *table[N];

// numero de palavras no dicionario
unsigned int nwords = 0;

FILE *file = NULL;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char wordl[strlen(word) + 1];
    for (int i = 0; i <= strlen(word); i++)
    {
        wordl[i] = tolower(word[i]);
    }

    unsigned int i = hash(wordl);
    node *temp = table[i];
    while (temp != NULL)
    {
        if (strcmp(temp -> word, wordl) == 0)
        {
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int hash = 0;
    int c = 0;
    while ((c = *word++))
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    // faz com que o valor do hash seja no máximo N. Se passar, começa do zero novamente.
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char sword[LENGTH + 1];
    while (fscanf(file, "%s", sword) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        // ajustar palavra. string termina com '\0', então tamanho + 1
        char newWord[strlen(sword) + 1];
        for (int i = 0; i <= strlen(sword); i++)
        {
            newWord[i] = sword[i];
        }


        strcpy(n -> word, newWord);
        nwords++;
        // chama a função hash para determinar o indice da tabela hash
        int index = hash(newWord);

        node *temp = table[index];
        table[index] = n;
        n -> next = temp;

    }

    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (file != NULL)
    {
        return nwords;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = NULL;
    //node *temp = NULL;
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            cursor = table[i] -> next;
            free(table[i]);
            table[i] = cursor;
        }
    }
    fclose(file);
    return true;
}
