#include "bits/stdc++.h"
using namespace std;

// sudo코드
// DFS(u, adj)
//		u.visited = 1
//		for u : adj[u]
//			if(u.visited == 0)
//				DFS(u, adj)

vector<int> adj[5];
int visited[5];
void dfs(int u) {
	visited[u] = 1;
	cout << u << '\n';
	for (int v : adj[u]) {
		if (visited[v] == 0)
			dfs(v);
	}
	cout << u << "로부터 시작된 함수가 종료되었습니다.\n";
	return;
}

int main() {
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[2].push_back(5);
	adj[4].push_back(2);

	dfs(1);
}