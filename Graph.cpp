#include "Graph.h"
#include <iostream>

Graph::Graph(): size (0) {}


Graph::Graph(int _size): size (_size)
{
    std::vector<int> v;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            v.push_back(0);

        Matrix.push_back(v);
    }
}

void Graph::input()
{
    int edges;
    std::cout<<"Input the number of edges: ";
    std::cin >> edges;
    std::cout<<"Format:\nVertic1 Vertic2 Weight\n";
    for (int i = 0; i < edges; i++)
    {
        int A, B, weight;
        std::cin >> A >> B >> weight;
        if(Matrix[A -1][B - 1]==0 || (Matrix[A -1][B - 1]>weight && weight!=0))
        {
            Matrix[A - 1][B - 1] = weight;
            Matrix[B - 1][A - 1] = weight;
        }
    }
}

int Graph::getSize()
{
    return size;
}

int Graph::distance_AB (int x, int y)
{
    return Matrix[x][y];
}

void Graph::output()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << Matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}
