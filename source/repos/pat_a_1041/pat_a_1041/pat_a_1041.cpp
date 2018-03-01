// pat_a_1041.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int num, i;
	cin >> num;
	int *numArr = new int[num];
	map<int, int> numMap;
	for (i = 0; i < num; i++) {
		cin >> numArr[i];
		if (numMap.find(numArr[i]) != numMap.end()) {
			//cout << "update" << endl;
			numMap[numArr[i]] = numMap[numArr[i]] + 1;
		}
		else {
			numMap[numArr[i]] = 1;
		}
	}
	bool find_unique = false;
	for (i = 0; i < num; i++) {
		if (numMap[numArr[i]] == 1) {
			cout << numArr[i];
			find_unique = true;
			break;
		}
	}
	if (!find_unique) {
		cout << "None";
	}
	system("pause");
    return 0;
}

