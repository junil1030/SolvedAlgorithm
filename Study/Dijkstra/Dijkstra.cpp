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


// --------------------------------------------------------------------
C_DIJKSTRA2::S_NODE* C_DIJKSTRA2::createNode(int nId)
{
	S_NODE* pNew = new S_NODE{};
	pNew->nId = nId;

	return pNew;
}

void C_DIJKSTRA::linkNode(int nParent, int nChild, int nLength)
{
	S_NODE* pParent = m_mapNode.find(nParent)->second;
	S_NODE* pChild = m_mapNode.find(nChild)->second;

	pParent->children.insert({ pChild, nLength });
	pChild->children.insert({ pParent, nLength });
}

void C_DIJKSTRA2::load()
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

void C_DIJKSTRA2::print()
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

void C_DIJKSTRA2::run(int nNode)
{
	S_NODE* pNode = m_mapNode.find(nNode)->second;

	std::map<S_NODE*, S_INFO> mapTrace{};
	mapTrace.insert({ pNode, { pNode, pNode, 0 } });

	std::priority_queue<S_INFO*, std::vector<S_INFO*>, S_CMP> heap{};

	for (auto iter : mapTrace)
	{
		heap.push(&iter.second);
	}

	S_INFO* pMin = heap.top();

	pMin->pNode->bVisit = true;

	for (auto iter : pMin->pNode->children)
	{
		if (!iter.first->bVisit)
		{
			mapTrace.insert({ iter.first, {iter.first, pMin->pNode, pMin->nLengthTotal + iter.second} });
			//mapTrace.insert({ 고유 아이디, { 내 아이디, 부모 아이디, 총 길이 } });
		}
	}
	mapTrace.erase(pMin->pNode);

	printf("%d\n", heap.top()->nLengthTotal);

	heap = std::priority_queue<S_INFO*, std::vector<S_INFO*>, S_CMP>{};
	for (auto iter : mapTrace)
	{
		heap.push(&iter.second);
	}
	pMin = heap.top();

	pMin->pNode->bVisit = true;
	for (auto iter : pMin->pNode->children)
	{
		if (!iter.first->bVisit)
		{
			mapTrace.insert({ iter.first ,	{iter.first , pMin->pNode , pMin->nLengthTotal + iter.second} });
		}
	}
	mapTrace.erase(pMin->pNode);
	printf("%d\n", heap.top()->nLengthTotal);
}