// pat_a_1078.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

bool IsPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) return false;
	}
	return true;
}

int main()
{
	int size, num, i, j, input, pos;
	cin >> size >> num;
	int *result = new int[num];
	for (i = 0; i < num; i++) {
		result[i] = -1;
	}
	while (!IsPrime(size)) {
		size++;
	}
	int *arr = new int[size];
	for (i = 0; i < size; i++) {
		arr[i] = 0;
	}
	for (i = 0; i < num; i++) {
		cin >> input;
		pos = input % size;
		// unsigned long pos = tmp;
		int flag = 1;
		j = 1;
		while (flag && j < size) {
			//cout << tmp + pos << endl;
			if (!arr[pos]) {
				result[i] = pos;
				arr[pos] = 1;
				flag = 0;
			}
			else {
				pos = (input + j*j) % size;
				//cout << pos << endl;
				j++;
			}
		}
	}

	for (i = 0; i < num; i++) {
		if (result[i] == -1) {
			cout << "-";
		}
		else {
			cout << result[i];
		}

		if (i != num - 1) {
			cout << " ";
		}
	}

	//if (IsPrime(10001)) cout << "AAA";

	system("pause");
    return 0;
}

