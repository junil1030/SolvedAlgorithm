// 다시 풀 문제 2회차 250216
// 정수론 다시 생각해보기

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

	cin >> a >> b >> c;
	cout << go(a, b) << "\n";

	return 0;
}