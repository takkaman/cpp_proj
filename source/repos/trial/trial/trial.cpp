// trial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

bool check(int input)
{
	if (input >= 10) {
		printf("True!!");
		return true;
	}
	else {
		printf("False!");
		return false;
	}
}

int main()
{
	printf("aaa");
	check(19);
	system("pause");
    return 0;
}

