#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;
struct node {
	int root;
	int count;
};
map<int, int> m;
vector<node> v;
vector<int> interest[1001];
vector<int> fa;
int Find(int a) {
	if (a != fa[a])
		fa[a] = Find(fa[a]);
	return fa[a];
}
void Union(int a, int b) {
	int aa = Find(a);
	int bb = Find(b);
	// printf("%d: %d %d: %d\n", a, aa, b, bb);
	if (aa != bb) {
		fa[bb] = aa;
	}
	return;
}
bool cmp(node a, node b) {
	return a.count > b.count;
}
int main() {
	int num, i;
	cin >> num;
	// fa.resize(num);
	for (i = 0; i < num; i++) {
		int k = i;
		fa.push_back(k);
	}
	for(i = 0; i < num; i++) {
		string cc;
		int l;
		cin >> cc;
		stringstream ss;
		ss << cc.substr(0, cc.length() - 1);
		ss >> l;
		for (int j = 0; j < l; j++) {
			int k;
			cin >> k;
			interest[k].push_back(i);
		}
	}
	for(i = 1; i <= 1000; i++) {
		int l = interest[i].size();
		if (l >= 2) {
			int a = interest[i][0];
			for (int j = 1; j < l; j++)
				Union(a, interest[i][j]);
		}
	}
	for (i = 0; i < num; i++) {
		int f = Find(i);
		if (m.find(f) != m.end()) {
			m[f]++;
		} else {
			m[f] = 1;
		}
	}
	for(map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++) {
		 node e = {iter->first, iter->second};
		 v.push_back(e);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << endl;
	for (i = 0; i < v.size(); i++) {
		cout << v[i].count;
		if (i < v.size() - 1)
			cout << " ";
	}
	system("pause");
	return 0;
}