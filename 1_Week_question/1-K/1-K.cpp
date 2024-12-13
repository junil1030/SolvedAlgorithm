#include "bits/stdc++.h"
using namespace std;

string s, ret;
int a[200];
int flag;
char mid;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	for (auto c : a)
		a[c]++;
	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (a[i])
		{
			if (a[i] & 1)
			{
				mid = char(i);
				flag++;
				a[i]--;
			}
			if (flag == 2)
				break;
			for (int j = 0; j < a[i]; j += 2)
			{
				ret = char(i) + ret;
				ret = ret + char(i);
			}
		}
	}

	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo\n";
	else
		cout << ret << "\n";
}