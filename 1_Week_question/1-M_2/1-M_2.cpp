#include "bits/stdc++.h"
using namespace std;

int n, cnt;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	while (n--) {
		string s;
		stack<char> stk;

		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (stk.size() == 0 || stk.top() != s[i])
				stk.push(s[i]);
			else {
				stk.pop();
			}
		}

		if (stk.size() == 0) cnt++;
	}

	cout << cnt << "\n";
}