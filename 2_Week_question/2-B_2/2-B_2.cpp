#include "bits/stdc++.h"
using namespace std;

int a[52][52], visited[52][52];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int t, n, m, ret, k;
void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] == 0 || visited[ny][nx] == 1) continue;
		dfs(ny, nx);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t; 
	int x, y;
	while (t--) {
		cin >> m >> n >> k;
		fill(&a[0][0], &a[0][0] + 52 * 52, 0);
		fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
		ret = 0;
		while (k--) {
			cin >> x >> y;
			a[y][x] = 1;
		}

		int b = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if(a[i][j] && visited[i][j] == 0) {
					dfs(i, j);
					ret++;
				}
			}
		}

		cout << ret << "\n";
	}

	return 0;
}