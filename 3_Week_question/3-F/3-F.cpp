#include "bits/stdc++.h"
using namespace std;

vector<int> num;
vector<char> op;
int n, ret = -987654321;
int oper(char a, int b, int c) {
	if (a == '+') return b + c;
	if (a == '*') return b * c;
	if (a == '-') return b - c;
}
void go(int here, int _num) {
	if (here == num.size() - 1) {
		ret = max(ret, _num);
		return;
	} 
	go(here + 1, oper(op[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1) {
		int temp = oper(op[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(op[here], _num, temp));
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; char c;
		if (i % 2 == 1) {
			cin >> c; 
			op.push_back(c);
		}
		else {
			cin >> a; 
			num.push_back(a);
		}
	}
	go(0, num[0]);
	cout << ret << "\n";

	return 0;
}