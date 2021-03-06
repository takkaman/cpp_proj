#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

struct node {
	// int parent;
	vector<int> children;
};

int main() {
	int n, l, i, n1, last, tmplast, maxcnt = 0, maxl = 1, tmpcnt = 0, tmpl = 1;
	cin >> n >> l;
	node *list = new node[n+1];
	//for (i = 0; i <= n; i++) {
	//	list[i].children.resize(0);
	//}

	for (i = 0; i < l; i++) {
		int id, num,c;
		cin >> id >> num;
		if (i == 0) n1 = id;
		//list[id].children.resize(num);
		for (int j = 0; j < num; j++) {
			cin >> c;
			// cout << c << endl;
			// list[c].parent = id;
			list[id].children.push_back(c);
		}
		//for (int j = 0; j < list[id].children.size(); j++) {
		//	cout << list[id].children[j] << endl;
		//}
	}

	//while(list[n1].parent != -1) {
	//	n1 = list[n1].parent;
	//}
	//for (i = 0; i <list[1].children.size(); i++) {
	//	cout << list[1].children[i] << endl;
	//}

	last = 1;
	queue<int> q;
	q.push(1);

	while(!q.empty()) {
		//cout << "AAA" << endl;
		int current = q.front();
		// cout << current << endl;
		tmpcnt++;
		//cout << current << " " << tmpcnt << endl;
		//cout << list[current].children.size() << endl;
		if (list[current].children.size() > 0) {
			for (i = 0; i < list[current].children.size(); i++) {
				q.push(list[current].children[i]);
			}
			tmplast = list[current].children[i-1];
		}
		if(current == last) {
			//cout  << "last: " << last << endl;
			//cout << "tmplast: " << tmplast << endl;
			if (maxcnt < tmpcnt) {
				maxcnt = tmpcnt;
				maxl = tmpl;
			}
			tmpl++;
			tmpcnt = 0;
			last = tmplast;
		}
		q.pop();
		//cout << q.empty() << endl;
	}

	printf("%d %d", maxcnt, maxl);

	system("pause");
	return 0;
}