// pat_a_1104.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int num, i, j, k;
	cin >> num;
	double sum = 0.0;
	double *numArr = new double[num+1];
	for (i = 1; i <= num; i++) {
		cin >> numArr[i];
		sum += numArr[i] * i * (num - i + 1);
	}

	//for (i = 0; i < num; i++) {
	//	for (j = i; j < num; j++) {
	//		for (k = i; k <= j; k++) {
	//			sum += numArr[k];
	//		}
	//	}
	//}


	printf("%.2f", sum);

	system("pause");
    return 0;
}

