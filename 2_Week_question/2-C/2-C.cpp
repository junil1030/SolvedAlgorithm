#include "bits/stdc++.h"
using namespace std;

int ret = 1;
int maxRain = 0;
int n;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int a[102][102];
bool visited[102][102];

void dfs(int y, int x, int num)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (!visited[ny][nx] && a[ny][nx] > num)
			dfs(ny, nx, num);
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
			cin >> a[j][i];
		}
	}

	for (int num = 1; num < 101; num++)
	{
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] > num && !visited[i][j])
				{
					dfs(i, j, num);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}
	cout << ret << '\n';
	return 0;
}