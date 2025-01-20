#include "dfs.h"


void C_DFS::init(int nBufferSize)
{
	m_nBufferSize = nBufferSize;
	m_ppBuffer = new S_NODE * [m_nBufferSize] {};
	for (int i = 0; i < m_nBufferSize; i++)
	{
		m_ppBuffer[i] = new S_NODE[m_nBufferSize]{};
	}
}

void C_DFS::release()
{
	for (int i = 0; i < m_nBufferSize; i++)
	{
		delete[] m_ppBuffer[i];
	}
	delete[] m_ppBuffer;
}

bool C_DFS::addNode(int nDst, int nSrc)
{
	if (nDst < 0 || nSrc < 0 || nDst >= m_nBufferSize || nSrc >= m_nBufferSize || m_ppBuffer[nDst][nSrc].bNode)
		return false;

	m_ppBuffer[nDst][nSrc].bNode = true;
	m_ppBuffer[nSrc][nDst].bNode = true;
	return true;
}

void C_DFS::print()
{
	for (int i = 0; i < m_nBufferSize; i++)
	{
		for (int j = 0; j < m_nBufferSize; j++)
		{
			printf("%d ", m_ppBuffer[i][j].bNode);
		}
		printf("\n");
	}
}

void C_DFS::dfs(int nNode)
{
	searchNode(nNode);
}

void C_DFS::searchNode(int nNode)
{
	for (int i = 0; i < m_nBufferSize; i++)
	{
		if (m_ppBuffer[nNode][i].bNode && !m_ppBuffer[nNode][i].bVisit)
		{
			m_ppBuffer[nNode][i].bVisit = true;
			m_ppBuffer[i][nNode].bVisit = true;
			printf("%d\n", i);
			searchNode(i);
		}
	}
}
