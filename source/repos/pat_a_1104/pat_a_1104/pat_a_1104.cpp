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
	float sum = 0;
	float *numArr = new float[num];
	for (i = 0; i < num; i++) {
		cin >> numArr[i];
	}

	for (i = 0; i < num; i++) {
		for (j = i; j < num; j++) {
			for (k = i; k <= j; k++) {
				sum += numArr[k];
			}
		}
	}


	printf("%.2f", sum);

	system("pause");
    return 0;
}

