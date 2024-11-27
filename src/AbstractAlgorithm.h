#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include "Graph.h"

class AbstractAlgorithm{
    protected:
        Graph graph;
    public:
        AbstractAlgorithm(Graph g){
            graph = g;
        }

        virtual void initiate(Graph spanningTree) = 0;

        virtual Graph* execute() = 0;
};

#endif // !ABSTRACTALGORITHM_H
