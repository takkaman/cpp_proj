// pat_a_1058.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	string num1[3], num2[3];
	int j = 0;
	for (int i = 0; i < str1.length(); i++) {
		if (str1[i] == '.') {
			j++;
		}
		else {
			num1[j] += str1[i];
		}
	}

	j = 0;
	for (int i = 0; i < str2.length(); i++) {
		if (str2[i] == '.') {
			j++;
		}
		else {
			num2[j] += str2[i];
		}
	}

	long result[3];

	long carry = 0;
	long div[3] = { 10000000, 17, 29 };
	for (int i = 2; i >= 0; i--) {
		long tmp = atoi(num1[i].c_str()) + atoi(num2[i].c_str()) + carry;
		result[i] = tmp % div[i];
		carry = tmp / div[i];
	}

	for (int i = 0; i < 3; i++) {
		cout << result[i];
		if (i < 2) {
			cout << ".";
		}
	}
	// cout << atoi(num1[1].c_str());
	system("pause");
    return 0;
}

