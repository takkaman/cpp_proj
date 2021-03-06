// sjtu_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int Fab1(long long num, long long *Fab) {
	int i = 1;
	while (Fab[i] <= num) {
		i++;
	}
	return Fab[i - 1];
}

int Fab2(long long num, long long *Fab) {
	int i = 1;
	while (Fab[i] <= num) {
		i++;
	}
	return Fab[i - 2];
}

int CntFabSum(long num, long prev, long long *Fab) {
	if (num == 0) return 1;
	if (num == 1 && prev != 1) return 1;
	if (num == 2) {
		if (prev == 2) return 0;
		return 1;
	}
	long num1 = Fab1(num, Fab);
	long num2 = Fab2(num, Fab);
	if (num1 != prev) {
		return CntFabSum(num - num1, num1, Fab) + CntFabSum(num - num2, num2, Fab);
	}
	else {
		return CntFabSum(num - num2, num2, Fab);
	}
}

int main()
{
	int len = 49;
	long long num, i = 1, val, cnt;
	cin >> num;
	long long  *Fab = new long long[len];
	Fab[1] = 1; Fab[2] = 2;
	for (i = 3; i <= len; i++) {
		Fab[i] = Fab[i - 1] + Fab[i - 2];
	}
	i = 0;
	while (Fab[i] <= num) {
		i++;
	}
	val = Fab[i - 1];


	cnt = CntFabSum(num, 0, Fab);
	cout << cnt;
	system("pause");
    return 0;
}

