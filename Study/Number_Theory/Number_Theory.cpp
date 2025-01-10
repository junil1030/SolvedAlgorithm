#include "bits/stdc++.h"
using namespace std;

// 최대공약수
int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b % a, a);
}

// 최소공배수
int lcm(int a, int b)
{
	return (a * b) / gcd(a, b);
}

// 에라토스테네스의 체
// 소수만을 걸러내어 배열 생성

const int max_n = 40;
bool che[max_n + 1]; // 40을 넣으면 40이 참조 되므로 +1
vector<int> era(int mx_n) {
	vector<int> v;
	for (int i = 2; i < mx_n; i++) {
		if (che[i]) continue;
		for (int j = 2 * i; j <= mx_n; j += i) {
			che[j] = 1;
		}
	}
	for (int i = 2; i < mx_n; i++)
		if (che[i] == 0)
			v.push_back(i);
	return v;
}

int main() {
	int a = 10, b = 12;
	cout << lcm(a, b) << '\n';

	vector<int> vctEra = era(max_n);
	for (int i : vctEra) cout << i << " ";

	return 0;
}