#include "bits/stdc++.h"
using namespace std;

int a[10][10], visited[10][10];
vector<pair<int, int>> virus, wall;
const int dy[4] = { -1,0,1,0 };
const int dx[4] = { 0,-1,0,1 };
int n, m, ret;
void dfs(int y, int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || a[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx);
    }

    return;
}

int go() {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);
    for (auto c : virus) {
        visited[c.first][c.second] = 1;
        dfs(c.first, c.second);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0 && !visited[i][j]) cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) virus.push_back({ i,j });
            if (a[i][j] == 0) wall.push_back({ i,j });
        }
    }

    for (int i = 0; i < wall.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                a[wall[i].first][wall[i].second] = 1;
                a[wall[j].first][wall[j].second] = 1;
                a[wall[k].first][wall[k].second] = 1;
                ret = max(ret, go());
                a[wall[i].first][wall[i].second] = 0;
                a[wall[j].first][wall[j].second] = 0;
                a[wall[k].first][wall[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";
    return 0;
}