// factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

int factorial(const int n) {
	int fact = 1;
	for (int i = 1; i <= n; i++) {
		fact *= i;
	}
	return fact;
}

int main()
{	
	int sum, tmp_sum = 0;
	int flag = 0, is_sum = 0;
	cin >> sum;

	for (int i = 1; flag == 0; i++) {
		tmp_sum += factorial(i);
		if (tmp_sum >= sum) {
			flag = 1;
			if (tmp_sum == sum) is_sum = 1;
		}
	}
	if (is_sum) cout << "YES" << endl;
	if (!is_sum) cout << "NO" << endl;
	
	system("pause");
    return 0;
}

