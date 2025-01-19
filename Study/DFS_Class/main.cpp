#include "dfs.h"

int main()
{
    C_DFS cDfs{};

	cDfs.init(10);

	cDfs.addNode(0, 1);
	cDfs.addNode(0, 2);
	cDfs.addNode(1, 2);
	cDfs.addNode(1, 3);
	cDfs.addNode(2, 4);
	cDfs.addNode(3, 6);
	cDfs.addNode(4, 5);
	cDfs.addNode(4, 6);
	cDfs.addNode(4, 7);
	cDfs.addNode(6, 8);

	cDfs.print();

	cDfs.dfs(3);

	cDfs.release();
}