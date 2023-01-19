#include "Algorithm2.h"
#include "Graph.h"
#include <iostream>
#include <vector>

Algorithm2::Algorithm2(int size, Graph* _g): g (_g)
{
    length = INT_MAX;
    curLength = 0;
    
	for (int i = 1; i < g->getSize(); i++)
		vertex.push_back(i);
}

void Algorithm2::hamilton2()
{
    int level=0;
	length = INT_MAX;
	do
    {
        curLength=0;
        path.clear();
        
		int k = 0;
        bool can=true;
		for (int i = 0; i < vertex.size(); i++) 
        {
            if(g->distance_AB(k,vertex[i])!=0)
			{
                curLength += g->distance_AB(k,vertex[i]);
                k = vertex[i];
                path.push_back(vertex[i]);
            }
            else
            {
                can=false;
                break;
            }
		}
        if(g->distance_AB(k,0)!=0)
		curLength += g->distance_AB(k,0);
        else
        can=false;


        if(length>curLength && can)
		{
            length = curLength;
            minPath=path;
        }

	} while (next_permutation(vertex.begin(), vertex.end()));
}

void Algorithm2::printHamilton2()
{
    if(length!=INT_MAX)
    {
        std::cout<<"\nMinimal path: 1 -> ";

        for (int i = 0; i < g->getSize() - 1; i++)
            std::cout<< minPath[i] + 1 << " -> ";

        std::cout<<"1\nPath curLength: "<<length<<"\n";
    }
    else
    std::cout<<"There is no Hamiltonian path in this graph!\n";
}