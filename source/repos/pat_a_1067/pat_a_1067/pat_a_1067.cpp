// pat_a_1067.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include "iostream"
#include <map>
#include <vector>
using namespace std;

//map<int, int> numMap;
//vector<int> remain;

int main()
{
	int n, i = 0, pos, tar, tmp, count = 0;
	int left = 0;
	cin >> n;
	int *numArr = new int[n];
	int *remain1 = new int[n];
	int *numMap = new int[n];
	int min_pos = n; // find 1st incorrect position, find next incorrect from here to reduce search time
	for (i = 0; i < n; i++) {
		cin >> tmp;
		numArr[i] = tmp;
		if (tmp != i) {
			left++;
			//remain.push_back(tmp);
			remain1[tmp] = 1;
			if (tmp < min_pos && tmp != 0) {
				min_pos = tmp;
			}
		}
		else {
			remain1[tmp] = 0;
		}
		numMap[tmp] = i;
	}
	//cout << left << endl;
	//system("pause");
	//return 0;
	while (left > 1) {
		while (numMap[0] != 0) {
			pos = numMap[0];
			tar = numMap[pos];
			tmp = numArr[pos];
			numArr[pos] = numArr[tar];
			numArr[tar] = tmp;
			//for (vector<int>::iterator iter = remain.begin(); iter != remain.end();) {
			//	if (*iter == pos) {
			//		remain.erase(iter);
			//		break;
			//	}
			//	else {
			//		iter++;
			//	}
			//}
			remain1[pos] = 0;
			numMap[0] = tar;
			count++;
			left--;
			//printf("Step: %d, pos: %d, left: %d", count, pos, left);
			//cout << endl;
			//for (i = 0; i < n; i++) {
			//	cout << numArr[i] << " ";
			//}
			//cout << endl;
		}
		if (left > 1) {
			pos = numMap[0];
			i = min_pos;
			while (remain1[i] == 0) i++;
			tmp = i;
			min_pos = i;
			tar = numMap[tmp];
			numMap[tmp] = pos;
			tmp = numArr[pos];
			numArr[pos] = numArr[tar];
			numArr[tar] = tmp;
			numMap[0] = tar;
			
			count++;
			//printf("Step: %d, pos: %d, left: %d", count, tar, left);
			//cout << endl;
			//for (i = 0; i < n; i++) {
			//	cout << numArr[i] << " ";
			//}
			//cout << endl;
		}
	}
	cout << count << endl;
	system("pause");
    return 0;
}

