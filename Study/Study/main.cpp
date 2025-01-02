#include <bits/stdc++.h>
using namespace std;

//----------------------
int a[3] = { 1, 2, 3 };
int n = 3, r = 3;
//----------------------

void print() {
    cout << "결과 출력: ";
    for (int i = 0; i < r; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "----------------------------------";
    cout << "\n";
}

void Currentprint() {
    cout << "현재 배열: ";
    for (int i = 0; i < r; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "----------------------------------";
    cout << "\n";
}

void printVector(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void makePermutation(int n, int r, int depth)
{
    Currentprint();
    if (r == depth) {
        print();
        return;
    }
    for (int i = depth; i < n; i++)
    {
        cout << i << " : " << depth << "를 바꾼다! " << "\n";
        swap(a[i], a[depth]);
        cout << "n: " << n << " depth: " << depth + 1 << "\n";
        makePermutation(n, r, depth + 1);
        cout << i << " : " << depth << "를 다시 바꾼다! " << "\n";

        swap(a[i], a[depth]);
    }
    return;
}

int main()
{
    //int a[] = { 2,1,3 };
    //vector<int> v;
    //for (int i = 0; i < 3; i++)
    //    v.push_back(a[i]);

    //sort(v.begin(), v.end());

    //do {
    //    printVector(v);
    //} while (next_permutation(v.begin(), v.end()));\

    makePermutation(n, r, 0);
    return 0;
}