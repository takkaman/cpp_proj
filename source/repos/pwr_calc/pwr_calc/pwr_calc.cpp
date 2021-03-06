// pwr_calc.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include <sstream>
#include <stdlib.h>
using namespace std;

void add(const string a, const string b) {
	int carry=0, sum, i;
	string s_long, s_short;
	if (a.size() > b.size()) {
		s_long = a;
		s_short = b;
	}
	else {
		s_long = b;
		s_short = a;
	}
	int *p = new int[s_long.size()+1];

	for (i = 0; i < s_short.size(); i++) {
		stringstream ss1, ss2;
		int c1, c2;
		ss1 << s_long[s_long.size()-1-i];
		ss1 >> c1;
		ss2 << s_short[s_short.size()-1-i];
		ss2 >> c2;
		sum = c1 + c2 + carry;
		carry = sum / 10;
		p[i] = abs(sum) % 10;
	}

	for (i = s_short.size(); i < s_long.size(); i++) {
		stringstream ss1;
		int c1;
		ss1 << s_long[s_long.size()-1-i];
		ss1 >> c1;
		sum = c1 + carry;
		carry = sum / 10;
		p[i] = abs(sum) % 10;
	}
	p[s_long.size()] = carry;
	for (i = s_long.size()-1; i >= 0; i--) {
		cout << p[i];
	}
	if (p[s_long.size()] > 0) cout << p[s_long.size()];
}

void sub(const string a, const string b) {

}

int main()
{
	string a, b;
	cin >> a >> b;
	add(a,b);

	system("pause");
    return 0;
}

