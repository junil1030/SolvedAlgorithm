#pragma once

#include <map>
#include <string>
#include <queue>

class C_KRUSKAL
{
private:
	struct S_NODE
	{
		std::string strId;
		std::map<S_NODE*, int> mapChild;
	};
	struct S_KRUSKAL
	{
		int nLength;
		S_NODE* pSrc;
		S_NODE* pDst;
		bool operator()(const S_KRUSKAL& dst, const S_KRUSKAL& src)
		{
			return dst.nLength > src.nLength;
		}
	};

private:
	std::map<std::string, S_NODE*> m_mapNode;
	std::priority_queue<S_KRUSKAL, std::vector<S_KRUSKAL>, S_KRUSKAL> m_heapKruskal;

	S_NODE* createNode(const char* strId);
	S_NODE* getNode(const char* strId);

public:
	C_KRUSKAL() = default;
	void add(const char* strDst, const char* strSrc, int nLength);
	void print();
	void Kruskal();
};