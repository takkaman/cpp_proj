// Zero-complexity Transposition.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;
#include "vector"

int main()
{
	int n, x;
	while (cin >> n) {
		vector <int> arr;
		while (n--) {
			cin >> x;
			arr.push_back(x);
		}

		for (int j = arr.size() - 1; j >= 0; j--) {
			cout << arr[j];
			if (j) {
				cout << " ";
			}
			else {
				cout << endl;
			}
		}
	}
	system("pause");
    return 0;
}

