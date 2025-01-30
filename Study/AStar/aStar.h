#pragma once
#include<stdio.h>
#include "aStarNode.h"
#include "aStarDynamicHeap.h"

class C_ASTAR
{
private:
	int m_map[10][10];
	C_ASTARNODE* m_node[10][10];
	C_ASTARDYNAMICHEAP m_openList;

private:
	void makeNode();
	void linkNode(int nY, int nX);
	bool isWay(int nY, int nX);
	void setNode(C_ASTARNODE* pNode, C_ASTARNODE::WAY way, C_ASTARNODE* pEnd, C_ASTARNODE* pParent);

public:
	C_ASTAR();
	void init();
	void find(int nBeginY, int nBeginX, int nEndY, int nEndX);
};