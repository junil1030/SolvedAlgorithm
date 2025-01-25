#include "Dijkstra.h"

C_DIJKSTRA::S_NODE* C_DIJKSTRA::createNode(int nId)
{
	S_NODE* pNew = new S_NODE{};
	pNew->nId = nId;

	pNew->nLengthTotal = INT_MAX;

	return pNew;
}

void C_DIJKSTRA::linkNode(int nParent, int nChild, int nLength)
{
	S_NODE* pParent = m_mapNode.find(nParent)->second;
	S_NODE* pChild = m_mapNode.find(nChild)->second;
	pParent->children.insert({ pChild , nLength });
	pChild->children.insert({ pParent , nLength });
}

C_DIJKSTRA::S_NODE* C_DIJKSTRA::findMinLengthNode()
{
	std::priority_queue<S_NODE*, std::vector<S_NODE*>, S_CMP> heap{};
	for (S_NODE* pNode : m_setTrace)
	{
		heap.push(pNode);
	}
	return heap.top();
}

void C_DIJKSTRA::load()
{
	for (int i = 1; i <= 8; i++)
	{
		m_mapNode.insert({ i , createNode(i) });
	}
	linkNode(1, 2, 3);
	linkNode(1, 3, 4);

	linkNode(2, 3, 5);
	linkNode(2, 4, 10);
	linkNode(2, 6, 9);

	linkNode(3, 4, 8);
	linkNode(3, 5, 5);

	linkNode(4, 5, 6);
	linkNode(4, 6, 10);
	linkNode(4, 7, 7);
	linkNode(4, 8, 3);

	linkNode(5, 7, 4);

	linkNode(6, 8, 2);

	linkNode(7, 8, 5);
}

void C_DIJKSTRA::print()
{
	for (auto iter : m_mapNode)
	{
		printf("%d ", iter.first);
		for (auto iterChild : iter.second->children)
		{
			printf("(%d -> %d)", iterChild.first->nId, iterChild.second);
		}
		printf("\n");
	}
}

void C_DIJKSTRA::printLength()
{
	for (auto iter : m_mapNode)
	{
		printf("%d , parent Id: %d, length: %d\n", iter.first, iter.second->pParent->nId, iter.second->nLengthTotal);
	}
}

void C_DIJKSTRA::run(int nNode)
{
	S_NODE* pNode = m_mapNode.find(nNode)->second;

	m_setTrace.insert(pNode);
	pNode->nLengthTotal = 0;
	pNode->pParent = pNode;

	while (!m_setTrace.empty())
	{
		S_NODE* pMinNode = findMinLengthNode();
		pMinNode->bVisit = true;
		m_setTrace.erase(pMinNode);

		for (auto iterChild : pMinNode->children)
		{
			if (!iterChild.first->bVisit)
			{
				m_setTrace.insert(iterChild.first);
				int nLength = pMinNode->nLengthTotal + iterChild.second;
				if (iterChild.first->nLengthTotal > nLength)
				{
					iterChild.first->pParent = pMinNode;
					iterChild.first->nLengthTotal = nLength;
				}
			}
		}
	}
}
