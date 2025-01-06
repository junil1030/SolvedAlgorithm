#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
int ary[100000];
int aNum, bNum;
int pSum[100000];
int n, m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> ary[i];
		pSum[i] = pSum[i - 1] + ary[i];
	}
	for (int i = 0; i < m; i++) 
	{
		cin >> aNum >> bNum;
		cout << pSum[bNum] - pSum[aNum] << "\n";
	}
	return 0;
}