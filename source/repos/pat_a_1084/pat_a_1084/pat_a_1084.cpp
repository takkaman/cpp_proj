// pat_a_1084.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

map<string, int> numMap;
vector<string> output;

int main()
{	
	string line1, line2;
	int i = 0, j = 0;
	cin >> line1 >> line2;
	while (i < line1.length() && j < line2.length()) {
		if (line1[i] != line2[j]) {
			string s = { line1[i] };
			transform(s.begin(), s.end(), s.begin(), ::toupper);
			output.push_back(s);
			//cout << s << endl;
			i++;
		}
		else {
			i++; j++;
		}
	}

	while (i++ < line1.length()) {
		string s = { line1[i] };
		output.push_back(s);
		//cout << s << endl;
	}

	for (i = 0; i < output.size(); i++) {
		if (numMap.find(output[i]) == numMap.end()) {
			cout << output[i];
			numMap[output[i]] = 1;
		}
	}

	system("pause");
    return 0;
}

