// pat_a_1050.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{	
	string line, pattern;
	getline(cin, line);
	getline(cin, pattern);
	for (int i = 0; i < line.length(); i++) {
		if (pattern.find(line[i]) == -1) {
			cout << line[i];
		}
	}

	system("pause");
    return 0;
}

