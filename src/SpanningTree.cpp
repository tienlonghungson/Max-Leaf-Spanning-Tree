#include "SpanningTree.h"
#include "Graph.h"
#include <algorithm>
#include <queue>

using namespace std;

SpanningTree::SpanningTree(int N): Graph(N){}

SpanningTree::SpanningTree(const Graph& g): Graph(g){}

SpanningTree::SpanningTree(): Graph(){}

bool SpanningTree::verify(Graph g){
    int degrees = 0;
    auto list = getAdjacentList();
    for(int i = 0; i < size(); i++){
        degrees += list[i].size();
    }
    if (degrees != 2*size() - 2){
        return false;
    }

    queue<int> q;
    q.push(0);
    vector<bool> visited(size());
    visited[0] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : list[u]){
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }

    for(int i = 0; i < size(); i++){
        if (!visited[i]){
            return false;
        }
    }

    auto graphList = g.getAdjacentList();
    for(int i = 0; i < graphList.size(); i++){
        sort(graphList[i].begin(), graphList[i].end());
    }

    for(int i = 0; i < size(); i++){
        for(auto v : list[i]){
            if(!binary_search(graphList[i].begin(), graphList[i].end(), v)){
                return false;
            }
        }
    }

    return true; 
}
