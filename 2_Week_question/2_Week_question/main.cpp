#include "bits/stdc++.h"
using namespace std;

int N, M;
pair<int, int> startLoc;
pair<int, int> endLoc;
int m[104][104];
int visited[104][104];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> startLoc.first >> startLoc.second;
	cin >> endLoc.first >> endLoc.second;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> m[i][j];
		}
	}

	queue<pair<int, int>> q;
	visited[startLoc.first][startLoc.second] = 1;
	q.push(startLoc);
	while (q.size())
	{
		startLoc = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = startLoc.first + dy[i];
			int nx = startLoc.second + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || m[ny][nx] == 0) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[startLoc.first][startLoc.second] + 1;
			q.push({ ny,nx });
		}
	}

	cout << visited[endLoc.first][endLoc.second] << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
