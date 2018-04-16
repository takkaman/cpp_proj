#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {

	int n, i, j;
	cin >> n;
	int max = (int) sqrt((double) n);
	int len;
	// cout << max;
	for (len = 12; len >= 1; len--) {
		for (i = 2; i <= max - len + 1; i++) {
			long long val = 1;
			for (j = i; j <= i + len -1; j++) {
				val *= j;
			}
			if ( n % val == 0) {
				cout << len << endl;
				cout << i;
				while(++i<=j-1) {
					cout << "*" << i;  q
				}
				system("pause");
				return 0;
			}
		}
	}

	printf("1\n%d", n);

	system("pause");
	return 0;
}