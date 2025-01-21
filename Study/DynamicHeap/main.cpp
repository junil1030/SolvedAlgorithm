#include <iostream>
#include "DynamicHeap.h"

int main()
{
    C_DYNAMICHEAP cDHeap{};

    cDHeap.addData(1);
    cDHeap.addData(5);
    cDHeap.addData(2);
    cDHeap.addData(7);
    cDHeap.addData(3);
    cDHeap.addData(8);
    cDHeap.addData(4);
    cDHeap.addData(9);
    cDHeap.addData(6);

    cDHeap.print();
    cDHeap.updateData(9, 4);
    cDHeap.print();

    for (int i = 0; i < 8; i++)
    {
        cDHeap.pop();
        cDHeap.print();
    }
}
