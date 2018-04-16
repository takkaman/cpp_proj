#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

int inf = 99999999;
int start, stop, mincost = inf;
bool visit[501];
int e[501][501], dist[501], cost[501][501];
vector<int> pre[501];
vector<int> path, tmp;

void dfs(int v) {
	int i, j;
	tmp.push_back(v);
	// cout << v << stopl;
	if (v == start) {
		int val = 0;
		for (i = 0; i < tmp.size() - 1; i++) {
			int node = tmp[i];
			int next = tmp[i+1];
			val += cost[node][next];
		}
		if (val < mincost) {
			mincost = val;
			path = tmp;
		}
		tmp.pop_back();
		return;
	}
	for (i = 0; i < pre[v].size(); i++) {
		dfs(pre[v][i]);
	}
	tmp.pop_back();
	return;
}

int main() {
	// cout << inf << stopl;
	int city, n, i, j, k, a, b, c, d;
	cin >> city >> n >> start >> stop;
	// cout << start << stop << stopl;
	fill(visit, visit+501, false);
	fill(dist, dist+501, inf);
	fill(e[0], e[0]+501*501, inf);
	dist[start] = 0;

	for (i = 0; i < n; i++) {
		cin >> a >> b >> d >> c;
		if (a == start) dist[b] = d;
		if (b == start) dist[a] = d;
		e[a][b] = d;
		e[b][a] = d;
		cost[a][b] = c;
		cost[b][a] = c;
	}

	for (i = 0; i < city; i++) {
		int u = -1; int min = inf;
		for (j = 0; j < city; j++) {
			if (!visit[j] && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		// cout << u << stopl;
		if (u == -1) break;
		visit[u] = true;

		for (k = 0; k < city; k++) {
			if(!visit[k]) {
				// cout << k << " " << dist[k] << " " << dist[u] + e[k][u] << stopl;
				if (dist[k] > dist[u] + e[k][u]) {
					dist[k] = dist[u] + e[k][u];
					pre[k].clear();
					pre[k].push_back(u);
				} else if (dist[k] == dist[u] + e[k][u]) {
					pre[k].push_back(u);
				}
			}
		}
	}

	dfs(stop);

	for (i = path.size() - 1; i >=0; i--) {
		cout << path[i] << " ";
	}
	cout << dist[stop] << " " << mincost;

	system("pause");
	return 0;
}