// pat_a_1020.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stdio.h>
#define MAX 100000
using namespace std;

struct Node {
	long left;
	long right;
};

long GetTree(long *post, long *in, Node *arr, long pstart, long pend, long istart, long iend) {
	if (istart > iend) return -1;
	long root, i = istart;
	root = post[pend];
	// cout << root << endl;
	while (in[i] != root) {
		i++;
	}
	// cout << i << endl;
	arr[root].left = GetTree(post, in, arr, pstart, pstart + i - istart - 1, istart, i - 1);
	arr[root].right = GetTree(post, in, arr, pend - 1 - iend + i + 1, pend - 1, i + 1, iend);
	return root;
}

int main()
{
	long n, i, root, j;
	cin >> n;
	Node *arr = new Node[MAX];
	long *post = new long[n];
	long *in = new long[n];

	for (i = 0; i < n; i++) {
		cin >> j;
		post[i] = j - 1;
	}
	for (i = 0; i < n; i++) {
		cin >> j;
		in[i] = j - 1;
	}

	root = GetTree(post, in, arr, 0, n-1, 0, n-1);
	queue<long> level;
	level.push(root);
	while (!level.empty()) {
		long node = level.front();
		printf("%d", node + 1);
		//cout << node << " " << n << " " << arr[node].left << " " << arr[node].right << endl;
		n--;
		
		if (n > 0) {
			cout << " ";
		}
		if (arr[node].left != -1) {
			level.push(arr[node].left);
		}
		if (arr[node].right != -1) {
			level.push(arr[node].right);
		}
		level.pop();
	}

	system("pause");
    return 0;
}

