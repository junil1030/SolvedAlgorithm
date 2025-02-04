#include "bits/stdc++.h"
using namespace std;

int n, root, r;
vector<int> adj[54];
int cnt;
int go(int here) {
	int ret = 0;
	int child = 0;
	for (int a : adj[here]) {
		if (a == r) continue;
		ret += go(a);
		child++;
	}
	if (child == 0) return 1;
	return ret;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == -1)
			root = i;
		else {
			adj[num].push_back(i);
		}
	}

	cin >> r;
	if (r == root) {
		cout << 0 << "\n";
		return 0;
	}
	cout << go(root) << "\n";
	return 0;
}