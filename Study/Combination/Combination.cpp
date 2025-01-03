#include "bits/stdc++.h"
using namespace std;

int n = 5, k = 3, a[5] = { 1,2,3,4,5 };
void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << "\n";
}

void combi(int start, vector<int> b) {
	if (b.size() == k) {
		//logic
		print(b);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);

	// 4개 이상은 재귀함수
	// 3개 이하는 중첩 for문
	vector<int> b;
	//combi(-1, b);

	// 중첩for문
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				cout << i << " " << j << " " << k << '\n';
			}
		}
	}

	return 0;
}