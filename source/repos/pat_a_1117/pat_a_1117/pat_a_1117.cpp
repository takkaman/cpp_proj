// pat_a_1117.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) { return a > b; }

int main()
{
	int i, n, m = 0;
	cin >> n;
	int *dist = new int[n];
	for (i = 0; i < n; i++) {
		cin >> dist[i];
	}

	sort(dist, dist + n, cmp);
	for (i = 0; i < n; i++) {
		if (dist[i] <= i+1) break;
	}

	cout << i;

	system("pause");
    return 0;
}

