#pragma once
#include "bits/stdc++.h"
using namespace std;

class C_DIJKSTRA {
private:
	struct S_NODE
	{
		int nId;
		map<S_NODE*, int> children;

		bool bVisit;
		S_NODE* pParent;
		int nLengthTotal;
	};

	struct S_CMP
	{
		bool operator()(S_NODE* pDst, S_NODE* pSrc) {
			return pDst->nLengthTotal > pSrc->nLengthTotal;
		}
	};

private:
	map<int, S_NODE*> m_mapNode;
	set<S_NODE*> m_setTrace{};

private:
	S_NODE* createNode(int nId);
	void linkNode(int nParent, int nChild, int nLength);
	S_NODE* findMinLengthNode();

public:
	C_DIJKSTRA() = default;
	void load();
	void print();
	void printLength();
	void run(int nNode);
};

