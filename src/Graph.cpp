#include "Graph.h"
#include <vector>
using namespace std;

Graph::Graph(int N): n(N){
    adjacentList = vector<vector<int> >(n);
}

Graph::Graph() {}

void Graph::addEdge(int u, int v){
    adjacentList[u].push_back(v);
    adjacentList[v].push_back(u);
}

int Graph::size(){
    return n;
}

const vector<vector<int> >& Graph::getAdjacentList() {
    return adjacentList;
}

void Graph::printGraph(){
    printGraph(this->n, this->adjacentList);
}

void Graph::printGraph(Graph g){
    int n = g.size();
    vector<vector<int> > adjacentList = g.getAdjacentList();
    printGraph(n,adjacentList);
}

void Graph::printGraph(int n, const vector<vector<int> >& adjacentList){
    for (int i=0;i<n;++i){
        for (int v : adjacentList[i]) {
            if (v>i) {
            printf("%d %d\n",i,v);
            }
        }
    }
}
