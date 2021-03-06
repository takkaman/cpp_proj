// pat_a_1072.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <sstream>
#define MAX_DIST 10000
using namespace std;

struct Station {
	int id;
	int min;
	float avg;
};

vector<Station> result;

bool cmp(Station a, Station b) {
	if (a.min == b.min) {
		if (a.avg == b.avg) return a.id < b.id;
		return a.avg < b.avg;
	}
	return a.min > b.min;
	
}

int main()
{
	int city, gs, line, mdist, dist, i, j, k, m, n, avail;
	float avg;
	string s1, s2;
	cin >> city >> gs >> line >> mdist;
	n = city + gs;
	int **G = new int*[n];
	for (i = 0; i < n; i++) {
		G[i] = new int[n];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				G[i][j] = 0;
			}
			else {
				G[i][j] = MAX_DIST;
			}
		}
	}
	while (line--) {
		cin >> s1 >> s2 >> dist;
		stringstream ss1, ss2;
		if (s1[0] != 'G') {
			ss1 << s1;
			ss1 >> i;
			i -= 1;
		}
		else {
			ss1 << s1.substr(1, s1.length()-1);
			ss1 >> i;
			i += city - 1;
		}
		if (s2[0] != 'G') {
			ss2 << s2;
			ss2 >> j;
			j -= 1;
		}
		else {
			ss2 << s2.substr(1, s2.length() - 1);
			ss2 >> j;
			j += city - 1;
		}
		G[i][j] = dist;
		G[j][i] = dist;
	}

	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (i != j ) {
					G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
				}
			}
		}
	}

	for (i = city; i < n; i++) {
		m = MAX_DIST;
		dist = 0;
		avail = 1;
		for (j = 0; j < city; j++) {
			if (G[i][j] > mdist) {
				avail = 0;
				break;
			}
			dist += G[i][j];
			if (G[i][j] < m) {
				m = G[i][j];
			}
		}
		if (avail) {
			avg = dist / (float) city;
			//cout << dist << " " << avg << endl;
			Station s = { i, m, avg };
			result.push_back(s);
		}
		
	}

	if (result.size() == 0) {
		cout << "No Solution";
		return 0;
	}
	sort(result.begin(), result.end(), cmp);

	//for (i = 0; i < n; i++) {
	//	for (j = 0; j < n; j++) {
	//		cout << G[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	printf("G%d", result[0].id - city + 1);
	cout << endl;
	printf("%.1f %.1f", (float) result[0].min, result[0].avg);

	system("pause");
    return 0;
}

