#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;
	for (int i = 0; i < 9; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += v[i];
		}
		if (sum == 100)
			break;
	} while (next_permutation(v.begin(), v.end()));

	for (int i = 0; i < 7; i++) {
		cout << v[i] << "\n";
	}

	return 0;
}