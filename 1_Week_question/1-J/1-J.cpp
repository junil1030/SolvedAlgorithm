#include "bits/stdc++.h"
using namespace std;

int t, n;
string a, b;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		map<string, int> m;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a >> b;
			m[b]++;
		}
		long long ret = 1;
		for (auto c : m)
		{
			ret *= ((long long)c.second + 1);
		}
		ret--;
		cout << ret << '\n';
	}

	return 0;
}