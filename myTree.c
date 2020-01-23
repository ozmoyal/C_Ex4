#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "myTree.h"

typedef struct TrieNode
{
    char letter;
    long unsigned int count;
    boolean wordEnd;
    struct TrieNode *childrens[ALPHABET];
} TrieNode;

struct TrieNode *addNode()
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    for (int i = 0; i < ALPHABET; i++)
    {
        node->childrens[i] = NULL;
    }
    node->wordEnd = FALSE;
    return node;
}

void addWord(TrieNode **root, char *word)
{
    if (word[0] == ' ' || word[0] == '\n' || word[0] == '\t')
        return;
    TrieNode *tNode = *root;
    for (int i = 0; i < strlen(word); i++)
    {
        char c = word[i];
        if (c >= 'a' && c <= 'z')
        {
            int place = c - 'a';
            if (tNode->childrens[place] == NULL)
            {
                tNode->childrens[place] = addNode();
                tNode = tNode->childrens[place];
            }
            else
            {
                tNode = tNode->childrens[place];
            }
            tNode->letter = c;
        }
    }
    tNode->wordEnd = TRUE;
    tNode->count++;
}

void printWord(TrieNode *p, char *str, int l)
{
    if (p->wordEnd)
    {
        str[l] = '\0';
        printf("%s \t %ld \n", str, p->count);
    }
    for (int i = 0; i < ALPHABET; i++)
    {
        if (p->childrens[i] != NULL)
        {
            str[l] = i + 'a';
            printWord(p->childrens[i], str, l + 1);
        }
    }
}

void reversePrintWord(TrieNode *p, char *str, int l)
{
    for (int i = ALPHABET - 1; i > -1; i--)
    {
        if (p->childrens[i])
        {
            str[l] = i + 'a';
            reversePrintWord(p->childrens[i], str, l + 1);
        }
    }
    if (p->wordEnd == TRUE)
    {
        str[l] = '\0';
        printf("%s \t %ld \n", str, p->count);
    }
}
void toLowerCase(char *word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }
}

int checkChild(TrieNode *tNode)
{
    for (int i = 0; i < ALPHABET; i++)
        if (tNode->childrens[i])
            return TRUE;
    return FALSE;
}

void deleteNode(TrieNode *dNode)
{
    for (int i = 0; i < ALPHABET; i++)
    {
        if (dNode->childrens[i])
            deleteNode(dNode->childrens[i]);
    }
    free(dNode);
}
