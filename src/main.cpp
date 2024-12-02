#include "AbstractAlgorithm.h"
#include "Graph.h"
#include "algorithms/DegreeProbAlgorithm.cpp"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "algorithms/TwoApprox.cpp"
#include "SpanningTree.h"
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int n, m, a, b;

    scanf("%d %d",&n, &m);
    Graph g(n);
    for (int i=0;i<m;++i){
        scanf("%d %d", &a, &b);
        g.addEdge(a,b);
    }


    AbstractAlgorithm* algorithm = new GreedyVertexAlgorithm(g);
    AbstractAlgorithm* twoApprox = new TwoApprox(g);

    SpanningTree* sp = (SpanningTree*)algorithm->execute();

    // print the SpanningTree of GreedyVertexAlgorithm
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

    cout<<"Result of TwoApprox\n";
    sp = (SpanningTree*) twoApprox->execute();

    // print the SpanningTree of TwoApprox
    edges = sp->getAdjacentList();
    i=0;
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
