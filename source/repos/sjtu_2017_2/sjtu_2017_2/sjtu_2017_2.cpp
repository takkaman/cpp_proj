#include <iostream>
#include <string>
using namespace std;

int toggle(int flag) {
	if (flag == 1) return -1;
	if (flag == -1) return 1;
}

bool Match(int flag, int prev, int curr) {
	if (curr > prev && flag == 1) return true;
	if (curr < prev && flag == -1) return true;
	return false;
}


int MaxZZ(int *arr, int start, int end) {
	if (start > end) return 0;
	if (start == end) return 1;
	int maxlen = 1, i = 0, flag;
	if (arr[start] == arr[start+1]) {
		return MaxZZ(arr, start+1, end);
	} else {
		if (arr[start] > arr[start+1]) {
			flag = -1;
		} else {
			flag = 1;
		}
		i = start + 2;
		maxlen++;
		while (Match(toggle(flag), arr[i-1], arr[i]) && i <= end) {
			maxlen++;
			i++;
			flag = toggle(flag);
		}
		if (i <= end) {
			return max(maxlen, MaxZZ(arr, i - 1, end));
		}
	}

	return maxlen;
}

int main(int argc, const char* argv[]) {
	int i, n;
	cin >> n;
	int *arr = new int[n];
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << MaxZZ(arr, 0, n-1);

	system("pause");
	return 0;
}