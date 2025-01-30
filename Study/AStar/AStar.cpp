#include "aStar.h"

C_ASTAR::C_ASTAR() :
	m_map{
		{1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,1,0,0,0,0,1},
		{1,0,0,0,1,0,0,1,0,1},
		{1,0,1,1,1,0,0,1,0,1},
		{1,0,0,0,1,0,0,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,1,1,1}, }
{
}

void C_ASTAR::makeNode()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			m_node[i][j] = new C_ASTARNODE{};
			m_node[i][j]->nY = i;
			m_node[i][j]->nX = j;
		}
	}
}

void C_ASTAR::linkNode(int nY, int nX)
{
	C_ASTARNODE* pNode = m_node[nY][nX];
	for (int i = 0; i < C_ASTARNODE::MAX; i++)
	{
		int nChildY = C_ASTARNODE::way[i][0] + nY;
		int nChildX = C_ASTARNODE::way[i][1] + nX;
		if (isWay(nChildY, nChildX))
			pNode->child[i] = m_node[nChildY][nChildX];
	}
}

bool C_ASTAR::isWay(int nY, int nX)
{
	if (nY < 0 || nX < 0 || nY >= 10 || nX >= 10 || m_map[nY][nX] == 1)
		return false;

	return true;
}

void C_ASTAR::setNode(C_ASTARNODE* pNode, C_ASTARNODE::WAY way, C_ASTARNODE* pEnd, C_ASTARNODE* pParent)
{
	pNode->nG += pParent->nG + C_ASTARNODE::length[way];
	pNode->nH = (abs(pNode->nX - pEnd->nX) + abs(pNode->nY - pEnd->nY)) * 10;
	pNode->nF = pNode->nG + pNode->nH;
}

void C_ASTAR::init()
{
	makeNode();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			linkNode(i, j);
		}
	}
}

void C_ASTAR::find(int nBeginY, int nBeginX, int nEndY, int nEndX)
{
	//노드를 찾고
	C_ASTARNODE* pBegin = m_node[nBeginY][nBeginX];
	C_ASTARNODE* pEnd = m_node[nEndY][nEndX];

	//자식을 open에 넣고
	C_ASTARNODE* pNode = pBegin;
	for (int i = 0; i < C_ASTARNODE::MAX; i++)
	{
		C_ASTARNODE* pChild = pNode->child[i];
		if (pChild)
		{
			setNode(pChild, (C_ASTARNODE::WAY)i, pEnd, pNode);
			m_openList.addData(pChild);
		}
	}

	m_openList.print();
	pNode = m_openList.top();
	m_openList.pop();

	//가장 작은 값을 가져오고 closed에 넣고
	//해당 child값을 갱신시키고
	//반복
}