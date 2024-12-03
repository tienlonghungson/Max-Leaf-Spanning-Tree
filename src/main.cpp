#include "AbstractAlgorithm.h"
#include "Graph.h"
#include "algorithms/DegreeProbAlgorithm.cpp"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "algorithms/TwoApprox.cpp"
#include "algorithms/LocalSearchAlgorithm.cpp"
#include "SpanningTree.h"
#include <cstdio>
#include <cstring>
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


    AbstractAlgorithm* greedyAlg = new GreedyVertexAlgorithm(g);
    AbstractAlgorithm* twoApprox = new TwoApprox(g);
    AbstractAlgorithm* localSearch = new LocalSearchAlgorithm(g);

    SpanningTree* ans;
    SpanningTree* tmpSP = (SpanningTree*)greedyAlg->execute();
    ans = tmpSP;

    cout<<"Greedy Sol:\n";
    ans->printGraph();

    localSearch->initiate(*tmpSP);
    tmpSP = (SpanningTree*) localSearch->execute();
    cout<<"Check current ans before LocalSearchAlgorithm\n";
    ans->printGraph();
    if (tmpSP->countLeaves()>ans->countLeaves()) {
        ans = tmpSP;
        cout<<"Updated:\n";
        ans->printGraph();
    }

    tmpSP = (SpanningTree*) twoApprox->execute();
    cout<<"TwoApprox Sol:\n";
    tmpSP->printGraph();
    cout<<"Current Best Sol:\n";
    ans->printGraph();

    localSearch->initiate(*tmpSP);
    tmpSP = (SpanningTree*) localSearch->execute();
    cout<<"Check current ans before TwoApprox\n";
    if (tmpSP->countLeaves()> ans->countLeaves()){
        ans = tmpSP;
        cout<<"Updated:\n";
        ans->printGraph();
    }


    return 0;
}
    // // print the SpanningTree of GreedyVertexAlgorithm
    // vector<vector<int> > edges = sp->getAdjacentList();
    // int i=0;
    // for (vector<int> neigh: edges){
    //     cout<<"Neighbors of "<<i<<" are: ";
    //     for (int v: neigh){
    //         cout<<v<<", ";
    //     }
    //     cout<<"\n";
    //     i++;
    // }
    //
    // cout<<"Result of TwoApprox\n";
    // sp = (SpanningTree*) twoApprox->execute();
    //
    // // print the SpanningTree of TwoApprox
    // edges = sp->getAdjacentList();
    // i=0;
    // for (vector<int> neigh: edges){
    //     cout<<"Neighbors of "<<i<<" are: ";
    //     for (int v: neigh){
    //         cout<<v<<", ";
    //     }
    //     cout<<"\n";
    //     i++;
    // }
