#pragma once
#include "bits/stdc++.h"

class C_DYNAMICHEAP
{
private:
	struct S_DATA
	{
		int nLength;
		int nData;
		int nTmp;
	};

private:
	std::vector<S_DATA*> m_vBuffer;

private:
	void swapData(int nDstId, int nSrcId);
	void up(int nId);
	void down(int nId);

public:
	C_DYNAMICHEAP();
	~C_DYNAMICHEAP();
	C_DYNAMICHEAP(const C_DYNAMICHEAP& other);
	C_DYNAMICHEAP& operator=(const C_DYNAMICHEAP& other);

	S_DATA* addData(int nLength);
	void print();
	S_DATA* top();
	void updateData(int nId, int nLength);
	void pop();
};