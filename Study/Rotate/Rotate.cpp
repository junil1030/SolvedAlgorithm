﻿#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<int> v = { 1, 2, 3, 4, 5, 6 };

	rotate(v.begin(), v.begin() + 1, v.end());
	//rotate(v.begin(), v.begin() + 2, v.end()); 2칸 이동

	vector<int> vv = { 1, 2, 3, 4, 5, 6 };
	int i = 1;
	int temp = vv[i];
	vv[i] = vv[i + 1];
	vv[i + 1] = vv[i + 2];
	vv[i + 2] = vv[i + 3];
	vv[i + 3] = temp;
	for (int i : vv) cout << i << ' ';

	for (int i : v) cout << i << ' ';

}