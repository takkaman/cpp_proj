// pat_a_1037.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nc, np, i, j;
	long val = 0;
	cin >> nc;
	int *coup = new int[nc];
	for (i = 0; i < nc; i++) {
		cin >> coup[i];
	}
	sort(coup, coup + nc);
	cin >> np;
	int *prod = new int[np];
	for (i = 0; i < np; i++) {
		cin >> prod[i];
	}
	sort(prod, prod + np);
	i = 0; j = 0;
	while (coup[i] < 0 && prod[j] < 0 && i < nc && j < np) {
		val += coup[i] * prod[j];
		i++; j++;
	}
	i = nc - 1; j = np - 1;
	while (coup[i] > 0 && prod[j] > 0 && i >= 0 && j >= 0) {
		val += coup[i] * prod[j];
		i--; j--;
	}
	cout << val;
	system("pause");
    return 0;
}

