// BOJ 2559
#include "bits/stdc++.h"
using namespace std;

//int result = INT_MIN;
//int n, k;
//int ary[100000];

int n, k;
int temp;
int ret = INT_MIN;
int pSum[100004];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	* 누적합으로 풀었어야 했음 pSum
	* 최악의 시간복잡도일 경우 시간초과가 일어날
	* 가능성이 큼
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> ary[i];  
	}

	for (int i = 0; i <= n - k; i++)
	{
		int sum = 0;
		for (int j = 0; j < k; j++)
		{
			sum += ary[i + j];
		}
		result = max(result, sum);
	}

	cout << result;
	return 0;
	*/


	/*
	* 누적합은 미리 누적된 값을 배열에 저장후
	* 예를 들어, 3~5의 구간 합을 구하라고 할 때,
	* pSum[5] - pSum[2]
	* 물론 누적합은 정적 배열에서만 사용 가능
	*/
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		pSum[i] = pSum[i - 1] + temp;
	}
	// 각 구간의 누적합이 pSum 배열에 생성됨

	for (int i = k; i <= n; i++)
	{
		ret = max(ret, pSum[i] - pSum[i - k]);
	}
	cout << ret;
	return 0;
}