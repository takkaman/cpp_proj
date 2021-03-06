// pat_a_1079.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

struct Retailer {
	long long id;
	long long prod;
};

vector<Retailer> list;

int main()
{
	long long num, i, type, prod, s;
	double price, incr, sum = 0;
	cin >> num >> price >> incr;
	long long *p = new long long[num];
	p[0] = -1;
	for (i = 0; i < num; i++) {
		cin >> type;
		if (type == 0) {
			cin >> prod;
			Retailer r = { i, prod };
			list.push_back(r);
		}
		else {
			while (type--) {
				cin >> s;
				p[s] = i;
			}
		}
	}

	for (auto &v : list) {
		double base = 1;
		//cout << v.id << " " << v.prod << endl;
		for (i = v.id; i != 0; i = p[i]) {
			base *= 1 + incr / 100;
			//cout << base << endl;
		}
		sum += base * price * v.prod;
	}
	printf("%.1f", sum);
	system("pause");
    return 0;
}

