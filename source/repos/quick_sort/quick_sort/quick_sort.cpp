// quick_sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int num,i,j;
	long long min, max;
	long count = 0;
	vector<long long> pivotL;
	cin >> num;
	long long *numArr = new long long[num];
	long long *maxL = new long long[num];
	long long *minL = new long long[num];

	for (i = 0; i < num; i++) {
		cin >> numArr[i];
	}

	for (i = 0; i < num; i++) {
		if (i == 0) {
			max = numArr[i];
		}
		else {
			if (max < numArr[i]) {
				max = numArr[i];
			}
		}
		maxL[i] = max;
	}

	for (i = num - 1; i >= 0; i--) {
		if (i == num - 1) {
			min = numArr[i];
		}
		else {
			if (min > numArr[i]) {
				min = numArr[i];
			}
		}
		minL[i] = min;
	}

	for (i = 0; i < num; i++) {
		if (i == 0) {
			if (numArr[i] <= minL[i + 1]) {
				count++;
				pivotL.push_back(numArr[i]);
			}
		} else if (i == num - 1) {
			if (numArr[i] >= maxL[i - 1]) {
				count++;
				pivotL.push_back(numArr[i]);
			}
		} else {
			// cout << numArr[i] << minL[i + 1] << maxL[i - 1]<< endl;
			if (numArr[i] <= minL[i + 1] && numArr[i] >= maxL[i - 1]) {
				count++;
				pivotL.push_back(numArr[i]);
			}
		}
	}

	cout << count << endl;
	for (i = 0; i < pivotL.size(); i++) {
		cout << pivotL[i];
		count--;
		if (count) {
			cout << " ";
		}
	}

	//system("pause");

    return 0;
}

