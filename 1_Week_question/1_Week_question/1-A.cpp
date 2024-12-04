// BOJ 2309
#include "bits/stdc++.h"
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a[9];

	/*for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
	}

	sort(a, a + 9);

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++)
			sum = sum + a[i];
		if (sum == 100)
			break;
	} while (next_permutation(a, a + 9));

	for (int i = 0; i < 7; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n';*/

	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	pair<int, int> ret;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - a[i] - a[j] == 100)
			{
				ret.first = i;
				ret.second = j;
			}
		}
	}

	vector<int> vct;
	for (int i = 0; i < 9; i++)
	{
		if (ret.first == i || ret.second == i)
			continue;
		vct.push_back(a[i]);
	}
	sort(vct.begin(), vct.end());
	for (int i : vct)
	{
		cout << i << " ";
	}
}

int b[9];
int n = 9, r = 7;
void makePermutation(int n, int r, int depth)
{
	if (depth == r)
	{
		print();
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(b[i], b[depth]);
		makePermutation(n, r, depth + 1);
		swap(b[i], b[depth]);
	}
}

void print()
{
	for (int i = 0; i < 7; i++)
	{
		cout << i << " ";
	}
	cout << "\n";
}