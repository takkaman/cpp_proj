#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "TrieTree.h"

int main() {
	TrieNode* root = createTrieTreeTable();
	char ip_addr[4][9];
	int i1, i2, i3, i4;
	while (true) {
		printf("Please enter IP address:\n");
		scanf("%d.%d.%d.%d", &i1, &i2, &i3, &i4);
		if (i1 >= 256 || i2 >= 256 || i3 >= 256 || i4 >= 256) {
			printf("IP address illegal...\n");
			continue;
		}
		createIP(i1, i2, i3, i4, ip_addr);
		//char *bin1 = "00101";
		//char *bin2 = "00001";
		// printf("level: %d\n", root->children[16]->children[0]->port);
		printf("Port: %d\n", search(ip_addr, root));
	}
	system("pause");

	return 0;
}