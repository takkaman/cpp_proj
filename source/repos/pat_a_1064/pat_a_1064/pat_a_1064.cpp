#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> in, level;

void LevelOrder(int start, int end, int index) {
	if (start > end) return;
	// int root, l, leaf, n;
	int n = end - start + 1;
	int l = log((float) n+1)/log((float) 2);
	int leaf = n - (int) pow((float) 2, l) + 1;
	int root = start + (int) pow((float) 2, l-1) - 1 + min(leaf, (int) pow((float) 2, l-1));
	// cout << n << " " << l << " " << leaf << endl;
	level[index] = in[root];
	LevelOrder(start, root-1, 2*index+1);
	LevelOrder(root+1, end, 2*index+2);
}

int main() {
	int n, i;
	cin >> n;
	in.resize(n);
	level.resize(n);

	for (i= 0; i < n; i++) {
		cin >> in[i];
	}

	sort(in.begin(), in.end());
	LevelOrder(0, n-1, 0);

	for (i = 0; i < n; i++) {
		cout << level[i];
		if (i < n - 1) {
			cout << " ";
		};
	}

	system("pause");
	return 0;
}