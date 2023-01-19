#include "Algorithm1.h"
#include "Algorithm2.h"
#include "Graph.h"

#include <iostream>
#include <time.h>
int main()
{
    int size;
    std::cout<<"Input the number of vertices: ";
    std::cin>>size;
    Graph g(size);
    g.input();
    int alg=-1;

    clock_t start, finish; 
    while(alg!=1 && alg!=2)
    {
        std::cout<<"Choose algorithm (1 / 2): ";
        std::cin>>alg;
        if(alg==1)
        {
            start = clock(); 
            Algorithm1 h(size, &g);
            h.hamilton1(0,0);
            h.printHamilton1();
        }
        else if (alg==2)
        {
            start = clock();
            Algorithm2 h(size, &g);
            h.hamilton2();
            h.printHamilton2();
        }
        else
        std::cout<<"There is no algorithm "<<alg<<"\n";
    } 
    finish = clock();
    double time_taken = double(finish - start) / double(CLOCKS_PER_SEC); 
    std::cout<<"Time taken by program is : "<<std::fixed<<time_taken; 
    std::cout<<"sec " << "\n";
    return 0;
}
/*
6
9
1 2 5
1 5 7
1 6 7
2 3 5
3 4 6
3 5 5
4 5 3
4 6 3
5 6 5
*/