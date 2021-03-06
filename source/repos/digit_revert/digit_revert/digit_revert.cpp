// digit_revert.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "sstream"
using namespace std;

int revertDigit(const int a) {
	stringstream ss, ss1;
	ss << a;
	string s1 = ss.str();
	
	int i = 0, j = s1.size() - 1;
	while (i < j) {
		swap(s1[i], s1[j]);
		i++;
		j--;
	}
	// cout << s1;
	int aa;
	ss1 << s1;
	ss1 >> aa;
	return aa;
}

bool couldRevert(const int a, const int b) {
	return revertDigit(a) + revertDigit(b) == revertDigit(a + b);
}

struct num_peer
{
	int first_num;
	int second_num;
};

int main()
{
	int n;
	cin >> n;

	vector<num_peer> s(n);

	for (int i = 0; i < n; i++) {
		cin >> s[i].first_num >> s[i].second_num;
	}

	for (int i = 0; i < n; i++) {
		if (couldRevert(s[i].first_num, s[i].second_num)) {
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
		//cout << revertDigit(s[i].first_num) << " " << revertDigit(s[i].second_num) << endl;
	}
	system("pause");
    return 0;
}

