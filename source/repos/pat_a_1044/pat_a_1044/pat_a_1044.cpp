// pat_a_1044.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void GetSum(int *numArr, long sum, int start, int end, vector<string> &lg_result, int &delta, bool &equal) {
	int val = 0, pos = start;
	while (val < sum && pos <= end) {
		val += numArr[pos++];
	}
	if (val == sum) {
		equal = true;
		stringstream ss1, ss2;
		ss1 << start + 1;
		ss2 << pos;
		cout << ss1.str() + "-" + ss2.str() << endl;
		//eq_result.push_back(ss1.str() + "-" + ss2.str());
	}

	if (val > sum && !equal) {
		if (val - sum < delta) {
			lg_result.clear();
			delta = val - sum;
			stringstream ss1, ss2;
			ss1 << start + 1;
			ss2 << pos;
			lg_result.push_back(ss1.str() + "-" + ss2.str());
		}
		else if (val - sum == delta) {
			stringstream ss1, ss2;
			ss1 << start + 1;
			ss2 << pos;
			lg_result.push_back(ss1.str() + "-" + ss2.str());
		}
	}
}

int main()
{
	int num, i;
	long sum;
	cin >> num >> sum;
	vector<string> eq_result;
	vector<string> lg_result;
	int *numArr = new int[num];
	for (i = 0; i < num; i++) {
		cin >> numArr[i];
	}

	int delta = sum;
	bool equal = false;
	for (i = 0; i < num; i++) {
		GetSum(numArr, sum, i, num - 1, lg_result, delta, equal);
	}

	if (lg_result.size() > 0 && !equal) {
		for (auto &r : lg_result) {
			cout << r << endl;
		}
	}

	system("pause");
    return 0;
}

