// pat_a_1038.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	string a1 = a + b;
	string b1 = b + a;
	return atol(a1.c_str()) < atol(b1.c_str());
}

int main()
{
	int num, i;
	cin >> num;
	string *numArr = new string[num];
	string output = "";
	for (i = 0; i < num; i++) {
		cin >> numArr[i];
	}
	sort(numArr, numArr + num, cmp);
	for (i = 0; i < num; i++) {
		output += numArr[i];
	}
	cout << atoll(output.c_str());
	system("pause");
    return 0;
}

