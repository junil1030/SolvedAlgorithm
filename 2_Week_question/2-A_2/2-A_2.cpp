#include "bits/stdc++.h"
using namespace std;

int n, m;
int a[102][102], visited[102][102];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			a[i][j] = int(s[j] - '0');
		}
	}

	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0,0 });
	while (q.size()) {
		pair<int, int> top = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = top.first + dy[i];
			int nx = top.second + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] || a[ny][nx] == 0) continue;
			visited[ny][nx] = visited[top.first][top.second] + 1;
			q.push({ ny, nx });
		}
	}

	cout << visited[n - 1][m - 1] << "\n";
	return 0;
}