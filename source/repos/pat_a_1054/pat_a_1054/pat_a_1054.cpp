// pat_a_1054.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef struct color {
	int rgb;
	int count;
}color;

map<int, int> colArr;
vector<color> colResult;

bool cmp(color a, color b) {
	return a.count > b.count;
}

int main()
{
	int m, n, i, j;
	cin >> m >> n;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++ ) {
			int tmp_col;
			cin >> tmp_col;
			if (colArr.find(tmp_col) != colArr.end()) {
				colArr[tmp_col] += 1;
			}
			else {
				colArr[tmp_col] = 1;
			}
		}
	}

	for (auto &p : colArr) {
		color a = {p.first , p.second };
		colResult.push_back(a);
	}

	sort(colResult.begin(), colResult.end(), cmp);

	//for (auto &v : colResult) {
	//	cout << v.rgb << " " << v.count << endl;
	//}

	cout << colResult[0].rgb;

	system("pause");
    return 0;
}

