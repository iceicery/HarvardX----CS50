// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "dictionary.h"

#define HASHTABLE_SIZE 5000

//I choose Hash table method.

//define struct for node
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

//create a hashtable which is an array of pointer
node* hashtable[HASHTABLE_SIZE];
//track if loaded: start with false, if loaded, it turn to true.
bool loaded = false;

//hush function from : https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for(int i=0;i<strlen(needs_hashing);i++)
        hash=(hash<<2)^needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}

// Returns true if word is in dictionary else false
//case-insensitive, only for alphabetical characters and apostrophes

bool check(const char *word)
{
    //create char word_array to store copy of word
    int len=strlen(word);
    char word_array[len+1];
    //make words to lowercase
    for(int i=0;i<len;i++)
    {
        word_array[i]=tolower(word[i]);
    }
    //add null terminator to the end of word array
    word_array[len]='\0';
    //get the hash value
    int h=hash_it(word_array);
    //assign cursor node to the first node of the bucket
    node* cursor=hashtable[h];
    //check until the end
    while (cursor !=NULL)
    {
        if (strcmp(cursor->word,word_array)==0) //word is in the dictionary
        {
            return true;
        }
        else
        {
           cursor=cursor->next; //move to next
        }   
    }
    return false;
}
int count;
// Loads dictionary into memory, returning true if successful else false
bool load(const char* dictionary)
{
    //identify some variables
    count=0; //count represents number of words
    int h;//h represent hash number
    //make all hash table elements Null
    for (int j=0;j<HASHTABLE_SIZE;j++)
    {
        hashtable[j]=NULL;
    }
    
    //open dictionary
    FILE* f=fopen(dictionary,"r");
    if (f==NULL) //if file could not be opened
    {
        return false;
    }
    while (true)
    {
        //create a size of node for each new word
        node* new_node=malloc(sizeof(node));
        //if run out of memory for new node
        if (new_node==NULL) //could not malloc a new node
        {
            return false;
        }
         
        //read a word from dictionary and store it in new_node->word
        fscanf(f,"%s",new_node->word);
        
        if (feof(f)) //end of file
        {
            free(new_node);
            break;
        }
        
        count ++;
        
        h= hash_it(new_node->word); //hash number
        //insert node into hashtable a h position
        node* head=hashtable[h];
        //insert first node
        if(head==NULL)
        {
            hashtable[h]=new_node;
        }
        else
        {
            new_node->next=head;
            hashtable[h]=new_node;
        }
         
    }
    //close file
    fclose(f);
    loaded=true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded

unsigned int size(void)
{
    if (loaded == true)
    {
        return count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i=0;i<HASHTABLE_SIZE;i++)
    {
        node* cursor = hashtable[i];
        while (cursor !=NULL)
        {
            //use temp to maintain connection to linked list
            node* temp=cursor;
            cursor=cursor->next;
            free(temp);
        }
    }
    loaded=false;
    return true;
}
