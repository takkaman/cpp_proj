// freckles_kruskal.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int fa[10000];

struct edge {
	int u;
	int v;
	double len;

	// constructor 
	edge(int a, int b, double l) :u(a), v(b), len(l) {}
};

int GetFather(int a) {
	if (fa[a] != a) {
		fa[a] = GetFather(fa[a]);
	}
	return fa[a];
}

void Union(int a, int b) {
	int aa = GetFather(a);
	int bb = GetFather(b);
	//cout << "bf: " << aa << endl;
	fa[aa] = bb;
	//cout << "af: " << fa[aa] << endl;
}

//bool operator<(const edge& a, const edge& b)
//{
//	return a.len < b.len;
//}

bool cmp(edge a, edge b) {
	return a.len < b.len;
}

int main()
{
	int i, j, n, index = 0;
	double l, sum = 0, min;
	vector<edge> edges;
	cin >> n;
	double *x = new double[n];
	double *y = new double[n];
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for (i = 0; i < 10000; i++) {
		fa[i] = i;
	}

	for (i = 0; i < n; i++) {
		for (j = i + 1 ; j < n; j++) {
			if (i != j) {
				l = sqrt(abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]));
				edges.push_back(edge(i, j, l));
				// cout << i << " " << j << endl;
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	//for (auto &e : edges) {
	//	cout << e.len << endl;
	//}

	for (vector<edge>::iterator iter = edges.begin(); iter != edges.end(); iter++) {
		int uu = GetFather(iter->u);
		int vv = GetFather(iter->v);
		//cout << uu << " " << vv << endl;
		if (uu != vv) {
			//cout << iter->u << " " << iter->v << endl;
			sum += iter->len;
			Union(iter->u, iter->v);
			index++;
		}
		//cout << "after:" << GetFather(iter->u) << " " << GetFather(iter->v) << endl;
	}

	printf("%.2f", sum);
	system("pause");
    return 0;
}

