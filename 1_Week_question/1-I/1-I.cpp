#include "bits/stdc++.h"
using namespace std;

int n, m;
map<int, string> docsInt;
map<string, int> docsStr;
string q[100004];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		string pokemon;
		cin >> pokemon;
		docsInt.insert({ i, pokemon });
		docsStr.insert({ pokemon, i });
	}

	for (int i = 1; i <= m; i++)
	{
		cin >> q[i];
	}

	for (int i = 1; i <= m; i++)
	{
		if (atoi(q[i].c_str()) == 0) //문자라면
		{
			cout << docsStr[q[i]] << "\n";
		}
		else
		{
			cout << docsInt[atoi(q[i].c_str())] << "\n";
		}
	}
	return 0;
}