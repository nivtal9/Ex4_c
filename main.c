#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

int main(int argc, char **argv) {

    trieNode* root = New_node();
    int size = 0;
    bool rev = false;
    int i = 0;
    char* word = (char*)malloc(sizeof (char) *2);
    if (word == NULL){
        perror("error with malloc allocation");
    }
    *(1+word),*word = 0;
    char c;
    while (scanf ("%c",&c) == 1 ) {
        if (FinishWord(c)) {
            if (i != 0) {
                insert(word, root);
                free(word);
                word = (char *) malloc(sizeof (char) * 2);
                *(1+word),*wod = 0;
                if (size <= i) size = i;
                i = 0;
            }
        } else {
            word[i++] = c;
            word = (char *) realloc (word, i + 2);
        }
    }
    char length[size];
    if (2 == argc) {
        if (!strncmp(argv[1], "r", 1))
            rev = true;
    }
    switch (i){
        case 0:
            free(word);
            break;
        default:
            insert(word,root);
            free(word);
            break;
    }
    PrintWords(rev, 0, length, root );
    allocateMemory(root);

    return 0;
}