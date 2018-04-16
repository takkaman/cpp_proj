#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<string> output;
int n, d, l;

string IsPopSeq(int *arr, int *list, int n, int d) {
	string result = "YES";
	stack<int> s;
	int i = 0;
	int posa = 0, posl = 0;
	while(!s.empty() || posl < n ) {
		if (s.empty()) {
			s.push(list[posl]);
			posl++;
		} else {
			if (s.size() > d) {
				result = "NO";
				break;
			}
			int a = s.top();
			if (a == arr[posa]) {
				s.pop();
				posa++;
			} else {
				if (posl == n) {
					result = "NO";
					break;
				} else {
					s.push(list[posl]);
					posl++;
				}
			}
		}
	}

	return result;
}

int main() {
	int i, j;
	cin >> d >> n >> l;
	int *list = new int[n];
	for (i = 0; i < n; i++) {
		list[i] = i + 1;
	}

	for (i = 0; i < l; i++) {
		int *arr = new int[n];
		for (j = 0; j < n; j++) {
			cin >> arr[j];
		}
		string result = IsPopSeq(arr, list, n, d);
		output.push_back(result);
	}

	for (i = 0; i < l; i++) {
		cout << output[i] << endl;
	}

	system("pause");
	return 0;
}

// gold
/*
C++

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    for(int i = 0; i < k; i++) {
        bool flag = false;
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1; j <= n; j++)
            scanf("%d", &v[j]);
        int current = 1;
        for(int j = 1; j <= n; j++) {
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[current]) {
                s.pop();
                current++;
            }
        }
        if(current == n + 1) flag = true;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
*/