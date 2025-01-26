#include <iostream>
#include "Kruskal.h"

int main()
{
    C_KRUSKAL cKruskal{};

    cKruskal.add("aa", "bb", 3);
    cKruskal.add("aa", "ii", 7);
    cKruskal.add("bb", "ii", 6);
    cKruskal.add("bb", "cc", 5);
    cKruskal.add("ii", "hh", 7);
    cKruskal.add("ii", "gg", 11);
    cKruskal.add("hh", "cc", 4);
    cKruskal.add("cc", "gg", 6);
    cKruskal.add("cc", "ff", 8);
    cKruskal.add("cc", "dd", 9);
    cKruskal.add("gg", "ff", 2);
    cKruskal.add("ff", "dd", 12);
    cKruskal.add("ee", "dd", 9);
    cKruskal.add("ee", "ff", 10);

    cKruskal.print();

    cKruskal.Kruskal();
}