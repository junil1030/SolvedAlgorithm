#include "bits/stdc++.h"
using namespace std;

int h, w;
int a[102][102];
bool flag;
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	fill(&a[0][0], &a[0][0] + 102 * 102, -1);

	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < w; j++) {
			if (s[j] == 'c') {
				a[i][j] = 0;
				flag = true;
			}
			else if (flag && s[j] == '.') {
				a[i][j] = a[i][j - 1] + 1;
			}
			else if (flag && s[j] == 'c') {
				a[i][j] = 0;
			}
		}
		flag = false;
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}