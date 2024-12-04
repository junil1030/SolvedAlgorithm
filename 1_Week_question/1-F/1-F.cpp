// BOJ 11655
#include "bits/stdc++.h"
using namespace std;

string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] > 'M') s[i] -= 13;
			else s[i] += 13;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] > 'm') s[i] -= 13;
			else s[i] += 13;
		}
	}

	cout << s;
}