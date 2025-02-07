#include "bits/stdc++.h"
using namespace std;


int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	string p;
	cin >> n >> p;

	string first = p.substr(0, p.find("*"));
	string end = p.substr(p.find("*") + 1);

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s.size() < (first.size() + end.size())) {
			cout << "NE" << "\n";
			continue;
		}

		string sFirst = s.substr(0, first.size());
		string sEnd = s.substr(s.size() - end.size());

		if (sFirst == first && sEnd == end)
			cout << "DA" << "\n";
		else
			cout << "NE" << "\n";
	}

	return 0;
}