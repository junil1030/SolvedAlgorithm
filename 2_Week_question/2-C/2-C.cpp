#include "bits/stdc++.h"
using namespace std;

int n, a[102][102];
bool visited[102][102];
int maxRain = INT_MIN;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int result;

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (a[ny][nx] > maxRain && visited[ny][nx] == false)
			dfs(ny, nx);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;
			cin >> temp;
			a[j][i] = temp;
			maxRain = max(maxRain, temp);
		}
	}
	while (maxRain--) {
		int ret = 0;
		fill(&visited[0][0], &visited[0][0] + 102 * 102, false);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i][j] > maxRain && visited[i][j] == false) {
					dfs(i, j);
					ret++;
				}
			}
		}
		result = max(result, ret);
	}

	cout << result;
	return 0;
}