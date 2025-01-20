#include "bfs.h"

std::map<int, C_BFS::S_NODE>::iterator C_BFS::createNode(int nId)
{
	S_NODE sNew{};
	sNew.nId = nId;

	return m_mapNode.insert({ nId, sNew }).first;
}

void C_BFS::add(int nDst, int nSrc)
{
	auto iterDst = createNode(nDst);
	auto iterSrc = createNode(nSrc);

	iterDst->second.listIter.push_back(iterSrc);
	iterSrc->second.listIter.push_back(iterDst);
}

void C_BFS::print()
{
	for (std::map<int, S_NODE>::iterator iter = m_mapNode.begin(); iter != m_mapNode.end(); iter++)
	{
		printf("id: %d - ", iter->first);
		std::list<std::map<int, S_NODE>::iterator>::iterator iterList = iter->second.listIter.begin();
		while (iterList != iter->second.listIter.end())
		{
			printf("%d ", (*iterList)->first);
			iterList++;
		}
		printf("\n");
	}
}

void C_BFS::run()
{
	std::queue<std::map<int, S_NODE>::iterator> queueIter{};

	queueIter.push(m_mapNode.find(0));

	while (!queueIter.empty())
	{
		std::map<int, S_NODE>::iterator iterNode = queueIter.front();
		queueIter.pop();
		iterNode->second.bVisit = true;
		printf("%d\n", iterNode->first);
		std::list<std::map<int, S_NODE>::iterator>::iterator iterChild{};
		iterChild = iterNode->second.listIter.begin();

		while (iterChild != iterNode->second.listIter.end())
		{
			if(!(*iterChild)->second.bVisit)
			{
				queueIter.push(*iterChild);
				(*iterChild)->second.bVisit = true;
			}
			iterChild++;
		}
	}
}

C_BFS_DEPTH::S_NODE* C_BFS_DEPTH::createNode(int nId)
{
	S_NODE* pNew = new S_NODE{};
	pNew->nId = nId;

	return pNew;
}

C_BFS_DEPTH::S_NODE* C_BFS_DEPTH::insertNode(int nId)
{
	auto iterResult = m_mapNode.insert({ nId, nullptr });
	if (iterResult.second)
		iterResult.first->second = createNode(nId);

	return iterResult.first->second;
}

bool C_BFS_DEPTH::add(int nDst, int nSrc)
{
	S_NODE* pDst = insertNode(nDst);
	S_NODE* pSrc = insertNode(nSrc);

	if (!pDst->setChild.insert(pSrc).second)
		return false;

	if (!pSrc->setChild.insert(pDst).second)
		return false;

	return true;
}

void C_BFS_DEPTH::print()
{
	for (std::map<int, S_NODE*>::iterator iter = m_mapNode.begin(); iter != m_mapNode.end(); iter++)
	{
		printf("%d: ", iter->first);
		for (S_NODE* pNode : iter->second->setChild)
		{
			printf("%d ", pNode->nId);
		}
		printf("\n");
	}
}

void C_BFS_DEPTH::run(int nId)
{
	S_NODE* pNode{};

	auto iterFind = m_mapNode.find(nId);
	if (m_mapNode.find(nId) == m_mapNode.end())
		return;

	pNode = iterFind->second;
	std::queue<S_NODE*> qBuffer{};
	pNode->bVisit = true;
	qBuffer.push(pNode);

	int nDepth{};
	while (!qBuffer.empty())
	{
		int nCount = qBuffer.size();

		for (int i = 0; i < nCount; i++)
		{
			pNode = qBuffer.front();
			qBuffer.pop();

			printf("%d\n", pNode->nId);
			for (S_NODE* pChild : pNode->setChild)
			{
				if (!pChild->bVisit)
				{
					pChild->bVisit = true;
					qBuffer.push(pChild);
				}
			}
		}
		printf("------------%d------------\n", nDepth);
		nDepth++;
	}
}
