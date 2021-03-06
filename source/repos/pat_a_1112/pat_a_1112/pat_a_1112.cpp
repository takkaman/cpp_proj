#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;

map<char, int> result;
vector<char> output;
map<char, int> wordCnt;

int main()
{
	int num, i, cnt = 1;
	string input;
	cin >> num >> input;
	char c, prev = input[0];
	for (i = 1; i <= input.length(); i++) {
		if (i == input.length()) {
			c = NULL;
		}
		else {
			c = input[i];
		}
		
		if (c == prev) {
			cnt++;
		}
		else {
			int val = cnt % num;
			if (val == 0) { val = num; }
			if (wordCnt.find(prev) != wordCnt.end()) {
				wordCnt[prev] = min(val, wordCnt[prev]);
			}
			else {
				wordCnt[prev] = val;
			}
			prev = c;
			cnt = 1;
		}
	}
    
	i = 0;
	while(i < input.length()) {
		c = input[i];
		if (wordCnt[c] == num) {
			if (result.find(c) == result.end()) {
				cout << c;
				result[c] = 1;
			}
			i += num;
		}
		else {
			i++;
		}
		output.push_back(c);
	}

	cout << endl;
	for (auto &v : output) {
		cout << v;
	}

	system("pause");
	return 0;
}

