// pat_a_1052.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info {
	string addr;
	int val;
	string next;
	bool flag;
}info;

bool cmp(info a, info b) {
	//if (!a.flag || !b.flag) {
	//	return a.flag > b.flag;
	//}
	return a.val<b.val;
}

int main()
{
	int num, i, val;
	string j, start;
	cin >> num >> start;
	if (num == 0) {
		cout << num << start;
		return 0;
	}
	vector<info> list;
	for (i = 0; i < num; i++) {
		info node;
		cin >> node.addr >> node.val >> node.next;
		list.push_back(node);
	}
	
	sort(list.begin(), list.end(), cmp);

	cout << num << " " << list[0].addr << endl;
	//list[0].next = "-1";
	//for (i = 1; i < num; i++) {
	//	list[i].next = list[i+1].addr;
	//}
	
	for (i = 0; i < num; i++) {
		if (i < num - 1) {
			cout << list[i].addr << " " << list[i].val << " " << list[i + 1].addr << endl;
		}
		else {
			cout << list[i].addr << " " << list[i].val << " " << "-1" << endl;
		}
	}


	system("pause");
    return 0;
}

