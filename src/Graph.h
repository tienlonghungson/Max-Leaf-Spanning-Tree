#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph{
    private:
        int n;
        vector<vector<int> > adjacentList;
    public:
        Graph(int N);

        Graph(const Graph& g);

        Graph();

        void addEdge(int u, int v);

        void removeEdge(int u, int v);

        int size();

        const vector<vector<int> >& getAdjacentList();

        void printGraph();

        void printGraph(Graph g);

        void printGraph(int n, const vector<vector<int> >& adjacentList);
};

#endif // !GRAPH_H
