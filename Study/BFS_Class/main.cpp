#include <iostream>
#include "BFS.h"

int main()
{
    C_BFS cBfs{};
    C_BFS_DEPTH cBfsDepth{};

    cBfs.add(0, 100);
    cBfs.add(100, 200);
    cBfs.add(100, 300);
    cBfs.add(200, 300);
    cBfs.add(200, 400);
    cBfs.add(300, 400);
    cBfs.add(300, 500);
    cBfs.add(500, 600);
    cBfs.add(500, 700);
    cBfs.add(600, 800);

    cBfs.print();
    cBfs.run();

    std::cout << "\n" << "##------------------------------------##" << "\n\n";

    cBfsDepth.add(0, 100);
    cBfsDepth.add(100, 200);
    cBfsDepth.add(100, 300);
    cBfsDepth.add(200, 300);
    cBfsDepth.add(200, 400);
    cBfsDepth.add(300, 400);
    cBfsDepth.add(300, 500);
    cBfsDepth.add(500, 600);
    cBfsDepth.add(500, 700);
    cBfsDepth.add(600, 800);

    cBfsDepth.print();
    cBfsDepth.run(800);
}