#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int inf = 99999999;

vector<int> pred[500];
vector<int> pret[500];
vector<int> pathd, temppathd, patht, temppatht;
int mindist = 0, mintime = inf, minlevel;
int start, stop;
bool visit[500];
int dist[500];
int timet[500];
int arrd[500][500], arrt[500][500];

void dfsd(int v) {
	//cout << v << endl;
	temppathd.push_back(v);
	if (v == start) {
		//cout << "Found start" << endl;
		int temptime = 0;
		for (int i = 0; i < temppathd.size() - 1; i++) {
			int prev = temppathd[i+1];
			int current = temppathd[i];
			//cout << prev << " " << current << endl;
			temptime += arrt[prev][current];
		}
		//cout << temptime << " " << mintime << endl;
		if (temptime < mintime) {
			mintime = temptime;
			pathd = temppathd;
			//for (int i = 0; i < pathd.size(); i++ ) {
				//cout << pathd[i] << " ";
			//}
			//cout << endl;
		}
		temppathd.pop_back();
		return;
	}

	for (int i = 0; i < pred[v].size(); i++) {
		dfsd(pred[v][i]);
	}
	temppathd.pop_back();
	return;
}

void dfst(int v) {
	//cout << v << endl;
	temppatht.push_back(v);
	if (v == start) {
		if (temppatht.size() < minlevel) {
			minlevel = temppatht.size();
			patht = temppatht;
		}
		temppatht.pop_back();
		return;
	}

	for (int i = 0; i < pret[v].size(); i++) {
		dfst(pret[v][i]);
	}
	temppatht.pop_back();
	return;
}

int main() {
	int n, l, i, j, k, ow, len, cost, s, d;
	cin >> n >> l;
	fill(visit, visit+500, false);
	fill(dist, dist+500, inf);
	fill(timet, timet+500, inf);

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) {
				arrd[i][j] = 0;
				arrt[j][i] = 0;
			} else {
				arrd[i][j] = inf;
				arrt[i][j] = inf;
			}
		}
	}

	for (i = 0; i < l; i++) {
		cin >> s >> d >> ow >> len >> cost;
		if (ow == 0) {
			arrd[d][s] = len;
			arrt[d][s] = cost;
		}
		arrd[s][d] = len;
		arrt[s][d] = cost;
	}

	cin >> start >> stop;

	dist[start] = 0;
	for (i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (j = 0; j < n; j++) {
			//cout << dist[j] << endl;
			if (!visit[j] && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		if (u == -1) break;
		// cout << u << endl;
		visit[u] = true;
		for (k = 0; k < n; k++) {
			if(!visit[k]) {
				if (dist[k] > dist[u] + arrd[u][k]) {
					dist[k] = dist[u] + arrd[u][k];
					pred[k].clear();
					pred[k].push_back(u);
				} else if (dist[k] == dist[u] + arrd[u][k]) {
					pred[k].push_back(u);
				}
			}
		}
	}

	dfsd(stop);
	for (i = pathd.size() - 1; i >=0; i--) {
		if (i > 0)
			mindist += arrd[pathd[i]][pathd[i-1]];
		//cout << pathd[i] << " ";
	}


	timet[start] = 0;
	fill(visit, visit+500, false);
	for (i = 0; i < n; i++) {
		int u = -1, min = inf;
		for (j = 0; j < n; j++) {
			//cout << dist[j] << endl;
			if (!visit[j] && timet[j] < min) {
				u = j;
				min = timet[j];
			}
		}
		if (u == -1) break;
		// cout << u << endl;
		visit[u] = true;
		for (k = 0; k < n; k++) {
			if(!visit[k]) {
				if (timet[k] > timet[u] + arrt[u][k]) {
					timet[k] = timet[u] + arrt[u][k];
					pret[k].clear();
					pret[k].push_back(u);
				} else if (timet[k] == timet[u] + arrt[u][k]) {
					pret[k].push_back(u);
				}
			}
		}
	}

	minlevel = n;
	dfst(stop);
	
	mintime = 0;
	for (i = patht.size() - 1; i >=0; i--) {
		if (i > 0)
			mintime += arrt[patht[i]][patht[i-1]];
		//cout << patht[i] << " ";
	}
	
	bool flag = true;
	if (pathd.size() == patht.size()) {
		for (i = 0; i < pathd.size(); i++) {
			if (pathd[i] != patht[i]) {
				flag = false;
				break;
			}
		}
	} else {
		flag = false;
	}

	if (flag) {
		printf("Distance = %d; Time = %d: %d", mindist, mintime, start);
		for (i = 1; i < pathd.size(); i++) {
			printf(" -> %d", pathd[i]);
		}
	} else {
		printf("Distance = %d: %d", mindist, start);
		for (i = pathd.size() - 2; i >= 0; i--) {
			printf(" -> %d", pathd[i]);
		}
		cout << endl;
		printf("Time = %d: %d", mintime, start);
		for (i = patht.size() - 2; i >= 0; i--) {
			printf(" -> %d", patht[i]);
		}
	}

	system("pause");
	return 0;
}

