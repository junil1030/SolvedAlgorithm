#include "bits/stdc++.h"
using namespace std;

int n, m;
int result = 9999999;
int a[52][52];
vector<pair<int, int>> house, chicken;
vector<vector<int>> chickenList;
void combi(int start, vector<int> v) {
	if (v.size() == m) {
		chickenList.push_back(v);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1)
				house.push_back({ i,j });
			else if (a[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}

	vector<int> v;
	combi(-1, v);
	for (auto cList : chickenList) {
		int ret = 0;
		for (pair<int, int> home : house) {
			int mini = 999999;
			for (int c : cList) {
				int dist = abs(home.first - chicken[c].first) + abs(home.second - chicken[c].second);
				mini = min(mini, dist);
			}
			ret += mini;
		}
		result = min(result, ret);
	}
	cout << result << "\n";
	return 0;
}