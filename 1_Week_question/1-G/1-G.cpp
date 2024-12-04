// BOJ 9996
#include "bits/stdc++.h"
using namespace std;

string s[100];
string pattern;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int cnt;
	cin >> cnt;
	cin >> pattern;
	for (int i = 0; i < cnt; i++)
	{
		cin >> s[i];
	}

	int idx = pattern.find(42);
	string front = pattern.substr(0, idx);
	string rear = pattern.substr(idx + 1);

	for (int i = 0; i < cnt; i++)
	{
		if(s[i].size() < front.size() + rear.size())
			cout << "NE" << "\n";
		else
		{
			if(front == s[i].substr(0, front.size()) && rear == s[i].substr(s[i].size() - rear.size()))
				cout << "DA" << "\n";
			else
				cout << "NE" << "\n";
		}
	}
} +