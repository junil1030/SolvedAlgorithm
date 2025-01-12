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

// 등차수열의 합
// a = 초항 / n = 항 / d = 공차 / l = 마지막 항
// Sn = n(a + l) / 2
// Sn = n(2a + (n - 1)d) / 2
int APanl(int n, int a, int l) {
	return (n * (a + l)) / 2;
}

int APand(int n, int a, int d) {
	return (n * ((2 * a) + ((n - 1) * d))) / 2;
}

// 등비수열의 합
// a = 초항 / r = 공비 / n = 더하는 것의 개수
// a(r^n - 1) / (r - 1)
// a / (1 - r)
vector<double> GC(double a, double r, int n) {
	vector<double> result;
	if (n <= 0)
		return result;

	double sum = 0.0;
	double term = a;

	if (r == 1) {
		sum = a * n;
		result.push_back(sum);
		for (int i = 0; i < n; ++i) {
			result.push_back(a);
		}
	}
	else {
		for (int i = 0; i < n; ++i) {
			result.push_back(term);
			sum += term;
			term *= r;
		}
		result.push_back(sum); // 마지막에 합한 값을 삽입
	}

	return result;
}

int main() {
	int a = 10, b = 12;
	cout << lcm(a, b) << '\n';

	vector<int> vctEra = era(max_n);
	for (int i : vctEra) cout << i << " ";

	cout << APanl(5, 3, 23) << '\n';
	cout << APand(5, 3, 5) << '\n';

	vector<double> gc = GC(2.0, 3.0, 5);
	for (double a : gc)
		cout << a << " ";

	return 0;
}