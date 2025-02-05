#include "bits/stdc++.h"
using namespace std;

int a[10];
int b[10][10];

// fill 함수를 사용할 경우 0, 1, 2 등 모든 숫자로 초기화가 가능하다.
// 반면 memset은 -1, 0으로만 초기화가 가능함.
// 하지만 memset이 좀 더 빠르기 때문에 시간적으로 최적화를 시킬 수 있기도 함.
// fill은 O(n)의 시간복잡도를 갖는다

// void fill(ForwardIterator first, ForwardIterator last, const T& val);
// void *memset(void* ptr, int value, size_t num);

int main() {
	fill(&a[0], &a[10], 100);

	//for (int i = 0; i < 10; i++) {
	//	cout << a[i] << " ";
	//}
	//cout << '\n';

	//fill(&b[0][0], &b[9][10], 2);
	//for (int i = 0; i < 10; i++) {
	//	for (int j = 0; j < 10; j++) {
	//		cout << b[i][j] << " ";
	//	}
	//	cout << '\n';
	//}

	memset(a, -1, sizeof(a));
	memset(b, 0, sizeof(b));
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << '\n';
	// -1, -1, ...

	memset(a, 'a', sizeof(a));
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
	cout << '\n';
	// a로 초기화가 안됨...

	return 0;
}