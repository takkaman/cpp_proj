// pat_a_1021.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
using namespace std;

set<int> output;
vector<vector<int>> v;
bool visit[10001];
int n, maxheight = 0;
vector<int> tmp;

void dfs(int n, int h) {
	if (h > maxheight) {
		tmp.clear();
		maxheight = h;
		tmp.push_back(n);
	}
	else if (h == maxheight) {
		tmp.push_back(n);
	}
	visit[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		if (!visit[v[n][i]]) {
			dfs(v[n][i], h + 1);
		}
	}
}

int main()
{
	int i, j, h, a, b, cnt = 0, s;
	fill(visit, visit + 10001, false);
	cin >> n;
	v.resize(n + 1);
	for (i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (i = 1; i <= n; i++) {
		// cout << visit[i] << endl;
		if (!visit[i]) {
			dfs(i, 1);
			if (i == 1) {
				for (j = 0; j < tmp.size(); j++) {
					output.insert(tmp[j]);
					if (j == 0) { 
						s = tmp[j]; 
					}
				}
			}
			cnt++;
		}
	}
	if (cnt >= 2) {
		printf("Error: %d components", cnt);
	}
	else {
		tmp.clear();
		maxheight = 0;
		fill(visit, visit + 10001, false);
		dfs(s, 1);
		for (i = 0; i < tmp.size(); i++) {
			output.insert(tmp[i]);
		}
		for (auto &s : output) {
			cout << s << endl;
		}
	}

	system("pause");
    return 0;
}

