// pat_a_1059.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct NumCnt {
	unsigned long num;
	int cnt;
}numc;

map<unsigned long, int> factMap;
vector<NumCnt> factList;

bool cmp(NumCnt a, NumCnt b) {
	return a.num < b.num;
}

bool IsPrim(unsigned long num) {
	for (long i = 2; i < sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void CalcPrim(unsigned long num, map<unsigned long, int> &factMap) {
	unsigned long i;
	// cout << num << endl;
	for (i = 2; i <= sqrt(num); i++) {
		if (IsPrim(i)) {
			if (num % i == 0) {
				if (factMap.find(i) != factMap.end()) {
					factMap[i] += 1;
				}
				else {
					factMap[i] = 1;
				}
				CalcPrim(num / i, factMap);
				return;
			}
		}
	}
	if (factMap.find(num) != factMap.end()) {
		factMap[num] += 1;
	}
	else {
		factMap[num] = 1;
	}
	return;
}

int main()
{
	unsigned long num;
	cin >> num;
	if (num == 1) {
		cout << "1=1";
		return 0;
	}
	CalcPrim(num, factMap);
	for (auto &v : factMap) {
		NumCnt numc = { v.first, v.second };
		factList.push_back(numc);
	}

	cout << num << "=";
	for (int i = 0; i < factList.size(); i++) {
		NumCnt p = factList[i];
		if (p.cnt > 1) {
			cout << p.num << "^" << p.cnt;
		}
		else {
			cout << p.num;
		}
		if (i != factList.size() - 1) {
			cout << "*";
		}
	}
	system("pause");
    return 0;
}

