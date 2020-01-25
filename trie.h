//
// Created by nivtal9 on 24/01/2020.
//

#ifndef trie_h
#define trie_h
#define num_of_children 26


#include <stdbool.h>

typedef struct trieNode{struct trieNode *children[num_of_children]; bool leaf; int wordcount;} trieNode;

trieNode *New_node(void);

void insert(char *word,trieNode *root);

void allocateMemory(trieNode *root);

void PrintWords(bool rev, int j, char outWord[],trieNode* root );

bool FinishWord(char c);

#endif //trie_h