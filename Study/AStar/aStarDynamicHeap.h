#pragma once
#include <vector>
#include "aStarNode.h"

class C_ASTARDYNAMICHEAP
{
private:
	std::vector<C_ASTARNODE*> m_vBuffer;

private:
	void swapData(int nDstId, int nSrcId);
	void up(int nId);
	void down(int nId);

public:
	C_ASTARDYNAMICHEAP();
	void addData(C_ASTARNODE* pNode);
	void print();
	C_ASTARNODE* top();
	void updateData(int nId);
	void pop();
};