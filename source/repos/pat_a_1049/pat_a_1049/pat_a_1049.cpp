// pat_a_1049.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int CntOnes(int num, int div) {
	if (num == 0) return 0;
	if (div == 1) return 1;
	
	int new_div = div;
	int val = num % div;
	if (val == 0) {
		new_div = 1;
	}
	else {
		while (val / new_div == 0) {
			new_div /= 10;
		}
	}
	if (num / div == 1) {
		return num % div + 1 + CntOnes(val, new_div) + CntOnes(div - 1, div / 10) * (num / div);
	}
	else {
		return div + CntOnes(val, new_div) + CntOnes(div - 1, div / 10) * (num / div);
	}

}

int main()
{
	int num, div = 1000000000;
	cin >> num;
	while (num / div == 0) {
		div /= 10;
	}
	// cout << div;
	cout << CntOnes(num, div);
	system("pause");
    return 0;
}

