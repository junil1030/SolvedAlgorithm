// BOJ 10808
#include "bits/stdc++.h"
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int alpha[26]{};

    for (int i = 0; i < s.length(); i++)
    {
        alpha[s[i] - 97]++;
    }

    for (int i : alpha)
    {
        cout << i << " ";
    }
}
