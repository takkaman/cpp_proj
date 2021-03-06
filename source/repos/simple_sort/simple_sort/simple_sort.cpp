// simple_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"
using namespace std;

void SimpleSort(int a[], int n) {
	int *p = new int[n];
	int j=0;
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int k = 0; k < n && !flag; k++) {
			if (p[k] == a[i]) flag = 1;
		}
		if (!flag) p[j++] = a[i];
	}
	sort(p, p + j);
	for (int k = 0; k < j; k++) {
		cout << p[k];
		if (k == j - 1) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}

int main()
{	
	int n;
	int a[1000];
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		SimpleSort(a, n);
	}
    return 0;
}

