#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector<int> inorder;
int index = 0;

struct node{
	int id;
	int left;
	int right;
	int val;
};

void InOrder(int root, node* &tree) {
	if (root == -1) return;
	InOrder(tree[root].left, tree);
	tree[root].val = inorder[index++];
	//printf("%d %d %d\n", root, tree[root].left, tree[root].right);
	InOrder(tree[root].right, tree);
	return;
}

int main() {
	int i, n, l, r;
	cin >> n;
	node *tree = new node[n];
	for (i = 0; i < n; i++) {
		cin >> l >> r;
		tree[i].id = i;
		tree[i].left = l;
		tree[i].right = r;
	}

	for(i = 0; i < n; i++) {
		int num;
		cin >> num;
		inorder.push_back(num);
	}
	
	//for (i = 0; i < n; i++) {
	//	cout << inorder[i];
	//}

	sort(inorder.begin(), inorder.end());
	InOrder(0, tree);

	//for(i = 0; i < n; i++) {
	//	cout << tree[i].id << " " << tree[i].val << endl;
	//}
	queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int o = q.front();
		cout << tree[o].val;
		n--;
		if (n > 0) {
			cout << " ";
		}
		if (tree[o].left != -1)
			q.push(tree[o].left);
		if (tree[o].right != -1)
			q.push(tree[o].right);
		q.pop();
	}

	system("pause");
	return 0;
}