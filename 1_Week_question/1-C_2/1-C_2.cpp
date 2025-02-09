// BOJ 2979
#include "bits/stdc++.h"
using namespace std;

int a, b, c;
int ary[100];
int total;
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		cin >> n >> m;
		for (int j = n; j < m; j++)	ary[j]++;
	}

	for (int i = 1; i < 100; i++)
	{
		if (ary[i] == 1)
			total += a;
		else if (ary[i] == 2)
			total += b * 2;
		else if (ary[i] == 3)
			total += c * 3;
	}

	cout << total;
}