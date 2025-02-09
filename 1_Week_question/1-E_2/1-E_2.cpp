// BOJ 1159
#include "bits/stdc++.h"
using namespace std;

int ary[28];
int num;

int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		string str;
		cin >> str;
		ary[str[0] - 'a']++;
	}

	bool bRet = false;
	for (int i = 0; i < 28; i++)
	{
		if (ary[i] >= 5)
		{
			char c = 'a' + i;
			cout << c;
			bRet = true;
		}
	}

	if (!bRet)
	{
		cout << "PREDAJA";
	}
}
