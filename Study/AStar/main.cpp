#include <iostream>
#include "aStar.h"

int main()
{
	C_ASTAR cAstar{};

	cAstar.init();
	cAstar.find(1, 1, 5, 2);
}