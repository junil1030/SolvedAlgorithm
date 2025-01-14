#include "bits/stdc++.h"
using namespace std;

// 싱글연결리스트 (Singly Linked List) next 포인터밖에 존재하지 않는 단 방향 리스트
// 이중연결리스트 (Doubly Linked List) prev, next 두개의 포인터로 양방향 연결된 리스트
// 원형연결리스트 (Circular Linked List) 마지막 노드와 첫번째 노드가 연결되어 원을 형성한 리스트
// 싱글 또는 이중으로 이루어진 두 종류의 원형연결리스트가 존재함.

// 기본적인 Node 클래스의 구현 형태
class Node {
public:
	int data;
	Node* next;
	Node() {
		data = 0;
		next = NULL;
	}
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void print(list<int> a) {
	for (auto it : a)
		cout << it << " ";
	cout << '\n';
}

// STL로 구현되어있는 list의 사용 예제
list<int> a;

int main() {
	for (int i = 1; i <= 3; i++)
		a.push_back(i);
	for (int i = 1; i <= 3; i++)
		a.push_front(i);

	list<int>::iterator it = a.begin();
	it++;
	a.insert(it, 1000);
	print(a);

	it = a.begin();
	it++;
	a.erase(it);
	print(a);

	a.pop_front();
	a.pop_back();
	print(a);

	cout << a.front() << " : " << a.back() << '\n';
	a.clear();
	return 0;
}