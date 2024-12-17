#include "bits/stdc++.h"
using namespace std;

int n, cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		stack<char> stk;
		for (char a : s)
		{
			if (stk.size() && stk.top() == a)
				stk.pop();
			else
				stk.push(a);
		}
		if (stk.size() == 0)
			cnt++;
	}
	cout << cnt;
}