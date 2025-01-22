#include "bits/stdc++.h"
using namespace std;

int n;
vector<string> v;
string s, result = "";
void go() {
	while (true) {
		if (result.size() && result.front() == '0') result.erase(result.begin());
		else break;
	}
	if (result.size() == 0)
		result = "0";
	v.push_back(result);
	result = "";
}
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}
int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		result = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 65) result += s[i];
			else if (result.size()) go();
		}
		if (result.size()) go();
	}
	sort(v.begin(), v.end(), cmp);

	for (auto a : v)
		cout << a << "\n";

	return 0;
}