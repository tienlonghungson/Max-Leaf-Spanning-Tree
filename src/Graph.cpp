#include "Graph.h"
#include <vector>
using namespace std;

Graph::Graph(int N): n(N){
    list = vector<vector<int> >(n);
}

Graph::Graph() {}

void Graph::addEdge(int u, int v){
    list[u].push_back(v);
    list[v].push_back(u);
}

int Graph::size(){
    return n;
}

const vector<vector<int> >& Graph::getAdjacentList() {
    return list;
}
