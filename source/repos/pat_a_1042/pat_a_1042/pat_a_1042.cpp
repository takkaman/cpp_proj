// pat_a_1042.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

string *Shuffle(string *initPos, int *shuffleArr) {
	string *tmpArr = new string[54];
	int i;
	for (i = 0; i < 54; i++) {
		int new_pos = shuffleArr[i] - 1;
		tmpArr[new_pos] = initPos[i];
	}

	return tmpArr;
}

int main()
{	
	int shuffle_count, i;
	cin >> shuffle_count;
	int cnt = 54;
	int *shuffleArr = new int[54];
	string *initPos = new string[54];

	for (i = 0; i < 13; i++) {
		stringstream str;
		str << i+1;
		string result;
		str >> result;
		initPos[i] = "S" + result;
	}
	for (i = 0; i < 13; i++) {
		stringstream str;
		str << i+1;
		string result;
		str >> result;
		initPos[i+13] = "H" + result;
	}
	for (i = 0; i < 13; i++) {
		stringstream str;
		str << i+1;
		string result;
		str >> result;
		initPos[i+26] = "C" + result;
	}
	for (i = 0; i < 13; i++) {
		stringstream str;
		str << i+1;
		string result;
		str >> result;
		initPos[i+39] = "D" + result;
	}
	initPos[52] = "J1";
	initPos[53] = "J2";

	for (i = 0; i < 54; i++) {
		cin >> shuffleArr[i];
	}

	while (shuffle_count-- > 0) {
		initPos = Shuffle(initPos, shuffleArr);
	}

	for (i = 0; i < 54; i++) {
		cout << initPos[i];
		if (i < 53) {
			cout << " ";
		}
	}

	system("pause");
    return 0;
}

