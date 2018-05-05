#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <sstream>
using namespace std;

struct prior{
	int isp;
	int icp;
};

map<char, prior> opmap;
stack<char> op;
stack<float> num;

void operation(char op) {
	float a, b;
	a = num.top();
	num.pop();
	b = num.top();
	num.pop();
	// cout << b << " " << op << " " << a << endl;
	if (op == '+') {
		num.push(b+a);
	} else if (op == '-') {
		num.push(b-a);
	} else if (op == '*') {
		num.push(b*a);
	} else if (op == '/') {
		num.push(b/a);
	}
}

int main() {
	int i;
	prior sharp = {0, 0};
	prior bkl = {1, 6};
	prior bkr = {6, 1};
	prior mult = {5, 4};
	prior divd = {5, 4};
	prior plus = {3, 2};
	prior minus = {3, 2};
	
	opmap['#'] = sharp;
	opmap['('] = bkl;
	opmap[')'] = bkr;
	opmap['*'] = mult;
	opmap['/'] = divd;
	opmap['+'] = plus;
	opmap['-'] = minus;

	string line;
	getline(cin, line);

	op.push('#');
	int number = 0;
	for(i = 0; i < line.length(); i++) {
		if (line[i] >= '0' && line[i] <= '9') {
			float digit = (float) line[i] - '0';
			number = number*10 + digit;

		} else {
			num.push(number);
			number = 0;
			char opin = line[i];
			//cout << opmap[opin].isp << " " << opmap[op.top()].icp << endl;
			while(opmap[opin].icp <= opmap[op.top()].isp) {
				char ops = op.top();
				operation(ops);
				op.pop();
			}
			op.push(opin);
		}
	}
	num.push(number);

	while(!op.empty()){
		if (op.top() == '#') break;
		//cout << op.top();
		operation(op.top());
		op.pop();
	}

	printf("%.0f", num.top());

	system("pause");
	return 0;
}