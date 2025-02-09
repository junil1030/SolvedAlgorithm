// BOJ 10988
#include "bits/stdc++.h"
using namespace std;

string str;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}
