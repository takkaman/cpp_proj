#include <iostream>
#include <algorithm>
using namespace std;

int pos[201], arr[10001], dp[10001];
int maxl = 0;
int main() {
	fill(dp, dp+10001, 0);
	int k, n, i, j, m;
	cin >> k;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> m;
		pos[m] = i;
	}
	int l, index = 0;
	cin >> l;
	for (i = 0; i < l; i++) {
		cin >> m;
		if (pos[m] >= 1) {
			arr[index++] = pos[m];
		}
	}

	for (i = 0; i < index; i++) {
		dp[i] = 1;
		for (j = 0; j < i; j++) {
			if (arr[i] >= arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		maxl = max(dp[i], maxl);
	}

	cout << maxl;

	system("pause");
	return 0;
}

		
