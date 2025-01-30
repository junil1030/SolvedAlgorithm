#include "aStarDynamicHeap.h"

C_ASTARDYNAMICHEAP::C_ASTARDYNAMICHEAP() :
	m_vBuffer{}
{
	m_vBuffer.reserve(100);
	m_vBuffer.push_back(nullptr);
}

void C_ASTARDYNAMICHEAP::addData(C_ASTARNODE* pNode)
{
	m_vBuffer.push_back(pNode);
	up((int)m_vBuffer.size() - 1);
}

void C_ASTARDYNAMICHEAP::swapData(int nDstId, int nSrcId)
{
	C_ASTARNODE* pTmp = m_vBuffer[nDstId];
	m_vBuffer[nDstId] = m_vBuffer[nSrcId];
	m_vBuffer[nSrcId] = pTmp;
}

void C_ASTARDYNAMICHEAP::up(int nId)
{
	int nUp = nId / 2;
	if (nUp == 0 || m_vBuffer[nId]->nF >= m_vBuffer[nUp]->nF)
		return;

	swapData(nId, nUp);
	up(nUp);
}

void C_ASTARDYNAMICHEAP::down(int nId)
{
	int nLeft = nId * 2;
	int nRight = nLeft + 1;

	if (nLeft >= m_vBuffer.size())
		return;

	int nMin = nLeft;
	if (nRight < m_vBuffer.size() && m_vBuffer[nLeft]->nF > m_vBuffer[nRight]->nF)
		nMin = nRight;

	if (m_vBuffer[nId]->nF <= m_vBuffer[nMin]->nF)
		return;

	swapData(nId, nMin);
	down(nMin);
}

void C_ASTARDYNAMICHEAP::print()
{
	for (int i = 1; i < m_vBuffer.size(); i++)
	{
		printf("%d ", m_vBuffer[i]->nF);
	}
	printf("\n");
}

C_ASTARNODE* C_ASTARDYNAMICHEAP::top()
{
	return m_vBuffer[1];
}

void C_ASTARDYNAMICHEAP::pop()
{
	delete m_vBuffer[1];
	m_vBuffer[1] = m_vBuffer[m_vBuffer.size() - 1];
	m_vBuffer.pop_back();

	down(1);
}

void C_ASTARDYNAMICHEAP::updateData(int nId)
{
	int nUp = nId / 2;
	while (nUp != 0)
	{
		swapData(nId, nUp);
		nId = nUp;
		nUp = nId / 2;
	}
	down(1);
}
