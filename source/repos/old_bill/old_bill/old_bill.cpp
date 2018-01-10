// old_bill.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

struct bill {
	int count;
	int x, y, z;
};

int main()
{
	vector <bill > arr;
	int n, x, y, z;
	
	//char bill[6];
	while (cin >> n >> x >> y >> z) {
		bill new_bill;
		new_bill.count = n;
		new_bill.x = x;
		new_bill.y = y;
		new_bill.z = z;
		arr.push_back(new_bill);
	}
	//cout << arr.size() << endl;
//	cin.get();
//	cin.getline(bill, 6);
	//cout << n << x << y << z << "\n";
	for (int k = 0; k < arr.size(); k++) {
		int flag = 1, price, val_i = 0, val_j = 0;
		//cout << arr[k].count << arr[k].x << arr[k].y << arr[k].z << endl;
		for (int i = 9; i > 0 && flag; i--) {
			for (int j = 9; j >= 0 && flag; j--) {
				int val = 10000 * i + 1000 * arr[k].x + 100 * arr[k].y + 10 * arr[k].z + j;
				//cout << val%n <<"\n";
				if (val%arr[k].count == 0) {
					price = val / arr[k].count;
					val_i = i;
					val_j = j;
					flag = 0;
					//break;
				}
			}
		}
		if (val_i == 0 && val_j == 0) {
			cout << 0 << endl;
		}
		else {
			cout << val_i << " " << val_j << " " << price << endl;
		}
	}
	system("pause");
    return 0;
}

