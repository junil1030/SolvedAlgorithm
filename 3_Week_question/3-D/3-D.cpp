#include "bits/stdc++.h"
using namespace std;

int r, c;
int INF = 99999;
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
char _map[1004][1004];
int fire[1004][1004], person[1004][1004];
int ret = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	pair<int, int> personStart;
	
	queue<pair<int, int>> q;
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> _map[i][j];
			if (_map[i][j] == 'J') {
				personStart = { i, j };
			}
			else if (_map[i][j] == 'F') {
				q.push({ i, j });
				fire[i][j] = 1;
			}
		}
	}

	while (q.size()) {
		pair<int, int> top = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = top.first + dy[i];
			int nx = top.second + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0 || _map[ny][nx] == '#')continue;
			if (fire[ny][nx] != INF) continue;
			q.push({ ny, nx });
			fire[ny][nx] = fire[top.first][top.second] + 1;
		}
	}

	q.push(personStart);
	person[personStart.first][personStart.second] = 1;
	while (q.size()) {
		pair<int, int> top = q.front();
		q.pop();
		if (top.first == r - 1 || top.second == c - 1 || top.first == 0 || top.second == 0) {
			ret = person[top.first][top.second];
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = top.first + dy[i];
			int nx = top.second + dx[i];
			if (ny >= r || ny < 0 || nx >= c || nx < 0)continue;
			if (person[ny][nx] || _map[ny][nx] == '#') continue;
			if (fire[ny][nx] <= person[top.first][top.second] + 1) continue;
			q.push({ ny, nx });
			person[ny][nx] = person[top.first][top.second] + 1;
		}
	}
	cout << "------------------------------------------------------------------\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << fire[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "------------------------------------------------------------------\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << person[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------------------------------------\n";

	if (ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";
	return 0;
}

/*
 	cout << "------------------------------------------------------------------\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << fire[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------------------------------------\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << person[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "------------------------------------------------------------------\n";
5 5
#####
#J.F#
#...#
#.F.#
#...#
*/