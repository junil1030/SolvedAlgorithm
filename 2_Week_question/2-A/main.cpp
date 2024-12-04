#include "bits/stdc++.h"
using namespace std;

int N, M;
int a[104][104];
int visited[104][104];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &a[i][j]);
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = 1;
	while (q.size())
	{
		pair<int, int> location = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = location.first + dy[i];
			int nx = location.second + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || a[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[location.first][location.second] + 1;
			q.push({ ny,nx });
		}
	}

	cout << visited[N-1][M-1];
	return 0;
}