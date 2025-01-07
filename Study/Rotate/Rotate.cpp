#include <bits/stdc++.h>
using namespace std;

const int n = 3;
const int m = 4;

void rotate_left_90(vector<vector<int>>& key) {
	int n = key.size();
	int m = key[0].size();
	vector<vector<int>> temp(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = key[j][m - i - 1];
		}
	}
	key.resize(m);
	key[0].resize(n);
	key = temp;
	return;
}

void rotate_right_90(vector<vector<int>>& key) {
	int n = key.size();
	int m = key[0].size();
	vector<vector<int>> temp(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = key[n - j - 1][i];
		}
	}
	key.resize(m);
	key[0].resize(n);
	key = temp;
	return;
}


int main() {
	vector<int> v = { 1, 2, 3, 4, 5, 6 };

	rotate(v.begin(), v.begin() + 1, v.end());
	//rotate(v.begin(), v.begin() + 2, v.end()); 2칸 이동
	//rotate(v.begin() + 1, v.begin() + 2, v.begin() + 5); 일부분 이동
	//rotate(v.rbegin(), v.rbegin() + 1, v.rend()); 시계방향 이동

	vector<int> vv = { 1, 2, 3, 4, 5, 6 };
	int i = 1;
	int temp = vv[i];
	vv[i] = vv[i + 1];
	vv[i + 1] = vv[i + 2];
	vv[i + 2] = vv[i + 3];
	vv[i + 3] = temp;
	for (int i : vv) cout << i << ' ';


	for (int i : v) cout << i << ' ';

	ios::sync_with_stdio(0); cin.tie(0);
	vector<vector<int>> a = {
	{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	};
	rotate_right_90(a);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}