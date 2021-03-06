// pat_a_1040.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool IsSymm(string str) {
	bool result = true;
	int i;
	int mid = (str.length() - 1) / 2;
	//cout << str.length() << endl;
	for (i = 0; i <= mid; i++) {
		if (str[i] != str[str.length() - 1 - i]) {
			result = false;
			break;
		}
	}
	//cout << result << endl;
	return result;
}

int MaxSymmLen(string str) {
	int len = 1, len_tmp, i, j;
	for (i = 0; i < str.length() - len; i++) {
		j = str.length() - 1;
		while (j > i) {
			if (str[i] == str[j]) {
				//cout << j << " " << str.substr(i, j-i+1) << endl;
				if (IsSymm(str.substr(i, j-i+1))) {
					len_tmp = j - i + 1;
					if (len_tmp > len) {
						len = len_tmp;
					}
					break;
				}
			}
			j--;
		}
	}
	return len;
}

int main()
{
	//char str[1000];
	int i = 0;
	//while ((str[i] = getchar()) != '\n') {
	//	i++;
	//}
	string str;
	//string str1 = "AAABBB";
	getline(cin, str);
	cout << MaxSymmLen(str);
	//cout << str1.substr(0, 3);
	system("pause");
    return 0;
}

