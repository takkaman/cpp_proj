#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
	int n, i, j, result = 0, l = 0;
	long long p;
	cin >> n >> p;
	arr.resize(n);

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	for (i = 0; i < n; i++) {
		for (j = i + result; j < n; j++) {
			if (arr[j] <= arr[i] * p) {
				l = j - i + 1;
				if (l > result) {
					result = l;
				}
			} else {
				break;
			}
		}
	}

	cout << result;

	system("pause");
	return 0;

}

