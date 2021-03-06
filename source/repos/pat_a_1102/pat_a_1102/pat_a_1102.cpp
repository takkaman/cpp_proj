// pat_a_1102.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <sstream>
#include <queue>
using namespace std;

struct Node {
	int parent;
	int id;
	int left;
	int right;
}node;

queue<Node> q;

void InOrder(int mr, int root, Node *nodeTree) {
	if (root == -1) return;
	InOrder(mr, nodeTree[root].right, nodeTree);
	if (root != mr) cout << " ";
	cout << root;
	InOrder(mr, nodeTree[root].left, nodeTree);
}

int main()
{
	int num, i, left, right;
	cin >> num;
	string inputl, inputr;
	Node *nodeTree = new Node[num];
	for (i = 0; i < num; i++) {
		Node node = { -1, i, -1, -1 };
		nodeTree[i] = node;
	}
	for (i = 0; i < num; i++) {
		cin >> inputl >> inputr;
		if (inputl != "-") {
			stringstream ss1;
			ss1 << inputl;
			ss1 >> left;
			nodeTree[i].left = left;
			nodeTree[left].parent = i;
		}
		if (inputr != "-") {
			stringstream ss2;
			ss2 << inputr;
			ss2 >> right;
			nodeTree[right].parent = i;
			nodeTree[i].right = right;
		}
	}

	i = 0;
	while(nodeTree[i].parent != -1) {
		i = nodeTree[i].parent;
	}

	// cout << "root: " << i;
	q.push(nodeTree[i]);
	while (!q.empty()) {
		Node n = q.front();
		if (n.id != i) { cout << " "; }
		cout << n.id;
		if (n.right != -1) { 
			q.push(nodeTree[n.right]); 
		}
		if (n.left != -1) {
			q.push(nodeTree[n.left]);
		}
		q.pop();
	}
	cout << endl;

	int j = i;
	while (nodeTree[j].right != -1) {
		j = nodeTree[j].right;
	}
	// cout << j << endl;
	InOrder(j, i, nodeTree);

	system("pause");
    return 0;
}

