#include "bits/stdc++.h"
using namespace std;

int M, N;
int ary[15003];
int cnt;
void combi(int idx, vector<int>& v)
{
	if (v.size() == 2)
	{
		int a = ary[v[0]];
		int b = ary[v[1]];
		if (a + b == M)
			cnt++;
		return;
	}
	for (int i = idx + 1; i < N; i++)
	{
		v.push_back(i);
		combi(i, v);
		v.pop_back();
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> ary[i];
	}
	/*for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (ary[i] + ary[j] == M)
				cnt++;
		}
	}
	cout << cnt;*/
	vector<int> v;
	combi(-1, v);
	cout << cnt;
}