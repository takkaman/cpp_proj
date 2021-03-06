// freckles.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

struct Vec {
	int id;
	float x;
	float y;
} vec;

struct Edge{
	int u;
	int v;
	float len;
} edge;


map<int, Vec> vMap;
map<int, Vec> vMapNew;
vector<Vec> vnew;
vector<Edge> eList;

int main()
{	
	int n, i, j, k, index;
	float x, y, dist, min, sum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x >> y;
		Vec vec = { i, x, y };
		vMap[i] = vec;
	}

	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			x = abs(vMap[i].x - vMap[j].x);
			y = abs(vMap[i].y - vMap[j].y);
			dist = sqrt(x * x + y * y);
			Edge e = { i, j, dist };
			eList.push_back(e);
		}
	}

	//for (auto &e : eList) {
	//	cout << e.len << " " << e.u << " " << e.v << endl;
	//}
	
	vnew.push_back(vMap[0]);
	vMapNew[0] = vMap[0];
	while (vnew.size() != n) {
		min = -1;
		for (i = 0; i < eList.size(); i++) {
			Edge e = eList[i];
			if (vMapNew.find(e.u) != vMapNew.end() && vMapNew.find(e.v) == vMapNew.end() && e.len != -1) {
				if (min == -1) {
					min = e.len;
					index = e.v;
					k = i;
				}
				else {
					if (min > e.len) {
						min = e.len;
						index = e.v;
						k = i;
					}
				}
			}

			if (vMapNew.find(e.u) == vMapNew.end() && vMapNew.find(e.v) != vMapNew.end() && e.len != -1) {
				if (min == -1) {
					min = e.len;
					index = e.u;
					k = i;
				}
				else {
					if (min > e.len) {
						min = e.len;
						index = e.u;
						k = i;
					}
				}
			}
		}
		eList[k].len = -1;
		sum += min;
		vnew.push_back(vMap[index]);
		vMapNew[index] = vMap[index];
		//cout << "min: " << min << " Adding: " << index << endl;
	}

	printf("%.2f", sum);
	
	system("pause");
    return 0;
}

