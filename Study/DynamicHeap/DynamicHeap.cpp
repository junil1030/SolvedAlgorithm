#include "DynamicHeap.h"

C_DYNAMICHEAP::C_DYNAMICHEAP() :
	m_vBuffer{}
{
	m_vBuffer.push_back(nullptr);
}

C_DYNAMICHEAP::~C_DYNAMICHEAP()
{
	for (S_DATA* pData : m_vBuffer) {
		delete pData;
	}
}

C_DYNAMICHEAP::C_DYNAMICHEAP(const C_DYNAMICHEAP& other) : m_vBuffer{}
{
	m_vBuffer.reserve(other.m_vBuffer.size());
	for (S_DATA* pData : other.m_vBuffer) {
		m_vBuffer.push_back(new S_DATA(*pData));
	}
}

C_DYNAMICHEAP& C_DYNAMICHEAP::operator=(const C_DYNAMICHEAP& other)
{
	if (this != &other) {
		for (S_DATA* pData : m_vBuffer) {
			delete pData;
		}

		m_vBuffer.clear();
		m_vBuffer.reserve(other.m_vBuffer.size());
		for (S_DATA* pData : other.m_vBuffer) {
			m_vBuffer.push_back(new S_DATA(*pData));
		}
	}
	return *this;
}

C_DYNAMICHEAP::S_DATA* C_DYNAMICHEAP::addData(int nLength)
{
	S_DATA* pData = new S_DATA{};
	pData->nLength = nLength;

	m_vBuffer.push_back(pData);
	up((int)m_vBuffer.size() - 1);
	return pData;
}

void C_DYNAMICHEAP::swapData(int nDstId, int nSrcId)
{
	S_DATA* pTmp = m_vBuffer[nDstId];
	m_vBuffer[nDstId] = m_vBuffer[nSrcId];
	m_vBuffer[nSrcId] = pTmp;
}

void C_DYNAMICHEAP::up(int nId)
{
	int nUp = nId / 2;
	if (nUp == 0 || m_vBuffer[nId]->nLength >= m_vBuffer[nUp]->nLength)
		return;

	swapData(nId, nUp);
	up(nUp);
}

void C_DYNAMICHEAP::down(int nId)
{
	int nLeft = nId * 2;
	int nRight = nLeft + 1;

	if (nLeft >= m_vBuffer.size())
		return;

	int nMin = nLeft;
	if (nRight < m_vBuffer.size() && m_vBuffer[nLeft]->nLength > m_vBuffer[nRight]->nLength)
		nMin = nRight;

	if (m_vBuffer[nId]->nLength <= m_vBuffer[nMin]->nLength)
		return;

	swapData(nId, nMin);
	down(nMin);
}

void C_DYNAMICHEAP::print()
{
	for (int i = 1; i < m_vBuffer.size(); i++)
	{
		printf("%d ", m_vBuffer[i]->nLength);
	}
	printf("\n");
}

C_DYNAMICHEAP::S_DATA* C_DYNAMICHEAP::top()
{
	return m_vBuffer.size() > 1 ? m_vBuffer[1] : nullptr;
}

void C_DYNAMICHEAP::pop()
{
	if (m_vBuffer.size() <= 1)
		return;

	delete m_vBuffer[1];
	m_vBuffer[1] = m_vBuffer[m_vBuffer.size() - 1];
	m_vBuffer.pop_back();

	down(1);
}

void C_DYNAMICHEAP::updateData(int nId, int nlength)
{
	//m_vBuffer[nId]->nLength = nlength;

	//int nUp = nId / 2;
	//while (nUp != 0)
	//{
	//	swapData(nId, nUp);
	//	nId = nUp;
	//	nUp = nId / 2;
	//}
	//down(1);
	if (nId >= 1 && nId < static_cast<int>(m_vBuffer.size())) {
		m_vBuffer[nId]->nLength = nlength;
		up(nId);
		down(nId);
	}
}
