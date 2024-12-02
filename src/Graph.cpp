#include "Graph.h"
#include <vector>
#include <algorithm>
using namespace std;

Graph::Graph(int N): n(N){
    list = vector<vector<int> >(n);
}

Graph::Graph(const Graph& g){
    n = g.n;
    list = g.list;
}

Graph::Graph() {}

void Graph::addEdge(int u, int v){
    list[u].push_back(v);
    list[v].push_back(u);
}

void Graph::removeEdge(int u, int v){
    list[u].erase(find(list[u].begin(), list[u].end(), v));
    list[v].erase(find(list[v].begin(), list[v].end(), u));
}

int Graph::size(){
    return n;
}

const vector<vector<int> >& Graph::getAdjacentList() {
    return list;
}
