#ifndef SPANNINGTREE_H
#define SPANNINGTREE_H

#include "Graph.h"

class SpanningTree : public Graph{
public:
    SpanningTree(int N);
    SpanningTree();

    // verify if this graph is a tree of g
    bool verify(Graph g);
};

#endif // !SPANNINGTREE_H
