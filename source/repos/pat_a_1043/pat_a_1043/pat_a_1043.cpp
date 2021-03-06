// pat_a_1043.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

bool IsBST(int *numArr, int start, int end, vector<int> &output) {
	bool result = true;
	if (start == end) {
		output.push_back(numArr[start]);
		return true;
	}
	int root = numArr[start];
	int i = start + 1;
	while (numArr[i] < root && i <= end) {
		i++;
	}
	//cout << i << endl;
	// only left tree
	if (i == end + 1) {
		result = IsBST(numArr, start + 1, end, output);
		output.push_back(numArr[start]);
		return result;
	}

	// only right tree
	if (i-1 == start) {
		for (int j = start + 1; j <= end; j++) {
			if (numArr[j] < root) return false;
		}
		result =  IsBST(numArr, start + 1, end, output);
		output.push_back(numArr[start]);
		return result;
	}

	// both left and right tree exist
	int lstart, lend, rstart, rend;
	lstart = start + 1;
	lend = i - 1;
	rstart = i;
	rend = end;
	for (int j = lstart; j <= lend; j++) {
		if (numArr[j] >= root) return false;
	}
	for (int j = rstart; j <= rend; j++) {
		if(numArr[j] < root) return false;
	}
	bool lresult = IsBST(numArr, lstart, lend, output);
	bool rresult = IsBST(numArr, rstart, rend, output);
	output.push_back(numArr[start]);
	return lresult && rresult;
}

bool IsMirrBST(int *numArr, int start, int end, vector<int> &output) {
	bool result = true;
	if (start == end) {
		output.push_back(numArr[start]);
		return true;
	}
	int root = numArr[start];
	int i = start + 1;
	while (numArr[i] >= root && i <= end) {
		i++;
	}
	//cout << i << endl;
	// only left tree
	if (i == end + 1) {
		result = IsMirrBST(numArr, start + 1, end, output);
		output.push_back(numArr[start]);
		return result;
	}

	// only right tree
	if (i - 1 == start) {
		for (int j = start + 1; j <= end; j++) {
			if (numArr[j] >= root) return false;
		}
		result = IsMirrBST(numArr, start + 1, end, output);
		output.push_back(numArr[start]);
		return result;
	}

	// both left and right tree exist
	int lstart, lend, rstart, rend;
	lstart = start + 1;
	lend = i - 1;
	rstart = i;
	rend = end;
	for (int j = lstart; j <= lend; j++) {
		if (numArr[j] < root) return false;
	}
	for (int j = rstart; j <= rend; j++) {
		if (numArr[j] >= root) return false;
	}
	bool lresult = IsMirrBST(numArr, lstart, lend, output);
	bool rresult = IsMirrBST(numArr, rstart, rend, output);
	output.push_back(numArr[start]);
	return lresult && rresult;
}

int main()
{
	int num, i;
	cin >> num;
	vector<int> output;
	int *numArr = new int[num];
	for (i = 0; i < num; i++) {
		cin >> numArr[i];
	}

	bool result = IsBST(numArr, 0, num-1, output);
	if (result) {
		cout << "YES" << endl;;
		//cout << output.size();
		for (i = 0; i < output.size(); i++) {
			cout << output[i];
			if (i < output.size() - 1) {
				cout << " ";
			}
		}
	}
	else {
		result = IsMirrBST(numArr, 0, num - 1, output);
		if (result) {
			cout << "YES" << endl;
			//cout << output.size();
			for (i = 0; i < output.size(); i++) {
				cout << output[i];
				if (i < output.size() - 1) {
					cout << " ";
				}
			}
		}
		else {
			cout << "NO";
		}
	}

	system("pause");
    return 0;
}

