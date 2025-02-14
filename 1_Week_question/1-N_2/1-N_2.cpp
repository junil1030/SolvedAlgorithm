#include "bits/stdc++.h"
using namespace std;
#define ll long long

ll a, b, c;
ll go(ll a, ll b) {
	if (b == 1) return a % c;
	ll ret = go(a, b / 2);
	ret = (ret * ret) % c;
	if (b % 2) ret = (ret * a) % c;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 다시 풀 문제
	cin >> a >> b >> c;
	cout << go(a, b) << "\n";

	return 0;
}