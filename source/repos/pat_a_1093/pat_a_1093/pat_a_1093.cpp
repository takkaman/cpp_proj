// pat_a_1093.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int FindStr(string s, string pt, long start, long end, long long &delta, long long &cnt) {
	// cout << pt << " " << start << " " << end << " " << cnt << endl;
	long i, pos = 0;
	int flag = 0;
	if (pt.length() == 1) {
		for (i = start; i <= end; i++) {
			string cmp = { s[i] };
			if (pt == cmp) {
				if (!flag) {
					flag = 1;
					pos = i;
				}
				delta++;
				cnt++;
			}
		}
	}
	else {
		i = start;
		long prev = -1;
		long long t;
		while (i <= end) {
			if (s[i] == pt[0]) {
				if (!flag) {
					pos = i;
					flag = 1;
				}
				//cout << i << " " << s[i] << " " << pt[0] << " " << pt.substr(1, pt.length() - 1) << " " << prev << endl;
				if (i < prev) {
					//cout << "not need search " << s[i] << " " << "t: " << t <<"cnt: " << cnt << endl;
					cnt += t;
				}
				else {
					long long delta = 0;
					t = cnt;
					prev = FindStr(s, pt.substr(1, pt.length() - 1), i + 1, end, delta, cnt);
					t = cnt - t;
					//cout << "prev: " << prev << "delta: " << delta << endl;
				}
			}
			i++;
		}
	}

	//cout << "pos: " << pos << endl;
	return pos;
}

int main()
{
	string input, pt = "PAT";
	cin >> input;
	long long cnt = 0, delta = 0;
	FindStr(input, pt, 0, input.length() - 1, delta, cnt);

	cout << cnt % 1000000007;

	system("pause");
    return 0;
}

