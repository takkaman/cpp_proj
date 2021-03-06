// coincidence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;

int LongestCommSubseq(string a, string b, int a_start, int a_end, int b_start, int b_end) {
	int max = 0;
	if (a_start > a_end || b_start > b_end) return 0;
	for (int i = a_start; i <= a_end; i++) {
		int len = 0 ;
		int new_b_start = b.find(a[i], b_start);
		if (new_b_start >= 0) {
			len = 1 + LongestCommSubseq(a, b, i+1, a_end, new_b_start+1, b_end);
			if (len > max) max = len;
		}
	}
	return max;
}

int main()
{
	string a, b, a1, b1;
	while (cin >> a1 >> b1) {
		int max_len;
		a = a1; b = b1;
		if (a.length() > b.length()) {
			a = b1; b = a1;
		}
		
		max_len = LongestCommSubseq(a, b, 0, a.length()-1, 0, b.length()-1);
		cout << max_len << endl;
	}
	system("pause");
    return 0;
}

