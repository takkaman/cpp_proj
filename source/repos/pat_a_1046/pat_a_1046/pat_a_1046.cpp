// pat_a_1046.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int CalcDistance(int *numArr, int start, int end, int len) {
	int sum = 0, i = start;
	while(i != end) {
		sum += numArr[i-1];
		i++;
		if (i == len+1) i = 1;
	}

	return sum;
}

int main()
{
	int len, i, dist, input, start, end;
	vector<int> result;
	cin >> len;
	int *numArr = new int[len];

	for (i = 0; i < len; i++) {
		cin >> numArr[i];
	}

	cin >> input;
	while (input-- > 0) {
		cin >> start >> end;
		int val = min(CalcDistance(numArr, start, end, len), CalcDistance(numArr, end, start, len));
		result.push_back(val);
	}

	for (auto &v : result) {
		cout << v << endl;
	}

	system("pause");
    return 0;
}

