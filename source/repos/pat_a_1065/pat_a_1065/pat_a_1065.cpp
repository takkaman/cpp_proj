// pat_a_1065.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
	long long a, b, c;
	long long sum;
	int i, num;
	cin >> num;
	for (i = 1; i <= num; i++) {
		cin >> a >> b >> c;
		sum = a + b;
		if (a > 0 && b > 0 && sum < 0) { // should be sum < 0, pos num will not have sum = 0
			printf("Case #%d: true", i);
		}
		else if (a < 0 && b < 0 && sum >= 0) { // should be sum >= 0, neg num will have sum = 0
			printf("Case #%d: false", i);
		}
		else {
			if (sum > c) {
				printf("Case #%d: true", i);
			}
			else {
				printf("Case #%d: false", i);
			}
		}
		cout << endl;
	}
	system("pause");
    return 0;
}

