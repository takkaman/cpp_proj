#include "TrieTree.h"
#include <stdlib.h>
#include <string.h>

TrieNode* createTrieTreeTable() {
	TrieNode* root = (TrieNode*) malloc(sizeof(TrieNode));
	TrieNode* current = root, *parent, *tmp;
	int level = 0;
	current->port = 0;
	current->level = level;
	current->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	parent = current;

	//======1st level======
	level++;
	// 00000
	parent->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[0];
	current->port = 35;
	current->level = level;
	current->field = "00000";
	current->children[0] = NULL;

	// 00001
	parent->children[1] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[1];
	current->port = 35;
	current->level = level;
	current->field = "00001";
	current->children[0] = NULL;

	// 00010
	parent->children[2] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[2];
	current->port = 68;
	current->level = level;
	current->field = "00010";
	current->children[0] = NULL;

	// 00011
	parent->children[3] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[3];
	current->port = 68;
	current->level = level;
	current->field = "00011";
	current->children[0] = NULL;

	// 00100
	parent->children[4] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[4];
	current->port = 35;
	current->level = level;
	current->field = "00100";
	current->children[0] = NULL;

	// 00101
	parent->children[5] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[5];
	current->port = 35;
	current->level = level;
	current->field = "00101";
	current->children[0] = NULL;

	// 00110
	parent->children[6] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[6];
	current->port = 3;
	current->level = level;
	current->field = "00110";
	current->children[0] = NULL;

	// 00111
	parent->children[7] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[7];
	current->port = 35;
	current->level = level;
	current->field = "00111";
	current->children[0] = NULL;

	// 01000
	parent->children[8] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[8];
	current->port = 21;
	current->level = level;
	current->field = "01000";
	current->children[0] = NULL;

	// 01001
	parent->children[9] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[9];
	current->port = 21;
	current->level = level;
	current->field = "01001";
	current->children[0] = NULL;

	// 01010
	parent->children[10] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[10];
	current->port = 21;
	current->level = level;
	current->field = "01010";
	current->children[0] = NULL;

	// 01011
	parent->children[11] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[11];
	current->port = 51;
	current->level = level;
	current->field = "01011";
	current->children[0] = NULL;

	// 01100
	parent->children[12] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[12];
	current->port = 21;
	current->level = level;
	current->field = "01100";
	current->children[0] = NULL;

	// 01101
	parent->children[13] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[13];
	current->port = 21;
	current->level = level;
	current->field = "01101";
	current->children[0] = NULL;

	// 01110
	parent->children[14] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[14];
	current->port = 21;
	current->level = level;
	current->field = "01110";
	current->children[0] = NULL;

	// 01111
	parent->children[15] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[15];
	current->port = 21;
	current->level = level;
	current->field = "01111";
	current->children[0] = NULL;

	// 10000 lv4
	parent->children[16] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[16];
	current->port = 0;
	current->level = level;
	current->field = "10000";
	// current->children[0] = NULL;

	// 10001
	parent->children[17] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[17];
	current->port = 6;
	current->level = level;
	current->field = "10001";
	current->children[0] = NULL;

	// 10010
	parent->children[18] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[18];
	current->port = 7;
	current->level = level;
	current->field = "10010";
	current->children[0] = NULL;

	// 10011
	parent->children[19] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[19];
	current->port = 7;
	current->level = level;
	current->field = "10011";
	current->children[0] = NULL;

	// 10100
	parent->children[20] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[20];
	current->port = 7;
	current->level = level;
	current->field = "10100";
	current->children[0] = NULL;

	// 10101
	parent->children[21] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[21];
	current->port = 7;
	current->level = level;
	current->field = "10101";
	current->children[0] = NULL;

	// 10110
	parent->children[22] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[22];
	current->port = 1;
	current->level = level;
	current->field = "10110";
	current->children[0] = NULL;

	// 10111
	parent->children[23] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[23];
	current->port = 1;
	current->level = level;
	current->field = "10111";
	current->children[0] = NULL;

	// 11000
	parent->children[24] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[24];
	current->port = 9;
	current->level = level;
	current->field = "11000";
	current->children[0] = NULL;

	// 11001
	parent->children[25] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[25];
	current->port = 9;
	current->level = level;
	current->field = "11001";
	current->children[0] = NULL;

	// 11010
	parent->children[26] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[26];
	current->port = 9;
	current->level = level;
	current->field = "11010";
	current->children[0] = NULL;

	// 11011
	parent->children[27] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[27];
	current->port = 9;
	current->level = level;
	current->field = "11011";
	current->children[0] = NULL;

	// 11100
	parent->children[28] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[28];
	current->port = 35;
	current->level = level;
	current->field = "11100";
	current->children[0] = NULL;

	// 11101
	parent->children[29] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[29];
	current->port = 35;
	current->level = level;
	current->field = "11101";
	current->children[0] = NULL;

	// 11110
	parent->children[30] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[30];
	current->port = 35;
	current->level = level;
	current->field = "11110";
	current->children[0] = NULL;

	// 11111
	parent->children[31] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[31];
	current->port = 35;
	current->level = level;
	current->field = "11111";
	current->children[0] = NULL;
	// field end
	parent->children[32] = NULL;

	//======2nd level======
	level++;
	parent = parent->children[16];
	// 10000 00 lv3
	parent->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[0];
	current->port = 0;
	current->level = level;
	current->field = "00";
	//current->children[0] = NULL;

	// 10000 01
	parent->children[1] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[1];
	current->port = 7;
	current->level = level;
	current->field = "01";
	current->children[0] = NULL;

	// 10000 10
	parent->children[2] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[2];
	current->port = 33;
	current->level = level;
	current->field = "10";
	current->children[0] = NULL;

	// 10000 11
	parent->children[3] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[3];
	current->port = 33;
	current->level = level;
	current->field = "11";
	current->children[0] = NULL;
	// tail end
	parent->children[4] = NULL;

	//======3rd level======
	level++;
	parent = parent->children[0];
	// 10000 00 00 lv2 
	parent->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[0];
	current->port = 0;
	current->level = level;
	current->field = "00";
	//current->children[0] = NULL;

	// 10000 00 01 lv2 
	parent->children[1] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[1];
	current->port = 0;
	current->level = level;
	current->field = "01";
	//current->children[0] = NULL;

	// 10000 00 10
	parent->children[2] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[2];
	current->port = 54;
	current->level = level;
	current->field = "10";
	current->children[0] = NULL;

	// 10000 00 11
	parent->children[3] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[3];
	current->port = 54;
	current->level = level;
	current->field = "11";
	current->children[0] = NULL;
	// tail end
	parent->children[4] = NULL;

	//======4th level-1======
	level++;
	tmp = parent;
	parent = parent->children[0];
	// 10000 00 00 000
	parent->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[0];
	current->port = 12;
	current->level = level;
	current->field = "000";
	current->children[0] = NULL;

	// 10000 00 00 001
	parent->children[1] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[1];
	current->port = 12;
	current->level = level;
	current->field = "001";
	current->children[0] = NULL;

	// 10000 00 00 010
	parent->children[2] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[2];
	current->port = 12;
	current->level = level;
	current->field = "010";
	current->children[0] = NULL;

	// 10000 00 00 011
	parent->children[3] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[3];
	current->port = 12;
	current->level = level;
	current->field = "011";
	current->children[0] = NULL;

	// 10000 00 00 100
	parent->children[4] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[4];
	current->port = 54;
	current->level = level;
	current->field = "100";
	//current->children[0] = NULL;

	// 10000 00 00 101
	parent->children[5] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[5];
	current->port = 54;
	current->level = level;
	current->field = "101";
	//current->children[0] = NULL;

	// 10000 00 00 110
	parent->children[6] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[6];
	current->port = 54;
	current->level = level;
	current->field = "110";
	current->children[0] = NULL;

	// 10000 00 00 111
	parent->children[7] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[7];
	current->port = 54;
	current->level = level;
	current->field = "111";
	current->children[0] = NULL;
	// tail end
	parent->children[8] = NULL;

	//======4th level-2======
	tmp = parent;
	parent = parent->children[1];
	// 10000 00 01 000
	parent->children[0] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[0];
	current->port = 54;
	current->level = level;
	current->field = "000";
	current->children[0] = NULL;

	// 10000 00 01 001
	parent->children[1] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[1];
	current->port = 54;
	current->level = level;
	current->field = "001";
	current->children[0] = NULL;

	// 10000 00 01 010
	parent->children[2] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[2];
	current->port = 54;
	current->level = level;
	current->field = "010";
	current->children[0] = NULL;

	// 10000 00 01 011
	parent->children[3] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[3];
	current->port = 54;
	current->level = level;
	current->field = "011";
	current->children[0] = NULL;

	// 10000 00 01 100
	parent->children[4] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[4];
	current->port = 14;
	current->level = level;
	current->field = "100";
	//current->children[0] = NULL;

	// 10000 00 01 101
	parent->children[5] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[5];
	current->port = 14;
	current->level = level;
	current->field = "101";
	//current->children[0] = NULL;

	// 10000 00 01 110
	parent->children[6] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[6];
	current->port = 14;
	current->level = level;
	current->field = "110";
	current->children[0] = NULL;

	// 10000 00 01 111
	parent->children[7] = (TrieNode*)malloc(sizeof(TrieNode));
	current = parent->children[7];
	current->port = 14;
	current->level = level;
	current->field = "111";
	current->children[0] = NULL;
	// tail end
	parent->children[8] = NULL;

	return root;
}

void dec2bin(int decimal, char *binary) {
	int k = 0, n, i, remain;
	char temp[8];

	for (n = 0; n<8; n++) {			// zero the binary string
		binary[n] = '0';
	}
	binary[n] = '\0';

	do {
		remain = decimal % 2;	// whittle down the decimal number
		decimal = decimal / 2;
		temp[k] = remain + '0';	// converts digit 0 or 1 to character '0' or '1'
		k++;
	} while (decimal > 0);

	n = 7;
	for (i = 0; i<k; i++) {		// reverse the spelling
		binary[n] = temp[i];
		n--;
	}
}

// Convert binary string into decimal
int bin2dec(char *binary) {
	int n = strlen(binary) - 1, i = 1, decimal = 0;

	while (n >= 0) {
		if (binary[n] == '1')
			decimal = decimal + i;
		n--;
		i = i * 2;
	}

	return decimal;
}

// Merge 4 numbers into multi-dimensional array
void createIP(int i1, int i2, int i3, int i4, char ip_addr[4][9]) {
	printf("IP adress: %d.%d.%d.%d\n", i1, i2, i3, i4);
	int n, i;

	for (i = 0; i<4; i++) {	// Zero the ip address
		for (n = 0; n<8; n++) {
			ip_addr[i][n] = '0';
		}
	}
	// Convert each number of the IP address to binary conversion (8bits)
	dec2bin(i1, ip_addr[0]);
	ip_addr[0][8] = '\0';
	dec2bin(i2, ip_addr[1]);
	ip_addr[1][8] = '\0';
	dec2bin(i3, ip_addr[2]);
	ip_addr[2][8] = '\0';
	dec2bin(i4, ip_addr[3]);
	ip_addr[3][8] = '\0';
}

int search(char ip_addr[4][9], TrieNode *root) {
	printf("Start search...\n");
	// i is number of tiers searched to, where 0 is root and 4 is 4th number of IP, count keeps track of how many steps in search
	int n = 0, i = 0, count = 0, j, level = 0;
	TrieNode *current = NULL;
	TrieNode *final = NULL;
	char *search_addr[4];
	search_addr[0] = malloc(sizeof(char) * 6);
	search_addr[1] = malloc(sizeof(char) * 3);
	search_addr[2] = malloc(sizeof(char) * 3);
	search_addr[3] = malloc(sizeof(char) * 4);

	for (j = 0; j < 5; j++) {
		search_addr[0][j] = ip_addr[0][j];
	}
	search_addr[0][5] = '\0';

	search_addr[1][0] = ip_addr[0][5];
	search_addr[1][1] = ip_addr[0][6];
	search_addr[1][2] = '\0';

	search_addr[2][0] = ip_addr[0][7];
	search_addr[2][1] = ip_addr[1][0];
	search_addr[2][2] = '\0';

	search_addr[3][0] = ip_addr[1][1];
	search_addr[3][1] = ip_addr[1][2];
	search_addr[3][2] = ip_addr[1][3];
	search_addr[3][3] = '\0';

	current = root;

	while (final == NULL) {
		n = 0;
		count++;
		if (current->children[0] == NULL) {
			final = current;
			break;
		}
		// this loop searches all the branches in that node for fields that
		// match the next number of the destination address
		printf("Current level: %d, IP sub addr is: %s\n", level, search_addr[level]);
		while (strcmp(current->children[n]->field, search_addr[level]) != 0) {
			printf("    level: %d, child: %d, field: %s not match, search next\n", level, n, current->children[n]->field);
			n++;
			count++;
			if (current->children[n] == NULL) {
				printf("   Level search reach the end, return parent port.\n");
				final = current;
				break;
			}
		}

		printf("    Child %d, field: %s match, level down.\n", n, current->children[n]->field);
		current = current->children[n];
		level++;
		i++;
	}
	printf("%i steps through tree, ", count);

	return final->port;
}