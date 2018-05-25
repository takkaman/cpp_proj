#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node {
	int data;
	struct node* next;
} LList;

void printList(LList * list);

LList* pushToResult(LList* resultList, int entry) {
	LList * temp = malloc(sizeof(LList));
	temp->data = entry;
	temp->next = resultList;
	resultList = temp;
	return resultList;
}

char* substr(char const* input, size_t start, size_t len) {
	char *nstr = malloc(len + 1);
	memcpy(nstr, input + start, len);
	nstr[len] = '\0';
	return nstr;
}

LList* convertToList(char* line) {
	int i;
	int strSize = strlen(line);
	//Eight elements in every node
	int maxelem = 4;
	int currentPartition = 0;
	int currentIndex = 0;
	int totalPartitions = strSize / maxelem;
	int len;
	LList* temp = NULL;
	// printf("strsize: %d\n", strSize);
	for (i = 0; i <= strSize - 1;) {
		// printf("i: %d\n", i);
		if (currentPartition > totalPartitions) break;
		if (currentPartition == 0) {
			len = strSize % maxelem;
			if (len == 0) len = 4;
		}
		else {
			len = maxelem;
		}
		// printf("len: %d\n", len);
		char * currStr = substr(line, i, len);
		int number = atoi(currStr);
		if (temp == NULL) {
			temp = malloc(sizeof(LList));
			temp->data = number;
			temp->next = NULL;
		}
		else {
			LList * current = malloc(sizeof(LList));
			current->data = number;
			current->next = temp;
			temp = current;
		}
		currentIndex = i;
		currentPartition++;
		i += len;
	}
	currentIndex = currentIndex + maxelem;
	if ((currentIndex > 0) && (currentIndex < (strSize - 1))) {
		char * remainingStr = substr(line, currentIndex, strSize - 1);
		int remainingNum = atoi(remainingStr);
		LList * current = malloc(sizeof(LList));
		current->data = remainingNum;
		current->next = temp;
		temp = current;
	}
	return temp;
}


void printList(LList * list, FILE *output) {
	LList * counter = list;
	char c[5];
	int i, j, k, num;
	//FILE *output = fopen("output.txt", "a+");
	while (counter != NULL) {
		num = counter->data;
		// printf("num: %d\n", num);
		for (i = 0; i<4; i++) {
			c[3-i] = num % 10 + '0';
			// printf("char c: %c", c[3 - i]);
			num /= 10;
		}
		c[4] = '\0';
		fprintf(output, "%s ", c);
		printf("%s ", c);
		counter = counter->next;
	}
	fprintf(output, "\n\n", c);
	printf("\n\n");
	//fclose(output);
}

int main() {
	//Read number 1 from the input file into a linked list
	//The unit's place is the head and the most significant number is the tail
	//Read number 2 from the input file into a linked list
	//The unit's place is the head and the most significant number is the tail
	//Create temporary List where the elements will be added
	//Create the carry variable that will consist of the element's carry over after addition


	int counter = 0;
	size_t read;
	size_t len = 0;
	char line[256];

	int carry = 0;
	LList* num1 = NULL;
	LList* num2 = NULL;
	LList* result = NULL;

	FILE * input = fopen("input.txt", "r");
	FILE * output = fopen("output.txt", "a+");
	if (input == NULL) {
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), input)) {
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		fprintf(output, "Read the line %s\n", line);
		printf("Read the line %s\n", line);
		//If it's the first line
		if (counter == 0) {
			num1 = convertToList(line);
			fprintf(output, "Printing the list containing the num1(it will be in reversed order)\n");
			printf("Printing the list containing the num1(it will be in reversed order)\n");
			printList(num1, output);
		}
		else {
			num2 = convertToList(line);
			fprintf(output, "Printing the list containing the num2(it will be in reversed order)\n");
			printf("Printing the list containing the num2(it will be in reversed order)\n");
			printList(num2, output);
		}
		counter++;
	}

	fclose(input);
	int j = 1;
	while ((num1 != NULL) || (num2 != NULL)) {
		fprintf(output, "Adding iteration %d:\n", j);
		j++;
		if (num1 != NULL) {
			fprintf(output, "Adding 4bit numbers in num1: %d ", num1->data);
			carry = carry + (num1->data);
			num1 = num1->next;
		}
		if (num2 != NULL) {
			fprintf(output, "and 4bit numbers in num2: %d ", num2->data);
			carry = carry + (num2->data);
			num2 = num2->next;
		}

		//Get the carry and the left over
		int carryOver = carry / 10000;
		int leftOver = carry % 10000;
		
		fprintf(output, "with result: %d and carry: %d\n\n", leftOver, carryOver);
		//put the left over in the result linked list
		//printf("Pushing the result into the result list");
		result = pushToResult(result, leftOver);
		carry = carryOver;

	}
	
	//Done with traversing the linked lists,if the carry is zero no need to push the value to the result
	//else push the value to the result
	if (carry != 0) {
		result = pushToResult(result, carry);
	}

	//Print the result here
	fprintf(output, "Printing out the result of the addition\n");
	printf("Printing out the result of the addition\n");
	printList(result, output);
	fclose(output);
	system("pause");
}
