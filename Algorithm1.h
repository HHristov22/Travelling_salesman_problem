#ifndef ALGORITHM1_H
#define ALGORITHM1_H

#include <bits/stdc++.h>
#include "Graph.h"

class Algorithm1
{
    private:
    Graph* g;
    int length;
    int curLength;
    std::vector<int> minPath;
    std::stack<int> path;
    std::vector<bool> passed;

    public:    
    void hamilton1(int, int);
    void printHamilton1();
    Algorithm1(int, Graph*);
};

#endif