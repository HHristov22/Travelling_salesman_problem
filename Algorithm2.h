#ifndef ALGORITHM2_H
#define ALGORITHM2_H

#include <bits/stdc++.h>
#include "Graph.h"

class Algorithm2
{
    private:
    std::vector<int> vertex;
    int length;
    int curLength;
    std::vector<int> path;
    std::vector<int> minPath;
    Graph* g;

    public:    
    Algorithm2(int, Graph*);
    void hamilton2();
    void printHamilton2();
};

#endif