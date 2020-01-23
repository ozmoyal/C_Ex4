#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myTree.h"

int main(int argc, char *argv[])
{
    char *word;
    char ch;
    TrieNode *head = addNode();
    size_t x = 0;
    word = (char *)malloc(sizeof(char));
    word[x++] = '\0';
    printf("enter a word: \n");
    ch = getchar();
    while (ch != EOF)
    {
        while (ch != EOF && ch != ' ' && ch != '\t' && ch != '\n')
        {
            word = realloc(word, (x + 1) * sizeof(char));
            word[x-1] = ch;
            word[x++] = '\0';
            ch = getchar();
        }
        toLowerCase(word);
        addWord(&head, word);
        free(word);
        ch = getchar();
        if (ch == EOF)
            break;
        x = 1;
        word = (char *)malloc(sizeof(char));
        word[0] = ch;
    }

    char *str = (char *)malloc(sizeof(char));
    if (argc == 1)
    {
        printWord(head, str, 0);
    }
    else if (argv[1][0] == 'r')
    {
        reversePrintWord(head, str, 0);
    }
    free(str);
    deleteNode(head);
}