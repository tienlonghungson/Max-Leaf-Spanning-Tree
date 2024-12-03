#include "SpanningTree.h"
#include "Graph.h"
#include <vector>

using namespace std;

SpanningTree::SpanningTree(int N): Graph(N){}

SpanningTree::SpanningTree(const Graph& g): Graph(g){}

SpanningTree::SpanningTree(): Graph(){}

bool SpanningTree::verify(Graph g){
    return true;
}

int SpanningTree::countLeaves(){
    int cnt = 0;
    vector<vector<int> > adjacentList = this->getAdjacentList();
    for (vector<int> neighbor : adjacentList) {
        if (neighbor.size()==1) {
            cnt++;
        }
    }
    return cnt;
}
