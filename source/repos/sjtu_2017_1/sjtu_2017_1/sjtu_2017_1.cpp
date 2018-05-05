#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int i, num = 0;
	string input;
	bool hasdigit = false, printed = false;

	getline(cin, input);

	for (i = 0; i < input.length(); i++) {
		char c = input[i];
		if (c >= '0' && c <= '9') {
			int prev = num;
			num = num*10 + (c - '0');
			int back = (num - (c - '0')) / 10;
			if (back != prev) {
				cout << "-1";
				system("pause");
				return 0;
			}
			hasdigit = true;
		} else {
			if (hasdigit) {
				cout << num;
				printed = true;
				break;
			}
		}
	}
	if (!hasdigit) {
		cout << "-1";
		system("pause");
		return -1;
	} else {
		if (!printed)
			cout << num;
	}

	system("pause");
	return 0;

}


