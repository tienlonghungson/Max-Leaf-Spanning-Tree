#include"Graph.cpp"

class AbstractAlgorithm{
    private:
        Graph graph;
    public:
        AbstractAlgorithm(Graph g){
            graph = g;
        }

        virtual void initiate(Graph spanningTree) = 0;

        virtual void execute() = 0;
};
