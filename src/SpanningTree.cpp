#include "SpanningTree.h"
#include "Graph.h"

using namespace std;

SpanningTree::SpanningTree(int N): Graph(N){}

SpanningTree::SpanningTree(const Graph& g): Graph(g){}

SpanningTree::SpanningTree(): Graph(){}

bool SpanningTree::verify(Graph g){
    return true;
}
