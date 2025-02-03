#include "bits/stdc++.h"
using namespace std;

int m, n, cnt, cnt2;
int a[102][102];
int visit[102][102];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
vector<pair<int, int>> v;

void dfs(int y, int x) {
	visit[y][x] = 1;
	if (a[y][x] == 1) {
		v.push_back({ y,x });
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n || visit[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	while (true) {
		fill(&visit[0][0], &visit[0][0] + 102 * 102, 0);
		v.clear();
		dfs(0, 0);
		cnt2 = v.size();
		for (pair<int, int> b : v) {
			a[b.first][b.second] = 0;
		}
		bool flag = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] != 0) flag = 1;
			}
		}
		cnt++;
		if (!flag) break;
	}
	cout << cnt << '\n' << cnt2 << '\n';
	return 0;
}