#define ALPHABET 26 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct TrieNode TrieNode;
void toLowerCase (char* word);
void deleteNode (TrieNode *dNode);
int checkChild(TrieNode* tNode);
void reversePrintWord( TrieNode *p, char *str, int l);
void printWord ( TrieNode *p, char *str, int l);
void addWord (TrieNode **root, char *word );
struct TrieNode* addNode();