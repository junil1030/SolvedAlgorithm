#include "bits/stdc++.h"
using namespace std;

int t;
int ret;
bool bRet;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++) {
		ret = 0;
		bRet = true;
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '(') ret++;
			else if (s[j] == ')') {
				if (ret > 0) ret--;
				else {
					bRet = false;
				}
			}
		}
		if(ret == 0 && bRet) cout << "YES" << '\n';
		else {
			cout << "NO" << '\n';
		}
	}
}