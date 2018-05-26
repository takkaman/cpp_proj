#include <stdbool.h>

typedef struct TrieNode {
	int port;
	char *field;
	int level;
	struct TrieNode *children[256];
}TrieNode;

TrieNode* createTrieTree();
void dec2bin(int decimal, char *binary);
int bin2dec(char *binary);
void createIP(int i1, int i2, int i3, int i4, char ip_addr[4][9]);
int search(char ip_addr[4][9]);