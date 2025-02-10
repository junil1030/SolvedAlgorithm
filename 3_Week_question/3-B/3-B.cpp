#include "bits/stdc++.h"
using namespace std;

int a[52][52], visited[52][52];
int dy[] = { -1, 0 , 1, 0 };
int dx[] = { 0, 1, 0 ,-1 };
int m, n, ret;
string s;
void bfs(int y, int x) {
	fill(&visited[0][0], &visited[0][0] + 52 * 52, 0);
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y,x });
	while (q.size())
	{
		pair<int, int> front = q.front();
		q.pop();
		int curY = front.first; int curX = front.second;
		for (int i = 0; i < 4; i++) {
			int ny = curY + dy[i];
			int nx = curX + dx[i];
			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (a[ny][nx] == 0) continue;
			visited[ny][nx] = visited[curY][curX] + 1;
			q.push({ ny,nx });
			ret = max(ret, visited[ny][nx]);
		}
	}
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	cin.ignore();
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'W')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				bfs(i, j);
			}
		}
	}

	cout << ret - 1;

	return 0;
}
