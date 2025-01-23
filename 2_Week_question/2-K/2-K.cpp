#include "bits/stdc++.h"
using namespace std;

int t, a;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a;
		int ret2 = 0, ret5 = 0;
		for (int j = 2; j <= a; j *= 2) {
			ret2 += a / j;
		}
		for (int j = 5; j <= a; j *= 5) {
			ret5 += a / j;
		}
		cout << min(ret2, ret5) << "\n";
	}
}