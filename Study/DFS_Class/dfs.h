#pragma once
#include "bits/stdc++.h"
using namespace std;

class C_DFS
{
	struct S_NODE
	{
		bool bNode;
		bool bVisit;
	};
private:
	S_NODE** m_ppBuffer;
	int			m_nBufferSize;

	void searchNode(int nNode);

public:
	C_DFS() = default;
	void init(int nBufferSize);
	void release();
	bool addNode(int nDst, int nSrc);
	void print();
	void dfs(int nNode);
};