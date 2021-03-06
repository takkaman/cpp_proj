// factorial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
using namespace std;

int factorial(const int n) {
	if (n == 1) return 1;
	int fact = 1;
	for (int i = 1; i <= n-1; i++) {
		fact *= i;
	}
	return fact;
}

int isFactorialSum(int sum, int start_num) {
	int result = 0;
	if (start_num == 1 && sum != factorial(1)) return 0;
	while (!result && start_num >= 1) {
		// cout << sum - factorial(start_num) << " " << start_num - 1 << endl;
		if (sum == factorial(start_num)) {
			result = 1;
		}
		else if (sum - factorial(start_num) > 0) {
			result = isFactorialSum(sum - factorial(start_num), start_num - 1);
		}
		start_num--;	
	}
	return result;
}

int main()
{	
	vector <int> arr;

	int sum;
	while (cin >> sum) {
		arr.push_back(sum);
	}
	
	for (int i = 0; i < arr.size(); i++) {
		int max_num = 1;
		while (!(factorial(max_num) > arr[i])) {
			max_num++;
		}
		max_num--;
		// cout << max_num << endl;

		if (isFactorialSum(arr[i], max_num)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	
	system("pause");
    return 0;
}

