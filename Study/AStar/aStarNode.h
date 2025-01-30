#pragma once
#include <list>

class C_ASTARDYNAMICHEAP;
class C_ASTAR;

class C_ASTARNODE
{
	C_ASTARNODE() = default;
	enum WAY
	{
		UL, // 0 Up Left 
		UC, // 1 Up Center
		UR, // 2 Up Right
		LC, // 3 Left Center
		RC, // 4 Right Center
		DL, // 5 Down Left
		DC, // 6 Down Center
		DR, // 7 Down Right
		MAX
	};

	friend C_ASTARDYNAMICHEAP;
	friend C_ASTAR;

	static const int way[8][2];
	static const int length[8];
	C_ASTARNODE* child[MAX];

	int nY;
	int nX;

	int nF;
	int nH;
	int nG;
};