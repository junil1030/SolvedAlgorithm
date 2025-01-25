#include <iostream>
#include "dijkstra.h"

int main()
{
	C_DIJKSTRA cDij{};

	cDij.load();
	cDij.print();
	cDij.run(1);
	cDij.printLength();
}