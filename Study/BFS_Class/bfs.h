#pragma once
#include "bits/stdc++.h"

class C_BFS 
{
private:
	struct S_NODE
	{
		int nId;
		std::list<std::map<int, S_NODE>::iterator> listIter;
		bool bVisit;
	};
private:
	std::map<int, S_NODE> m_mapNode;
	std::map<int, S_NODE>::iterator createNode(int nId);

public:
	C_BFS() = default;
	void add(int nDst, int nSrc);
	void print();
	void run();
};

class C_BFS_DEPTH
{
private:
	struct S_NODE
	{
		int nId;
		bool bVisit;
		std::set<S_NODE*> setChild;
	};

private:
	std::map<int, S_NODE*> m_mapNode;

private:
	S_NODE* createNode(int nId);
	S_NODE* insertNode(int nId);

public:
	C_BFS_DEPTH() = default;
	bool add(int nDst, int nSrc);
	void print();
	void run(int nId);
};