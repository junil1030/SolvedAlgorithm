#include "bits/stdc++.h"
using namespace std;

int T;
int m, n, k;
bool mmap[52][52];
bool visited[52][52];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,-1,0,1 };
int cnt;
int ny, nx;
void dfs(int y, int x)
{
	visited[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m)	continue;
		if (mmap[ny][nx] == true && !visited[ny][nx])
			dfs(ny, nx);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--)
	{
		cnt = 0;
		cin >> m >> n >> k;

		memset(mmap, 0, sizeof(mmap));
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			mmap[b][a] = true;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mmap[i][j] == true && !visited[i][j])
				{
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}