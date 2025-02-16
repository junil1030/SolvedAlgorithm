// 다시 풀 문제 2회차 250216

#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	while (cin >> n) {
		long long cnt = 1, ret = 1;
		while (true) {
			if (cnt % n == 0)
			{
				cout << ret << '\n';
				break;
			}
			else
			{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
}