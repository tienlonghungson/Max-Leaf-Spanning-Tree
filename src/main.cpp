#include "algorithms/DegreeProbAlgorithm.cpp"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "SpanningTree.h"
#include <vector>

using namespace std;

int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);


    AbstractAlgorithm* algorithm = new GreedyVertexAlgorithm(g);

    SpanningTree* sp = (SpanningTree*)algorithm->execute();

    // print the SpanningTree
    vector<vector<int> > edges = sp->getAdjacentList();
    int i=0;
    for (vector<int> neigh: edges){
        cout<<"Neighbors of "<<i<<" are: ";
        for (int v: neigh){
            cout<<v<<", ";
        }
        cout<<"\n";
        i++;
    }

    return 0;
}
