//
// Created by nivtal9 on 24/01/2020.
//
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <stdio.h>

/**
 * //adds a node to the trie//
 * @return
 */
trieNode *New_node(void){
    trieNode *node = NULL;
    node = (trieNode *)malloc(sizeof(trieNode));
    if(node > 0){
        for(int i = 0;i < num_of_children ; ++i ){
            node -> wordcount = 0;
            node -> children[i] = NULL;
            if(i==num_of_children-1) node -> leaf = false;
        }
    }
    return node;
}
/**
 * checking from the buffer if we finish reading a word
 * @param c the character we standing on
 * @return
 */
bool FinishWord(char c){
    if(c == '\t' || c == ' ' || c == '\0' || c == ',' || c == '\n') return true;
    return false;
}

/**
 * //insert a word to the trie and update the number of appearance//
 * @param root the root of the trie
 * @param word the word we will insert into the trie
 */
void insert(char *word,trieNode *root) {
    int i;
    int k=0;
    for (i = 0; i < strlen(word) ; ++i) {
        int x = word[i];
        if(x >= 65 && x <= 90)word[i] = x + 32;
        if(97 <= x && x <= 122)word[k++] = (char) x;
        if(i==strlen(word)-1) word[k] = '\0';
    }
    trieNode *curr = root;
    for (i = 0; i < (int) strlen(word); ++i) {
        int c = (int)word[i] - (int)'a';
        if (!curr -> children[c]) {
            curr -> children[c] = New_node();
        }
        curr = curr -> children[c];
    }
    curr -> leaf = true;
    curr -> wordcount++;
}

/**
 * //remove from memory the whole trie//
 * @param root of the trie
 */
void allocateMemory(trieNode *root){
    trieNode *curr=root;
    if(curr -> leaf ) return free(curr);
    for(int i = 0;i < num_of_children ; ++i ) {
        if(i == 25) free(curr);
        if(curr -> children[i]) allocateMemory(curr->children[i]);
    }
}

/**
 * //print all the words with alphabetic order or Reverse alphabetic order//
 * @param root of the trie
 * @param ans the word with the number of appearance
 * @param j indicator of nodes
 * @param rev if true - print in reverse, false - print regularly
 */
void PrintWords(bool rev, int j,char outWord[],trieNode* root){
    trieNode *curr = root;
    if (curr -> wordcount != 0 ) {
        outWord[j] = '\0';
        printf("%s %d\n", outWord, root -> wordcount);
    }
    int index;
    for (int i = 0; i < num_of_children; ++i) {
        if (rev) {
            index = num_of_children-i-1;
        } else {
            index = i;
        }
        if (curr->children[index] != NULL ) {
            outWord[j] = index + 'a';
            PrintWords(rev,j+1 ,outWord, curr -> children[index]);
        }
    }
}