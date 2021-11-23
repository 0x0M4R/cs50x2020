// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// initialize dictionary counter
int a = 0; 

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    
    int length = strlen(word);
    char lower[length + 1];
    
    //changing word to lowercase inorder to hash properly
    for (int i = 0; i < length; i++)
    {
        lower[i] = tolower(word[i]);
    }
    lower[length] = '\0';
    
    //hashing lowercased word
    unsigned int b = hash(lower);
    
    // traversing through table and checking if word matches
    node *temp = table[b];
    while (temp != NULL)
    {
        if (strcasecmp(word, temp -> word) == 0)
        {
            return true;
        }
        temp = temp-> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Djb2 hash function from github
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char dict[LENGTH + 1];
    
    //try to open dictionary and check if opened file is NULL
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    
    //read strings from file one at a time
    while (fscanf(d, "%s", dict) != EOF)
    {
        //hashing dictionary word
        unsigned int b = hash(dict);
        
        //creating temp table for new node and checking if NULL
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            printf("Could not allocate memory \n");
            return false;
        }
        
        //copying string to temp table
        strcpy(temp -> word, dict);
        temp -> next = NULL;
        
        //if table is empty set to temp
        if (table[b] == NULL)
        {     
            table[b] = temp;
        }
        else
        {
            //creating another temp table and setting to hash table
            node *temp1 = table[b];
            
            //traverse the table until temp1 is the last node.
            while (temp1 -> next != NULL)
            {
                temp1 = temp1 -> next;
            }
            
            //pointing the last node (temp1) to the new node (temp)
            temp1 -> next = temp;
        }
        
        //incrementing dictionary counter
        a++;
    }
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return a;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //for every bucket in table
    for (int i = 0; i < N; i++)
    {
        //set temp table to table[i]
        node *temp = table[i];
        
        //traverse table and freeing every node in table
        while (temp != NULL)
        {
            node *temp1 = temp;
            temp = temp -> next;
            free(temp1);
        }
        
        //freeing table[i]
        free(temp);
    }
    return true;
}
