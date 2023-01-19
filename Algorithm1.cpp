#include "Algorithm1.h"
#include "Graph.h"
#include <iostream>
#include <vector>

Algorithm1::Algorithm1(int size, Graph* _g)
{
    g=_g;
    length = INT_MAX;
    curLength = 0;
    for (int k = 0; k < size; k++)
    {
        passed.push_back(false);
        minPath.push_back(0);
    }
}

void Algorithm1::hamilton1(int index, int level)
{
    if ( index==0 && level > 0 && level == g->getSize() )
    {
        length = curLength;
        std::stack<int> _path=path;
        for (int k = g->getSize()-1 ; k >= 0; k--)
        {
            minPath[k] = _path.top();
            _path.pop();
        }
        return;
    }
    if (passed[index])
        return;
        
    passed[index] = true;
    
    for (int k = 0; k < g->getSize(); k++)
        if (g->distance_AB(index,k) && k != index)
        {
            path.push(k);
            curLength += g->distance_AB(index, k);

            if (curLength < length)
                hamilton1(k, level + 1);
            
            curLength -= g->distance_AB(index, k);
            path.pop();
        }
    passed[index] = false;
}

void Algorithm1::printHamilton1()
{
    if(length!=INT_MAX)
    {
        std::cout<<"\nMinimal path: 1 -> ";

        for (int i = 0; i < g->getSize() - 1; i++)
            std::cout<< minPath[i] + 1 << " -> ";

        std::cout<<"1\nPath length: "<<length<<"\n";
    }
    else
    std::cout<<"There is no Hamiltonian path in this graph!\n";
}