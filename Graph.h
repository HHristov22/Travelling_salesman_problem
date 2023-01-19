#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{    
    private:
    int size;
    std::vector<std::vector<int>> Matrix;

    public:
    Graph();
    Graph(int);
    int getSize();
    int distance_AB (int, int);
    void input();
    void output();
};

#endif