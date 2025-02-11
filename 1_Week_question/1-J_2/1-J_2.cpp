#include "bits/stdc++.h"
using namespace std;

int t, n;
map<string, int> m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		m.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			string temp, s;
			cin >> temp >> s;
			m[s]++;
		}

		long long ret = 1;
		for (auto a : m) {
			ret *= (a.second + 1);
		}
		cout << ret - 1 << "\n";
	}
}