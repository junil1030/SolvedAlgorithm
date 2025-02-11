#include "bits/stdc++.h"
using namespace std;

int n, k, temp;
int ret = INT_MIN;
vector<int> pSum;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	pSum.push_back(0);
	for (int i = 1; i <= n; i++) {
		cin >> temp;
		pSum.push_back(pSum[i - 1] + temp);
	}

	for (int i = k; i <= n; i++) {
		ret = max(ret, pSum[i] - pSum[i - k]);
	}
	cout << ret;

	return 0;
}