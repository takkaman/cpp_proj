// old_bill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

int main()
{
	int n, x, y, z;
	int flag = 1, price, val_i = 0, val_j = 0;
	char bill[6];
	cin >> n >> x >> y >> z;
//	cin.get();
//	cin.getline(bill, 6);
	//cout << n << x << y << z << "\n";
	for (int i = 9; i > 0 && flag; i--) {
		for (int j = 9; j >= 0; j--) {
			int val = 10000 * i + 1000 * x + 100 * y + 10 * z + j;
			//cout << val%n <<"\n";
			if (val%n == 0) {
				price = val / n;
				val_i = i;
				val_j = j;
				flag = 0;
				break;
			}
		}
	}
	if (val_i == 0 && val_j == 0) {
		cout << 0;
	}
	else {
		cout << val_i << " " << val_j << " " << price;
	}
	system("pause");
    return 0;
}

