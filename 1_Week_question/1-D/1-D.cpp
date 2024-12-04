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
	/*
	int len = str.length();
	if (len % 2 == 1)
	{
		int mid = len / 2;
		for (int i = 0; i < mid; i++)
		{
			if (str[i] == str[len - 1])
				len--;
		}
		len--;
		if (len == mid) cout << 1;
		else cout << 0;
	}
	else
	{
		int mid = len / 2;
		for (int i = 0; i < mid; i++)
		{
			if (str[i] == str[len - 1])
				len--;
		}
		if (len == mid) cout << 1;
		else cout << 0;
	}
	*/

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
