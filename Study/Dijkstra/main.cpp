#include <iostream>
#include "dijkstra.h"

int main()
{
	C_DIJKSTRA cDij{};

	cDij.load();
	cDij.print();
	cDij.run(1);
	cDij.printLength();

	C_DIJKSTRA2 cDijkstra{};

	cDijkstra.load();
	cDijkstra.print();
	cDijkstra.run(1);
}