#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'm') {
			s[i] += 13;
		}
		else if (s[i] > 'm' && s[i] <= 'z') {
			s[i] -= 13;
		}
		else if (s[i] >= 'A' && s[i] <= 'M') {
			s[i] += 13;
		}
		else if (s[i] > 'M' && s[i] <= 'Z') {
			s[i] -= 13;
		}
	}

	cout << s;

	return 0;
}