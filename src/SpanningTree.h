#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include "Graph.h"

class SpanningTree : public Graph{
public:
    SpanningTree(int N);
    SpanningTree(const Graph &g);
    SpanningTree();

    // verify if this graph is a tree of g
    bool verify(Graph g);

    // count the number of leaves
    int countLeaves();
};

#endif // !SPANNINGTREE_H
