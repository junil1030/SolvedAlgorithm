#include "bits/stdc++.h"
using namespace std;
int visited[200004], _prev[200004];
int n, k, ret;
queue<int> q;
vector<int> v;
int main() {
	cin >> n >> k;
	q.push(n);
	visited[n] = 1;
	while (q.size()) {
		int here = q.front(); q.pop();
		if (here == k) {
			ret = visited[k];
			break;	
		}
		for (int next : {here - 1, here + 1, here * 2}) {
			if (next >= 200004 || next < 0 || visited[next]) continue;
			visited[next] = visited[here] + 1;
			_prev[next] = here;
			q.push(next);
		}
	}
	for (int i = k; i != n; i = _prev[i]) {
		v.push_back(i);
	}
	v.push_back(n);
	cout << ret - 1 << "\n";
	reverse(v.begin(), v.end());
	for (int i : v) cout << i << ' ';
	return 0;
}