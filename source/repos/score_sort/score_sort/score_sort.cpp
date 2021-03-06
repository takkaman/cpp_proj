// score_sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "string"
#include "algorithm"
#include "vector"
using namespace std;

struct student
{
	string name;
	int score;
};

bool cmp1(const student s1, const student s2);
bool cmp2(const student s1, const student s2);

bool cmp1(const student s1, const student s2) {
	return s1.score > s2.score;
}

bool cmp2(const student s1, const student s2) {
	return s1.score < s2.score;
}

int main()
{
	int n, type;
	while (cin >> n >> type) {
		int i;
		printf("%d, %d", n, type);
		vector<student> s(n);
		for (i = 0; i < n; i++) {
			printf("enter no.%d info\n", i);
			cin >> s[i].score >> s[i].name;
		}
		if (type == 0) {
			stable_sort(s.begin(), s.end(), cmp1);
		}
		else if (type == 1) {
			stable_sort(s.begin(), s.end(), cmp2);
		}
		for (i = 0; i < n; i++) {
			cout << s[i].name << s[i].score << "\n";
		}
	}
	// system("pause");
    return 0;
}

