// prime_num.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include<math.h>
using namespace std;

bool isPrime(int n) {
	//cout << n << endl;
	for (int i = 2; i <= sqrt(n); i++) {
		
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	while (cin >> n) {
		int i = 2, j = 0;
		while (j != n) {
			if (isPrime(i)) j++;
			i++;
		}
		cout << i - 1 << endl;
	}


	system("pause");
    return 0;
}

