#include "bits/stdc++.h"
using namespace std;

int m, n, k;
int a[102][102];
bool visited[102][102];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int dfs(int y, int x) {
	visited[y][x] = true;
	int area = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (a[ny][nx] == 0 && visited[ny][nx] == false) {
			area += dfs(ny, nx);
		}
	}
	return area;
}

int main() {
	cin >> m >> n >> k;
	int x1, y1, x2, y2;
	while (k--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1; i < y2; i++) {
			for (int j = x1; j < x2; j++) {
				a[i][j] = 1;
			}
		}
	}

	vector<int> v;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && visited[i][j] == false) {
				v.push_back(dfs(i, j));
			}
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for (auto n : v)
		cout << n << " ";
	return 0;
}