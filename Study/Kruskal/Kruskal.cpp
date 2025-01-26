#include "Kruskal.h"

C_KRUSKAL::S_NODE* C_KRUSKAL::createNode(const char* strId)
{
	S_NODE* pNew = new S_NODE{};
	pNew->strId = strId;
	return pNew;
}

C_KRUSKAL::S_NODE* C_KRUSKAL::getNode(const char* strId)
{
	auto iterResult = m_mapNode.insert({ strId, nullptr });

	if (iterResult.second)
		iterResult.first->second = createNode(strId);

	return iterResult.first->second;
}

void C_KRUSKAL::add(const char* strDst, const char* strSrc, int nLength)
{
	S_NODE* pDst = getNode(strDst);
	S_NODE* pSrc = getNode(strSrc);

	pDst->mapChild.insert({ pSrc, nLength });
	pSrc->mapChild.insert({ pDst, nLength });

	m_heapKruskal.push({ nLength, pSrc, pDst });
}

void C_KRUSKAL::print()
{
	for (auto iter = m_mapNode.begin(); iter != m_mapNode.end(); iter++)
	{
		printf("%s: ", iter->first.c_str());
		for (auto iterChild = iter->second->mapChild.begin();
			iterChild != iter->second->mapChild.end();
			iterChild++)
		{
			printf("(%s, %d)  ", iterChild->first->strId.c_str(), iterChild->second);
		}
		printf("\n");
	}
}

void C_KRUSKAL::Kruskal()
{
	while (!m_heapKruskal.empty())
	{
		S_KRUSKAL s = m_heapKruskal.top();
		m_heapKruskal.pop();

		printf("%d, %s, %s\n", s.nLength, s.pDst->strId.c_str(), s.pSrc->strId.c_str());
	}
}
